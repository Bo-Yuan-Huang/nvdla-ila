// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: modeling_config.h

#ifndef MODELING_CONFIG_H__
#define MODELING_CONFIG_H__

namespace ilang {

// model Boolean expr as 1-bit bit-vector
//#define MODEL_BOOL_AS_BV

// model AXI protocol
//#define MODEL_AXI_DETAIL

// work in progress comment
#define MODEL_SKIP_TODO

}; // namespace ilang

#endif // MODELING_CONFIG_H__

