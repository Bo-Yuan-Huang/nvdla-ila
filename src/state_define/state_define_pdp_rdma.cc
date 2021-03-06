// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: state_define_pdp_rdma.cc

#include <ilang/ilang++.h>
#include <nvdla/configs/state_info.h>
#include <nvdla/utils.h>

// namespace ilang
namespace ilang {

void StateDefinePdp_Rdma(Ila& m) {
  // Idle status of two register groups
  NewState(m, PDP_RDMA_S_STATUS, PDP_RDMA_S_STATUS_BWID);

  // Pointer for CSB master and data path to access groups
  NewState(m, PDP_RDMA_S_POINTER, PDP_RDMA_S_POINTER_BWID);

  // Set it to 1 to kick off operation for current register group
  NewState(m, PDP_RDMA_D_OP_ENABLE_G0, PDP_RDMA_D_OP_ENABLE_BWID);
  NewState(m, PDP_RDMA_D_OP_ENABLE_G1, PDP_RDMA_D_OP_ENABLE_BWID);

  // Input data cube’s width
  NewState(m, PDP_RDMA_D_DATA_CUBE_IN_WIDTH_G0,
           PDP_RDMA_D_DATA_CUBE_IN_WIDTH_BWID);
  NewState(m, PDP_RDMA_D_DATA_CUBE_IN_WIDTH_G1,
           PDP_RDMA_D_DATA_CUBE_IN_WIDTH_BWID);

  // Input data cube’s height
  NewState(m, PDP_RDMA_D_DATA_CUBE_IN_HEIGHT_G0,
           PDP_RDMA_D_DATA_CUBE_IN_HEIGHT_BWID);
  NewState(m, PDP_RDMA_D_DATA_CUBE_IN_HEIGHT_G1,
           PDP_RDMA_D_DATA_CUBE_IN_HEIGHT_BWID);

  // Input data cube’s channel
  NewState(m, PDP_RDMA_D_DATA_CUBE_IN_CHANNEL_G0,
           PDP_RDMA_D_DATA_CUBE_IN_CHANNEL_BWID);
  NewState(m, PDP_RDMA_D_DATA_CUBE_IN_CHANNEL_G1,
           PDP_RDMA_D_DATA_CUBE_IN_CHANNEL_BWID);

  // Indicate source is SDP or external memory
  NewState(m, PDP_RDMA_D_FLYING_MODE_G0, PDP_RDMA_D_FLYING_MODE_BWID);
  NewState(m, PDP_RDMA_D_FLYING_MODE_G1, PDP_RDMA_D_FLYING_MODE_BWID);

  // Lower 32bits of input data address
  NewState(m, PDP_RDMA_D_SRC_BASE_ADDR_LOW_G0,
           PDP_RDMA_D_SRC_BASE_ADDR_LOW_BWID);
  NewState(m, PDP_RDMA_D_SRC_BASE_ADDR_LOW_G1,
           PDP_RDMA_D_SRC_BASE_ADDR_LOW_BWID);

  // Higher 32bits of input data address when axi araddr is 64bits
  NewState(m, PDP_RDMA_D_SRC_BASE_ADDR_HIGH_G0,
           PDP_RDMA_D_SRC_BASE_ADDR_HIGH_BWID);
  NewState(m, PDP_RDMA_D_SRC_BASE_ADDR_HIGH_G1,
           PDP_RDMA_D_SRC_BASE_ADDR_HIGH_BWID);

  // Line stride of input cube
  NewState(m, PDP_RDMA_D_SRC_LINE_STRIDE_G0, PDP_RDMA_D_SRC_LINE_STRIDE_BWID);
  NewState(m, PDP_RDMA_D_SRC_LINE_STRIDE_G1, PDP_RDMA_D_SRC_LINE_STRIDE_BWID);

  // Surface stride of input cube
  NewState(m, PDP_RDMA_D_SRC_SURFACE_STRIDE_G0,
           PDP_RDMA_D_SRC_SURFACE_STRIDE_BWID);
  NewState(m, PDP_RDMA_D_SRC_SURFACE_STRIDE_G1,
           PDP_RDMA_D_SRC_SURFACE_STRIDE_BWID);

  // RAM type of input data cube
  NewState(m, PDP_RDMA_D_SRC_RAM_CFG_G0, PDP_RDMA_D_SRC_RAM_CFG_BWID);
  NewState(m, PDP_RDMA_D_SRC_RAM_CFG_G1, PDP_RDMA_D_SRC_RAM_CFG_BWID);

  // Input data cube
  NewState(m, PDP_RDMA_D_DATA_FORMAT_G0, PDP_RDMA_D_DATA_FORMAT_BWID);
  NewState(m, PDP_RDMA_D_DATA_FORMAT_G1, PDP_RDMA_D_DATA_FORMAT_BWID);

  // Split number
  NewState(m, PDP_RDMA_D_OPERATION_MODE_CFG_G0,
           PDP_RDMA_D_OPERATION_MODE_CFG_BWID);
  NewState(m, PDP_RDMA_D_OPERATION_MODE_CFG_G1,
           PDP_RDMA_D_OPERATION_MODE_CFG_BWID);

  // Kernel width and kernel stride
  NewState(m, PDP_RDMA_D_POOLING_KERNEL_CFG_G0,
           PDP_RDMA_D_POOLING_KERNEL_CFG_BWID);
  NewState(m, PDP_RDMA_D_POOLING_KERNEL_CFG_G1,
           PDP_RDMA_D_POOLING_KERNEL_CFG_BWID);

  // Padding width
  NewState(m, PDP_RDMA_D_POOLING_PADDING_CFG_G0,
           PDP_RDMA_D_POOLING_PADDING_CFG_BWID);
  NewState(m, PDP_RDMA_D_POOLING_PADDING_CFG_G1,
           PDP_RDMA_D_POOLING_PADDING_CFG_BWID);

  // Partial width for first, last and middle partitions
  NewState(m, PDP_RDMA_D_PARTIAL_WIDTH_IN_G0, PDP_RDMA_D_PARTIAL_WIDTH_IN_BWID);
  NewState(m, PDP_RDMA_D_PARTIAL_WIDTH_IN_G1, PDP_RDMA_D_PARTIAL_WIDTH_IN_BWID);

  // Enable/Disable performance counting
  NewState(m, PDP_RDMA_D_PERF_ENABLE_G0, PDP_RDMA_D_PERF_ENABLE_BWID);
  NewState(m, PDP_RDMA_D_PERF_ENABLE_G1, PDP_RDMA_D_PERF_ENABLE_BWID);

  // Element number that for both LUT underflow.
  NewState(m, PDP_RDMA_D_PERF_READ_STALL_G0, PDP_RDMA_D_PERF_READ_STALL_BWID);
  NewState(m, PDP_RDMA_D_PERF_READ_STALL_G1, PDP_RDMA_D_PERF_READ_STALL_BWID);

  return;
}

}; // namespace ilang
