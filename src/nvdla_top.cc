// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: nvdla_top.cc

#include <nvdla/cbuf.h>
#include <nvdla/cdma.h>
#include <nvdla/configs/addr_space.h>
#include <nvdla/configs/modeling_config.h>
#include <nvdla/configs/state_info.h>
#include <nvdla/csc.h>
#include <nvdla/nvdla_top.h>
#include <nvdla/utils.h>

namespace ilang {

// static data member
const std::string NvDla::k_tag_glb = "tag_glb";
const std::string NvDla::k_tag_mcif = "tag_mcif";
const std::string NvDla::k_tag_bdma = "tag_bdma";
const std::string NvDla::k_tag_cbuf = "tag_cbuf";
const std::string NvDla::k_tag_cdma = "tag_cdma";
const std::string NvDla::k_tag_csc = "tag_csc";
const std::string NvDla::k_tag_cmac_a = "tag_cmac_a";
const std::string NvDla::k_tag_cmac_b = "tag_cmac_b";
const std::string NvDla::k_tag_cacc = "tag_cacc";
const std::string NvDla::k_tag_sdp_rdma = "tag_sdp_rdma";
const std::string NvDla::k_tag_sdp = "tag_sdp";
const std::string NvDla::k_tag_pdp_rdma = "tag_pdp_rdma";
const std::string NvDla::k_tag_pdp = "tag_pdp";
const std::string NvDla::k_tag_cdp_rdma = "tag_cdp_rdma";
const std::string NvDla::k_tag_cdp = "tag_cdp";
const std::string NvDla::k_tag_rubic = "tag_rubic";

const std::string NvDla::k_child_cdma = "cdma";
const std::string NvDla::k_child_cbuf = "cbuf";
const std::string NvDla::k_child_csc = "csc";
const std::string NvDla::k_child_cmac_a = "cmac_a";
const std::string NvDla::k_child_cmac_b = "cmac_b";
const std::string NvDla::k_child_cacc = "cacc";

// state define methods (extern)
void StateDefineCsb(Ila& m);
void StateDefineGlb(Ila& m);
void StateDefineMcif(Ila& m);
void StateDefineSramif(Ila& m);
void StateDefineBdma(Ila& m);

// state init methods (extern)
void StateInitCsb(Ila& m);
void StateInitGlb(Ila& m);
void StateInitMcif(Ila& m);
void StateInitSramif(Ila& m);
void StateInitBdma(Ila& m);

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
  /* Trigger signals (tag of child-ILAs) */

  auto tag_glb = NewState(m, k_tag_glb);
  auto tag_mcif = NewState(m, k_tag_mcif);
  auto tag_bdma = NewState(m, k_tag_bdma);
  auto tag_cbuf = NewState(m, k_tag_cbuf);
  auto tag_cdma = NewState(m, k_tag_cdma);
  auto tag_csc = NewState(m, k_tag_csc);
  auto tag_cmac_a = NewState(m, k_tag_cmac_a);
  auto tag_cmac_b = NewState(m, k_tag_cmac_b);
  auto tag_cacc = NewState(m, k_tag_cacc);
  auto tag_sdp_rdma = NewState(m, k_tag_sdp_rdma);
  auto tag_sdp = NewState(m, k_tag_sdp);
  auto tag_pdp_rdma = NewState(m, k_tag_pdp_rdma);
  auto tag_pdp = NewState(m, k_tag_pdp);
  auto tag_cdp_rdma = NewState(m, k_tag_cdp_rdma);
  auto tag_cdp = NewState(m, k_tag_cdp);
  auto tag_rubic = NewState(m, k_tag_rubic);

  m.AddInit(IsFalse(tag_glb));
  m.AddInit(IsFalse(tag_mcif));
  m.AddInit(IsFalse(tag_bdma));
  m.AddInit(IsFalse(tag_cbuf));
  m.AddInit(IsFalse(tag_cdma));
  m.AddInit(IsFalse(tag_csc));
  m.AddInit(IsFalse(tag_cmac_a));
  m.AddInit(IsFalse(tag_cmac_b));
  m.AddInit(IsFalse(tag_cacc));
  m.AddInit(IsFalse(tag_sdp_rdma));
  m.AddInit(IsFalse(tag_sdp));
  m.AddInit(IsFalse(tag_pdp_rdma));
  m.AddInit(IsFalse(tag_pdp));
  m.AddInit(IsFalse(tag_cdp_rdma));
  m.AddInit(IsFalse(tag_cdp));
  m.AddInit(IsFalse(tag_rubic));
}

