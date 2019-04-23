// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: addr_cmac_a.h

#ifndef NVDLA_ADDR_CMAC_A_H__
#define NVDLA_ADDR_CMAC_A_H__

/// \namespace ilang
namespace ilang {

// Idle status of two register groups
#define CMAC_A_S_STATUS_ADDR 0x7000
// Pointer for CSB master and data path to access groups
#define CMAC_A_S_POINTER_ADDR 0x7004
// Set it to 1 to kick off operation for current register group
#define CMAC_A_D_OP_ENABLE_ADDR 0x7008
// Configuration of operation: convolution mode, precision, etc.
#define CMAC_A_D_MISC_CFG_ADDR 0x700c

}; // namespace ilang

#endif // NVDLA_ADDR_CMAC_A_H__
