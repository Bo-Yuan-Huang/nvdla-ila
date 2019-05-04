// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: conv_pipe.cc

#include <ilang/util/log.h>
#include <nvdla/configs/hw_param.h>
#include <nvdla/configs/modeling_config.h>
#include <nvdla/configs/state_info.h>
#include <nvdla/conv_pipe.h>
#include <nvdla/state_update/ppsm_cdma.h>
#include <nvdla/utils.h>

// namespace ilang
namespace ilang {

// static data member

// extern member
void StateDefineCdma(Ila& m);
void StateDefineCsc(Ila& m);
void StateDefineCmac_B(Ila& m);
void StateDefineCacc(Ila& m);

void StateInitCdma(Ila& m);
void StateInitCsc(Ila& m);
void StateInitCmac_B(Ila& m);
void StateInitCacc(Ila& m);

Ila ConvPipe::New(Ila& parent, const std::string& name) {
  auto m = parent.NewChild(name);

  // state var
  SetArchStateVar(m);
  SetImplStateVar(m);

  // model hierarchy
  SetChild(m);

  // instructions
  SetInstr(m);

  // valid
  auto valid = IsTrue(m.state(k_trig_conv_pipe));
  m.SetValid(valid);

  // fetch
  auto fetch = m.input(CSB2NVDLA_ADDR);
  m.SetFetch(fetch);

  return m;
}

void ConvPipe::GetInputAssumption(const Ila& m, ExprVec& assm) {
  //
  return;
}

void ConvPipe::GetStateInvariant(const Ila& m, ExprVec& invr) {
  //
  return;
}

std::string ConvPipe::CbufBankName(const int& idx) {
  ILA_ASSERT((idx >= 0) && (idx < NVDLA_CBUF_BANK_NUMBER))
      << "Invalid cbuf idx " << idx;
  auto name = "cbuf_bank_" + std::to_string(idx);
  return name;
}

void ConvPipe::SetArchStateVar(Ila& m) {
  // CDMA
  StateDefineCdma(m);
  StateInitCdma(m);

  // CBUF
  // no MMIO addressible registers

  // CSC
  StateDefineCsc(m);
  StateInitCsc(m);

  // CMAC
  StateDefineCmac_B(m);
  StateInitCmac_B(m);

  // CACC
  StateDefineCacc(m);
  StateInitCacc(m);

  return;
}

void ConvPipe::SetImplStateVar(Ila& m) {
  // CBUF
  for (auto i = 0; i < NVDLA_CBUF_BANK_NUMBER; i++) {
    auto bank_i =
        m.NewMemState(CbufBankName(i), ICFG_PTR_BWID, NVDLA_CBUF_BANK_WIDTH);
    bank_i.SetEntryNum(NVDLA_CBUF_BANK_DEPTH);
  }

  return;
}

void ConvPipe::SetChild(Ila& m) {
  //
  return;
}

void ConvPipe::SetInstr(Ila& m) {
  // CSB write (no side effect)
  // CDMA
  CsbWrPpsm_CDMA_D_OP_ENABLE(m);

  // CSC

  // CMAC

  // CACC

  return;
}

}; // namespace ilang

