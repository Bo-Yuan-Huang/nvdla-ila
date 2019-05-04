// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: ppsm_rubik.h

#ifndef PPSM_RUBIK_H__
#define PPSM_RUBIK_H__

#include <ilang/ilang++.h>

// namespace ilang
namespace ilang {

void CsbWrPpsm_RUBIK_D_OP_ENABLE(Ila& m);
void CsbWrPpsm_RUBIK_D_MISC_CFG(Ila& m);
void CsbWrPpsm_RUBIK_D_DAIN_RAM_TYPE(Ila& m);
void CsbWrPpsm_RUBIK_D_DATAIN_SIZE_0(Ila& m);
void CsbWrPpsm_RUBIK_D_DATAIN_SIZE_1(Ila& m);
void CsbWrPpsm_RUBIK_D_DAIN_ADDR_HIGH(Ila& m);
void CsbWrPpsm_RUBIK_D_DAIN_ADDR_LOW(Ila& m);
void CsbWrPpsm_RUBIK_D_DAIN_LINE_STRIDE(Ila& m);
void CsbWrPpsm_RUBIK_D_DAIN_SURF_STRIDE(Ila& m);
void CsbWrPpsm_RUBIK_D_DAIN_PLANAR_STRIDE(Ila& m);
void CsbWrPpsm_RUBIK_D_DAOUT_RAM_TYPE(Ila& m);
void CsbWrPpsm_RUBIK_D_DATAOUT_SIZE_1(Ila& m);
void CsbWrPpsm_RUBIK_D_DAOUT_ADDR_HIGH(Ila& m);
void CsbWrPpsm_RUBIK_D_DAOUT_ADDR_LOW(Ila& m);
void CsbWrPpsm_RUBIK_D_DAOUT_LINE_STRIDE(Ila& m);
void CsbWrPpsm_RUBIK_D_CONTRACT_STRIDE_0(Ila& m);
void CsbWrPpsm_RUBIK_D_CONTRACT_STRIDE_1(Ila& m);
void CsbWrPpsm_RUBIK_D_DAOUT_SURF_STRIDE(Ila& m);
void CsbWrPpsm_RUBIK_D_DAOUT_PLANAR_STRIDE(Ila& m);
void CsbWrPpsm_RUBIK_D_DECONV_STRIDE(Ila& m);
void CsbWrPpsm_RUBIK_D_PERF_ENABLE(Ila& m);
void CsbWrPpsm_RUBIK_D_PERF_READ_STALL(Ila& m);
void CsbWrPpsm_RUBIK_D_PERF_WRITE_STALL(Ila& m);

}; // namespace ilang

#endif // PPSM_RUBIK_H__
