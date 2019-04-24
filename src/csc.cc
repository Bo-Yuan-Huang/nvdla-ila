// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: csc.cc

#include <ilang/util/log.h>
#include <nvdla/configs/addr_space.h>
#include <nvdla/configs/state_info.h>
#include <nvdla/csc.h>
#include <nvdla/utils.h>

namespace ilang {

void StateDefineCsc(Ila& m);

Ila Csc::New(Ila& parent, const std::string& name) {
  auto m = parent.NewChild(name);

  DefineInterface(m);
  DefineInternal(m);
  DefineChild(m);
  DefineInstr(m);

  // valid
  auto valid = IsTrue(m.state(k_tag_csc));
  m.SetValid(valid);

  // fetch
  auto fetch = BvConst(1, 1); // XXX
  m.SetFetch(fetch);

  return m;
}

void Csc::DefineInterface(Ila& m) {
  // CSB accessable registers
  StateDefineCsc(m);
  // StateInitCdma(m);
}

void Csc::DefineInternal(Ila& m) {
  //
}

void Csc::DefineChild(Ila& m) {
  //
}

void Csc::DefineInstr(Ila& m) {
  //
}

}; // namespace ilang

