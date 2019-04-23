// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: cdma.cc

#include <ilang/util/log.h>
#include <nvdla/cdma.h>
#include <nvdla/configs/addr_space.h>
#include <nvdla/configs/state_info.h>
#include <nvdla/utils.h>

namespace ilang {

Ila Cdma::New(Ila& parent, const std::string& name) {
  auto m = parent.NewChild(name);

  DefineInterface(m);
  DefineInternal(m);
  DefineChild(m);
  DefineInstr(m);

  // valid
  auto valid = IsTrue(m.state(k_tag_cdma));
  m.SetValid(valid);

  // fetch
  auto fetch = BvConst(1, 1); // XXX
  m.SetFetch(fetch);

  return m;
}

void Cdma::DefineInterface(Ila& m) {
  // CSB accessable registers

  // Idle status of two register groups
  NewState(m, CDMA_S_STATUS, CSB_REQ_DATA_BWID);
  // Pointer for CSB master and data path to access groups
  NewState(m, CDMA_S_POINTER, CSB_REQ_DATA_BWID);
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

