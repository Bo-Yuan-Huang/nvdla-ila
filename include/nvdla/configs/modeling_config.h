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
//#define ICFG_BOOL_AS_BV

// model AXI protocol
//#define ICFG_AXI_DETAIL

// work in progress comment
#define ICFG_SKIP_TODO

// CSB address bit width
#define ICFG_CSB_ADDR_BWID 16
// CSB register bit width
#define ICFG_CSB_DATA_BWID 32

// bit-width of pointer type
#define ICFG_PTR_BWID ICFG_CSB_ADDR_BWID

// first bit of the "PRODUCER" field in the "POINTER" register
#define ICFG_PPSM_PTR_PRODUCER_BEGIN 0
// last bit of the "PRODUCER" field in the "POINTER" register
#define ICFG_PPSM_PTR_PRODUCER_END ((ICFG_CSB_DATA_BWID / 2) - 1)
// first bit of the "CONSUMER" field in the "POINTER" register
#define ICFG_PPSM_PTR_CONSUMER_BEGIN (ICFG_CSB_DATA_BWID / 2)
// last bit of the "CONSUMER" field in the "POINTER" register
#define ICFG_PPSM_PTR_CONSUMER_END (ICFG_CSB_DATA_BWID - 1)

// first bit of the "group 0 status" field in the "STATUS" register
#define ICFG_PPSM_STATUS_G0_BEGIN 0
// last bit of the "group 0 status" field in the "STATUS" register
#define ICFG_PPSM_STATUS_G0_END ((ICFG_CSB_DATA_BWID / 2) - 1)
// first bit of the "group 1 status" field in the "STATUS" register
#define ICFG_PPSM_STATUS_G1_BEGIN (ICFG_CSB_DATA_BWID / 2)
// last bit of the "group 1 status" field in the "STATUS" register
#define ICFG_PPSM_STATUS_G1_END (ICFG_CSB_DATA_BWID - 1)

}; // namespace ilang

#endif // MODELING_CONFIG_H__

