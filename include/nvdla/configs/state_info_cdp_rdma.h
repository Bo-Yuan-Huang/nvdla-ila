// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: state_info_cdp_rdma.h

#ifndef STATE_INFO_CDP_RDMA_H__
#define STATE_INFO_CDP_RDMA_H__

// namespace ilang
namespace ilang {

// Idle status of two register groups
#define CDP_RDMA_S_STATUS "cdp_rdma_s_status"
#define CDP_RDMA_S_STATUS_ADDR 0xe000
#define CDP_RDMA_S_STATUS_BWID 32

// Pointer for CSB master and data path to access groups
#define CDP_RDMA_S_POINTER "cdp_rdma_s_pointer"
#define CDP_RDMA_S_POINTER_ADDR 0xe004
#define CDP_RDMA_S_POINTER_BWID 32

// Set it to 1 to kick off operation for current register group
#define CDP_RDMA_D_OP_ENABLE_G0 "cdp_rdma_d_op_enable_g0"
#define CDP_RDMA_D_OP_ENABLE_G1 "cdp_rdma_d_op_enable_g1"
#define CDP_RDMA_D_OP_ENABLE_ADDR 0xe008
#define CDP_RDMA_D_OP_ENABLE_BWID 32

// Input data cube’s width
#define CDP_RDMA_D_DATA_CUBE_WIDTH_G0 "cdp_rdma_d_data_cube_width_g0"
#define CDP_RDMA_D_DATA_CUBE_WIDTH_G1 "cdp_rdma_d_data_cube_width_g1"
#define CDP_RDMA_D_DATA_CUBE_WIDTH_ADDR 0xe00c
#define CDP_RDMA_D_DATA_CUBE_WIDTH_BWID 32

// Input data cube’s height
#define CDP_RDMA_D_DATA_CUBE_HEIGHT_G0 "cdp_rdma_d_data_cube_height_g0"
#define CDP_RDMA_D_DATA_CUBE_HEIGHT_G1 "cdp_rdma_d_data_cube_height_g1"
#define CDP_RDMA_D_DATA_CUBE_HEIGHT_ADDR 0xe010
#define CDP_RDMA_D_DATA_CUBE_HEIGHT_BWID 32

// Input data cube’s channel
#define CDP_RDMA_D_DATA_CUBE_CHANNEL_G0 "cdp_rdma_d_data_cube_channel_g0"
#define CDP_RDMA_D_DATA_CUBE_CHANNEL_G1 "cdp_rdma_d_data_cube_channel_g1"
#define CDP_RDMA_D_DATA_CUBE_CHANNEL_ADDR 0xe014
#define CDP_RDMA_D_DATA_CUBE_CHANNEL_BWID 32

// Lower 32bits of input data address
#define CDP_RDMA_D_SRC_BASE_ADDR_LOW_G0 "cdp_rdma_d_src_base_addr_low_g0"
#define CDP_RDMA_D_SRC_BASE_ADDR_LOW_G1 "cdp_rdma_d_src_base_addr_low_g1"
#define CDP_RDMA_D_SRC_BASE_ADDR_LOW_ADDR 0xe018
#define CDP_RDMA_D_SRC_BASE_ADDR_LOW_BWID 32

// Higher 32bits of input data address when axi araddr is 64bits
#define CDP_RDMA_D_SRC_BASE_ADDR_HIGH_G0 "cdp_rdma_d_src_base_addr_high_g0"
#define CDP_RDMA_D_SRC_BASE_ADDR_HIGH_G1 "cdp_rdma_d_src_base_addr_high_g1"
#define CDP_RDMA_D_SRC_BASE_ADDR_HIGH_ADDR 0xe01c
#define CDP_RDMA_D_SRC_BASE_ADDR_HIGH_BWID 32

// Line stride of input cube
#define CDP_RDMA_D_SRC_LINE_STRIDE_G0 "cdp_rdma_d_src_line_stride_g0"
#define CDP_RDMA_D_SRC_LINE_STRIDE_G1 "cdp_rdma_d_src_line_stride_g1"
#define CDP_RDMA_D_SRC_LINE_STRIDE_ADDR 0xe020
#define CDP_RDMA_D_SRC_LINE_STRIDE_BWID 32

// Surface stride of input cube
#define CDP_RDMA_D_SRC_SURFACE_STRIDE_G0 "cdp_rdma_d_src_surface_stride_g0"
#define CDP_RDMA_D_SRC_SURFACE_STRIDE_G1 "cdp_rdma_d_src_surface_stride_g1"
#define CDP_RDMA_D_SRC_SURFACE_STRIDE_ADDR 0xe024
#define CDP_RDMA_D_SRC_SURFACE_STRIDE_BWID 32

// RAM type of input data cube
#define CDP_RDMA_D_SRC_DMA_CFG_G0 "cdp_rdma_d_src_dma_cfg_g0"
#define CDP_RDMA_D_SRC_DMA_CFG_G1 "cdp_rdma_d_src_dma_cfg_g1"
#define CDP_RDMA_D_SRC_DMA_CFG_ADDR 0xe028
#define CDP_RDMA_D_SRC_DMA_CFG_BWID 32

// This register is not used in OpenDLA 1.0
#define CDP_RDMA_D_SRC_COMPRESSION_EN_G0 "cdp_rdma_d_src_compression_en_g0"
#define CDP_RDMA_D_SRC_COMPRESSION_EN_G1 "cdp_rdma_d_src_compression_en_g1"
#define CDP_RDMA_D_SRC_COMPRESSION_EN_ADDR 0xe02c
#define CDP_RDMA_D_SRC_COMPRESSION_EN_BWID 32

// Split number
#define CDP_RDMA_D_OPERATION_MODE_G0 "cdp_rdma_d_operation_mode_g0"
#define CDP_RDMA_D_OPERATION_MODE_G1 "cdp_rdma_d_operation_mode_g1"
#define CDP_RDMA_D_OPERATION_MODE_ADDR 0xe030
#define CDP_RDMA_D_OPERATION_MODE_BWID 32

// Input data cube
#define CDP_RDMA_D_DATA_FORMAT_G0 "cdp_rdma_d_data_format_g0"
#define CDP_RDMA_D_DATA_FORMAT_G1 "cdp_rdma_d_data_format_g1"
#define CDP_RDMA_D_DATA_FORMAT_ADDR 0xe034
#define CDP_RDMA_D_DATA_FORMAT_BWID 32

// Enable/Disable performance counting
#define CDP_RDMA_D_PERF_ENABLE_G0 "cdp_rdma_d_perf_enable_g0"
#define CDP_RDMA_D_PERF_ENABLE_G1 "cdp_rdma_d_perf_enable_g1"
#define CDP_RDMA_D_PERF_ENABLE_ADDR 0xe038
#define CDP_RDMA_D_PERF_ENABLE_BWID 32

// Counting stalls of read requests
#define CDP_RDMA_D_PERF_READ_STALL_G0 "cdp_rdma_d_perf_read_stall_g0"
#define CDP_RDMA_D_PERF_READ_STALL_G1 "cdp_rdma_d_perf_read_stall_g1"
#define CDP_RDMA_D_PERF_READ_STALL_ADDR 0xe03c
#define CDP_RDMA_D_PERF_READ_STALL_BWID 32

}; // namespace ilang

#endif // STATE_INFO_CDP_RDMA_H__