void NvDla::DefineChild(Ila& m) {
  // CDMA
  auto cdma = Cdma::New(m, k_child_cdma);

  // CBUF
  auto cbuf = Cbuf::New(m, k_child_cbuf);

  // CSC
  auto csc = Csc::New(m, k_child_csc);

#ifdef NVDLA_RETIMING_ENABLE
  // CMAC
  auto cmac_b = Cmac::New(m, k_child_cmac_b);
#endif

#ifdef NVDLA_RETIMING_ENABLE
  // CACC
  auto cacc = Cacc::New(m, k_child_cacc);
#endif

#if 0
  // SDP
  auto sdp = Sdp::New(m, k_child_sdp);
  // SDP RDMA
  auto sdp_rdma = Sdp_Rdma::New(m, k_child_sdp_rdma);

  // PDP
  auto pdp = Pdp::New(m, k_child_pdp);
  // PDP RDMA
  auto pdp_rdma = Pdp_Rdma::New(m, k_child_pdp_rdma);

  // CDP
  auto cdp = Cdp::New(m, k_child_cdp);
  // CDP RDMA
  auto cdp_rdma = Cdp_Rdma::New(m, k_child_cdp_rdma);
#endif

#ifdef NVDLA_BDMA_ENABLE
  // BDMA
  auto bdma = Bdma::New(m, k_child_bdma);
#endif // NVDLA_BDMA_ENABLE

#ifdef NVDLA_RUBIK_ENABLE
  // RUBIK
  auto rubik = Rubik::New(m, k_child_rubik);
#endif // NVDLA_RUBIK_ENABLE

  return;
}

void NvDla::DefineInstr(Ila& m) {
  // helper functions
  auto is_csb = m.state(CSB2NVDLA_READY) & m.input(CSB2NVDLA_VALID);
  auto csb_wr = (m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE));
  auto csb_rd = (m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_READ));
  auto raise_tag_val = BoolVal(1);

  { // Write to CDMA CSB registers
    auto instr = m.NewInstr("csb_wr_cdma");
    auto decode = is_csb & csb_wr &
                  (m.input(CSB2NVDLA_ADDR) >= CDMA_ADDR_SPACE_START) &
                  (m.input(CSB2NVDLA_ADDR) <= CDMA_ADDR_SPACE_END);
    instr.SetDecode(decode);

    instr.SetProgram(m.child(k_child_cdma));

    auto tag_update = raise_tag_val;
    instr.SetUpdate(m.state(k_tag_cdma), tag_update);
  }

  { // Read from CDMA CSB registers
    auto instr = m.NewInstr("csb_rd_cdma");
    auto decode = is_csb & csb_rd &
                  (m.input(CSB2NVDLA_ADDR) >= CDMA_ADDR_SPACE_START) &
                  (m.input(CSB2NVDLA_ADDR) <= CDMA_ADDR_SPACE_END);
    instr.SetDecode(decode);

    instr.SetProgram(m.child(k_child_cdma));

    auto tag_update = raise_tag_val;
    instr.SetUpdate(m.state(k_tag_cdma), tag_update);
  }

  { // Write to CSC CSB registers
    auto instr = m.NewInstr("csb_wr_csc");
    auto decode = is_csb & csb_wr &
                  (m.input(CSB2NVDLA_ADDR) >= CSC_ADDR_SPACE_START) &
                  (m.input(CSB2NVDLA_ADDR) <= CSC_ADDR_SPACE_END);

    instr.SetDecode(decode);

    instr.SetProgram(m.child(k_child_csc));

    auto tag_update = raise_tag_val;
    instr.SetUpdate(m.state(k_tag_csc), tag_update);
  }

  { // Read from CSC CSB registers
    auto instr = m.NewInstr("csb_rd_csc");
    auto decode = is_csb & csb_rd &
                  (m.input(CSB2NVDLA_ADDR) >= CSC_ADDR_SPACE_START) &
                  (m.input(CSB2NVDLA_ADDR) <= CSC_ADDR_SPACE_END);

    instr.SetDecode(decode);

    instr.SetProgram(m.child(k_child_csc));

    auto tag_update = raise_tag_val;
    instr.SetUpdate(m.state(k_tag_csc), tag_update);
  }
}

}; // namespace ilang
