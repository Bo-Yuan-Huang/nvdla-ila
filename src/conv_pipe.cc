// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: conv_pipe.cc

#include <nvdla/cdma.h>
#include <nvdla/configs/hw_param.h>
#include <nvdla/conv_pipe.h>
#include <nvdla/csc.h>
#include <nvdla/utils.h>

// namespace ilang
namespace ilang {

// static data member

const std::string ConvPipe::k_name_cdma = "cdma";
const std::string ConvPipe::k_trig_cdma = "trig_cdma";

const std::string ConvPipe::k_name_csc = "csc";
const std::string ConvPipe::k_trig_csc = "trig_csc";

const std::string ConvPipe::k_name_cmac = "cmac";
const std::string ConvPipe::k_trig_cmac = "trig_cmac";

const std::string ConvPipe::k_name_cacc = "cacc";
const std::string ConvPipe::k_trig_cacc = "trig_cacc";

Ila ConvPipe::New(Ila& parent, const std::string& name) {
  auto m = parent.NewChild(name);

  SetArchStateVar(m);
  SetImplStateVar(m);
  SetChild(m);
  SetInstr(m);

  // valid
  auto valid = IsTrue(m.state(k_trig_conv_pipe));
  m.SetValid(valid);

  // fetch
  auto fetch = BvConst(1, 1); // FIXME
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
  //
  return;
}

void ConvPipe::SetImplStateVar(Ila& m) {
  // CDMA
  // auto trig_cdma = NewState(m, k_trig_cdma);
  // m.AddInit(IsFalse(trig_cdma));

  // CSC
  // auto trig_csc = NewState(m, k_trig_csc);
  // m.AddInit(IsFalse(trig_csc));

#ifdef NVDLA_RETIMING_ENABLE
  // CMAC

  // CACC

#endif // NVDLA_RETIMING_ENABLE

  return;
}

void ConvPipe::SetChild(Ila& m) {
  // CDMA
  // auto cdma = Cdma::New(m, k_name_cdma);
  // cdma.SetValid(IsTrue(m.state(k_trig_cdma)));

  // CSC
  // auto csc = Csc::New(m, k_name_csc);
  // csc.SetValid(IsTrue(m.state(k_trig_csc)));

#ifdef NVDLA_RETIMING_ENABLE
  // CMAC
  // CACC
#endif // NVDLA_RETIMING_ENABLE

  return;
}

void ConvPipe::SetInstr(Ila& m) {
  //
  return;
}

}; // namespace ilang

