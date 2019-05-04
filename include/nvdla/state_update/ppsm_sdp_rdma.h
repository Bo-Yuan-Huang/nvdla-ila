// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: ppsm_sdp_rdma.h

#ifndef PPSM_SDP_RDMA_H__
#define PPSM_SDP_RDMA_H__

#include <ilang/ilang++.h>

// namespace ilang
namespace ilang {

void CsbWrPpsm_SDP_RDMA_D_OP_ENABLE(Ila& m);
void CsbWrPpsm_SDP_RDMA_D_DATA_CUBE_WIDTH(Ila& m);
void CsbWrPpsm_SDP_RDMA_D_DATA_CUBE_HEIGHT(Ila& m);
void CsbWrPpsm_SDP_RDMA_D_DATA_CUBE_CHANNEL(Ila& m);
void CsbWrPpsm_SDP_RDMA_D_SRC_BASE_ADDR_LOW(Ila& m);
void CsbWrPpsm_SDP_RDMA_D_SRC_BASE_ADDR_HIGH(Ila& m);
void CsbWrPpsm_SDP_RDMA_D_SRC_LINE_STRIDE(Ila& m);
void CsbWrPpsm_SDP_RDMA_D_SRC_SURFACE_STRIDE(Ila& m);
void CsbWrPpsm_SDP_RDMA_D_BRDMA_CFG(Ila& m);
void CsbWrPpsm_SDP_RDMA_D_BS_BASE_ADDR_LOW(Ila& m);
void CsbWrPpsm_SDP_RDMA_D_BS_BASE_ADDR_HIGH(Ila& m);
void CsbWrPpsm_SDP_RDMA_D_BS_LINE_STRIDE(Ila& m);
void CsbWrPpsm_SDP_RDMA_D_BS_SURFACE_STRIDE(Ila& m);
void CsbWrPpsm_SDP_RDMA_D_BS_BATCH_STRIDE(Ila& m);
void CsbWrPpsm_SDP_RDMA_D_NRDMA_CFG(Ila& m);
void CsbWrPpsm_SDP_RDMA_D_BN_BASE_ADDR_LOW(Ila& m);
void CsbWrPpsm_SDP_RDMA_D_BN_BASE_ADDR_HIGH(Ila& m);
void CsbWrPpsm_SDP_RDMA_D_BN_LINE_STRIDE(Ila& m);
void CsbWrPpsm_SDP_RDMA_D_BN_SURFACE_STRIDE(Ila& m);
void CsbWrPpsm_SDP_RDMA_D_BN_BATCH_STRIDE(Ila& m);
void CsbWrPpsm_SDP_RDMA_D_ERDMA_CFG(Ila& m);
void CsbWrPpsm_SDP_RDMA_D_EW_BASE_ADDR_LOW(Ila& m);
void CsbWrPpsm_SDP_RDMA_D_EW_BASE_ADDR_HIGH(Ila& m);
void CsbWrPpsm_SDP_RDMA_D_EW_LINE_STRIDE(Ila& m);
void CsbWrPpsm_SDP_RDMA_D_EW_SURFACE_STRIDE(Ila& m);
void CsbWrPpsm_SDP_RDMA_D_EW_BATCH_STRIDE(Ila& m);
void CsbWrPpsm_SDP_RDMA_D_FEATURE_MODE_CFG(Ila& m);
void CsbWrPpsm_SDP_RDMA_D_SRC_DMA_CFG(Ila& m);
void CsbWrPpsm_SDP_RDMA_D_STATUS_NAN_INPUT_NUM(Ila& m);
void CsbWrPpsm_SDP_RDMA_D_STATUS_INF_INPUT_NUM(Ila& m);
void CsbWrPpsm_SDP_RDMA_D_PERF_ENABLE(Ila& m);
void CsbWrPpsm_SDP_RDMA_D_PERF_MRDMA_READ_STALL(Ila& m);
void CsbWrPpsm_SDP_RDMA_D_PERF_BRDMA_READ_STALL(Ila& m);
void CsbWrPpsm_SDP_RDMA_D_PERF_NRDMA_READ_STALL(Ila& m);
void CsbWrPpsm_SDP_RDMA_D_PERF_ERDMA_READ_STALL(Ila& m);

}; // namespace ilang

#endif // PPSM_SDP_RDMA_H__
