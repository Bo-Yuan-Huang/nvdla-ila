// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: addr_sramif.h

#ifndef NVDLA_ADDR_SRAMIF_H__
#define NVDLA_ADDR_SRAMIF_H__

/// \namespace ilang
namespace ilang {

// Register0 to control the read weight of clients in MCIF
#define SRAMIF_CFG_RD_WEIGHT_0 0x3000
// Register1 to control the read weight of clients in MCIF
#define SRAMIF_CFG_RD_WEIGHT_1 0x3004
// Register2 to control the read weight of clients in MCIF
#define SRAMIF_CFG_RD_WEIGHT_2 0x3008
// Register0 to control the write weight of clients in MCIF
#define SRAMIF_CFG_WR_WEIGHT_0 0x300c
// Register1 to control the write weight of clients in MCIF
#define SRAMIF_CFG_WR_WEIGHT_1 0x3010
// Outstanding AXI transactions in unit of 64Byte
#define SRAMIF_CFG_OUTSTANDING_CNT 0x3014
// Idle status of SRAMIF
#define SRAMIF_STATUS 0x3018

}; // namespace ilang

#endif // NVDLA_ADDR_SRAMIF_H__
