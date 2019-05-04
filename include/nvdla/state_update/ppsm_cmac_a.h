// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: ppsm_cmac_a.h

#ifndef PPSM_CMAC_A_H__
#define PPSM_CMAC_A_H__

#include <ilang/ilang++.h>

// namespace ilang
namespace ilang {

void CsbWrPpsm_CMAC_A_D_OP_ENABLE(Ila& m);
void CsbWrPpsm_CMAC_A_D_MISC_CFG(Ila& m);

}; // namespace ilang

#endif // PPSM_CMAC_A_H__
