// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: state_info_cmac_b.h

#ifndef STATE_INFO_CMAC_B_H__
#define STATE_INFO_CMAC_B_H__

/// \namespace ilang
namespace ilang {

// Idle status of two register groups
#define CMAC_B_S_STATUS_NAME "cmac_b_s_status"
#define CMAC_B_S_STATUS_BWID 32
// Pointer for CSB master and data path to access groups
#define CMAC_B_S_POINTER_NAME "cmac_b_s_pointer"
#define CMAC_B_S_POINTER_BWID 32
// Set it to 1 to kick off operation for current register group
#define CMAC_B_D_OP_ENABLE_NAME "cmac_b_d_op_enable"
#define CMAC_B_D_OP_ENABLE_BWID 32
// Configuration of operation: convolution mode, precision, etc.
#define CMAC_B_D_MISC_CFG_NAME "cmac_b_d_misc_cfg"
#define CMAC_B_D_MISC_CFG_BWID 32

}; // namespace ilang

#endif // STATE_INFO_CMAC_B_H__
