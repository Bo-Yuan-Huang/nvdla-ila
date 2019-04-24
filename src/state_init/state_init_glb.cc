// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: state_init_glb.cc

#include <ilang/ilang++.h>
#include <nvdla/configs/state_info.h>

// namespace ilang
namespace ilang {

void StateInitGlb(Ila& m) {
  // FIXME this is temporary

  // HW version of NVDLA
  m.AddInit(m.state(GLB_HW_VERSION) == 0);

  // Interrupt mask control
  m.AddInit(m.state(GLB_INTR_MASK) == 0);

  // Interrupt set control
  m.AddInit(m.state(GLB_INTR_SET) == 0);

  // Interrupt status
  m.AddInit(m.state(GLB_INTR_STATUS) == 0);

  return;
}

}; // namespace ilang
