// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: state_init_sdp_rdma.cc

#include <ilang/ilang++.h>
#include <nvdla/configs/state_info.h>
#include <nvdla/utils.h>

// namespace ilang
namespace ilang {

// FIXME this is auto-generated placeholder

void StateInitSdp_Rdma(Ila& m) {
  // Idle status of two register groups
  m.AddInit(m.state(SDP_RDMA_S_STATUS) == 0);

  // Pointer for CSB master and data path to access groups
  m.AddInit(m.state(SDP_RDMA_S_POINTER) == 0);

  // Set it to 1 to kick off operation for current register group
  m.AddInit(m.state(SDP_RDMA_D_OP_ENABLE) == 0);

  // Input cube’s width
  m.AddInit(m.state(SDP_RDMA_D_DATA_CUBE_WIDTH) == 0);

  // Input cube’s height
  m.AddInit(m.state(SDP_RDMA_D_DATA_CUBE_HEIGHT) == 0);

  // Input cube’s channel
  m.AddInit(m.state(SDP_RDMA_D_DATA_CUBE_CHANNEL) == 0);

  // Lower 32bits of input data address
  m.AddInit(m.state(SDP_RDMA_D_SRC_BASE_ADDR_LOW) == 0);

  // Higher 32bits of input data address when axi araddr is 64bits
  m.AddInit(m.state(SDP_RDMA_D_SRC_BASE_ADDR_HIGH) == 0);

  // Line stride of input cube
  m.AddInit(m.state(SDP_RDMA_D_SRC_LINE_STRIDE) == 0);

  // Surface stride of input cube
  m.AddInit(m.state(SDP_RDMA_D_SRC_SURFACE_STRIDE) == 0);

  // Configuration of BRDMA: enable/disable, data size, Ram type, etc.
  m.AddInit(m.state(SDP_RDMA_D_BRDMA_CFG) == 0);

  // Lower 32bits address of the bias data cube
  m.AddInit(m.state(SDP_RDMA_D_BS_BASE_ADDR_LOW) == 0);

  // Higher 32bits address of the bias data cube when axi araddr is 64bits
  m.AddInit(m.state(SDP_RDMA_D_BS_BASE_ADDR_HIGH) == 0);

  // Line stride of bias data cube
  m.AddInit(m.state(SDP_RDMA_D_BS_LINE_STRIDE) == 0);

  // Surface stride of bias data cube
  m.AddInit(m.state(SDP_RDMA_D_BS_SURFACE_STRIDE) == 0);

  // Stride of bias data cube in batch mode
  m.AddInit(m.state(SDP_RDMA_D_BS_BATCH_STRIDE) == 0);

  // Configuration of NRDMA: enable/disable, data size, Ram type, etc.
  m.AddInit(m.state(SDP_RDMA_D_NRDMA_CFG) == 0);

  // Lower 32bits address of the bias data cube
  m.AddInit(m.state(SDP_RDMA_D_BN_BASE_ADDR_LOW) == 0);

  // Higher 32bits address of the bias data cube when axi araddr is 64bits
  m.AddInit(m.state(SDP_RDMA_D_BN_BASE_ADDR_HIGH) == 0);

  // Line stride of bias data cube
  m.AddInit(m.state(SDP_RDMA_D_BN_LINE_STRIDE) == 0);

  // Surface stride of bias data cube
  m.AddInit(m.state(SDP_RDMA_D_BN_SURFACE_STRIDE) == 0);

  // Stride of bias data cube in batch mode
  m.AddInit(m.state(SDP_RDMA_D_BN_BATCH_STRIDE) == 0);

  // Configuration of ERDMA: enable/disable, data size, Ram type, etc.
  m.AddInit(m.state(SDP_RDMA_D_ERDMA_CFG) == 0);

  // Lower 32bits address of the bias data cube
  m.AddInit(m.state(SDP_RDMA_D_EW_BASE_ADDR_LOW) == 0);

  // Higher 32bits address of the bias data cube when axi araddr is 64bits
  m.AddInit(m.state(SDP_RDMA_D_EW_BASE_ADDR_HIGH) == 0);

  // Line stride of bias data cube
  m.AddInit(m.state(SDP_RDMA_D_EW_LINE_STRIDE) == 0);

  // Surface stride of bias data cube
  m.AddInit(m.state(SDP_RDMA_D_EW_SURFACE_STRIDE) == 0);

  // Stride of bias data cube in batch mode
  m.AddInit(m.state(SDP_RDMA_D_EW_BATCH_STRIDE) == 0);

  // Operation configuration: flying mode, output destination, Direct or
  // Winograd mode, flush NaN to zero, batch number.
  m.AddInit(m.state(SDP_RDMA_D_FEATURE_MODE_CFG) == 0);

  // RAM type of input data cube
  m.AddInit(m.state(SDP_RDMA_D_SRC_DMA_CFG) == 0);

  // Input NaN element number
  m.AddInit(m.state(SDP_RDMA_D_STATUS_NAN_INPUT_NUM) == 0);

  // Input Infinity element number
  m.AddInit(m.state(SDP_RDMA_D_STATUS_INF_INPUT_NUM) == 0);

  // Enable/Disable performance counting
  m.AddInit(m.state(SDP_RDMA_D_PERF_ENABLE) == 0);

  // Count stall cycles of M read DMA for one layer
  m.AddInit(m.state(SDP_RDMA_D_PERF_MRDMA_READ_STALL) == 0);

  // Count stall cycles of B read DMA for one layer
  m.AddInit(m.state(SDP_RDMA_D_PERF_BRDMA_READ_STALL) == 0);

  // Count stall cycles of N read DMA for one layer
  m.AddInit(m.state(SDP_RDMA_D_PERF_NRDMA_READ_STALL) == 0);

  // Count stall cycles of E read DMA for one layer
  m.AddInit(m.state(SDP_RDMA_D_PERF_ERDMA_READ_STALL) == 0);

  return;
}

}; // namespace ilang
