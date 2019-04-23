// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: state_define_glb.cc

#include <ilang/ilang++.h>
#include <nvdla/configs/state_info.h>
#include <nvdla/utils.h>

// namespace ilang
namespace ilang {

void StateDefine_glb(Ila& m) {
  // HW version of NVDLA
  NewState(m, GLB_HW_VERSION, GLB_HW_VERSION_BWID);

  // Interrupt mask control
  NewState(m, GLB_INTR_MASK, GLB_INTR_MASK_BWID);

  // Interrupt set control
  NewState(m, GLB_INTR_SET, GLB_INTR_SET_BWID);

  // Interrupt status
  NewState(m, GLB_INTR_STATUS, GLB_INTR_STATUS_BWID);

  return;
}

}; // namespace ilang
