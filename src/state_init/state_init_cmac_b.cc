// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: state_init_cmac_b.cc

#include <ilang/ilang++.h>
#include <nvdla/configs/state_info.h>
#include <nvdla/utils.h>

// namespace ilang
namespace ilang {

// FIXME this is auto-generated placeholder

void StateInitCmac_B(Ila& m) {
  // Idle status of two register groups
  m.AddInit(m.state(CMAC_B_S_STATUS) == 0);

  // Pointer for CSB master and data path to access groups
  m.AddInit(m.state(CMAC_B_S_POINTER) == 0);

  // Set it to 1 to kick off operation for current register group
  m.AddInit(m.state(CMAC_B_D_OP_ENABLE) == 0);

  // Configuration of operation: convolution mode, precision, etc.
  m.AddInit(m.state(CMAC_B_D_MISC_CFG) == 0);

  return;
}

}; // namespace ilang
