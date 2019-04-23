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
#define SDP_RDMA_S_STATUS "sdp_rdma_s_status"
#define SDP_RDMA_S_STATUS_ADDR 0xa000
#define SDP_RDMA_S_STATUS_BWID 32

// Pointer for CSB master and data path to access groups
#define SDP_RDMA_S_POINTER "sdp_rdma_s_pointer"
#define SDP_RDMA_S_POINTER_ADDR 0xa004
#define SDP_RDMA_S_POINTER_BWID 32

// Set it to 1 to kick off operation for current register group
#define SDP_RDMA_D_OP_ENABLE "sdp_rdma_d_op_enable"
#define SDP_RDMA_D_OP_ENABLE_ADDR 0xa008
#define SDP_RDMA_D_OP_ENABLE_BWID 32

// Input cube’s width
#define SDP_RDMA_D_DATA_CUBE_WIDTH "sdp_rdma_d_data_cube_width"
#define SDP_RDMA_D_DATA_CUBE_WIDTH_ADDR 0xa00c
#define SDP_RDMA_D_DATA_CUBE_WIDTH_BWID 32

// Input cube’s height
#define SDP_RDMA_D_DATA_CUBE_HEIGHT "sdp_rdma_d_data_cube_height"
#define SDP_RDMA_D_DATA_CUBE_HEIGHT_ADDR 0xa010
#define SDP_RDMA_D_DATA_CUBE_HEIGHT_BWID 32

// Input cube’s channel
#define SDP_RDMA_D_DATA_CUBE_CHANNEL "sdp_rdma_d_data_cube_channel"
#define SDP_RDMA_D_DATA_CUBE_CHANNEL_ADDR 0xa014
#define SDP_RDMA_D_DATA_CUBE_CHANNEL_BWID 32

// Lower 32bits of input data address
#define SDP_RDMA_D_SRC_BASE_ADDR_LOW "sdp_rdma_d_src_base_addr_low"
#define SDP_RDMA_D_SRC_BASE_ADDR_LOW_ADDR 0xa018
#define SDP_RDMA_D_SRC_BASE_ADDR_LOW_BWID 32

// Higher 32bits of input data address when axi araddr is 64bits
#define SDP_RDMA_D_SRC_BASE_ADDR_HIGH "sdp_rdma_d_src_base_addr_high"
#define SDP_RDMA_D_SRC_BASE_ADDR_HIGH_ADDR 0xa01c
#define SDP_RDMA_D_SRC_BASE_ADDR_HIGH_BWID 32

// Line stride of input cube
#define SDP_RDMA_D_SRC_LINE_STRIDE "sdp_rdma_d_src_line_stride"
#define SDP_RDMA_D_SRC_LINE_STRIDE_ADDR 0xa020
#define SDP_RDMA_D_SRC_LINE_STRIDE_BWID 32

// Surface stride of input cube
#define SDP_RDMA_D_SRC_SURFACE_STRIDE "sdp_rdma_d_src_surface_stride"
#define SDP_RDMA_D_SRC_SURFACE_STRIDE_ADDR 0xa024
#define SDP_RDMA_D_SRC_SURFACE_STRIDE_BWID 32

// Configuration of BRDMA: enable/disable, data size, Ram type, etc.
#define SDP_RDMA_D_BRDMA_CFG "sdp_rdma_d_brdma_cfg"
#define SDP_RDMA_D_BRDMA_CFG_ADDR 0xa028
#define SDP_RDMA_D_BRDMA_CFG_BWID 32

// Lower 32bits address of the bias data cube
#define SDP_RDMA_D_BS_BASE_ADDR_LOW "sdp_rdma_d_bs_base_addr_low"
#define SDP_RDMA_D_BS_BASE_ADDR_LOW_ADDR 0xa02c
#define SDP_RDMA_D_BS_BASE_ADDR_LOW_BWID 32

// Higher 32bits address of the bias data cube when axi araddr is 64bits
#define SDP_RDMA_D_BS_BASE_ADDR_HIGH "sdp_rdma_d_bs_base_addr_high"
#define SDP_RDMA_D_BS_BASE_ADDR_HIGH_ADDR 0xa030
#define SDP_RDMA_D_BS_BASE_ADDR_HIGH_BWID 32

