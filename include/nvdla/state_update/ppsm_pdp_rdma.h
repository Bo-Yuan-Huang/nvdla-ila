// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: ppsm_pdp_rdma.h

#ifndef PPSM_PDP_RDMA_H__
#define PPSM_PDP_RDMA_H__

#include <ilang/ilang++.h>

// namespace ilang
namespace ilang {

void CsbWrPpsm_PDP_RDMA_D_OP_ENABLE(Ila& m);
void CsbWrPpsm_PDP_RDMA_D_DATA_CUBE_IN_WIDTH(Ila& m);
void CsbWrPpsm_PDP_RDMA_D_DATA_CUBE_IN_HEIGHT(Ila& m);
void CsbWrPpsm_PDP_RDMA_D_DATA_CUBE_IN_CHANNEL(Ila& m);
void CsbWrPpsm_PDP_RDMA_D_FLYING_MODE(Ila& m);
void CsbWrPpsm_PDP_RDMA_D_SRC_BASE_ADDR_LOW(Ila& m);
void CsbWrPpsm_PDP_RDMA_D_SRC_BASE_ADDR_HIGH(Ila& m);
void CsbWrPpsm_PDP_RDMA_D_SRC_LINE_STRIDE(Ila& m);
void CsbWrPpsm_PDP_RDMA_D_SRC_SURFACE_STRIDE(Ila& m);
void CsbWrPpsm_PDP_RDMA_D_SRC_RAM_CFG(Ila& m);
void CsbWrPpsm_PDP_RDMA_D_DATA_FORMAT(Ila& m);
void CsbWrPpsm_PDP_RDMA_D_OPERATION_MODE_CFG(Ila& m);
void CsbWrPpsm_PDP_RDMA_D_POOLING_KERNEL_CFG(Ila& m);
void CsbWrPpsm_PDP_RDMA_D_POOLING_PADDING_CFG(Ila& m);
void CsbWrPpsm_PDP_RDMA_D_PARTIAL_WIDTH_IN(Ila& m);
void CsbWrPpsm_PDP_RDMA_D_PERF_ENABLE(Ila& m);
void CsbWrPpsm_PDP_RDMA_D_PERF_READ_STALL(Ila& m);

}; // namespace ilang

#endif // PPSM_PDP_RDMA_H__
