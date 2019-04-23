// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: state_info_sramif.h

#ifndef STATE_INFO_SRAMIF_H__
#define STATE_INFO_SRAMIF_H__

/// \namespace ilang
namespace ilang {

// Register0 to control the read weight of clients in MCIF
#define SRAMIF_CFG_RD_WEIGHT_0_NAME "sramif_cfg_rd_weight_0"
#define SRAMIF_CFG_RD_WEIGHT_0_BWID 32
// Register1 to control the read weight of clients in MCIF
#define SRAMIF_CFG_RD_WEIGHT_1_NAME "sramif_cfg_rd_weight_1"
#define SRAMIF_CFG_RD_WEIGHT_1_BWID 32
// Register2 to control the read weight of clients in MCIF
#define SRAMIF_CFG_RD_WEIGHT_2_NAME "sramif_cfg_rd_weight_2"
#define SRAMIF_CFG_RD_WEIGHT_2_BWID 32
// Register0 to control the write weight of clients in MCIF
#define SRAMIF_CFG_WR_WEIGHT_0_NAME "sramif_cfg_wr_weight_0"
#define SRAMIF_CFG_WR_WEIGHT_0_BWID 32
// Register1 to control the write weight of clients in MCIF
#define SRAMIF_CFG_WR_WEIGHT_1_NAME "sramif_cfg_wr_weight_1"
#define SRAMIF_CFG_WR_WEIGHT_1_BWID 32
// Outstanding AXI transactions in unit of 64Byte
#define SRAMIF_CFG_OUTSTANDING_CNT_NAME "sramif_cfg_outstanding_cnt"
#define SRAMIF_CFG_OUTSTANDING_CNT_BWID 32
// Idle status of SRAMIF
#define SRAMIF_STATUS_NAME "sramif_status"
#define SRAMIF_STATUS_BWID 32

}; // namespace ilang

#endif // STATE_INFO_SRAMIF_H__
