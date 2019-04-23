// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: state_info_sdp_rdma.h

#ifndef STATE_INFO_SDP_RDMA_H__
#define STATE_INFO_SDP_RDMA_H__

/// \namespace ilang
namespace ilang {

// Idle status of two register groups
#define SDP_RDMA_S_STATUS_NAME "sdp_rdma_s_status"

// Pointer for CSB master and data path to access groups
#define SDP_RDMA_S_POINTER_NAME "sdp_rdma_s_pointer"

// Set it to 1 to kick off operation for current register group
#define SDP_RDMA_D_OP_ENABLE_NAME "sdp_rdma_d_op_enable"

// Input cube’s width
#define SDP_RDMA_D_DATA_CUBE_WIDTH_NAME "sdp_rdma_d_data_cube_width"

// Input cube’s height
#define SDP_RDMA_D_DATA_CUBE_HEIGHT_NAME "sdp_rdma_d_data_cube_height"

// Input cube’s channel
#define SDP_RDMA_D_DATA_CUBE_CHANNEL_NAME "sdp_rdma_d_data_cube_channel"

// Lower 32bits of input data address
#define SDP_RDMA_D_SRC_BASE_ADDR_LOW_NAME "sdp_rdma_d_src_base_addr_low"

// Higher 32bits of input data address when axi araddr is 64bits
#define SDP_RDMA_D_SRC_BASE_ADDR_HIGH_NAME "sdp_rdma_d_src_base_addr_high"

// Line stride of input cube
#define SDP_RDMA_D_SRC_LINE_STRIDE_NAME "sdp_rdma_d_src_line_stride"

// Surface stride of input cube
#define SDP_RDMA_D_SRC_SURFACE_STRIDE_NAME "sdp_rdma_d_src_surface_stride"

// Configuration of BRDMA: enable/disable, data size, Ram type, etc.
#define SDP_RDMA_D_BRDMA_CFG_NAME "sdp_rdma_d_brdma_cfg"

// Lower 32bits address of the bias data cube
#define SDP_RDMA_D_BS_BASE_ADDR_LOW_NAME "sdp_rdma_d_bs_base_addr_low"

// Higher 32bits address of the bias data cube when axi araddr is 64bits
#define SDP_RDMA_D_BS_BASE_ADDR_HIGH_NAME "sdp_rdma_d_bs_base_addr_high"

// Line stride of bias data cube
#define SDP_RDMA_D_BS_LINE_STRIDE_NAME "sdp_rdma_d_bs_line_stride"

// Surface stride of bias data cube
#define SDP_RDMA_D_BS_SURFACE_STRIDE_NAME "sdp_rdma_d_bs_surface_stride"

// Stride of bias data cube in batch mode
#define SDP_RDMA_D_BS_BATCH_STRIDE_NAME "sdp_rdma_d_bs_batch_stride"

// Configuration of NRDMA: enable/disable, data size, Ram type, etc.
#define SDP_RDMA_D_NRDMA_CFG_NAME "sdp_rdma_d_nrdma_cfg"

// Lower 32bits address of the bias data cube
#define SDP_RDMA_D_BN_BASE_ADDR_LOW_NAME "sdp_rdma_d_bn_base_addr_low"

// Higher 32bits address of the bias data cube when axi araddr is 64bits
#define SDP_RDMA_D_BN_BASE_ADDR_HIGH_NAME "sdp_rdma_d_bn_base_addr_high"

// Line stride of bias data cube
#define SDP_RDMA_D_BN_LINE_STRIDE_NAME "sdp_rdma_d_bn_line_stride"

// Surface stride of bias data cube
#define SDP_RDMA_D_BN_SURFACE_STRIDE_NAME "sdp_rdma_d_bn_surface_stride"

// Stride of bias data cube in batch mode
#define SDP_RDMA_D_BN_BATCH_STRIDE_NAME "sdp_rdma_d_bn_batch_stride"

// Configuration of ERDMA: enable/disable, data size, Ram type, etc.
#define SDP_RDMA_D_ERDMA_CFG_NAME "sdp_rdma_d_erdma_cfg"

// Lower 32bits address of the bias data cube
#define SDP_RDMA_D_EW_BASE_ADDR_LOW_NAME "sdp_rdma_d_ew_base_addr_low"

// Higher 32bits address of the bias data cube when axi araddr is 64bits
#define SDP_RDMA_D_EW_BASE_ADDR_HIGH_NAME "sdp_rdma_d_ew_base_addr_high"

// Line stride of bias data cube
#define SDP_RDMA_D_EW_LINE_STRIDE_NAME "sdp_rdma_d_ew_line_stride"

// Surface stride of bias data cube
#define SDP_RDMA_D_EW_SURFACE_STRIDE_NAME "sdp_rdma_d_ew_surface_stride"

// Stride of bias data cube in batch mode
#define SDP_RDMA_D_EW_BATCH_STRIDE_NAME "sdp_rdma_d_ew_batch_stride"

// Operation configuration: flying mode, output destination, Direct or Winograd
// mode, flush NaN to zero, batch number.
#define SDP_RDMA_D_FEATURE_MODE_CFG_NAME "sdp_rdma_d_feature_mode_cfg"

// RAM type of input data cube
#define SDP_RDMA_D_SRC_DMA_CFG_NAME "sdp_rdma_d_src_dma_cfg"

// Input NaN element number
#define SDP_RDMA_D_STATUS_NAN_INPUT_NUM_NAME "sdp_rdma_d_status_nan_input_num"

// Input Infinity element number
#define SDP_RDMA_D_STATUS_INF_INPUT_NUM_NAME "sdp_rdma_d_status_inf_input_num"

// Enable/Disable performance counting
#define SDP_RDMA_D_PERF_ENABLE_NAME "sdp_rdma_d_perf_enable"

// Count stall cycles of M read DMA for one layer
#define SDP_RDMA_D_PERF_MRDMA_READ_STALL_NAME "sdp_rdma_d_perf_mrdma_read_stall"

// Count stall cycles of B read DMA for one layer
#define SDP_RDMA_D_PERF_BRDMA_READ_STALL_NAME "sdp_rdma_d_perf_brdma_read_stall"

// Count stall cycles of N read DMA for one layer
#define SDP_RDMA_D_PERF_NRDMA_READ_STALL_NAME "sdp_rdma_d_perf_nrdma_read_stall"

// Count stall cycles of E read DMA for one layer
#define SDP_RDMA_D_PERF_ERDMA_READ_STALL_NAME "sdp_rdma_d_perf_erdma_read_stall"

}; // namespace ilang

#endif // STATE_INFO_SDP_RDMA_H__
