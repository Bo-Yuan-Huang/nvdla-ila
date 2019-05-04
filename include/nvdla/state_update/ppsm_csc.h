// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: ppsm_csc.h

#ifndef PPSM_CSC_H__
#define PPSM_CSC_H__

#include <ilang/ilang++.h>

// namespace ilang
namespace ilang {

void CsbWrPpsm_CSC_D_OP_ENABLE(Ila& m);
void CsbWrPpsm_CSC_D_MISC_CFG(Ila& m);
void CsbWrPpsm_CSC_D_DATAIN_FORMAT(Ila& m);
void CsbWrPpsm_CSC_D_DATAIN_SIZE_EXT_0(Ila& m);
void CsbWrPpsm_CSC_D_DATAIN_SIZE_EXT_1(Ila& m);
void CsbWrPpsm_CSC_D_BATCH_NUMBER(Ila& m);
void CsbWrPpsm_CSC_D_POST_Y_EXTENSION(Ila& m);
void CsbWrPpsm_CSC_D_ENTRY_PER_SLICE(Ila& m);
void CsbWrPpsm_CSC_D_WEIGHT_FORMAT(Ila& m);
void CsbWrPpsm_CSC_D_WEIGHT_SIZE_EXT_0(Ila& m);
void CsbWrPpsm_CSC_D_WEIGHT_SIZE_EXT_1(Ila& m);
void CsbWrPpsm_CSC_D_WEIGHT_BYTES(Ila& m);
void CsbWrPpsm_CSC_D_WMB_BYTES(Ila& m);
void CsbWrPpsm_CSC_D_DATAOUT_SIZE_0(Ila& m);
void CsbWrPpsm_CSC_D_DATAOUT_SIZE_1(Ila& m);
void CsbWrPpsm_CSC_D_ATOMICS(Ila& m);
void CsbWrPpsm_CSC_D_RELEASE(Ila& m);
void CsbWrPpsm_CSC_D_CONV_STRIDE_EXT(Ila& m);
void CsbWrPpsm_CSC_D_DILATION_EXT(Ila& m);
void CsbWrPpsm_CSC_D_ZERO_PADDING(Ila& m);
void CsbWrPpsm_CSC_D_ZERO_PADDING_VALUE(Ila& m);
void CsbWrPpsm_CSC_D_BANK(Ila& m);
void CsbWrPpsm_CSC_D_PRA_CFG(Ila& m);

}; // namespace ilang

#endif // PPSM_CSC_H__
