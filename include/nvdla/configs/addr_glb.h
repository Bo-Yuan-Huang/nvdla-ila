// File Name: addr_glb.h

#ifndef NVDLA_ADDR_GLB_H__
#define NVDLA_ADDR_GLB_H__

/// \namespace ilang
namespace ilang {

// HW version of NVDLA
#define GLB_HW_VERSION_ADDR 0x0000
// Interrupt mask control
#define GLB_INTR_MASK_ADDR 0x0004
// Interrupt set control
#define GLB_INTR_SET_ADDR 0x0008
// Interrupt status
#define GLB_INTR_STATUS_ADDR 0x000c

}; // namespace ilang

#endif // NVDLA_ADDR_GLB_H__
