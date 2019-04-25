// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: state_init_pdp_rdma.cc

#include <ilang/ilang++.h>
#include <nvdla/configs/state_info.h>
#include <nvdla/utils.h>

// namespace ilang
namespace ilang {

// FIXME this is auto-generated placeholder

void StateInitPdp_Rdma(Ila& m) {
  // Idle status of two register groups
  m.AddInit(m.state(PDP_RDMA_S_STATUS) == 0);

  // Pointer for CSB master and data path to access groups
  m.AddInit(m.state(PDP_RDMA_S_POINTER) == 0);

  // Set it to 1 to kick off operation for current register group
  m.AddInit(m.state(PDP_RDMA_D_OP_ENABLE) == 0);

  // Input data cube’s width
  m.AddInit(m.state(PDP_RDMA_D_DATA_CUBE_IN_WIDTH) == 0);

  // Input data cube’s height
  m.AddInit(m.state(PDP_RDMA_D_DATA_CUBE_IN_HEIGHT) == 0);

  // Input data cube’s channel
  m.AddInit(m.state(PDP_RDMA_D_DATA_CUBE_IN_CHANNEL) == 0);

  // Indicate source is SDP or external memory
  m.AddInit(m.state(PDP_RDMA_D_FLYING_MODE) == 0);

  // Lower 32bits of input data address
  m.AddInit(m.state(PDP_RDMA_D_SRC_BASE_ADDR_LOW) == 0);

  // Higher 32bits of input data address when axi araddr is 64bits
  m.AddInit(m.state(PDP_RDMA_D_SRC_BASE_ADDR_HIGH) == 0);

  // Line stride of input cube
  m.AddInit(m.state(PDP_RDMA_D_SRC_LINE_STRIDE) == 0);

  // Surface stride of input cube
  m.AddInit(m.state(PDP_RDMA_D_SRC_SURFACE_STRIDE) == 0);

  // RAM type of input data cube
  m.AddInit(m.state(PDP_RDMA_D_SRC_RAM_CFG) == 0);

  // Input data cube
  m.AddInit(m.state(PDP_RDMA_D_DATA_FORMAT) == 0);

  // Split number
  m.AddInit(m.state(PDP_RDMA_D_OPERATION_MODE_CFG) == 0);

  // Kernel width and kernel stride
  m.AddInit(m.state(PDP_RDMA_D_POOLING_KERNEL_CFG) == 0);

  // Padding width
  m.AddInit(m.state(PDP_RDMA_D_POOLING_PADDING_CFG) == 0);

  // Partial width for first, last and middle partitions
  m.AddInit(m.state(PDP_RDMA_D_PARTIAL_WIDTH_IN) == 0);

  // Enable/Disable performance counting
  m.AddInit(m.state(PDP_RDMA_D_PERF_ENABLE) == 0);

  // Element number that for both LUT underflow.
  m.AddInit(m.state(PDP_RDMA_D_PERF_READ_STALL) == 0);

  return;
}

}; // namespace ilang
