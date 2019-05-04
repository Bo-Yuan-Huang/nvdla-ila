// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: ppsm_cdp_rdma.h

#ifndef PPSM_CDP_RDMA_H__
#define PPSM_CDP_RDMA_H__

#include <ilang/ilang++.h>

// namespace ilang
namespace ilang {

void CsbWrPpsm_CDP_RDMA_D_OP_ENABLE(Ila& m);
void CsbWrPpsm_CDP_RDMA_D_DATA_CUBE_WIDTH(Ila& m);
void CsbWrPpsm_CDP_RDMA_D_DATA_CUBE_HEIGHT(Ila& m);
void CsbWrPpsm_CDP_RDMA_D_DATA_CUBE_CHANNEL(Ila& m);
void CsbWrPpsm_CDP_RDMA_D_SRC_BASE_ADDR_LOW(Ila& m);
void CsbWrPpsm_CDP_RDMA_D_SRC_BASE_ADDR_HIGH(Ila& m);
void CsbWrPpsm_CDP_RDMA_D_SRC_LINE_STRIDE(Ila& m);
void CsbWrPpsm_CDP_RDMA_D_SRC_SURFACE_STRIDE(Ila& m);
void CsbWrPpsm_CDP_RDMA_D_SRC_DMA_CFG(Ila& m);
void CsbWrPpsm_CDP_RDMA_D_SRC_COMPRESSION_EN(Ila& m);
void CsbWrPpsm_CDP_RDMA_D_OPERATION_MODE(Ila& m);
void CsbWrPpsm_CDP_RDMA_D_DATA_FORMAT(Ila& m);
void CsbWrPpsm_CDP_RDMA_D_PERF_ENABLE(Ila& m);
void CsbWrPpsm_CDP_RDMA_D_PERF_READ_STALL(Ila& m);

}; // namespace ilang

#endif // PPSM_CDP_RDMA_H__
