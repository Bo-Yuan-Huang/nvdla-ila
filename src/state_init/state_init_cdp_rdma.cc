// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: state_init_cdp_rdma.cc

#include <ilang/ilang++.h>
#include <nvdla/configs/state_info.h>
#include <nvdla/utils.h>

// namespace ilang
namespace ilang {

// FIXME this is auto-generated placeholder

void StateInitCdp_Rdma(Ila& m) {
  // Idle status of two register groups
  m.AddInit(m.state(CDP_RDMA_S_STATUS) == 0);

  // Pointer for CSB master and data path to access groups
  m.AddInit(m.state(CDP_RDMA_S_POINTER) == 0);

  // Set it to 1 to kick off operation for current register group
  m.AddInit(m.state(CDP_RDMA_D_OP_ENABLE) == 0);

  // Input data cube’s width
  m.AddInit(m.state(CDP_RDMA_D_DATA_CUBE_WIDTH) == 0);

  // Input data cube’s height
  m.AddInit(m.state(CDP_RDMA_D_DATA_CUBE_HEIGHT) == 0);

  // Input data cube’s channel
  m.AddInit(m.state(CDP_RDMA_D_DATA_CUBE_CHANNEL) == 0);

  // Lower 32bits of input data address
  m.AddInit(m.state(CDP_RDMA_D_SRC_BASE_ADDR_LOW) == 0);

  // Higher 32bits of input data address when axi araddr is 64bits
  m.AddInit(m.state(CDP_RDMA_D_SRC_BASE_ADDR_HIGH) == 0);

  // Line stride of input cube
  m.AddInit(m.state(CDP_RDMA_D_SRC_LINE_STRIDE) == 0);

  // Surface stride of input cube
  m.AddInit(m.state(CDP_RDMA_D_SRC_SURFACE_STRIDE) == 0);

  // RAM type of input data cube
  m.AddInit(m.state(CDP_RDMA_D_SRC_DMA_CFG) == 0);

  // This register is not used in OpenDLA 1.0
  m.AddInit(m.state(CDP_RDMA_D_SRC_COMPRESSION_EN) == 0);

  // Split number
  m.AddInit(m.state(CDP_RDMA_D_OPERATION_MODE) == 0);

  // Input data cube
  m.AddInit(m.state(CDP_RDMA_D_DATA_FORMAT) == 0);

  // Enable/Disable performance counting
  m.AddInit(m.state(CDP_RDMA_D_PERF_ENABLE) == 0);

  // Counting stalls of read requests
  m.AddInit(m.state(CDP_RDMA_D_PERF_READ_STALL) == 0);

  return;
}

}; // namespace ilang
