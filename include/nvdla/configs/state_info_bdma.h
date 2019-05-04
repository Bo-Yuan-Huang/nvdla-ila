// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: state_info_bdma.h

#ifndef STATE_INFO_BDMA_H__
#define STATE_INFO_BDMA_H__

#include <nvdla/configs/modeling_config.h>

// namespace ilang
namespace ilang {

// Lower 32bits of source address
#define BDMA_CFG_SRC_ADDR_LOW "bdma_cfg_src_addr_low"
#define BDMA_CFG_SRC_ADDR_LOW_ADDR 0x4000
#define BDMA_CFG_SRC_ADDR_LOW_BWID ICFG_CSB_DATA_BWID

// Higher 32bits of source address when axi araddr is 64bits
#define BDMA_CFG_SRC_ADDR_HIGH "bdma_cfg_src_addr_high"
#define BDMA_CFG_SRC_ADDR_HIGH_ADDR 0x4004
#define BDMA_CFG_SRC_ADDR_HIGH_BWID ICFG_CSB_DATA_BWID

// Lower 32bits of dest address
#define BDMA_CFG_DST_ADDR_LOW "bdma_cfg_dst_addr_low"
#define BDMA_CFG_DST_ADDR_LOW_ADDR 0x4008
#define BDMA_CFG_DST_ADDR_LOW_BWID ICFG_CSB_DATA_BWID

// Higher 32bits of dest address when axi awaddr is 64bits
#define BDMA_CFG_DST_ADDR_HIGH "bdma_cfg_dst_addr_high"
#define BDMA_CFG_DST_ADDR_HIGH_ADDR 0x400c
#define BDMA_CFG_DST_ADDR_HIGH_BWID ICFG_CSB_DATA_BWID

// Size of one line
#define BDMA_CFG_LINE "bdma_cfg_line"
#define BDMA_CFG_LINE_ADDR 0x4010
#define BDMA_CFG_LINE_BWID ICFG_CSB_DATA_BWID

// Ram type of source and destination
#define BDMA_CFG_CMD "bdma_cfg_cmd"
#define BDMA_CFG_CMD_ADDR 0x4014
#define BDMA_CFG_CMD_BWID ICFG_CSB_DATA_BWID

// Number of lines to be moved in one surface
#define BDMA_CFG_LINE_REPEAT "bdma_cfg_line_repeat"
#define BDMA_CFG_LINE_REPEAT_ADDR 0x4018
#define BDMA_CFG_LINE_REPEAT_BWID ICFG_CSB_DATA_BWID

// Source line stride
#define BDMA_CFG_SRC_LINE "bdma_cfg_src_line"
#define BDMA_CFG_SRC_LINE_ADDR 0x401c
#define BDMA_CFG_SRC_LINE_BWID ICFG_CSB_DATA_BWID

// Destination line stride
#define BDMA_CFG_DST_LINE "bdma_cfg_dst_line"
#define BDMA_CFG_DST_LINE_ADDR 0x4020
#define BDMA_CFG_DST_LINE_BWID ICFG_CSB_DATA_BWID

// Number of surfaces to be moved in one operation
#define BDMA_CFG_SURF_REPEAT "bdma_cfg_surf_repeat"
#define BDMA_CFG_SURF_REPEAT_ADDR 0x4024
#define BDMA_CFG_SURF_REPEAT_BWID ICFG_CSB_DATA_BWID

// Source surface stride
#define BDMA_CFG_SRC_SURF "bdma_cfg_src_surf"
#define BDMA_CFG_SRC_SURF_ADDR 0x4028
#define BDMA_CFG_SRC_SURF_BWID ICFG_CSB_DATA_BWID

// Destination surface stride
#define BDMA_CFG_DST_SURF "bdma_cfg_dst_surf"
#define BDMA_CFG_DST_SURF_ADDR 0x402c
#define BDMA_CFG_DST_SURF_BWID ICFG_CSB_DATA_BWID

// This register is not used in NVDLA 1.0
#define BDMA_CFG_OP "bdma_cfg_op"
#define BDMA_CFG_OP_ADDR 0x4030
#define BDMA_CFG_OP_BWID ICFG_CSB_DATA_BWID

// Set it to 1 to kick off operations in group0
#define BDMA_CFG_LAUNCH0 "bdma_cfg_launch0"
#define BDMA_CFG_LAUNCH0_ADDR 0x4034
#define BDMA_CFG_LAUNCH0_BWID ICFG_CSB_DATA_BWID

// Set it to 1 to kick off operations in group1
#define BDMA_CFG_LAUNCH1 "bdma_cfg_launch1"
#define BDMA_CFG_LAUNCH1_ADDR 0x4038
#define BDMA_CFG_LAUNCH1_BWID ICFG_CSB_DATA_BWID

// Enable/Disable of counting stalls
#define BDMA_CFG_STATUS "bdma_cfg_status"
#define BDMA_CFG_STATUS_ADDR 0x403c
#define BDMA_CFG_STATUS_BWID ICFG_CSB_DATA_BWID

// Status register: idle status of bdma, group0 and group1
#define BDMA_STATUS "bdma_status"
#define BDMA_STATUS_ADDR 0x4040
#define BDMA_STATUS_BWID ICFG_CSB_DATA_BWID

// Counting register of group0 read stall
#define BDMA_STAUS_GRP0_READ_STALL "bdma_staus_grp0_read_stall"
#define BDMA_STAUS_GRP0_READ_STALL_ADDR 0x4044
#define BDMA_STAUS_GRP0_READ_STALL_BWID ICFG_CSB_DATA_BWID

// Counting register of group0 write stall
#define BDMA_STATUS_GRP0_WRITE_STALL "bdma_status_grp0_write_stall"
#define BDMA_STATUS_GRP0_WRITE_STALL_ADDR 0x4048
#define BDMA_STATUS_GRP0_WRITE_STALL_BWID ICFG_CSB_DATA_BWID

// Counting register of group1 read stall
#define BDMA_STAUS_GRP1_READ_STALL "bdma_staus_grp1_read_stall"
#define BDMA_STAUS_GRP1_READ_STALL_ADDR 0x404c
#define BDMA_STAUS_GRP1_READ_STALL_BWID ICFG_CSB_DATA_BWID

// Counting register of group1 write stall
#define BDMA_STATUS_GRP1_WRITE_STALL "bdma_status_grp1_write_stall"
#define BDMA_STATUS_GRP1_WRITE_STALL_ADDR 0x4050
#define BDMA_STATUS_GRP1_WRITE_STALL_BWID ICFG_CSB_DATA_BWID

}; // namespace ilang

#endif // STATE_INFO_BDMA_H__
