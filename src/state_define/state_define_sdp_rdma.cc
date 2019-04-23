// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: state_define_sdp_rdma.cc

#include <ilang/ilang++.h>
#include <nvdla/configs/state_info.h>
#include <nvdla/utils.h>

// namespace ilang
namespace ilang {

void StateDefine_sdp_rdma(Ila& m) {
  // Idle status of two register groups
  NewState(m, SDP_RDMA_S_STATUS, SDP_RDMA_S_STATUS_BWID);

  // Pointer for CSB master and data path to access groups
  NewState(m, SDP_RDMA_S_POINTER, SDP_RDMA_S_POINTER_BWID);

  // Set it to 1 to kick off operation for current register group
  NewState(m, SDP_RDMA_D_OP_ENABLE, SDP_RDMA_D_OP_ENABLE_BWID);

  // Input cube’s width
  NewState(m, SDP_RDMA_D_DATA_CUBE_WIDTH, SDP_RDMA_D_DATA_CUBE_WIDTH_BWID);

  // Input cube’s height
  NewState(m, SDP_RDMA_D_DATA_CUBE_HEIGHT, SDP_RDMA_D_DATA_CUBE_HEIGHT_BWID);

  // Input cube’s channel
  NewState(m, SDP_RDMA_D_DATA_CUBE_CHANNEL, SDP_RDMA_D_DATA_CUBE_CHANNEL_BWID);

  // Lower 32bits of input data address
  NewState(m, SDP_RDMA_D_SRC_BASE_ADDR_LOW, SDP_RDMA_D_SRC_BASE_ADDR_LOW_BWID);

  // Higher 32bits of input data address when axi araddr is 64bits
  NewState(m, SDP_RDMA_D_SRC_BASE_ADDR_HIGH,
           SDP_RDMA_D_SRC_BASE_ADDR_HIGH_BWID);

  // Line stride of input cube
  NewState(m, SDP_RDMA_D_SRC_LINE_STRIDE, SDP_RDMA_D_SRC_LINE_STRIDE_BWID);

  // Surface stride of input cube
  NewState(m, SDP_RDMA_D_SRC_SURFACE_STRIDE,
           SDP_RDMA_D_SRC_SURFACE_STRIDE_BWID);

  // Configuration of BRDMA: enable/disable, data size, Ram type, etc.
  NewState(m, SDP_RDMA_D_BRDMA_CFG, SDP_RDMA_D_BRDMA_CFG_BWID);

  // Lower 32bits address of the bias data cube
  NewState(m, SDP_RDMA_D_BS_BASE_ADDR_LOW, SDP_RDMA_D_BS_BASE_ADDR_LOW_BWID);

  // Higher 32bits address of the bias data cube when axi araddr is 64bits
  NewState(m, SDP_RDMA_D_BS_BASE_ADDR_HIGH, SDP_RDMA_D_BS_BASE_ADDR_HIGH_BWID);

  // Line stride of bias data cube
  NewState(m, SDP_RDMA_D_BS_LINE_STRIDE, SDP_RDMA_D_BS_LINE_STRIDE_BWID);

  // Surface stride of bias data cube
  NewState(m, SDP_RDMA_D_BS_SURFACE_STRIDE, SDP_RDMA_D_BS_SURFACE_STRIDE_BWID);

  // Stride of bias data cube in batch mode
  NewState(m, SDP_RDMA_D_BS_BATCH_STRIDE, SDP_RDMA_D_BS_BATCH_STRIDE_BWID);

  // Configuration of NRDMA: enable/disable, data size, Ram type, etc.
  NewState(m, SDP_RDMA_D_NRDMA_CFG, SDP_RDMA_D_NRDMA_CFG_BWID);

  // Lower 32bits address of the bias data cube
  NewState(m, SDP_RDMA_D_BN_BASE_ADDR_LOW, SDP_RDMA_D_BN_BASE_ADDR_LOW_BWID);

  // Higher 32bits address of the bias data cube when axi araddr is 64bits
  NewState(m, SDP_RDMA_D_BN_BASE_ADDR_HIGH, SDP_RDMA_D_BN_BASE_ADDR_HIGH_BWID);

  // Line stride of bias data cube
  NewState(m, SDP_RDMA_D_BN_LINE_STRIDE, SDP_RDMA_D_BN_LINE_STRIDE_BWID);

  // Surface stride of bias data cube
  NewState(m, SDP_RDMA_D_BN_SURFACE_STRIDE, SDP_RDMA_D_BN_SURFACE_STRIDE_BWID);

  // Stride of bias data cube in batch mode
  NewState(m, SDP_RDMA_D_BN_BATCH_STRIDE, SDP_RDMA_D_BN_BATCH_STRIDE_BWID);

  // Configuration of ERDMA: enable/disable, data size, Ram type, etc.
  NewState(m, SDP_RDMA_D_ERDMA_CFG, SDP_RDMA_D_ERDMA_CFG_BWID);

  // Lower 32bits address of the bias data cube
  NewState(m, SDP_RDMA_D_EW_BASE_ADDR_LOW, SDP_RDMA_D_EW_BASE_ADDR_LOW_BWID);

  // Higher 32bits address of the bias data cube when axi araddr is 64bits
  NewState(m, SDP_RDMA_D_EW_BASE_ADDR_HIGH, SDP_RDMA_D_EW_BASE_ADDR_HIGH_BWID);

  // Line stride of bias data cube
  NewState(m, SDP_RDMA_D_EW_LINE_STRIDE, SDP_RDMA_D_EW_LINE_STRIDE_BWID);

  // Surface stride of bias data cube
  NewState(m, SDP_RDMA_D_EW_SURFACE_STRIDE, SDP_RDMA_D_EW_SURFACE_STRIDE_BWID);

  // Stride of bias data cube in batch mode
  NewState(m, SDP_RDMA_D_EW_BATCH_STRIDE, SDP_RDMA_D_EW_BATCH_STRIDE_BWID);

  // Operation configuration: flying mode, output destination, Direct or
  // Winograd mode, flush NaN to zero, batch number.
  NewState(m, SDP_RDMA_D_FEATURE_MODE_CFG, SDP_RDMA_D_FEATURE_MODE_CFG_BWID);

  // RAM type of input data cube
  NewState(m, SDP_RDMA_D_SRC_DMA_CFG, SDP_RDMA_D_SRC_DMA_CFG_BWID);

  // Input NaN element number
  NewState(m, SDP_RDMA_D_STATUS_NAN_INPUT_NUM,
           SDP_RDMA_D_STATUS_NAN_INPUT_NUM_BWID);

  // Input Infinity element number
  NewState(m, SDP_RDMA_D_STATUS_INF_INPUT_NUM,
           SDP_RDMA_D_STATUS_INF_INPUT_NUM_BWID);

  // Enable/Disable performance counting
  NewState(m, SDP_RDMA_D_PERF_ENABLE, SDP_RDMA_D_PERF_ENABLE_BWID);

  // Count stall cycles of M read DMA for one layer
  NewState(m, SDP_RDMA_D_PERF_MRDMA_READ_STALL,
           SDP_RDMA_D_PERF_MRDMA_READ_STALL_BWID);

  // Count stall cycles of B read DMA for one layer
  NewState(m, SDP_RDMA_D_PERF_BRDMA_READ_STALL,
           SDP_RDMA_D_PERF_BRDMA_READ_STALL_BWID);

  // Count stall cycles of N read DMA for one layer
  NewState(m, SDP_RDMA_D_PERF_NRDMA_READ_STALL,
           SDP_RDMA_D_PERF_NRDMA_READ_STALL_BWID);

  // Count stall cycles of E read DMA for one layer
  NewState(m, SDP_RDMA_D_PERF_ERDMA_READ_STALL,
           SDP_RDMA_D_PERF_ERDMA_READ_STALL_BWID);

  return;
}

}; // namespace ilang
