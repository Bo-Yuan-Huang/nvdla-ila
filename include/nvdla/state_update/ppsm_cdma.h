// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: ppsm_cdma.h

#ifndef PPSM_CDMA_H__
#define PPSM_CDMA_H__

#include <ilang/ilang++.h>

// namespace ilang
namespace ilang {

void CsbWrPpsm_CDMA_D_OP_ENABLE(Ila& m);
void CsbWrPpsm_CDMA_D_MISC_CFG(Ila& m);
void CsbWrPpsm_CDMA_D_DATAIN_FORMAT(Ila& m);
void CsbWrPpsm_CDMA_D_DATAIN_SIZE_0(Ila& m);
void CsbWrPpsm_CDMA_D_DATAIN_SIZE_1(Ila& m);
void CsbWrPpsm_CDMA_D_DATAIN_SIZE_EXT_0(Ila& m);
void CsbWrPpsm_CDMA_D_PIXEL_OFFSET(Ila& m);
void CsbWrPpsm_CDMA_D_DAIN_RAM_TYPE(Ila& m);
void CsbWrPpsm_CDMA_D_DAIN_ADDR_HIGH_0(Ila& m);
void CsbWrPpsm_CDMA_D_DAIN_ADDR_LOW_0(Ila& m);
void CsbWrPpsm_CDMA_D_DAIN_ADDR_HIGH_1(Ila& m);
void CsbWrPpsm_CDMA_D_DAIN_ADDR_LOW_1(Ila& m);
void CsbWrPpsm_CDMA_D_LINE_STRIDE(Ila& m);
void CsbWrPpsm_CDMA_D_LINE_UV_STRIDE(Ila& m);
void CsbWrPpsm_CDMA_D_SURF_STRIDE(Ila& m);
void CsbWrPpsm_CDMA_D_DAIN_MAP(Ila& m);
void CsbWrPpsm_CDMA_D_BATCH_NUMBER(Ila& m);
void CsbWrPpsm_CDMA_D_BATCH_STRIDE(Ila& m);
void CsbWrPpsm_CDMA_D_ENTRY_PER_SLICE(Ila& m);
void CsbWrPpsm_CDMA_D_FETCH_GRAIN(Ila& m);
void CsbWrPpsm_CDMA_D_WEIGHT_FORMAT(Ila& m);
void CsbWrPpsm_CDMA_D_WEIGHT_SIZE_0(Ila& m);
void CsbWrPpsm_CDMA_D_WEIGHT_SIZE_1(Ila& m);
void CsbWrPpsm_CDMA_D_WEIGHT_RAM_TYPE(Ila& m);
void CsbWrPpsm_CDMA_D_WEIGHT_ADDR_HIGH(Ila& m);
void CsbWrPpsm_CDMA_D_WEIGHT_ADDR_LOW(Ila& m);
void CsbWrPpsm_CDMA_D_WEIGHT_BYTES(Ila& m);
void CsbWrPpsm_CDMA_D_WGS_ADDR_HIGH(Ila& m);
void CsbWrPpsm_CDMA_D_WGS_ADDR_LOW(Ila& m);
void CsbWrPpsm_CDMA_D_WMB_ADDR_HIGH(Ila& m);
void CsbWrPpsm_CDMA_D_WMB_ADDR_LOW(Ila& m);
void CsbWrPpsm_CDMA_D_WMB_BYTES(Ila& m);
void CsbWrPpsm_CDMA_D_MEAN_FORMAT(Ila& m);
void CsbWrPpsm_CDMA_D_MEAN_GLOBAL_0(Ila& m);
void CsbWrPpsm_CDMA_D_MEAN_GLOBAL_1(Ila& m);
void CsbWrPpsm_CDMA_D_CVT_CFG(Ila& m);
void CsbWrPpsm_CDMA_D_CVT_OFFSET(Ila& m);
void CsbWrPpsm_CDMA_D_CVT_SCALE(Ila& m);
void CsbWrPpsm_CDMA_D_CONV_STRIDE(Ila& m);
void CsbWrPpsm_CDMA_D_ZERO_PADDING(Ila& m);
void CsbWrPpsm_CDMA_D_ZERO_PADDING_VALUE(Ila& m);
void CsbWrPpsm_CDMA_D_BANK(Ila& m);
void CsbWrPpsm_CDMA_D_NAN_FLUSH_TO_ZERO(Ila& m);
void CsbWrPpsm_CDMA_D_NAN_INPUT_DATA_NUM(Ila& m);
void CsbWrPpsm_CDMA_D_NAN_INPUT_WEIGHT_NUM(Ila& m);
void CsbWrPpsm_CDMA_D_INF_INPUT_DATA_NUM(Ila& m);
void CsbWrPpsm_CDMA_D_INF_INPUT_WEIGHT_NUM(Ila& m);
void CsbWrPpsm_CDMA_D_PERF_ENABLE(Ila& m);
void CsbWrPpsm_CDMA_D_PERF_DAT_READ_STALL(Ila& m);
void CsbWrPpsm_CDMA_D_PERF_WT_READ_STALL(Ila& m);
void CsbWrPpsm_CDMA_D_PERF_DAT_READ_LATENCY(Ila& m);
void CsbWrPpsm_CDMA_D_PERF_WT_READ_LATENCY(Ila& m);

}; // namespace ilang

#endif // PPSM_CDMA_H__