// Line stride of bias data cube
#define SDP_RDMA_D_BS_LINE_STRIDE "sdp_rdma_d_bs_line_stride"
#define SDP_RDMA_D_BS_LINE_STRIDE_ADDR 0xa034
#define SDP_RDMA_D_BS_LINE_STRIDE_BWID 32

// Surface stride of bias data cube
#define SDP_RDMA_D_BS_SURFACE_STRIDE "sdp_rdma_d_bs_surface_stride"
#define SDP_RDMA_D_BS_SURFACE_STRIDE_ADDR 0xa038
#define SDP_RDMA_D_BS_SURFACE_STRIDE_BWID 32

// Stride of bias data cube in batch mode
#define SDP_RDMA_D_BS_BATCH_STRIDE "sdp_rdma_d_bs_batch_stride"
#define SDP_RDMA_D_BS_BATCH_STRIDE_ADDR 0xa03c
#define SDP_RDMA_D_BS_BATCH_STRIDE_BWID 32

// Configuration of NRDMA: enable/disable, data size, Ram type, etc.
#define SDP_RDMA_D_NRDMA_CFG "sdp_rdma_d_nrdma_cfg"
#define SDP_RDMA_D_NRDMA_CFG_ADDR 0xa040
#define SDP_RDMA_D_NRDMA_CFG_BWID 32

// Lower 32bits address of the bias data cube
#define SDP_RDMA_D_BN_BASE_ADDR_LOW "sdp_rdma_d_bn_base_addr_low"
#define SDP_RDMA_D_BN_BASE_ADDR_LOW_ADDR 0xa044
#define SDP_RDMA_D_BN_BASE_ADDR_LOW_BWID 32

// Higher 32bits address of the bias data cube when axi araddr is 64bits
#define SDP_RDMA_D_BN_BASE_ADDR_HIGH "sdp_rdma_d_bn_base_addr_high"
#define SDP_RDMA_D_BN_BASE_ADDR_HIGH_ADDR 0xa048
#define SDP_RDMA_D_BN_BASE_ADDR_HIGH_BWID 32

// Line stride of bias data cube
#define SDP_RDMA_D_BN_LINE_STRIDE "sdp_rdma_d_bn_line_stride"
#define SDP_RDMA_D_BN_LINE_STRIDE_ADDR 0xa04c
#define SDP_RDMA_D_BN_LINE_STRIDE_BWID 32

// Surface stride of bias data cube
#define SDP_RDMA_D_BN_SURFACE_STRIDE "sdp_rdma_d_bn_surface_stride"
#define SDP_RDMA_D_BN_SURFACE_STRIDE_ADDR 0xa050
#define SDP_RDMA_D_BN_SURFACE_STRIDE_BWID 32

// Stride of bias data cube in batch mode
#define SDP_RDMA_D_BN_BATCH_STRIDE "sdp_rdma_d_bn_batch_stride"
#define SDP_RDMA_D_BN_BATCH_STRIDE_ADDR 0xa054
#define SDP_RDMA_D_BN_BATCH_STRIDE_BWID 32

// Configuration of ERDMA: enable/disable, data size, Ram type, etc.
#define SDP_RDMA_D_ERDMA_CFG "sdp_rdma_d_erdma_cfg"
#define SDP_RDMA_D_ERDMA_CFG_ADDR 0xa058
#define SDP_RDMA_D_ERDMA_CFG_BWID 32

// Lower 32bits address of the bias data cube
#define SDP_RDMA_D_EW_BASE_ADDR_LOW "sdp_rdma_d_ew_base_addr_low"
#define SDP_RDMA_D_EW_BASE_ADDR_LOW_ADDR 0xa05c
#define SDP_RDMA_D_EW_BASE_ADDR_LOW_BWID 32

// Higher 32bits address of the bias data cube when axi araddr is 64bits
#define SDP_RDMA_D_EW_BASE_ADDR_HIGH "sdp_rdma_d_ew_base_addr_high"
#define SDP_RDMA_D_EW_BASE_ADDR_HIGH_ADDR 0xa060
#define SDP_RDMA_D_EW_BASE_ADDR_HIGH_BWID 32

