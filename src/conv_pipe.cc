// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: conv_pipe.cc

#include <nvdla/configs/hw_param.h>
#include <nvdla/configs/state_info.h>
#include <nvdla/conv_pipe.h>
#include <nvdla/utils.h>

// namespace ilang
namespace ilang {

// static data member

// extern member
void StateDefineCdma(Ila& m);
void StateDefineCsc(Ila& m);
void StateDefineCmac_b(Ila& m);
void StateDefineCacc(Ila& m);

void StateInitCdma(Ila& m);
void StateInitCsc(Ila& m);
void StateInitCmac_b(Ila& m);
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

void ConvPipe::SetArchStateVar(Ila& m) {
  // CDMA
  StateDefineCdma(m);
  StateInitCdma(m);

  // CBUF
  // no MMIO addressible registers

  // CSC
  StateDefineCsc(m);
  StateInitCsc(m);

#ifdef NVDLA_RETIMING_ENABLE
  // CMAC
  StateDefineCmac(m);
  StateInitCmac(m);

  // CACC
  StateDefineCacc(m);
  StateInitCacc(m);

#endif // NVDLA_RETIMING_ENABLE

  return;
}

void ConvPipe::SetImplStateVar(Ila& m) {
  // CBUF

  return;
}

void ConvPipe::SetChild(Ila& m) {
  //
  return;
}

void ConvPipe::SetInstr(Ila& m) {
  //
  return;
}

}; // namespace ilang

