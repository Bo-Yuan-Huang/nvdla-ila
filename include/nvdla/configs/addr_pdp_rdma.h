// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: addr_pdp_rdma.h

#ifndef NVDLA_ADDR_PDP_RDMA_H__
#define NVDLA_ADDR_PDP_RDMA_H__

/// \namespace ilang
namespace ilang {

// Idle status of two register groups
#define PDP_RDMA_S_STATUS_ADDR 0xc000
// Pointer for CSB master and data path to access groups
#define PDP_RDMA_S_POINTER_ADDR 0xc004
// Set it to 1 to kick off operation for current register group
#define PDP_RDMA_D_OP_ENABLE_ADDR 0xc008
// Input data cube’s width
#define PDP_RDMA_D_DATA_CUBE_IN_WIDTH_ADDR 0xc00c
// Input data cube’s height
#define PDP_RDMA_D_DATA_CUBE_IN_HEIGHT_ADDR 0xc010
// Input data cube’s channel
#define PDP_RDMA_D_DATA_CUBE_IN_CHANNEL_ADDR 0xc014
// Indicate source is SDP or external memory
#define PDP_RDMA_D_FLYING_MODE_ADDR 0xc018
// Lower 32bits of input data address
#define PDP_RDMA_D_SRC_BASE_ADDR_LOW_ADDR 0xc01c
// Higher 32bits of input data address when axi araddr is 64bits
#define PDP_RDMA_D_SRC_BASE_ADDR_HIGH_ADDR 0xc020
// Line stride of input cube
#define PDP_RDMA_D_SRC_LINE_STRIDE_ADDR 0xc024
// Surface stride of input cube
#define PDP_RDMA_D_SRC_SURFACE_STRIDE_ADDR 0xc028
// RAM type of input data cube
#define PDP_RDMA_D_SRC_RAM_CFG_ADDR 0xc02c
// Input data cube
#define PDP_RDMA_D_DATA_FORMAT_ADDR 0xc030
// Split number
#define PDP_RDMA_D_OPERATION_MODE_CFG_ADDR 0xc034
// Kernel width and kernel stride
#define PDP_RDMA_D_POOLING_KERNEL_CFG_ADDR 0xc038
// Padding width
#define PDP_RDMA_D_POOLING_PADDING_CFG_ADDR 0xc03c
// Partial width for first, last and middle partitions
#define PDP_RDMA_D_PARTIAL_WIDTH_IN_ADDR 0xc040
// Enable/Disable performance counting
#define PDP_RDMA_D_PERF_ENABLE_ADDR 0xc044
// Element number that for both LUT underflow.
#define PDP_RDMA_D_PERF_READ_STALL_ADDR 0xc048

}; // namespace ilang

#endif // NVDLA_ADDR_PDP_RDMA_H__
