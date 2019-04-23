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

/// \namespace ilang
namespace ilang {

// Idle status of two register groups
#define CDP_RDMA_S_STATUS_NAME "cdp_rdma_s_status"

// Pointer for CSB master and data path to access groups
#define CDP_RDMA_S_POINTER_NAME "cdp_rdma_s_pointer"

// Set it to 1 to kick off operation for current register group
#define CDP_RDMA_D_OP_ENABLE_NAME "cdp_rdma_d_op_enable"

// Input data cube’s width
#define CDP_RDMA_D_DATA_CUBE_WIDTH_NAME "cdp_rdma_d_data_cube_width"

// Input data cube’s height
#define CDP_RDMA_D_DATA_CUBE_HEIGHT_NAME "cdp_rdma_d_data_cube_height"

// Input data cube’s channel
#define CDP_RDMA_D_DATA_CUBE_CHANNEL_NAME "cdp_rdma_d_data_cube_channel"

// Lower 32bits of input data address
#define CDP_RDMA_D_SRC_BASE_ADDR_LOW_NAME "cdp_rdma_d_src_base_addr_low"

// Higher 32bits of input data address when axi araddr is 64bits
#define CDP_RDMA_D_SRC_BASE_ADDR_HIGH_NAME "cdp_rdma_d_src_base_addr_high"

// Line stride of input cube
#define CDP_RDMA_D_SRC_LINE_STRIDE_NAME "cdp_rdma_d_src_line_stride"

// Surface stride of input cube
#define CDP_RDMA_D_SRC_SURFACE_STRIDE_NAME "cdp_rdma_d_src_surface_stride"

// RAM type of input data cube
#define CDP_RDMA_D_SRC_DMA_CFG_NAME "cdp_rdma_d_src_dma_cfg"

// This register is not used in OpenDLA 1.0
#define CDP_RDMA_D_SRC_COMPRESSION_EN_NAME "cdp_rdma_d_src_compression_en"

// Split number
#define CDP_RDMA_D_OPERATION_MODE_NAME "cdp_rdma_d_operation_mode"

// Input data cube
#define CDP_RDMA_D_DATA_FORMAT_NAME "cdp_rdma_d_data_format"

// Enable/Disable performance counting
#define CDP_RDMA_D_PERF_ENABLE_NAME "cdp_rdma_d_perf_enable"

// Counting stalls of read requests
#define CDP_RDMA_D_PERF_READ_STALL_NAME "cdp_rdma_d_perf_read_stall"

}; // namespace ilang

#endif // STATE_INFO_CDP_RDMA_H__
