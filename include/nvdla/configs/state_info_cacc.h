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

#include <nvdla/configs/modeling_config.h>

// namespace ilang
namespace ilang {

// Idle status of two register groups
#define CACC_S_STATUS "cacc_s_status"
#define CACC_S_STATUS_ADDR 0x9000
#define CACC_S_STATUS_BWID ICFG_CSB_DATA_BWID

// Pointer for CSB master and data path to access groups
#define CACC_S_POINTER "cacc_s_pointer"
#define CACC_S_POINTER_ADDR 0x9004
#define CACC_S_POINTER_BWID ICFG_CSB_DATA_BWID

// Set it to 1 to kick off operation for current register group
#define CACC_D_OP_ENABLE_G0 "cacc_d_op_enable_g0"
#define CACC_D_OP_ENABLE_G1 "cacc_d_op_enable_g1"
#define CACC_D_OP_ENABLE_ADDR 0x9008
#define CACC_D_OP_ENABLE_BWID ICFG_CSB_DATA_BWID

// Configuration of operation: convolution mode, precision, etc.
#define CACC_D_MISC_CFG_G0 "cacc_d_misc_cfg_g0"
#define CACC_D_MISC_CFG_G1 "cacc_d_misc_cfg_g1"
#define CACC_D_MISC_CFG_ADDR 0x900c
#define CACC_D_MISC_CFG_BWID ICFG_CSB_DATA_BWID

// Input cube’s width and height after extension
#define CACC_D_DATAOUT_SIZE_0_G0 "cacc_d_dataout_size_0_g0"
#define CACC_D_DATAOUT_SIZE_0_G1 "cacc_d_dataout_size_0_g1"
#define CACC_D_DATAOUT_SIZE_0_ADDR 0x9010
#define CACC_D_DATAOUT_SIZE_0_BWID ICFG_CSB_DATA_BWID

// Input cube’s channel after extension
#define CACC_D_DATAOUT_SIZE_1_G0 "cacc_d_dataout_size_1_g0"
#define CACC_D_DATAOUT_SIZE_1_G1 "cacc_d_dataout_size_1_g1"
#define CACC_D_DATAOUT_SIZE_1_ADDR 0x9014
#define CACC_D_DATAOUT_SIZE_1_BWID ICFG_CSB_DATA_BWID

// Address of output cube
#define CACC_D_DATAOUT_ADDR_G0 "cacc_d_dataout_addr_g0"
#define CACC_D_DATAOUT_ADDR_G1 "cacc_d_dataout_addr_g1"
#define CACC_D_DATAOUT_ADDR_ADDR 0x9018
#define CACC_D_DATAOUT_ADDR_BWID ICFG_CSB_DATA_BWID

// Number of batches
#define CACC_D_BATCH_NUMBER_G0 "cacc_d_batch_number_g0"
#define CACC_D_BATCH_NUMBER_G1 "cacc_d_batch_number_g1"
#define CACC_D_BATCH_NUMBER_ADDR 0x901c
#define CACC_D_BATCH_NUMBER_BWID ICFG_CSB_DATA_BWID

// Line stride of output cube
#define CACC_D_LINE_STRIDE_G0 "cacc_d_line_stride_g0"
#define CACC_D_LINE_STRIDE_G1 "cacc_d_line_stride_g1"
#define CACC_D_LINE_STRIDE_ADDR 0x9020
#define CACC_D_LINE_STRIDE_BWID ICFG_CSB_DATA_BWID

// Line stride of surface cube
#define CACC_D_SURF_STRIDE_G0 "cacc_d_surf_stride_g0"
#define CACC_D_SURF_STRIDE_G1 "cacc_d_surf_stride_g1"
#define CACC_D_SURF_STRIDE_ADDR 0x9024
#define CACC_D_SURF_STRIDE_BWID ICFG_CSB_DATA_BWID

// Whether output cube is line packed or surface packed
#define CACC_D_DATAOUT_MAP_G0 "cacc_d_dataout_map_g0"
#define CACC_D_DATAOUT_MAP_G1 "cacc_d_dataout_map_g1"
#define CACC_D_DATAOUT_MAP_ADDR 0x9028
#define CACC_D_DATAOUT_MAP_BWID ICFG_CSB_DATA_BWID

// Number of bits to be truncated before sending to SDP
#define CACC_D_CLIP_CFG_G0 "cacc_d_clip_cfg_g0"
#define CACC_D_CLIP_CFG_G1 "cacc_d_clip_cfg_g1"
#define CACC_D_CLIP_CFG_ADDR 0x902c
#define CACC_D_CLIP_CFG_BWID ICFG_CSB_DATA_BWID

// Output saturation count
#define CACC_D_OUT_SATURATION_G0 "cacc_d_out_saturation_g0"
#define CACC_D_OUT_SATURATION_G1 "cacc_d_out_saturation_g1"
#define CACC_D_OUT_SATURATION_ADDR 0x9030
#define CACC_D_OUT_SATURATION_BWID ICFG_CSB_DATA_BWID

}; // namespace ilang

#endif // STATE_INFO_CACC_H__
