// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: addr_cacc.h

#ifndef NVDLA_ADDR_CACC_H__
#define NVDLA_ADDR_CACC_H__

/// \namespace ilang
namespace ilang {

// Idle status of two register groups
#define CACC_S_STATUS_ADDR 0x9000
// Pointer for CSB master and data path to access groups
#define CACC_S_POINTER_ADDR 0x9004
// Set it to 1 to kick off operation for current register group
#define CACC_D_OP_ENABLE_ADDR 0x9008
// Configuration of operation: convolution mode, precision, etc.
#define CACC_D_MISC_CFG_ADDR 0x900c
// Input cube’s width and height after extension
#define CACC_D_DATAOUT_SIZE_0_ADDR 0x9010
// Input cube’s channel after extension
#define CACC_D_DATAOUT_SIZE_1_ADDR 0x9014
// Address of output cube
#define CACC_D_DATAOUT_ADDR_ADDR 0x9018
// Number of batches
#define CACC_D_BATCH_NUMBER_ADDR 0x901c
// Line stride of output cube
#define CACC_D_LINE_STRIDE_ADDR 0x9020
// Line stride of surface cube
#define CACC_D_SURF_STRIDE_ADDR 0x9024
// Whether output cube is line packed or surface packed
#define CACC_D_DATAOUT_MAP_ADDR 0x9028
// Number of bits to be truncated before sending to SDP
#define CACC_D_CLIP_CFG_ADDR 0x902c
// Output saturation count
#define CACC_D_OUT_SATURATION_ADDR 0x9030

}; // namespace ilang

#endif // NVDLA_ADDR_CACC_H__
