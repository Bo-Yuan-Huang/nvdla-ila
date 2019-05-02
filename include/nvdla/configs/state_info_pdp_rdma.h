// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: state_info_pdp_rdma.h

#ifndef STATE_INFO_PDP_RDMA_H__
#define STATE_INFO_PDP_RDMA_H__

// namespace ilang
namespace ilang {

// Idle status of two register groups
#define PDP_RDMA_S_STATUS "pdp_rdma_s_status"
#define PDP_RDMA_S_STATUS_ADDR 0xc000
#define PDP_RDMA_S_STATUS_BWID 32

// Pointer for CSB master and data path to access groups
#define PDP_RDMA_S_POINTER "pdp_rdma_s_pointer"
#define PDP_RDMA_S_POINTER_ADDR 0xc004
#define PDP_RDMA_S_POINTER_BWID 32

// Set it to 1 to kick off operation for current register group
#define PDP_RDMA_D_OP_ENABLE_G0 "pdp_rdma_d_op_enable_g0"
#define PDP_RDMA_D_OP_ENABLE_G1 "pdp_rdma_d_op_enable_g1"
#define PDP_RDMA_D_OP_ENABLE_ADDR 0xc008
#define PDP_RDMA_D_OP_ENABLE_BWID 32

// Input data cube’s width
#define PDP_RDMA_D_DATA_CUBE_IN_WIDTH_G0 "pdp_rdma_d_data_cube_in_width_g0"
#define PDP_RDMA_D_DATA_CUBE_IN_WIDTH_G1 "pdp_rdma_d_data_cube_in_width_g1"
#define PDP_RDMA_D_DATA_CUBE_IN_WIDTH_ADDR 0xc00c
#define PDP_RDMA_D_DATA_CUBE_IN_WIDTH_BWID 32

// Input data cube’s height
#define PDP_RDMA_D_DATA_CUBE_IN_HEIGHT_G0 "pdp_rdma_d_data_cube_in_height_g0"
#define PDP_RDMA_D_DATA_CUBE_IN_HEIGHT_G1 "pdp_rdma_d_data_cube_in_height_g1"
#define PDP_RDMA_D_DATA_CUBE_IN_HEIGHT_ADDR 0xc010
#define PDP_RDMA_D_DATA_CUBE_IN_HEIGHT_BWID 32

// Input data cube’s channel
#define PDP_RDMA_D_DATA_CUBE_IN_CHANNEL_G0 "pdp_rdma_d_data_cube_in_channel_g0"
#define PDP_RDMA_D_DATA_CUBE_IN_CHANNEL_G1 "pdp_rdma_d_data_cube_in_channel_g1"
#define PDP_RDMA_D_DATA_CUBE_IN_CHANNEL_ADDR 0xc014
#define PDP_RDMA_D_DATA_CUBE_IN_CHANNEL_BWID 32

// Indicate source is SDP or external memory
#define PDP_RDMA_D_FLYING_MODE_G0 "pdp_rdma_d_flying_mode_g0"
#define PDP_RDMA_D_FLYING_MODE_G1 "pdp_rdma_d_flying_mode_g1"
#define PDP_RDMA_D_FLYING_MODE_ADDR 0xc018
#define PDP_RDMA_D_FLYING_MODE_BWID 32

// Lower 32bits of input data address
#define PDP_RDMA_D_SRC_BASE_ADDR_LOW_G0 "pdp_rdma_d_src_base_addr_low_g0"
#define PDP_RDMA_D_SRC_BASE_ADDR_LOW_G1 "pdp_rdma_d_src_base_addr_low_g1"
#define PDP_RDMA_D_SRC_BASE_ADDR_LOW_ADDR 0xc01c
#define PDP_RDMA_D_SRC_BASE_ADDR_LOW_BWID 32

// Higher 32bits of input data address when axi araddr is 64bits
#define PDP_RDMA_D_SRC_BASE_ADDR_HIGH_G0 "pdp_rdma_d_src_base_addr_high_g0"
#define PDP_RDMA_D_SRC_BASE_ADDR_HIGH_G1 "pdp_rdma_d_src_base_addr_high_g1"
#define PDP_RDMA_D_SRC_BASE_ADDR_HIGH_ADDR 0xc020
#define PDP_RDMA_D_SRC_BASE_ADDR_HIGH_BWID 32

// Line stride of input cube
#define PDP_RDMA_D_SRC_LINE_STRIDE_G0 "pdp_rdma_d_src_line_stride_g0"
#define PDP_RDMA_D_SRC_LINE_STRIDE_G1 "pdp_rdma_d_src_line_stride_g1"
#define PDP_RDMA_D_SRC_LINE_STRIDE_ADDR 0xc024
#define PDP_RDMA_D_SRC_LINE_STRIDE_BWID 32

// Surface stride of input cube
#define PDP_RDMA_D_SRC_SURFACE_STRIDE_G0 "pdp_rdma_d_src_surface_stride_g0"
#define PDP_RDMA_D_SRC_SURFACE_STRIDE_G1 "pdp_rdma_d_src_surface_stride_g1"
#define PDP_RDMA_D_SRC_SURFACE_STRIDE_ADDR 0xc028
#define PDP_RDMA_D_SRC_SURFACE_STRIDE_BWID 32

// RAM type of input data cube
#define PDP_RDMA_D_SRC_RAM_CFG_G0 "pdp_rdma_d_src_ram_cfg_g0"
#define PDP_RDMA_D_SRC_RAM_CFG_G1 "pdp_rdma_d_src_ram_cfg_g1"
#define PDP_RDMA_D_SRC_RAM_CFG_ADDR 0xc02c
#define PDP_RDMA_D_SRC_RAM_CFG_BWID 32

// Input data cube
#define PDP_RDMA_D_DATA_FORMAT_G0 "pdp_rdma_d_data_format_g0"
#define PDP_RDMA_D_DATA_FORMAT_G1 "pdp_rdma_d_data_format_g1"
#define PDP_RDMA_D_DATA_FORMAT_ADDR 0xc030
#define PDP_RDMA_D_DATA_FORMAT_BWID 32

// Split number
#define PDP_RDMA_D_OPERATION_MODE_CFG_G0 "pdp_rdma_d_operation_mode_cfg_g0"
#define PDP_RDMA_D_OPERATION_MODE_CFG_G1 "pdp_rdma_d_operation_mode_cfg_g1"
#define PDP_RDMA_D_OPERATION_MODE_CFG_ADDR 0xc034
#define PDP_RDMA_D_OPERATION_MODE_CFG_BWID 32

// Kernel width and kernel stride
#define PDP_RDMA_D_POOLING_KERNEL_CFG_G0 "pdp_rdma_d_pooling_kernel_cfg_g0"
#define PDP_RDMA_D_POOLING_KERNEL_CFG_G1 "pdp_rdma_d_pooling_kernel_cfg_g1"
#define PDP_RDMA_D_POOLING_KERNEL_CFG_ADDR 0xc038
#define PDP_RDMA_D_POOLING_KERNEL_CFG_BWID 32

// Padding width
#define PDP_RDMA_D_POOLING_PADDING_CFG_G0 "pdp_rdma_d_pooling_padding_cfg_g0"
#define PDP_RDMA_D_POOLING_PADDING_CFG_G1 "pdp_rdma_d_pooling_padding_cfg_g1"
#define PDP_RDMA_D_POOLING_PADDING_CFG_ADDR 0xc03c
#define PDP_RDMA_D_POOLING_PADDING_CFG_BWID 32

// Partial width for first, last and middle partitions
#define PDP_RDMA_D_PARTIAL_WIDTH_IN_G0 "pdp_rdma_d_partial_width_in_g0"
#define PDP_RDMA_D_PARTIAL_WIDTH_IN_G1 "pdp_rdma_d_partial_width_in_g1"
#define PDP_RDMA_D_PARTIAL_WIDTH_IN_ADDR 0xc040
#define PDP_RDMA_D_PARTIAL_WIDTH_IN_BWID 32

// Enable/Disable performance counting
#define PDP_RDMA_D_PERF_ENABLE_G0 "pdp_rdma_d_perf_enable_g0"
#define PDP_RDMA_D_PERF_ENABLE_G1 "pdp_rdma_d_perf_enable_g1"
#define PDP_RDMA_D_PERF_ENABLE_ADDR 0xc044
#define PDP_RDMA_D_PERF_ENABLE_BWID 32

// Element number that for both LUT underflow.
#define PDP_RDMA_D_PERF_READ_STALL_G0 "pdp_rdma_d_perf_read_stall_g0"
#define PDP_RDMA_D_PERF_READ_STALL_G1 "pdp_rdma_d_perf_read_stall_g1"
#define PDP_RDMA_D_PERF_READ_STALL_ADDR 0xc048
#define PDP_RDMA_D_PERF_READ_STALL_BWID 32

}; // namespace ilang

#endif // STATE_INFO_PDP_RDMA_H__
