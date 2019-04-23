// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: addr_mcif.h

#ifndef NVDLA_ADDR_MCIF_H__
#define NVDLA_ADDR_MCIF_H__

/// \namespace ilang
namespace ilang {

// Register0 to control the read weight of clients in MCIF
#define MCIF_CFG_RD_WEIGHT_0_ADDR 0x2000
// Register1 to control the read weight of clients in MCIF
#define MCIF_CFG_RD_WEIGHT_1_ADDR 0x2004
// Register2 to control the read weight of clients in MCIF
#define MCIF_CFG_RD_WEIGHT_2_ADDR 0x2008
// Register0 to control the write weight of clients in MCIF
#define MCIF_CFG_WR_WEIGHT_0_ADDR 0x200c
// Register1 to control the write weight of clients in MCIF
#define MCIF_CFG_WR_WEIGHT_1_ADDR 0x2010
// Outstanding AXI transactions in unit of 64Byte
#define MCIF_CFG_OUTSTANDING_CNT_ADDR 0x2014
// Idle status of MCIF
#define MCIF_STATUS_ADDR 0x2018

}; // namespace ilang

#endif // NVDLA_ADDR_MCIF_H__
