// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: state_info_cmac_a.h

#ifndef STATE_INFO_CMAC_A_H__
#define STATE_INFO_CMAC_A_H__

/// \namespace ilang
namespace ilang {

// Idle status of two register groups
#define CMAC_A_S_STATUS_NAME "cmac_a_s_status"

// Pointer for CSB master and data path to access groups
#define CMAC_A_S_POINTER_NAME "cmac_a_s_pointer"

// Set it to 1 to kick off operation for current register group
#define CMAC_A_D_OP_ENABLE_NAME "cmac_a_d_op_enable"

// Configuration of operation: convolution mode, precision, etc.
#define CMAC_A_D_MISC_CFG_NAME "cmac_a_d_misc_cfg"

}; // namespace ilang

#endif // STATE_INFO_CMAC_A_H__
