// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: state_info_mcif.h

#ifndef STATE_INFO_MCIF_H__
#define STATE_INFO_MCIF_H__

/// \namespace ilang
namespace ilang {

// Register0 to control the read weight of clients in MCIF
#define MCIF_CFG_RD_WEIGHT_0_NAME "mcif_cfg_rd_weight_0"

// Register1 to control the read weight of clients in MCIF
#define MCIF_CFG_RD_WEIGHT_1_NAME "mcif_cfg_rd_weight_1"

// Register2 to control the read weight of clients in MCIF
#define MCIF_CFG_RD_WEIGHT_2_NAME "mcif_cfg_rd_weight_2"

// Register0 to control the write weight of clients in MCIF
#define MCIF_CFG_WR_WEIGHT_0_NAME "mcif_cfg_wr_weight_0"

// Register1 to control the write weight of clients in MCIF
#define MCIF_CFG_WR_WEIGHT_1_NAME "mcif_cfg_wr_weight_1"

// Outstanding AXI transactions in unit of 64Byte
#define MCIF_CFG_OUTSTANDING_CNT_NAME "mcif_cfg_outstanding_cnt"

// Idle status of MCIF
#define MCIF_STATUS_NAME "mcif_status"

}; // namespace ilang

#endif // STATE_INFO_MCIF_H__
