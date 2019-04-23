// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: state_define_cmac_b.cc

#include <ilang/ilang++.h>
#include <nvdla/configs/state_info.h>
#include <nvdla/utils.h>

// namespace ilang
namespace ilang {

void StateDefine_cmac_b(Ila& m) {
  // Idle status of two register groups
  NewState(m, CMAC_B_S_STATUS, CMAC_B_S_STATUS_BWID);

  // Pointer for CSB master and data path to access groups
  NewState(m, CMAC_B_S_POINTER, CMAC_B_S_POINTER_BWID);

  // Set it to 1 to kick off operation for current register group
  NewState(m, CMAC_B_D_OP_ENABLE, CMAC_B_D_OP_ENABLE_BWID);

  // Configuration of operation: convolution mode, precision, etc.
  NewState(m, CMAC_B_D_MISC_CFG, CMAC_B_D_MISC_CFG_BWID);

  return;
}

}; // namespace ilang
