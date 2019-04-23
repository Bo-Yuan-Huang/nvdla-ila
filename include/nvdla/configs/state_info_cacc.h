// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: state_info_cacc.h

#ifndef STATE_INFO_CACC_H__
#define STATE_INFO_CACC_H__

// namespace ilang
namespace ilang {

// Idle status of two register groups
#define CACC_S_STATUS "cacc_s_status"
#define CACC_S_STATUS_ADDR 0x9000
#define CACC_S_STATUS_BWID 32

// Pointer for CSB master and data path to access groups
#define CACC_S_POINTER "cacc_s_pointer"
#define CACC_S_POINTER_ADDR 0x9004
#define CACC_S_POINTER_BWID 32

// Set it to 1 to kick off operation for current register group
#define CACC_D_OP_ENABLE "cacc_d_op_enable"
#define CACC_D_OP_ENABLE_ADDR 0x9008
#define CACC_D_OP_ENABLE_BWID 32

// Configuration of operation: convolution mode, precision, etc.
#define CACC_D_MISC_CFG "cacc_d_misc_cfg"
#define CACC_D_MISC_CFG_ADDR 0x900c
#define CACC_D_MISC_CFG_BWID 32

// Input cube’s width and height after extension
#define CACC_D_DATAOUT_SIZE_0 "cacc_d_dataout_size_0"
#define CACC_D_DATAOUT_SIZE_0_ADDR 0x9010
#define CACC_D_DATAOUT_SIZE_0_BWID 32

// Input cube’s channel after extension
#define CACC_D_DATAOUT_SIZE_1 "cacc_d_dataout_size_1"
#define CACC_D_DATAOUT_SIZE_1_ADDR 0x9014
#define CACC_D_DATAOUT_SIZE_1_BWID 32

// Address of output cube
#define CACC_D_DATAOUT_ADDR "cacc_d_dataout_addr"
#define CACC_D_DATAOUT_ADDR_ADDR 0x9018
#define CACC_D_DATAOUT_ADDR_BWID 32

// Number of batches
#define CACC_D_BATCH_NUMBER "cacc_d_batch_number"
#define CACC_D_BATCH_NUMBER_ADDR 0x901c
#define CACC_D_BATCH_NUMBER_BWID 32

// Line stride of output cube
#define CACC_D_LINE_STRIDE "cacc_d_line_stride"
#define CACC_D_LINE_STRIDE_ADDR 0x9020
#define CACC_D_LINE_STRIDE_BWID 32

// Line stride of surface cube
#define CACC_D_SURF_STRIDE "cacc_d_surf_stride"
#define CACC_D_SURF_STRIDE_ADDR 0x9024
#define CACC_D_SURF_STRIDE_BWID 32

// Whether output cube is line packed or surface packed
#define CACC_D_DATAOUT_MAP "cacc_d_dataout_map"
#define CACC_D_DATAOUT_MAP_ADDR 0x9028
#define CACC_D_DATAOUT_MAP_BWID 32

// Number of bits to be truncated before sending to SDP
#define CACC_D_CLIP_CFG "cacc_d_clip_cfg"
#define CACC_D_CLIP_CFG_ADDR 0x902c
#define CACC_D_CLIP_CFG_BWID 32

// Output saturation count
#define CACC_D_OUT_SATURATION "cacc_d_out_saturation"
#define CACC_D_OUT_SATURATION_ADDR 0x9030
#define CACC_D_OUT_SATURATION_BWID 32

}; // namespace ilang

#endif // STATE_INFO_CACC_H__
