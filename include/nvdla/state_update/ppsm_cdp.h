// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: ppsm_cdp.h

#ifndef PPSM_CDP_H__
#define PPSM_CDP_H__

#include <ilang/ilang++.h>

// namespace ilang
namespace ilang {

void CsbWrPpsm_CDP_D_OP_ENABLE(Ila& m);
void CsbWrPpsm_CDP_D_FUNC_BYPASS(Ila& m);
void CsbWrPpsm_CDP_D_DST_BASE_ADDR_LOW(Ila& m);
void CsbWrPpsm_CDP_D_DST_BASE_ADDR_HIGH(Ila& m);
void CsbWrPpsm_CDP_D_DST_LINE_STRIDE(Ila& m);
void CsbWrPpsm_CDP_D_DST_SURFACE_STRIDE(Ila& m);
void CsbWrPpsm_CDP_D_DST_DMA_CFG(Ila& m);
void CsbWrPpsm_CDP_D_DST_COMPRESSION_EN(Ila& m);
void CsbWrPpsm_CDP_D_DATA_FORMAT(Ila& m);
void CsbWrPpsm_CDP_D_NAN_FLUSH_TO_ZERO(Ila& m);
void CsbWrPpsm_CDP_D_LRN_CFG(Ila& m);
void CsbWrPpsm_CDP_D_DATIN_OFFSET(Ila& m);
void CsbWrPpsm_CDP_D_DATIN_SCALE(Ila& m);
void CsbWrPpsm_CDP_D_DATIN_SHIFTER(Ila& m);
void CsbWrPpsm_CDP_D_DATOUT_OFFSET(Ila& m);
void CsbWrPpsm_CDP_D_DATOUT_SCALE(Ila& m);
void CsbWrPpsm_CDP_D_DATOUT_SHIFTER(Ila& m);
void CsbWrPpsm_CDP_D_NAN_INPUT_NUM(Ila& m);
void CsbWrPpsm_CDP_D_INF_INPUT_NUM(Ila& m);
void CsbWrPpsm_CDP_D_NAN_OUTPUT_NUM(Ila& m);
void CsbWrPpsm_CDP_D_OUT_SATURATION(Ila& m);
void CsbWrPpsm_CDP_D_PERF_ENABLE(Ila& m);
void CsbWrPpsm_CDP_D_PERF_WRITE_STALL(Ila& m);
void CsbWrPpsm_CDP_D_PERF_LUT_UFLOW(Ila& m);
void CsbWrPpsm_CDP_D_PERF_LUT_OFLOW(Ila& m);
void CsbWrPpsm_CDP_D_PERF_LUT_HYBRID(Ila& m);
void CsbWrPpsm_CDP_D_PERF_LUT_LE_HIT(Ila& m);
void CsbWrPpsm_CDP_D_PERF_LUT_LO_HIT(Ila& m);

}; // namespace ilang

#endif // PPSM_CDP_H__
