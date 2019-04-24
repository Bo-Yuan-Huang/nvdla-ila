// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: cbuf.cc

#include <ilang/util/log.h>
#include <nvdla/cbuf.h>
#include <nvdla/configs/addr_space.h>
#include <nvdla/configs/state_info.h>
#include <nvdla/utils.h>

namespace ilang {

Ila Cbuf::New(Ila& parent, const std::string& name) {
  auto m = parent.NewChild(name);

  DefineInterface(m);
  DefineInternal(m);
  DefineChild(m);
  DefineInstr(m);

  // valid
  auto valid = IsTrue(m.state(k_tag_cbuf));
  m.SetValid(valid);

  // fetch
  auto fetch = BvConst(1, 1); // XXX
  m.SetFetch(fetch);

  return m;
}

void Cbuf::DefineInterface(Ila& m) {
  // CSB accessable registers
  // StateDefineCsc(m);
  // StateInitCdma(m);
}

void Cbuf::DefineInternal(Ila& m) {
  //
}

void Cbuf::DefineChild(Ila& m) {
  //
}

void Cbuf::DefineInstr(Ila& m) {
  //
}

}; // namespace ilang

