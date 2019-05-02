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

// namespace ilang
namespace ilang {

// Idle status of two register groups
#define CMAC_A_S_STATUS "cmac_a_s_status"
#define CMAC_A_S_STATUS_ADDR 0x7000
#define CMAC_A_S_STATUS_BWID 32

// Pointer for CSB master and data path to access groups
#define CMAC_A_S_POINTER "cmac_a_s_pointer"
#define CMAC_A_S_POINTER_ADDR 0x7004
#define CMAC_A_S_POINTER_BWID 32

// Set it to 1 to kick off operation for current register group
#define CMAC_A_D_OP_ENABLE_G0 "cmac_a_d_op_enable_g0"
#define CMAC_A_D_OP_ENABLE_G1 "cmac_a_d_op_enable_g1"
#define CMAC_A_D_OP_ENABLE_ADDR 0x7008
#define CMAC_A_D_OP_ENABLE_BWID 32

// Configuration of operation: convolution mode, precision, etc.
#define CMAC_A_D_MISC_CFG_G0 "cmac_a_d_misc_cfg_g0"
#define CMAC_A_D_MISC_CFG_G1 "cmac_a_d_misc_cfg_g1"
#define CMAC_A_D_MISC_CFG_ADDR 0x700c
#define CMAC_A_D_MISC_CFG_BWID 32

}; // namespace ilang

#endif // STATE_INFO_CMAC_A_H__