// Line stride of bias data cube
#define SDP_RDMA_D_EW_LINE_STRIDE "sdp_rdma_d_ew_line_stride"
#define SDP_RDMA_D_EW_LINE_STRIDE_ADDR 0xa064
#define SDP_RDMA_D_EW_LINE_STRIDE_BWID 32

// Surface stride of bias data cube
#define SDP_RDMA_D_EW_SURFACE_STRIDE "sdp_rdma_d_ew_surface_stride"
#define SDP_RDMA_D_EW_SURFACE_STRIDE_ADDR 0xa068
#define SDP_RDMA_D_EW_SURFACE_STRIDE_BWID 32

// Stride of bias data cube in batch mode
#define SDP_RDMA_D_EW_BATCH_STRIDE "sdp_rdma_d_ew_batch_stride"
#define SDP_RDMA_D_EW_BATCH_STRIDE_ADDR 0xa06c
#define SDP_RDMA_D_EW_BATCH_STRIDE_BWID 32

// Operation configuration: flying mode, output destination, Direct or Winograd
// mode, flush NaN to zero, batch number.
#define SDP_RDMA_D_FEATURE_MODE_CFG "sdp_rdma_d_feature_mode_cfg"
#define SDP_RDMA_D_FEATURE_MODE_CFG_ADDR 0xa070
#define SDP_RDMA_D_FEATURE_MODE_CFG_BWID 32

// RAM type of input data cube
#define SDP_RDMA_D_SRC_DMA_CFG "sdp_rdma_d_src_dma_cfg"
#define SDP_RDMA_D_SRC_DMA_CFG_ADDR 0xa074
#define SDP_RDMA_D_SRC_DMA_CFG_BWID 32

// Input NaN element number
#define SDP_RDMA_D_STATUS_NAN_INPUT_NUM "sdp_rdma_d_status_nan_input_num"
#define SDP_RDMA_D_STATUS_NAN_INPUT_NUM_ADDR 0xa078
#define SDP_RDMA_D_STATUS_NAN_INPUT_NUM_BWID 32

// Input Infinity element number
#define SDP_RDMA_D_STATUS_INF_INPUT_NUM "sdp_rdma_d_status_inf_input_num"
#define SDP_RDMA_D_STATUS_INF_INPUT_NUM_ADDR 0xa07c
#define SDP_RDMA_D_STATUS_INF_INPUT_NUM_BWID 32

// Enable/Disable performance counting
#define SDP_RDMA_D_PERF_ENABLE "sdp_rdma_d_perf_enable"
#define SDP_RDMA_D_PERF_ENABLE_ADDR 0xa080
#define SDP_RDMA_D_PERF_ENABLE_BWID 32

// Count stall cycles of M read DMA for one layer
#define SDP_RDMA_D_PERF_MRDMA_READ_STALL "sdp_rdma_d_perf_mrdma_read_stall"
#define SDP_RDMA_D_PERF_MRDMA_READ_STALL_ADDR 0xa084
#define SDP_RDMA_D_PERF_MRDMA_READ_STALL_BWID 32

// Count stall cycles of B read DMA for one layer
#define SDP_RDMA_D_PERF_BRDMA_READ_STALL "sdp_rdma_d_perf_brdma_read_stall"
#define SDP_RDMA_D_PERF_BRDMA_READ_STALL_ADDR 0xa088
#define SDP_RDMA_D_PERF_BRDMA_READ_STALL_BWID 32

// Count stall cycles of N read DMA for one layer
#define SDP_RDMA_D_PERF_NRDMA_READ_STALL "sdp_rdma_d_perf_nrdma_read_stall"
#define SDP_RDMA_D_PERF_NRDMA_READ_STALL_ADDR 0xa08c
#define SDP_RDMA_D_PERF_NRDMA_READ_STALL_BWID 32

// Count stall cycles of E read DMA for one layer
#define SDP_RDMA_D_PERF_ERDMA_READ_STALL "sdp_rdma_d_perf_erdma_read_stall"
#define SDP_RDMA_D_PERF_ERDMA_READ_STALL_ADDR 0xa090
#define SDP_RDMA_D_PERF_ERDMA_READ_STALL_BWID 32

}; // namespace ilang

#endif // STATE_INFO_SDP_RDMA_H__
