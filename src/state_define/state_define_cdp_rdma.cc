// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: state_define_cdp_rdma.cc

#include <ilang/ilang++.h>
#include <nvdla/configs/state_info.h>
#include <nvdla/utils.h>

// namespace ilang
namespace ilang {

void StateDefineCdp_Rdma(Ila& m) {
  // Idle status of two register groups
  NewState(m, CDP_RDMA_S_STATUS, CDP_RDMA_S_STATUS_BWID);

  // Pointer for CSB master and data path to access groups
  NewState(m, CDP_RDMA_S_POINTER, CDP_RDMA_S_POINTER_BWID);

  // Set it to 1 to kick off operation for current register group
  NewState(m, CDP_RDMA_D_OP_ENABLE_G0, CDP_RDMA_D_OP_ENABLE_BWID);
  NewState(m, CDP_RDMA_D_OP_ENABLE_G1, CDP_RDMA_D_OP_ENABLE_BWID);

  // Input data cube’s width
  NewState(m, CDP_RDMA_D_DATA_CUBE_WIDTH_G0, CDP_RDMA_D_DATA_CUBE_WIDTH_BWID);
  NewState(m, CDP_RDMA_D_DATA_CUBE_WIDTH_G1, CDP_RDMA_D_DATA_CUBE_WIDTH_BWID);

  // Input data cube’s height
  NewState(m, CDP_RDMA_D_DATA_CUBE_HEIGHT_G0, CDP_RDMA_D_DATA_CUBE_HEIGHT_BWID);
  NewState(m, CDP_RDMA_D_DATA_CUBE_HEIGHT_G1, CDP_RDMA_D_DATA_CUBE_HEIGHT_BWID);

  // Input data cube’s channel
  NewState(m, CDP_RDMA_D_DATA_CUBE_CHANNEL_G0,
           CDP_RDMA_D_DATA_CUBE_CHANNEL_BWID);
  NewState(m, CDP_RDMA_D_DATA_CUBE_CHANNEL_G1,
           CDP_RDMA_D_DATA_CUBE_CHANNEL_BWID);

  // Lower 32bits of input data address
  NewState(m, CDP_RDMA_D_SRC_BASE_ADDR_LOW_G0,
           CDP_RDMA_D_SRC_BASE_ADDR_LOW_BWID);
  NewState(m, CDP_RDMA_D_SRC_BASE_ADDR_LOW_G1,
           CDP_RDMA_D_SRC_BASE_ADDR_LOW_BWID);

  // Higher 32bits of input data address when axi araddr is 64bits
  NewState(m, CDP_RDMA_D_SRC_BASE_ADDR_HIGH_G0,
           CDP_RDMA_D_SRC_BASE_ADDR_HIGH_BWID);
  NewState(m, CDP_RDMA_D_SRC_BASE_ADDR_HIGH_G1,
           CDP_RDMA_D_SRC_BASE_ADDR_HIGH_BWID);

  // Line stride of input cube
  NewState(m, CDP_RDMA_D_SRC_LINE_STRIDE_G0, CDP_RDMA_D_SRC_LINE_STRIDE_BWID);
  NewState(m, CDP_RDMA_D_SRC_LINE_STRIDE_G1, CDP_RDMA_D_SRC_LINE_STRIDE_BWID);

  // Surface stride of input cube
  NewState(m, CDP_RDMA_D_SRC_SURFACE_STRIDE_G0,
           CDP_RDMA_D_SRC_SURFACE_STRIDE_BWID);
  NewState(m, CDP_RDMA_D_SRC_SURFACE_STRIDE_G1,
           CDP_RDMA_D_SRC_SURFACE_STRIDE_BWID);

  // RAM type of input data cube
  NewState(m, CDP_RDMA_D_SRC_DMA_CFG_G0, CDP_RDMA_D_SRC_DMA_CFG_BWID);
  NewState(m, CDP_RDMA_D_SRC_DMA_CFG_G1, CDP_RDMA_D_SRC_DMA_CFG_BWID);

  // This register is not used in OpenDLA 1.0
  NewState(m, CDP_RDMA_D_SRC_COMPRESSION_EN_G0,
           CDP_RDMA_D_SRC_COMPRESSION_EN_BWID);
  NewState(m, CDP_RDMA_D_SRC_COMPRESSION_EN_G1,
           CDP_RDMA_D_SRC_COMPRESSION_EN_BWID);

  // Split number
  NewState(m, CDP_RDMA_D_OPERATION_MODE_G0, CDP_RDMA_D_OPERATION_MODE_BWID);
  NewState(m, CDP_RDMA_D_OPERATION_MODE_G1, CDP_RDMA_D_OPERATION_MODE_BWID);

  // Input data cube
  NewState(m, CDP_RDMA_D_DATA_FORMAT_G0, CDP_RDMA_D_DATA_FORMAT_BWID);
  NewState(m, CDP_RDMA_D_DATA_FORMAT_G1, CDP_RDMA_D_DATA_FORMAT_BWID);

  // Enable/Disable performance counting
  NewState(m, CDP_RDMA_D_PERF_ENABLE_G0, CDP_RDMA_D_PERF_ENABLE_BWID);
  NewState(m, CDP_RDMA_D_PERF_ENABLE_G1, CDP_RDMA_D_PERF_ENABLE_BWID);

  // Counting stalls of read requests
  NewState(m, CDP_RDMA_D_PERF_READ_STALL_G0, CDP_RDMA_D_PERF_READ_STALL_BWID);
  NewState(m, CDP_RDMA_D_PERF_READ_STALL_G1, CDP_RDMA_D_PERF_READ_STALL_BWID);

  return;
}

}; // namespace ilang
