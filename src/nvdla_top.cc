// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: nvdla_top.cc

#include <nvdla/configs/addr_space.h>
#include <nvdla/configs/hw_param.h>
#include <nvdla/configs/modeling_config.h>
#include <nvdla/configs/state_info.h>
#include <nvdla/conv_pipe.h>
#include <nvdla/nvdla_top.h>
#include <nvdla/utils.h>

namespace ilang {

// static data member
const std::string NvDla::k_name_conv_pipe = "conv_pipe";
const std::string NvDla::k_trig_conv_pipe = "trig_conv_pipe";

const std::string NvDla::k_name_sdp_pipe = "sdp_pipe";
const std::string NvDla::k_trig_sdp_pipe = "trig_sdp_pipe";

const std::string NvDla::k_name_pdp_pipe = "pdp_pipe";
const std::string NvDla::k_trig_pdp_pipe = "trig_pdp_pipe";

const std::string NvDla::k_name_cdp_pipe = "cdp_pipe";
const std::string NvDla::k_trig_cdp_pipe = "trig_cdp_pipe";

const std::string NvDla::k_name_bdma = "bdma";
const std::string NvDla::k_trig_bdma = "trig_bdma";

const std::string NvDla::k_name_rubik = "rubik";
const std::string NvDla::k_trig_rubik = "trig_rubik";

// state define methods (extern)
void StateDefineCsb(Ila& m);
void StateDefineDbbif(Ila& m); // XXX abstracted
void StateDefineGlb(Ila& m);
void StateDefineMcif(Ila& m);
void StateDefineSramif(Ila& m); // XXX not in nv_small

// state init methods (extern)
void StateInitCsb(Ila& m);
void StateInitDbbif(Ila& m); // XXX abstracted
void StateInitGlb(Ila& m);
void StateInitMcif(Ila& m);
void StateInitSramif(Ila& m); // XXX not in nv_small

NvDla::NvDla() {}

NvDla::~NvDla() {}

Ila NvDla::New(const std::string& name) {
  auto m = Ila(name);

  DefineInterface(m);
  DefineInternal(m);
  DefineChild(m);
  DefineInstr(m);

  // valid
  m.SetValid(BoolVal(1)); // FIXME

  // fetch
  m.SetFetch(BvConst(1, 1)); // FIXME

  return m;
}

std::vector<ExprRef> NvDla::Assumptions(Ila& m) {
  auto assumptions = std::vector<ExprRef>();

  { // CSB request channel vs. read response
    // no (immediate) request at time of previous read response
    auto imm = m.input(CSB2NVDLA_VALID) & m.state(NVDLA2CSB_VALID);
    auto no_imm_rd = IsFalse(imm);
    assumptions.push_back(no_imm_rd);
  }

  { // CSB request channel vs. read response
    // no (immediate) request at time of previous write response
    auto imm = m.input(CSB2NVDLA_VALID) & m.state(NVDLA2CSB_WR_COMPLETE);
    auto no_imm_wr = IsFalse(imm);
    assumptions.push_back(no_imm_wr);
  }

  return assumptions;
}

std::vector<ExprRef> NvDla::Invariants(Ila& m) {
  auto invariants = std::vector<ExprRef>();

#if 0
  { // CSB request channel vs. read response
    // not allow (immediate) request at time of previous read response
    auto imm = m.state(CSB2NVDLA_READY) & m.state(NVDLA2CSB_VALID);
    auto not_allow_imm_rd = IsFalse(imm);
    invariants.push_back(not_allow_imm_rd);
  }

  { // CSB request channel vs. write response
    // not allow (immediate) request at time of previous write response
    auto imm = m.state(CSB2NVDLA_READY) & m.state(NVDLA2CSB_WR_COMPLETE);
    auto not_allow_imm_wr = IsFalse(imm);
    invariants.push_back(not_allow_imm_wr);
  }
#endif

  return invariants;
}

void NvDla::DefineInterface(Ila& m) {
  // CSB
  StateDefineCsb(m);
  StateInitCsb(m);

#ifdef MODEL_AXI_DETAIL
  // DBBIF (abstract AXI protocol)
  StateDefineDbbif(m);
  StateInitDbbif(m);
#endif

  // GLB
  StateDefineGlb(m);
  StateInitGlb(m);

  // MCIF
  StateDefineMcif(m);
  StateInitMcif(m);

#ifdef NVDLA_SECONDARY_MEMIF_ENABLE
  // SRAMIF
  StateDefineSramif(m);
  StateInitSramif(m);
#endif // NVDLA_SECONDARY_MEMIF_ENABLE

  return;
}

void NvDla::DefineInternal(Ila& m) {
  /* Trigger signals */

  // single data processor pipeline
  auto trig_conv = NewState(m, k_trig_conv_pipe);
  m.AddInit(IsFalse(trig_conv));

  // TODO not implemented yet
#if 0
  // single data processor pipeline
  auto trig_sdp = NewState(m, k_trig_sdp_pipe);
  m.AddInit(IsFalse(trig_sdp));

  // planar data processor pipeline
  auto trig_pdp = NewState(m, k_trig_pdp_pipe);
  m.AddInit(IsFalse(trig_pdp));

  // channel data processor pipeline
  auto trig_cdp = NewState(m, k_trig_cdp_pipe);
  m.AddInit(IsFalse(trig_cdp));
#endif

#ifdef NVDLA_BDMA_ENABLE
  // BDMA
  auto trig_bdma = NewState(m, k_trig_bdma);
  m.AddInit(IsFalse(trig_bdma));
#endif // NVDLA_BDMA_ENABLE

#ifdef NVDLA_RUBIK_ENABLE
  // RUBIK
  auto trig_rubik = NewState(m, k_trig_rubik);
  m.AddInit(IsFalse(trig_rubik));
#endif // NVDLA_RUBIK_ENABLE

  return;
}

void NvDla::DefineChild(Ila& m) {

  // convolution pipeline
  auto conv = ConvPipe::New(m, k_name_conv_pipe);
  conv.SetValid(IsTrue(m.state(k_trig_conv_pipe)));

  // TODO not implemented yet
#if 0
  // single data processor pipeline
  auto sdp = SdpPipe::New(m, k_name_sdp_pipe);
  sdp.SetValid(IsTrue(m.state(k_trig_sdp_pipe)));

  // planar data processor pipeline
  auto pdp = PdpPipe::New(m, k_name_pdp_pipe);
  pdp.SetValid(IsTrue(m.state(k_trig_pdp_pipe)));

  // channel data processor pipeline
  auto cdp = CdpPipe::New(m, k_name_cdp_pipe);
  cdp.SetValid(IsTrue(m.state(k_trig_cdp_pipe)));
#endif

#ifdef NVDLA_BDMA_ENABLE
  // BDMA
  auto bdma = Bdma::New(m, k_name_bdma);
  bdma.SetValid(IsTrue(m.state(k_trig_bdma)));
#endif // NVDLA_BDMA_ENABLE

#ifdef NVDLA_RUBIK_ENABLE
  // RUBIK
  auto rubik = Rubik::New(m, k_name_rubik);
  rubik.SetValid(IsTrue(m.state(k_trig_rubik)));
#endif // NVDLA_RUBIK_ENABLE

  return;
}

void NvDla::DefineInstr(Ila& m) {
  // helper functions
  auto is_csb = m.state(CSB2NVDLA_READY) & m.input(CSB2NVDLA_VALID);
  auto csb_wr = (m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE));
  auto csb_rd = (m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_READ));
  auto raise_trig_val = BoolVal(1);

  { // Write to CDMA/CSC/CMAC/CACC CSB registers
    auto instr = m.NewInstr("csb_wr_conv_pipe");
    auto decode = is_csb & csb_wr &
                  (m.input(CSB2NVDLA_ADDR) >= CDMA_ADDR_SPACE_START) &
                  (m.input(CSB2NVDLA_ADDR) <= CACC_ADDR_SPACE_END);
    instr.SetDecode(decode);

    instr.SetProgram(m.child(k_name_conv_pipe));

    auto trig_update = raise_trig_val;
    instr.SetUpdate(m.state(k_trig_conv_pipe), trig_update);
  }

  { // Read from CDMA/CSC/CMAC/CACC CSB registers
    auto instr = m.NewInstr("csb_rd_conv_pipe");
    auto decode = is_csb & csb_rd &
                  (m.input(CSB2NVDLA_ADDR) >= CDMA_ADDR_SPACE_START) &
                  (m.input(CSB2NVDLA_ADDR) <= CACC_ADDR_SPACE_END);
    instr.SetDecode(decode);

    instr.SetProgram(m.child(k_name_conv_pipe));

    auto trig_update = raise_trig_val;
    instr.SetUpdate(m.state(k_trig_conv_pipe), trig_update);
  }
}

}; // namespace ilang
