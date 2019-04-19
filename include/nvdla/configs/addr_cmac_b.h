// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" wich comes with this distribution for more information.
// ============================================================================

// File Name: addr_cmac_b.h

#ifndef NVDLA_ADDR_CMAC_B_H__
#define NVDLA_ADDR_CMAC_B_H__

/// \namespace ilang
namespace ilang {

// Idle status of two register groups
#define CMAC_B_S_STATUS 0x8000
// Pointer for CSB master and data path to access groups
#define CMAC_B_S_POINTER 0x8004
// Set it to 1 to kick off operation for current register group
#define CMAC_B_D_OP_ENABLE 0x8008
// Configuration of operation: convolution mode, precision, etc.
#define CMAC_B_D_MISC_CFG 0x800c

}; // namespace ilang

#endif // NVDLA_ADDR_CMAC_B_H__
