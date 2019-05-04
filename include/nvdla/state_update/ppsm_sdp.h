// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: ppsm_sdp.h

#ifndef PPSM_SDP_H__
#define PPSM_SDP_H__

#include <ilang/ilang++.h>

// namespace ilang
namespace ilang {

void CsbWrPpsm_SDP_D_OP_ENABLE(Ila& m);
void CsbWrPpsm_SDP_D_DATA_CUBE_WIDTH(Ila& m);
void CsbWrPpsm_SDP_D_DATA_CUBE_HEIGHT(Ila& m);
void CsbWrPpsm_SDP_D_DATA_CUBE_CHANNEL(Ila& m);
void CsbWrPpsm_SDP_D_DST_BASE_ADDR_LOW(Ila& m);
void CsbWrPpsm_SDP_D_DST_BASE_ADDR_HIGH(Ila& m);
void CsbWrPpsm_SDP_D_DST_LINE_STRIDE(Ila& m);
void CsbWrPpsm_SDP_D_DST_SURFACE_STRIDE(Ila& m);
void CsbWrPpsm_SDP_D_DP_BS_CFG(Ila& m);
void CsbWrPpsm_SDP_D_DP_BS_ALU_CFG(Ila& m);
void CsbWrPpsm_SDP_D_DP_BS_ALU_SRC_VALUE(Ila& m);
void CsbWrPpsm_SDP_D_DP_BS_MUL_CFG(Ila& m);
void CsbWrPpsm_SDP_D_DP_BS_MUL_SRC_VALUE(Ila& m);
void CsbWrPpsm_SDP_D_DP_BN_CFG(Ila& m);
void CsbWrPpsm_SDP_D_DP_BN_ALU_CFG(Ila& m);
void CsbWrPpsm_SDP_D_DP_BN_ALU_SRC_VALUE(Ila& m);
void CsbWrPpsm_SDP_D_DP_BN_MUL_CFG(Ila& m);
void CsbWrPpsm_SDP_D_DP_BN_MUL_SRC_VALUE(Ila& m);
void CsbWrPpsm_SDP_D_DP_EW_CFG(Ila& m);
void CsbWrPpsm_SDP_D_DP_EW_ALU_CFG(Ila& m);
void CsbWrPpsm_SDP_D_DP_EW_ALU_SRC_VALUE(Ila& m);
void CsbWrPpsm_SDP_D_DP_EW_ALU_CVT_OFFSET_VALUE(Ila& m);
void CsbWrPpsm_SDP_D_DP_EW_ALU_CVT_SCALE_VALUE(Ila& m);
void CsbWrPpsm_SDP_D_DP_EW_ALU_CVT_TRUNCATE_VALUE(Ila& m);
void CsbWrPpsm_SDP_D_DP_EW_MUL_CFG(Ila& m);
void CsbWrPpsm_SDP_D_DP_EW_MUL_SRC_VALUE(Ila& m);
void CsbWrPpsm_SDP_D_DP_EW_MUL_CVT_OFFSET_VALUE(Ila& m);
void CsbWrPpsm_SDP_D_DP_EW_MUL_CVT_SCALE_VALUE(Ila& m);
void CsbWrPpsm_SDP_D_DP_EW_MUL_CVT_TRUNCATE_VALUE(Ila& m);
void CsbWrPpsm_SDP_D_DP_EW_TRUNCATE_VALUE(Ila& m);
void CsbWrPpsm_SDP_D_FEATURE_MODE_CFG(Ila& m);
void CsbWrPpsm_SDP_D_DST_DMA_CFG(Ila& m);
void CsbWrPpsm_SDP_D_DST_BATCH_STRIDE(Ila& m);
void CsbWrPpsm_SDP_D_DATA_FORMAT(Ila& m);
void CsbWrPpsm_SDP_D_CVT_OFFSET(Ila& m);
void CsbWrPpsm_SDP_D_CVT_SCALE(Ila& m);
void CsbWrPpsm_SDP_D_CVT_SHIFT(Ila& m);
void CsbWrPpsm_SDP_D_STATUS(Ila& m);
void CsbWrPpsm_SDP_D_STATUS_NAN_INPUT_NUM(Ila& m);
void CsbWrPpsm_SDP_D_STATUS_INF_INPUT_NUM(Ila& m);
void CsbWrPpsm_SDP_D_STATUS_NAN_OUTPUT_NUM(Ila& m);
void CsbWrPpsm_SDP_D_PERF_ENABLE(Ila& m);
void CsbWrPpsm_SDP_D_PERF_WDMA_WRITE_STALL(Ila& m);
void CsbWrPpsm_SDP_D_PERF_LUT_UFLOW(Ila& m);
void CsbWrPpsm_SDP_D_PERF_LUT_OFLOW(Ila& m);
void CsbWrPpsm_SDP_D_PERF_OUT_SATURATION(Ila& m);
void CsbWrPpsm_SDP_D_PERF_LUT_HYBRID(Ila& m);
void CsbWrPpsm_SDP_D_PERF_LUT_LE_HIT(Ila& m);
void CsbWrPpsm_SDP_D_PERF_LUT_LO_HIT(Ila& m);

}; // namespace ilang

#endif // PPSM_SDP_H__
