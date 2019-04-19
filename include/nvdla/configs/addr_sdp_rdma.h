// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" wich comes with this distribution for more information.
// ============================================================================

// File Name: addr_sdp_rdma.h

#ifndef NVDLA_ADDR_SDP_RDMA_H__
#define NVDLA_ADDR_SDP_RDMA_H__

/// \namespace ilang
namespace ilang {

// Idle status of two register groups
#define SDP_RDMA_S_STATUS 0xa000
// Pointer for CSB master and data path to access groups
#define SDP_RDMA_S_POINTER 0xa004
// Set it to 1 to kick off operation for current register group
#define SDP_RDMA_D_OP_ENABLE 0xa008
// Input cube’s width
#define SDP_RDMA_D_DATA_CUBE_WIDTH 0xa00c
// Input cube’s height
#define SDP_RDMA_D_DATA_CUBE_HEIGHT 0xa010
// Input cube’s channel
#define SDP_RDMA_D_DATA_CUBE_CHANNEL 0xa014
// Lower 32bits of input data address
#define SDP_RDMA_D_SRC_BASE_ADDR_LOW 0xa018
// Higher 32bits of input data address when axi araddr is 64bits
#define SDP_RDMA_D_SRC_BASE_ADDR_HIGH 0xa01c
// Line stride of input cube
#define SDP_RDMA_D_SRC_LINE_STRIDE 0xa020
// Surface stride of input cube
#define SDP_RDMA_D_SRC_SURFACE_STRIDE 0xa024
// Configuration of BRDMA: enable/disable, data size, Ram type, etc.
#define SDP_RDMA_D_BRDMA_CFG 0xa028
// Lower 32bits address of the bias data cube
#define SDP_RDMA_D_BS_BASE_ADDR_LOW 0xa02c
// Higher 32bits address of the bias data cube when axi araddr is 64bits
#define SDP_RDMA_D_BS_BASE_ADDR_HIGH 0xa030
// Line stride of bias data cube
#define SDP_RDMA_D_BS_LINE_STRIDE 0xa034
// Surface stride of bias data cube
#define SDP_RDMA_D_BS_SURFACE_STRIDE 0xa038
// Stride of bias data cube in batch mode
#define SDP_RDMA_D_BS_BATCH_STRIDE 0xa03c
// Configuration of NRDMA: enable/disable, data size, Ram type, etc.
#define SDP_RDMA_D_NRDMA_CFG 0xa040
// Lower 32bits address of the bias data cube
#define SDP_RDMA_D_BN_BASE_ADDR_LOW 0xa044
// Higher 32bits address of the bias data cube when axi araddr is 64bits
#define SDP_RDMA_D_BN_BASE_ADDR_HIGH 0xa048
// Line stride of bias data cube
#define SDP_RDMA_D_BN_LINE_STRIDE 0xa04c
// Surface stride of bias data cube
#define SDP_RDMA_D_BN_SURFACE_STRIDE 0xa050
// Stride of bias data cube in batch mode
#define SDP_RDMA_D_BN_BATCH_STRIDE 0xa054
// Configuration of ERDMA: enable/disable, data size, Ram type, etc.
#define SDP_RDMA_D_ERDMA_CFG 0xa058
// Lower 32bits address of the bias data cube
#define SDP_RDMA_D_EW_BASE_ADDR_LOW 0xa05c
// Higher 32bits address of the bias data cube when axi araddr is 64bits
#define SDP_RDMA_D_EW_BASE_ADDR_HIGH 0xa060
// Line stride of bias data cube
#define SDP_RDMA_D_EW_LINE_STRIDE 0xa064
// Surface stride of bias data cube
#define SDP_RDMA_D_EW_SURFACE_STRIDE 0xa068
// Stride of bias data cube in batch mode
#define SDP_RDMA_D_EW_BATCH_STRIDE 0xa06c
// Operation configuration: flying mode, output destination, Direct or Winograd
// mode, flush NaN to zero, batch number.
#define SDP_RDMA_D_FEATURE_MODE_CFG 0xa070
// RAM type of input data cube
#define SDP_RDMA_D_SRC_DMA_CFG 0xa074
// Input NaN element number
#define SDP_RDMA_D_STATUS_NAN_INPUT_NUM 0xa078
// Input Infinity element number
#define SDP_RDMA_D_STATUS_INF_INPUT_NUM 0xa07c
// Enable/Disable performance counting
#define SDP_RDMA_D_PERF_ENABLE 0xa080
// Count stall cycles of M read DMA for one layer
#define SDP_RDMA_D_PERF_MRDMA_READ_STALL 0xa084
// Count stall cycles of B read DMA for one layer
#define SDP_RDMA_D_PERF_BRDMA_READ_STALL 0xa088
// Count stall cycles of N read DMA for one layer
#define SDP_RDMA_D_PERF_NRDMA_READ_STALL 0xa08c
// Count stall cycles of E read DMA for one layer
#define SDP_RDMA_D_PERF_ERDMA_READ_STALL 0xa090

}; // namespace ilang

#endif // NVDLA_ADDR_SDP_RDMA_H__
