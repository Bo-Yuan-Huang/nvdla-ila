// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: state_info_glb.h

#ifndef STATE_INFO_GLB_H__
#define STATE_INFO_GLB_H__

/// \namespace ilang
namespace ilang {

// HW version of NVDLA
#define GLB_HW_VERSION_NAME "glb_hw_version"
#define GLB_HW_VERSION_BWID 32
// Interrupt mask control
#define GLB_INTR_MASK_NAME "glb_intr_mask"
#define GLB_INTR_MASK_BWID 32
// Interrupt set control
#define GLB_INTR_SET_NAME "glb_intr_set"
#define GLB_INTR_SET_BWID 32
// Interrupt status
#define GLB_INTR_STATUS_NAME "glb_intr_status"
#define GLB_INTR_STATUS_BWID 32

}; // namespace ilang

#endif // STATE_INFO_GLB_H__
