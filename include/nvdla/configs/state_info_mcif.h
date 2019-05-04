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

#include <nvdla/configs/modeling_config.h>

// namespace ilang
namespace ilang {

// Register0 to control the read weight of clients in MCIF
#define MCIF_CFG_RD_WEIGHT_0 "mcif_cfg_rd_weight_0"
#define MCIF_CFG_RD_WEIGHT_0_ADDR 0x2000
#define MCIF_CFG_RD_WEIGHT_0_BWID ICFG_CSB_DATA_BWID

// Register1 to control the read weight of clients in MCIF
#define MCIF_CFG_RD_WEIGHT_1 "mcif_cfg_rd_weight_1"
#define MCIF_CFG_RD_WEIGHT_1_ADDR 0x2004
#define MCIF_CFG_RD_WEIGHT_1_BWID ICFG_CSB_DATA_BWID

// Register2 to control the read weight of clients in MCIF
#define MCIF_CFG_RD_WEIGHT_2 "mcif_cfg_rd_weight_2"
#define MCIF_CFG_RD_WEIGHT_2_ADDR 0x2008
#define MCIF_CFG_RD_WEIGHT_2_BWID ICFG_CSB_DATA_BWID

// Register0 to control the write weight of clients in MCIF
#define MCIF_CFG_WR_WEIGHT_0 "mcif_cfg_wr_weight_0"
#define MCIF_CFG_WR_WEIGHT_0_ADDR 0x200c
#define MCIF_CFG_WR_WEIGHT_0_BWID ICFG_CSB_DATA_BWID

// Register1 to control the write weight of clients in MCIF
#define MCIF_CFG_WR_WEIGHT_1 "mcif_cfg_wr_weight_1"
#define MCIF_CFG_WR_WEIGHT_1_ADDR 0x2010
#define MCIF_CFG_WR_WEIGHT_1_BWID ICFG_CSB_DATA_BWID

// Outstanding AXI transactions in unit of 64Byte
#define MCIF_CFG_OUTSTANDING_CNT "mcif_cfg_outstanding_cnt"
#define MCIF_CFG_OUTSTANDING_CNT_ADDR 0x2014
#define MCIF_CFG_OUTSTANDING_CNT_BWID ICFG_CSB_DATA_BWID

// Idle status of MCIF
#define MCIF_STATUS "mcif_status"
#define MCIF_STATUS_ADDR 0x2018
#define MCIF_STATUS_BWID ICFG_CSB_DATA_BWID

}; // namespace ilang

#endif // STATE_INFO_MCIF_H__
