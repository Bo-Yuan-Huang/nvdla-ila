// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: ppsm_cacc.h

#ifndef PPSM_CACC_H__
#define PPSM_CACC_H__

#include <ilang/ilang++.h>

// namespace ilang
namespace ilang {

void CsbWrPpsm_CACC_D_OP_ENABLE(Ila& m);
void CsbWrPpsm_CACC_D_MISC_CFG(Ila& m);
void CsbWrPpsm_CACC_D_DATAOUT_SIZE_0(Ila& m);
void CsbWrPpsm_CACC_D_DATAOUT_SIZE_1(Ila& m);
void CsbWrPpsm_CACC_D_DATAOUT_ADDR(Ila& m);
void CsbWrPpsm_CACC_D_BATCH_NUMBER(Ila& m);
void CsbWrPpsm_CACC_D_LINE_STRIDE(Ila& m);
void CsbWrPpsm_CACC_D_SURF_STRIDE(Ila& m);
void CsbWrPpsm_CACC_D_DATAOUT_MAP(Ila& m);
void CsbWrPpsm_CACC_D_CLIP_CFG(Ila& m);
void CsbWrPpsm_CACC_D_OUT_SATURATION(Ila& m);

}; // namespace ilang

#endif // PPSM_CACC_H__
