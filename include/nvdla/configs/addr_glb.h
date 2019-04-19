// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" wich comes with this distribution for more information.
// ============================================================================

// File Name: addr_glb.h

#ifndef NVDLA_ADDR_GLB_H__
#define NVDLA_ADDR_GLB_H__

/// \namespace ilang
namespace ilang {

// HW version of NVDLA
#define GLB_HW_VERSION 0x0000
// Interrupt mask control
#define GLB_INTR_MASK 0x0004
// Interrupt set control
#define GLB_INTR_SET 0x0008
// Interrupt status
#define GLB_INTR_STATUS 0x000c

}; // namespace ilang

#endif // NVDLA_ADDR_GLB_H__
