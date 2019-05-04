// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: ppsm_pdp.h

#ifndef PPSM_PDP_H__
#define PPSM_PDP_H__

#include <ilang/ilang++.h>

// namespace ilang
namespace ilang {

void CsbWrPpsm_PDP_D_OP_ENABLE(Ila& m);
void CsbWrPpsm_PDP_D_DATA_CUBE_IN_WIDTH(Ila& m);
void CsbWrPpsm_PDP_D_DATA_CUBE_IN_HEIGHT(Ila& m);
void CsbWrPpsm_PDP_D_DATA_CUBE_IN_CHANNEL(Ila& m);
void CsbWrPpsm_PDP_D_DATA_CUBE_OUT_WIDTH(Ila& m);
void CsbWrPpsm_PDP_D_DATA_CUBE_OUT_HEIGHT(Ila& m);
void CsbWrPpsm_PDP_D_DATA_CUBE_OUT_CHANNEL(Ila& m);
void CsbWrPpsm_PDP_D_OPERATION_MODE_CFG(Ila& m);
void CsbWrPpsm_PDP_D_NAN_FLUSH_TO_ZERO(Ila& m);
void CsbWrPpsm_PDP_D_PARTIAL_WIDTH_IN(Ila& m);
void CsbWrPpsm_PDP_D_PARTIAL_WIDTH_OUT(Ila& m);
void CsbWrPpsm_PDP_D_POOLING_KERNEL_CFG(Ila& m);
void CsbWrPpsm_PDP_D_RECIP_KERNEL_WIDTH(Ila& m);
void CsbWrPpsm_PDP_D_RECIP_KERNEL_HEIGHT(Ila& m);
void CsbWrPpsm_PDP_D_POOLING_PADDING_CFG(Ila& m);
void CsbWrPpsm_PDP_D_POOLING_PADDING_VALUE_1_CFG(Ila& m);
void CsbWrPpsm_PDP_D_POOLING_PADDING_VALUE_2_CFG(Ila& m);
void CsbWrPpsm_PDP_D_POOLING_PADDING_VALUE_3_CFG(Ila& m);
void CsbWrPpsm_PDP_D_POOLING_PADDING_VALUE_4_CFG(Ila& m);
void CsbWrPpsm_PDP_D_POOLING_PADDING_VALUE_5_CFG(Ila& m);
void CsbWrPpsm_PDP_D_POOLING_PADDING_VALUE_6_CFG(Ila& m);
void CsbWrPpsm_PDP_D_POOLING_PADDING_VALUE_7_CFG(Ila& m);
void CsbWrPpsm_PDP_D_SRC_BASE_ADDR_LOW(Ila& m);
void CsbWrPpsm_PDP_D_SRC_BASE_ADDR_HIGH(Ila& m);
void CsbWrPpsm_PDP_D_SRC_LINE_STRIDE(Ila& m);
void CsbWrPpsm_PDP_D_SRC_SURFACE_STRIDE(Ila& m);
void CsbWrPpsm_PDP_D_DST_BASE_ADDR_LOW(Ila& m);
void CsbWrPpsm_PDP_D_DST_BASE_ADDR_HIGH(Ila& m);
void CsbWrPpsm_PDP_D_DST_LINE_STRIDE(Ila& m);
void CsbWrPpsm_PDP_D_DST_SURFACE_STRIDE(Ila& m);
void CsbWrPpsm_PDP_D_DST_RAM_CFG(Ila& m);
void CsbWrPpsm_PDP_D_DATA_FORMAT(Ila& m);
void CsbWrPpsm_PDP_D_INF_INPUT_NUM(Ila& m);
void CsbWrPpsm_PDP_D_NAN_INPUT_NUM(Ila& m);
void CsbWrPpsm_PDP_D_NAN_OUTPUT_NUM(Ila& m);
void CsbWrPpsm_PDP_D_PERF_ENABLE(Ila& m);
void CsbWrPpsm_PDP_D_PERF_WRITE_STALL(Ila& m);

}; // namespace ilang

#endif // PPSM_PDP_H__
