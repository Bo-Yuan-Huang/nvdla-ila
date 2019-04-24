// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: cdma.cc

#include <nvdla/cdma.h>
#include <nvdla/utils.h>

namespace ilang {

void StateDefineCdma(Ila& m);

Ila Cdma::New(Ila& parent, const std::string& name) {
  auto m = parent.NewChild(name);

  DefineInterface(m);
  DefineInternal(m);
  DefineChild(m);
  DefineInstr(m);

#if 1
  // valid
  auto valid = IsTrue(m.state(k_trig_cdma));
  m.SetValid(valid);
#endif

  // fetch
  auto fetch = BvConst(1, 1); // FIXME
  m.SetFetch(fetch);

  return m;
}

void Cdma::DefineInterface(Ila& m) {
  // CSB accessable registers
  StateDefineCdma(m);
  // StateInitCdma(m);
}

void Cdma::DefineInternal(Ila& m) {
  //
}

void Cdma::DefineChild(Ila& m) {
  //
}

void Cdma::DefineInstr(Ila& m) {
  //
}

}; // namespace ilang

