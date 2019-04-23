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

/// \namespace ilang
namespace ilang {

// Lower 32bits of source address
#define BDMA_CFG_SRC_ADDR_LOW_NAME "bdma_cfg_src_addr_low"
#define BDMA_CFG_SRC_ADDR_LOW_BWID 32
// Higher 32bits of source address when axi araddr is 64bits
#define BDMA_CFG_SRC_ADDR_HIGH_NAME "bdma_cfg_src_addr_high"
#define BDMA_CFG_SRC_ADDR_HIGH_BWID 32
// Lower 32bits of dest address
#define BDMA_CFG_DST_ADDR_LOW_NAME "bdma_cfg_dst_addr_low"
#define BDMA_CFG_DST_ADDR_LOW_BWID 32
// Higher 32bits of dest address when axi awaddr is 64bits
#define BDMA_CFG_DST_ADDR_HIGH_NAME "bdma_cfg_dst_addr_high"
#define BDMA_CFG_DST_ADDR_HIGH_BWID 32
// Size of one line
#define BDMA_CFG_LINE_NAME "bdma_cfg_line"
#define BDMA_CFG_LINE_BWID 32
// Ram type of source and destination
#define BDMA_CFG_CMD_NAME "bdma_cfg_cmd"
#define BDMA_CFG_CMD_BWID 32
// Number of lines to be moved in one surface
#define BDMA_CFG_LINE_REPEAT_NAME "bdma_cfg_line_repeat"
#define BDMA_CFG_LINE_REPEAT_BWID 32
// Source line stride
#define BDMA_CFG_SRC_LINE_NAME "bdma_cfg_src_line"
#define BDMA_CFG_SRC_LINE_BWID 32
// Destination line stride
#define BDMA_CFG_DST_LINE_NAME "bdma_cfg_dst_line"
#define BDMA_CFG_DST_LINE_BWID 32
// Number of surfaces to be moved in one operation
#define BDMA_CFG_SURF_REPEAT_NAME "bdma_cfg_surf_repeat"
#define BDMA_CFG_SURF_REPEAT_BWID 32
// Source surface stride
#define BDMA_CFG_SRC_SURF_NAME "bdma_cfg_src_surf"
#define BDMA_CFG_SRC_SURF_BWID 32
// Destination surface stride
#define BDMA_CFG_DST_SURF_NAME "bdma_cfg_dst_surf"
#define BDMA_CFG_DST_SURF_BWID 32
// This register is not used in NVDLA 1.0
#define BDMA_CFG_OP_NAME "bdma_cfg_op"
#define BDMA_CFG_OP_BWID 32
// Set it to 1 to kick off operations in group0
#define BDMA_CFG_LAUNCH0_NAME "bdma_cfg_launch0"
#define BDMA_CFG_LAUNCH0_BWID 32
// Set it to 1 to kick off operations in group1
#define BDMA_CFG_LAUNCH1_NAME "bdma_cfg_launch1"
#define BDMA_CFG_LAUNCH1_BWID 32
// Enable/Disable of counting stalls
#define BDMA_CFG_STATUS_NAME "bdma_cfg_status"
#define BDMA_CFG_STATUS_BWID 32
// Status register: idle status of bdma, group0 and group1
#define BDMA_STATUS_NAME "bdma_status"
#define BDMA_STATUS_BWID 32
// Counting register of group0 read stall
#define BDMA_STAUS_GRP0_READ_STALL_NAME "bdma_staus_grp0_read_stall"
#define BDMA_STAUS_GRP0_READ_STALL_BWID 32
// Counting register of group0 write stall
#define BDMA_STATUS_GRP0_WRITE_STALL_NAME "bdma_status_grp0_write_stall"
#define BDMA_STATUS_GRP0_WRITE_STALL_BWID 32
// Counting register of group1 read stall
#define BDMA_STAUS_GRP1_READ_STALL_NAME "bdma_staus_grp1_read_stall"
#define BDMA_STAUS_GRP1_READ_STALL_BWID 32
// Counting register of group1 write stall
#define BDMA_STATUS_GRP1_WRITE_STALL_NAME "bdma_status_grp1_write_stall"
#define BDMA_STATUS_GRP1_WRITE_STALL_BWID 32

}; // namespace ilang

#endif // STATE_INFO_BDMA_H__
