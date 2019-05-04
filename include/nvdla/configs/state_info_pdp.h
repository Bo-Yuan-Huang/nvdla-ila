// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: state_info_pdp.h

#ifndef STATE_INFO_PDP_H__
#define STATE_INFO_PDP_H__

#include <nvdla/configs/modeling_config.h>

// namespace ilang
namespace ilang {

// Idle status of two register groups
#define PDP_S_STATUS "pdp_s_status"
#define PDP_S_STATUS_ADDR 0xd000
#define PDP_S_STATUS_BWID ICFG_CSB_DATA_BWID

// Pointer for CSB master and data path to access groups
#define PDP_S_POINTER "pdp_s_pointer"
#define PDP_S_POINTER_ADDR 0xd004
#define PDP_S_POINTER_BWID ICFG_CSB_DATA_BWID

// Set it to 1 to kick off operation for current register group
#define PDP_D_OP_ENABLE_G0 "pdp_d_op_enable_g0"
#define PDP_D_OP_ENABLE_G1 "pdp_d_op_enable_g1"
#define PDP_D_OP_ENABLE_ADDR 0xd008
#define PDP_D_OP_ENABLE_BWID ICFG_CSB_DATA_BWID

// Input data cube’s width
#define PDP_D_DATA_CUBE_IN_WIDTH_G0 "pdp_d_data_cube_in_width_g0"
#define PDP_D_DATA_CUBE_IN_WIDTH_G1 "pdp_d_data_cube_in_width_g1"
#define PDP_D_DATA_CUBE_IN_WIDTH_ADDR 0xd00c
#define PDP_D_DATA_CUBE_IN_WIDTH_BWID ICFG_CSB_DATA_BWID

// Input data cube’s height
#define PDP_D_DATA_CUBE_IN_HEIGHT_G0 "pdp_d_data_cube_in_height_g0"
#define PDP_D_DATA_CUBE_IN_HEIGHT_G1 "pdp_d_data_cube_in_height_g1"
#define PDP_D_DATA_CUBE_IN_HEIGHT_ADDR 0xd010
#define PDP_D_DATA_CUBE_IN_HEIGHT_BWID ICFG_CSB_DATA_BWID

// Input data cube’s channel
#define PDP_D_DATA_CUBE_IN_CHANNEL_G0 "pdp_d_data_cube_in_channel_g0"
#define PDP_D_DATA_CUBE_IN_CHANNEL_G1 "pdp_d_data_cube_in_channel_g1"
#define PDP_D_DATA_CUBE_IN_CHANNEL_ADDR 0xd014
#define PDP_D_DATA_CUBE_IN_CHANNEL_BWID ICFG_CSB_DATA_BWID

// Output data cube’s width
#define PDP_D_DATA_CUBE_OUT_WIDTH_G0 "pdp_d_data_cube_out_width_g0"
#define PDP_D_DATA_CUBE_OUT_WIDTH_G1 "pdp_d_data_cube_out_width_g1"
#define PDP_D_DATA_CUBE_OUT_WIDTH_ADDR 0xd018
#define PDP_D_DATA_CUBE_OUT_WIDTH_BWID ICFG_CSB_DATA_BWID

// Output data cube’s height
#define PDP_D_DATA_CUBE_OUT_HEIGHT_G0 "pdp_d_data_cube_out_height_g0"
#define PDP_D_DATA_CUBE_OUT_HEIGHT_G1 "pdp_d_data_cube_out_height_g1"
#define PDP_D_DATA_CUBE_OUT_HEIGHT_ADDR 0xd01c
#define PDP_D_DATA_CUBE_OUT_HEIGHT_BWID ICFG_CSB_DATA_BWID

// Output data cube’s channel
#define PDP_D_DATA_CUBE_OUT_CHANNEL_G0 "pdp_d_data_cube_out_channel_g0"
#define PDP_D_DATA_CUBE_OUT_CHANNEL_G1 "pdp_d_data_cube_out_channel_g1"
#define PDP_D_DATA_CUBE_OUT_CHANNEL_ADDR 0xd020
#define PDP_D_DATA_CUBE_OUT_CHANNEL_BWID ICFG_CSB_DATA_BWID

// Split number
#define PDP_D_OPERATION_MODE_CFG_G0 "pdp_d_operation_mode_cfg_g0"
#define PDP_D_OPERATION_MODE_CFG_G1 "pdp_d_operation_mode_cfg_g1"
#define PDP_D_OPERATION_MODE_CFG_ADDR 0xd024
#define PDP_D_OPERATION_MODE_CFG_BWID ICFG_CSB_DATA_BWID

// Option to flush input NaN to zero
#define PDP_D_NAN_FLUSH_TO_ZERO_G0 "pdp_d_nan_flush_to_zero_g0"
#define PDP_D_NAN_FLUSH_TO_ZERO_G1 "pdp_d_nan_flush_to_zero_g1"
#define PDP_D_NAN_FLUSH_TO_ZERO_ADDR 0xd028
#define PDP_D_NAN_FLUSH_TO_ZERO_BWID ICFG_CSB_DATA_BWID

// Partial width for first, last and middle partitions of input cube
#define PDP_D_PARTIAL_WIDTH_IN_G0 "pdp_d_partial_width_in_g0"
#define PDP_D_PARTIAL_WIDTH_IN_G1 "pdp_d_partial_width_in_g1"
#define PDP_D_PARTIAL_WIDTH_IN_ADDR 0xd02c
#define PDP_D_PARTIAL_WIDTH_IN_BWID ICFG_CSB_DATA_BWID

// Partial width for first, last and middle partitions of output cube
#define PDP_D_PARTIAL_WIDTH_OUT_G0 "pdp_d_partial_width_out_g0"
#define PDP_D_PARTIAL_WIDTH_OUT_G1 "pdp_d_partial_width_out_g1"
#define PDP_D_PARTIAL_WIDTH_OUT_ADDR 0xd030
#define PDP_D_PARTIAL_WIDTH_OUT_BWID ICFG_CSB_DATA_BWID

// Kernel width and kernel stride
#define PDP_D_POOLING_KERNEL_CFG_G0 "pdp_d_pooling_kernel_cfg_g0"
#define PDP_D_POOLING_KERNEL_CFG_G1 "pdp_d_pooling_kernel_cfg_g1"
#define PDP_D_POOLING_KERNEL_CFG_ADDR 0xd034
#define PDP_D_POOLING_KERNEL_CFG_BWID ICFG_CSB_DATA_BWID

// Reciprocal of pooling kernel width, set to actual value * (2^16) when
// INT8/INT16 format enabled. and set to actual value for fp16 precision mode
// with fp17 data format.
#define PDP_D_RECIP_KERNEL_WIDTH_G0 "pdp_d_recip_kernel_width_g0"
#define PDP_D_RECIP_KERNEL_WIDTH_G1 "pdp_d_recip_kernel_width_g1"
#define PDP_D_RECIP_KERNEL_WIDTH_ADDR 0xd038
#define PDP_D_RECIP_KERNEL_WIDTH_BWID ICFG_CSB_DATA_BWID

// Reciprocal of pooling kernel height, set to actual value * (2^16) when
// INT8/INT16 format enabled. and set to actual value for fp16 precision mode
// with fp17 data format.
#define PDP_D_RECIP_KERNEL_HEIGHT_G0 "pdp_d_recip_kernel_height_g0"
#define PDP_D_RECIP_KERNEL_HEIGHT_G1 "pdp_d_recip_kernel_height_g1"
#define PDP_D_RECIP_KERNEL_HEIGHT_ADDR 0xd03c
#define PDP_D_RECIP_KERNEL_HEIGHT_BWID ICFG_CSB_DATA_BWID

// Left/right/top/bottom padding size
#define PDP_D_POOLING_PADDING_CFG_G0 "pdp_d_pooling_padding_cfg_g0"
#define PDP_D_POOLING_PADDING_CFG_G1 "pdp_d_pooling_padding_cfg_g1"
#define PDP_D_POOLING_PADDING_CFG_ADDR 0xd040
#define PDP_D_POOLING_PADDING_CFG_BWID ICFG_CSB_DATA_BWID

// Padding_value*1
#define PDP_D_POOLING_PADDING_VALUE_1_CFG_G0                                   \
  "pdp_d_pooling_padding_value_1_cfg_g0"
#define PDP_D_POOLING_PADDING_VALUE_1_CFG_G1                                   \
  "pdp_d_pooling_padding_value_1_cfg_g1"
#define PDP_D_POOLING_PADDING_VALUE_1_CFG_ADDR 0xd044
#define PDP_D_POOLING_PADDING_VALUE_1_CFG_BWID ICFG_CSB_DATA_BWID

// Padding_value*2
#define PDP_D_POOLING_PADDING_VALUE_2_CFG_G0                                   \
  "pdp_d_pooling_padding_value_2_cfg_g0"
#define PDP_D_POOLING_PADDING_VALUE_2_CFG_G1                                   \
  "pdp_d_pooling_padding_value_2_cfg_g1"
#define PDP_D_POOLING_PADDING_VALUE_2_CFG_ADDR 0xd048
#define PDP_D_POOLING_PADDING_VALUE_2_CFG_BWID ICFG_CSB_DATA_BWID

// Padding_value*3
#define PDP_D_POOLING_PADDING_VALUE_3_CFG_G0                                   \
  "pdp_d_pooling_padding_value_3_cfg_g0"
#define PDP_D_POOLING_PADDING_VALUE_3_CFG_G1                                   \
  "pdp_d_pooling_padding_value_3_cfg_g1"
#define PDP_D_POOLING_PADDING_VALUE_3_CFG_ADDR 0xd04c
#define PDP_D_POOLING_PADDING_VALUE_3_CFG_BWID ICFG_CSB_DATA_BWID

// Padding_value*4
#define PDP_D_POOLING_PADDING_VALUE_4_CFG_G0                                   \
  "pdp_d_pooling_padding_value_4_cfg_g0"
#define PDP_D_POOLING_PADDING_VALUE_4_CFG_G1                                   \
  "pdp_d_pooling_padding_value_4_cfg_g1"
#define PDP_D_POOLING_PADDING_VALUE_4_CFG_ADDR 0xd050
#define PDP_D_POOLING_PADDING_VALUE_4_CFG_BWID ICFG_CSB_DATA_BWID

// Padding_value*5
#define PDP_D_POOLING_PADDING_VALUE_5_CFG_G0                                   \
  "pdp_d_pooling_padding_value_5_cfg_g0"
#define PDP_D_POOLING_PADDING_VALUE_5_CFG_G1                                   \
  "pdp_d_pooling_padding_value_5_cfg_g1"
#define PDP_D_POOLING_PADDING_VALUE_5_CFG_ADDR 0xd054
#define PDP_D_POOLING_PADDING_VALUE_5_CFG_BWID ICFG_CSB_DATA_BWID

// Padding_value*6
#define PDP_D_POOLING_PADDING_VALUE_6_CFG_G0                                   \
  "pdp_d_pooling_padding_value_6_cfg_g0"
#define PDP_D_POOLING_PADDING_VALUE_6_CFG_G1                                   \
  "pdp_d_pooling_padding_value_6_cfg_g1"
#define PDP_D_POOLING_PADDING_VALUE_6_CFG_ADDR 0xd058
#define PDP_D_POOLING_PADDING_VALUE_6_CFG_BWID ICFG_CSB_DATA_BWID

// Padding_value*7
#define PDP_D_POOLING_PADDING_VALUE_7_CFG_G0                                   \
  "pdp_d_pooling_padding_value_7_cfg_g0"
#define PDP_D_POOLING_PADDING_VALUE_7_CFG_G1                                   \
  "pdp_d_pooling_padding_value_7_cfg_g1"
#define PDP_D_POOLING_PADDING_VALUE_7_CFG_ADDR 0xd05c
#define PDP_D_POOLING_PADDING_VALUE_7_CFG_BWID ICFG_CSB_DATA_BWID

// Lower 32bits of input data address
#define PDP_D_SRC_BASE_ADDR_LOW_G0 "pdp_d_src_base_addr_low_g0"
#define PDP_D_SRC_BASE_ADDR_LOW_G1 "pdp_d_src_base_addr_low_g1"
#define PDP_D_SRC_BASE_ADDR_LOW_ADDR 0xd060
#define PDP_D_SRC_BASE_ADDR_LOW_BWID ICFG_CSB_DATA_BWID

// Higher 32bits of input data address when axi araddr is 64bits
#define PDP_D_SRC_BASE_ADDR_HIGH_G0 "pdp_d_src_base_addr_high_g0"
#define PDP_D_SRC_BASE_ADDR_HIGH_G1 "pdp_d_src_base_addr_high_g1"
#define PDP_D_SRC_BASE_ADDR_HIGH_ADDR 0xd064
#define PDP_D_SRC_BASE_ADDR_HIGH_BWID ICFG_CSB_DATA_BWID

// Line stride of input cube
#define PDP_D_SRC_LINE_STRIDE_G0 "pdp_d_src_line_stride_g0"
#define PDP_D_SRC_LINE_STRIDE_G1 "pdp_d_src_line_stride_g1"
#define PDP_D_SRC_LINE_STRIDE_ADDR 0xd068
#define PDP_D_SRC_LINE_STRIDE_BWID ICFG_CSB_DATA_BWID

// Surface stride of input cube
#define PDP_D_SRC_SURFACE_STRIDE_G0 "pdp_d_src_surface_stride_g0"
#define PDP_D_SRC_SURFACE_STRIDE_G1 "pdp_d_src_surface_stride_g1"
#define PDP_D_SRC_SURFACE_STRIDE_ADDR 0xd06c
#define PDP_D_SRC_SURFACE_STRIDE_BWID ICFG_CSB_DATA_BWID

// Lower 32bits of output data address
#define PDP_D_DST_BASE_ADDR_LOW_G0 "pdp_d_dst_base_addr_low_g0"
#define PDP_D_DST_BASE_ADDR_LOW_G1 "pdp_d_dst_base_addr_low_g1"
#define PDP_D_DST_BASE_ADDR_LOW_ADDR 0xd070
#define PDP_D_DST_BASE_ADDR_LOW_BWID ICFG_CSB_DATA_BWID

// Higher 32bits of output data address when axi awaddr is 64bits
#define PDP_D_DST_BASE_ADDR_HIGH_G0 "pdp_d_dst_base_addr_high_g0"
#define PDP_D_DST_BASE_ADDR_HIGH_G1 "pdp_d_dst_base_addr_high_g1"
#define PDP_D_DST_BASE_ADDR_HIGH_ADDR 0xd074
#define PDP_D_DST_BASE_ADDR_HIGH_BWID ICFG_CSB_DATA_BWID

// Line stride of output cube
#define PDP_D_DST_LINE_STRIDE_G0 "pdp_d_dst_line_stride_g0"
#define PDP_D_DST_LINE_STRIDE_G1 "pdp_d_dst_line_stride_g1"
#define PDP_D_DST_LINE_STRIDE_ADDR 0xd078
#define PDP_D_DST_LINE_STRIDE_BWID ICFG_CSB_DATA_BWID

// Surface stride of output cube
#define PDP_D_DST_SURFACE_STRIDE_G0 "pdp_d_dst_surface_stride_g0"
#define PDP_D_DST_SURFACE_STRIDE_G1 "pdp_d_dst_surface_stride_g1"
#define PDP_D_DST_SURFACE_STRIDE_ADDR 0xd07c
#define PDP_D_DST_SURFACE_STRIDE_BWID ICFG_CSB_DATA_BWID

// RAM type of destination cube
#define PDP_D_DST_RAM_CFG_G0 "pdp_d_dst_ram_cfg_g0"
#define PDP_D_DST_RAM_CFG_G1 "pdp_d_dst_ram_cfg_g1"
#define PDP_D_DST_RAM_CFG_ADDR 0xd080
#define PDP_D_DST_RAM_CFG_BWID ICFG_CSB_DATA_BWID

// Precision of input data
#define PDP_D_DATA_FORMAT_G0 "pdp_d_data_format_g0"
#define PDP_D_DATA_FORMAT_G1 "pdp_d_data_format_g1"
#define PDP_D_DATA_FORMAT_ADDR 0xd084
#define PDP_D_DATA_FORMAT_BWID ICFG_CSB_DATA_BWID

// Input infinity element number
#define PDP_D_INF_INPUT_NUM_G0 "pdp_d_inf_input_num_g0"
#define PDP_D_INF_INPUT_NUM_G1 "pdp_d_inf_input_num_g1"
#define PDP_D_INF_INPUT_NUM_ADDR 0xd088
#define PDP_D_INF_INPUT_NUM_BWID ICFG_CSB_DATA_BWID

// Input NaN element number
#define PDP_D_NAN_INPUT_NUM_G0 "pdp_d_nan_input_num_g0"
#define PDP_D_NAN_INPUT_NUM_G1 "pdp_d_nan_input_num_g1"
#define PDP_D_NAN_INPUT_NUM_ADDR 0xd08c
#define PDP_D_NAN_INPUT_NUM_BWID ICFG_CSB_DATA_BWID

// Output NaN element number
#define PDP_D_NAN_OUTPUT_NUM_G0 "pdp_d_nan_output_num_g0"
#define PDP_D_NAN_OUTPUT_NUM_G1 "pdp_d_nan_output_num_g1"
#define PDP_D_NAN_OUTPUT_NUM_ADDR 0xd090
#define PDP_D_NAN_OUTPUT_NUM_BWID ICFG_CSB_DATA_BWID

// Enable/disable performance counting
#define PDP_D_PERF_ENABLE_G0 "pdp_d_perf_enable_g0"
#define PDP_D_PERF_ENABLE_G1 "pdp_d_perf_enable_g1"
#define PDP_D_PERF_ENABLE_ADDR 0xd094
#define PDP_D_PERF_ENABLE_BWID ICFG_CSB_DATA_BWID

// Counting stalls of write requests
#define PDP_D_PERF_WRITE_STALL_G0 "pdp_d_perf_write_stall_g0"
#define PDP_D_PERF_WRITE_STALL_G1 "pdp_d_perf_write_stall_g1"
#define PDP_D_PERF_WRITE_STALL_ADDR 0xd098
#define PDP_D_PERF_WRITE_STALL_BWID ICFG_CSB_DATA_BWID

}; // namespace ilang

#endif // STATE_INFO_PDP_H__
