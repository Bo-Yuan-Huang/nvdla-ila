// File Name: addr_cdp_rdma.h

#ifndef NVDLA_ADDR_CDP_RDMA_H__
#define NVDLA_ADDR_CDP_RDMA_H__

/// \namespace ilang
namespace ilang {

// Idle status of two register groups
#define CDP_RDMA_S_STATUS_ADDR 0xe000
// Pointer for CSB master and data path to access groups
#define CDP_RDMA_S_POINTER_ADDR 0xe004
// Set it to 1 to kick off operation for current register group
#define CDP_RDMA_D_OP_ENABLE_ADDR 0xe008
// Input data cube’s width
#define CDP_RDMA_D_DATA_CUBE_WIDTH_ADDR 0xe00c
// Input data cube’s height
#define CDP_RDMA_D_DATA_CUBE_HEIGHT_ADDR 0xe010
// Input data cube’s channel
#define CDP_RDMA_D_DATA_CUBE_CHANNEL_ADDR 0xe014
// Lower 32bits of input data address
#define CDP_RDMA_D_SRC_BASE_ADDR_LOW_ADDR 0xe018
// Higher 32bits of input data address when axi araddr is 64bits
#define CDP_RDMA_D_SRC_BASE_ADDR_HIGH_ADDR 0xe01c
// Line stride of input cube
#define CDP_RDMA_D_SRC_LINE_STRIDE_ADDR 0xe020
// Surface stride of input cube
#define CDP_RDMA_D_SRC_SURFACE_STRIDE_ADDR 0xe024
// RAM type of input data cube
#define CDP_RDMA_D_SRC_DMA_CFG_ADDR 0xe028
// This register is not used in OpenDLA 1.0
#define CDP_RDMA_D_SRC_COMPRESSION_EN_ADDR 0xe02c
// Split number
#define CDP_RDMA_D_OPERATION_MODE_ADDR 0xe030
// Input data cube
#define CDP_RDMA_D_DATA_FORMAT_ADDR 0xe034
// Enable/Disable performance counting
#define CDP_RDMA_D_PERF_ENABLE_ADDR 0xe038
// Counting stalls of read requests
#define CDP_RDMA_D_PERF_READ_STALL_ADDR 0xe03c

}; // namespace ilang

#endif // NVDLA_ADDR_CDP_RDMA_H__
