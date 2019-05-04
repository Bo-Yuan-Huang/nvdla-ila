// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: state_info_cdp.h

#ifndef STATE_INFO_CDP_H__
#define STATE_INFO_CDP_H__

#include <nvdla/configs/modeling_config.h>

// namespace ilang
namespace ilang {

// Idle status of two register groups
#define CDP_S_STATUS "cdp_s_status"
#define CDP_S_STATUS_ADDR 0xf000
#define CDP_S_STATUS_BWID ICFG_CSB_DATA_BWID

// Pointer for CSB master and data path to access groups
#define CDP_S_POINTER "cdp_s_pointer"
#define CDP_S_POINTER_ADDR 0xf004
#define CDP_S_POINTER_BWID ICFG_CSB_DATA_BWID

// LUT access address and type
#define CDP_S_LUT_ACCESS_CFG "cdp_s_lut_access_cfg"
#define CDP_S_LUT_ACCESS_CFG_ADDR 0xf008
#define CDP_S_LUT_ACCESS_CFG_BWID ICFG_CSB_DATA_BWID

// Data register of read or write LUT
#define CDP_S_LUT_ACCESS_DATA "cdp_s_lut_access_data"
#define CDP_S_LUT_ACCESS_DATA_ADDR 0xf00c
#define CDP_S_LUT_ACCESS_DATA_BWID ICFG_CSB_DATA_BWID

// LUT’s type: exponent or linear. And the selection between LE and LO tables.
#define CDP_S_LUT_CFG "cdp_s_lut_cfg"
#define CDP_S_LUT_CFG_ADDR 0xf010
#define CDP_S_LUT_CFG_BWID ICFG_CSB_DATA_BWID

// LE and LO LUT index offset and selection
#define CDP_S_LUT_INFO "cdp_s_lut_info"
#define CDP_S_LUT_INFO_ADDR 0xf014
#define CDP_S_LUT_INFO_BWID ICFG_CSB_DATA_BWID

// Lower 32bits of start of LE LUT’s range
#define CDP_S_LUT_LE_START_LOW "cdp_s_lut_le_start_low"
#define CDP_S_LUT_LE_START_LOW_ADDR 0xf018
#define CDP_S_LUT_LE_START_LOW_BWID ICFG_CSB_DATA_BWID

// Higher 6bits of start of LE LUT’s range
#define CDP_S_LUT_LE_START_HIGH "cdp_s_lut_le_start_high"
#define CDP_S_LUT_LE_START_HIGH_ADDR 0xf01c
#define CDP_S_LUT_LE_START_HIGH_BWID ICFG_CSB_DATA_BWID

// Lower 32bits of end of LE LUT’s range
#define CDP_S_LUT_LE_END_LOW "cdp_s_lut_le_end_low"
#define CDP_S_LUT_LE_END_LOW_ADDR 0xf020
#define CDP_S_LUT_LE_END_LOW_BWID ICFG_CSB_DATA_BWID

// Higher 6bits of end of LE LUT’s range
#define CDP_S_LUT_LE_END_HIGH "cdp_s_lut_le_end_high"
#define CDP_S_LUT_LE_END_HIGH_ADDR 0xf024
#define CDP_S_LUT_LE_END_HIGH_BWID ICFG_CSB_DATA_BWID

// Lower 32bits of start of LO LUT’s range
#define CDP_S_LUT_LO_START_LOW "cdp_s_lut_lo_start_low"
#define CDP_S_LUT_LO_START_LOW_ADDR 0xf028
#define CDP_S_LUT_LO_START_LOW_BWID ICFG_CSB_DATA_BWID

// Higher 6bits of start of LO LUT’s range
#define CDP_S_LUT_LO_START_HIGH "cdp_s_lut_lo_start_high"
#define CDP_S_LUT_LO_START_HIGH_ADDR 0xf02c
#define CDP_S_LUT_LO_START_HIGH_BWID ICFG_CSB_DATA_BWID

// Lower 32bits of end of LO LUT’s range
#define CDP_S_LUT_LO_END_LOW "cdp_s_lut_lo_end_low"
#define CDP_S_LUT_LO_END_LOW_ADDR 0xf030
#define CDP_S_LUT_LO_END_LOW_BWID ICFG_CSB_DATA_BWID

// Higher 6bits of end of LO LUT’s range
#define CDP_S_LUT_LO_END_HIGH "cdp_s_lut_lo_end_high"
#define CDP_S_LUT_LO_END_HIGH_ADDR 0xf034
#define CDP_S_LUT_LO_END_HIGH_BWID ICFG_CSB_DATA_BWID

// Slope scale parameter for LE LUT underflow and overflow, signed value
#define CDP_S_LUT_LE_SLOPE_SCALE "cdp_s_lut_le_slope_scale"
#define CDP_S_LUT_LE_SLOPE_SCALE_ADDR 0xf038
#define CDP_S_LUT_LE_SLOPE_SCALE_BWID ICFG_CSB_DATA_BWID

// Slope shift parameter for LE_LUT underflow and overflow, signed value
#define CDP_S_LUT_LE_SLOPE_SHIFT "cdp_s_lut_le_slope_shift"
#define CDP_S_LUT_LE_SLOPE_SHIFT_ADDR 0xf03c
#define CDP_S_LUT_LE_SLOPE_SHIFT_BWID ICFG_CSB_DATA_BWID

// Slope scale parameter for LO LUT underflow and overflow, signed value
#define CDP_S_LUT_LO_SLOPE_SCALE "cdp_s_lut_lo_slope_scale"
#define CDP_S_LUT_LO_SLOPE_SCALE_ADDR 0xf040
#define CDP_S_LUT_LO_SLOPE_SCALE_BWID ICFG_CSB_DATA_BWID

// Slope shift parameter for LO_LUT underflow and overflow, signed value
#define CDP_S_LUT_LO_SLOPE_SHIFT "cdp_s_lut_lo_slope_shift"
#define CDP_S_LUT_LO_SLOPE_SHIFT_ADDR 0xf044
#define CDP_S_LUT_LO_SLOPE_SHIFT_BWID ICFG_CSB_DATA_BWID

// Set it to 1 to kick off operation for current register group
#define CDP_D_OP_ENABLE_G0 "cdp_d_op_enable_g0"
#define CDP_D_OP_ENABLE_G1 "cdp_d_op_enable_g1"
#define CDP_D_OP_ENABLE_ADDR 0xf048
#define CDP_D_OP_ENABLE_BWID ICFG_CSB_DATA_BWID

// Square sum process bypass control and multiplier after interpolator bypass
// control
#define CDP_D_FUNC_BYPASS_G0 "cdp_d_func_bypass_g0"
#define CDP_D_FUNC_BYPASS_G1 "cdp_d_func_bypass_g1"
#define CDP_D_FUNC_BYPASS_ADDR 0xf04c
#define CDP_D_FUNC_BYPASS_BWID ICFG_CSB_DATA_BWID

// Lower 32bits of output data address
#define CDP_D_DST_BASE_ADDR_LOW_G0 "cdp_d_dst_base_addr_low_g0"
#define CDP_D_DST_BASE_ADDR_LOW_G1 "cdp_d_dst_base_addr_low_g1"
#define CDP_D_DST_BASE_ADDR_LOW_ADDR 0xf050
#define CDP_D_DST_BASE_ADDR_LOW_BWID ICFG_CSB_DATA_BWID

// Higher 32bits of output data address when axi awaddr is 64bits
#define CDP_D_DST_BASE_ADDR_HIGH_G0 "cdp_d_dst_base_addr_high_g0"
#define CDP_D_DST_BASE_ADDR_HIGH_G1 "cdp_d_dst_base_addr_high_g1"
#define CDP_D_DST_BASE_ADDR_HIGH_ADDR 0xf054
#define CDP_D_DST_BASE_ADDR_HIGH_BWID ICFG_CSB_DATA_BWID

// Line stride of output cube
#define CDP_D_DST_LINE_STRIDE_G0 "cdp_d_dst_line_stride_g0"
#define CDP_D_DST_LINE_STRIDE_G1 "cdp_d_dst_line_stride_g1"
#define CDP_D_DST_LINE_STRIDE_ADDR 0xf058
#define CDP_D_DST_LINE_STRIDE_BWID ICFG_CSB_DATA_BWID

// Surface stride of output cube
#define CDP_D_DST_SURFACE_STRIDE_G0 "cdp_d_dst_surface_stride_g0"
#define CDP_D_DST_SURFACE_STRIDE_G1 "cdp_d_dst_surface_stride_g1"
#define CDP_D_DST_SURFACE_STRIDE_ADDR 0xf05c
#define CDP_D_DST_SURFACE_STRIDE_BWID ICFG_CSB_DATA_BWID

// RAM type of output data cube
#define CDP_D_DST_DMA_CFG_G0 "cdp_d_dst_dma_cfg_g0"
#define CDP_D_DST_DMA_CFG_G1 "cdp_d_dst_dma_cfg_g1"
#define CDP_D_DST_DMA_CFG_ADDR 0xf060
#define CDP_D_DST_DMA_CFG_BWID ICFG_CSB_DATA_BWID

// This register is not used in OpenDLA 1.0
#define CDP_D_DST_COMPRESSION_EN_G0 "cdp_d_dst_compression_en_g0"
#define CDP_D_DST_COMPRESSION_EN_G1 "cdp_d_dst_compression_en_g1"
#define CDP_D_DST_COMPRESSION_EN_ADDR 0xf064
#define CDP_D_DST_COMPRESSION_EN_BWID ICFG_CSB_DATA_BWID

// Precision of input data
#define CDP_D_DATA_FORMAT_G0 "cdp_d_data_format_g0"
#define CDP_D_DATA_FORMAT_G1 "cdp_d_data_format_g1"
#define CDP_D_DATA_FORMAT_ADDR 0xf068
#define CDP_D_DATA_FORMAT_BWID ICFG_CSB_DATA_BWID

// Option to flush input NaN to zero
#define CDP_D_NAN_FLUSH_TO_ZERO_G0 "cdp_d_nan_flush_to_zero_g0"
#define CDP_D_NAN_FLUSH_TO_ZERO_G1 "cdp_d_nan_flush_to_zero_g1"
#define CDP_D_NAN_FLUSH_TO_ZERO_ADDR 0xf06c
#define CDP_D_NAN_FLUSH_TO_ZERO_BWID ICFG_CSB_DATA_BWID

// Normalization length
#define CDP_D_LRN_CFG_G0 "cdp_d_lrn_cfg_g0"
#define CDP_D_LRN_CFG_G1 "cdp_d_lrn_cfg_g1"
#define CDP_D_LRN_CFG_ADDR 0xf070
#define CDP_D_LRN_CFG_BWID ICFG_CSB_DATA_BWID

// Input data convertor offset
#define CDP_D_DATIN_OFFSET_G0 "cdp_d_datin_offset_g0"
#define CDP_D_DATIN_OFFSET_G1 "cdp_d_datin_offset_g1"
#define CDP_D_DATIN_OFFSET_ADDR 0xf074
#define CDP_D_DATIN_OFFSET_BWID ICFG_CSB_DATA_BWID

// Input data convertor scale
#define CDP_D_DATIN_SCALE_G0 "cdp_d_datin_scale_g0"
#define CDP_D_DATIN_SCALE_G1 "cdp_d_datin_scale_g1"
#define CDP_D_DATIN_SCALE_ADDR 0xf078
#define CDP_D_DATIN_SCALE_BWID ICFG_CSB_DATA_BWID

// Input data convertor shifter value
#define CDP_D_DATIN_SHIFTER_G0 "cdp_d_datin_shifter_g0"
#define CDP_D_DATIN_SHIFTER_G1 "cdp_d_datin_shifter_g1"
#define CDP_D_DATIN_SHIFTER_ADDR 0xf07c
#define CDP_D_DATIN_SHIFTER_BWID ICFG_CSB_DATA_BWID

// Output data convertor offset
#define CDP_D_DATOUT_OFFSET_G0 "cdp_d_datout_offset_g0"
#define CDP_D_DATOUT_OFFSET_G1 "cdp_d_datout_offset_g1"
#define CDP_D_DATOUT_OFFSET_ADDR 0xf080
#define CDP_D_DATOUT_OFFSET_BWID ICFG_CSB_DATA_BWID

// Output data convertor scale
#define CDP_D_DATOUT_SCALE_G0 "cdp_d_datout_scale_g0"
#define CDP_D_DATOUT_SCALE_G1 "cdp_d_datout_scale_g1"
#define CDP_D_DATOUT_SCALE_ADDR 0xf084
#define CDP_D_DATOUT_SCALE_BWID ICFG_CSB_DATA_BWID

// Output data convertor shifter value
#define CDP_D_DATOUT_SHIFTER_G0 "cdp_d_datout_shifter_g0"
#define CDP_D_DATOUT_SHIFTER_G1 "cdp_d_datout_shifter_g1"
#define CDP_D_DATOUT_SHIFTER_ADDR 0xf088
#define CDP_D_DATOUT_SHIFTER_BWID ICFG_CSB_DATA_BWID

// input NaN element number
#define CDP_D_NAN_INPUT_NUM_G0 "cdp_d_nan_input_num_g0"
#define CDP_D_NAN_INPUT_NUM_G1 "cdp_d_nan_input_num_g1"
#define CDP_D_NAN_INPUT_NUM_ADDR 0xf08c
#define CDP_D_NAN_INPUT_NUM_BWID ICFG_CSB_DATA_BWID

// input Infinity element number
#define CDP_D_INF_INPUT_NUM_G0 "cdp_d_inf_input_num_g0"
#define CDP_D_INF_INPUT_NUM_G1 "cdp_d_inf_input_num_g1"
#define CDP_D_INF_INPUT_NUM_ADDR 0xf090
#define CDP_D_INF_INPUT_NUM_BWID ICFG_CSB_DATA_BWID

// output NaN element number
#define CDP_D_NAN_OUTPUT_NUM_G0 "cdp_d_nan_output_num_g0"
#define CDP_D_NAN_OUTPUT_NUM_G1 "cdp_d_nan_output_num_g1"
#define CDP_D_NAN_OUTPUT_NUM_ADDR 0xf094
#define CDP_D_NAN_OUTPUT_NUM_BWID ICFG_CSB_DATA_BWID

// saturated element number.
#define CDP_D_OUT_SATURATION_G0 "cdp_d_out_saturation_g0"
#define CDP_D_OUT_SATURATION_G1 "cdp_d_out_saturation_g1"
#define CDP_D_OUT_SATURATION_ADDR 0xf098
#define CDP_D_OUT_SATURATION_BWID ICFG_CSB_DATA_BWID

// Enable/Disable performance counting
#define CDP_D_PERF_ENABLE_G0 "cdp_d_perf_enable_g0"
#define CDP_D_PERF_ENABLE_G1 "cdp_d_perf_enable_g1"
#define CDP_D_PERF_ENABLE_ADDR 0xf09c
#define CDP_D_PERF_ENABLE_BWID ICFG_CSB_DATA_BWID

// Element number that for both LUT under-flow
#define CDP_D_PERF_WRITE_STALL_G0 "cdp_d_perf_write_stall_g0"
#define CDP_D_PERF_WRITE_STALL_G1 "cdp_d_perf_write_stall_g1"
#define CDP_D_PERF_WRITE_STALL_ADDR 0xf0a0
#define CDP_D_PERF_WRITE_STALL_BWID ICFG_CSB_DATA_BWID

// Element number that for both LUT under-flow
#define CDP_D_PERF_LUT_UFLOW_G0 "cdp_d_perf_lut_uflow_g0"
#define CDP_D_PERF_LUT_UFLOW_G1 "cdp_d_perf_lut_uflow_g1"
#define CDP_D_PERF_LUT_UFLOW_ADDR 0xf0a4
#define CDP_D_PERF_LUT_UFLOW_BWID ICFG_CSB_DATA_BWID

// Element number that for both LUT over-flow
#define CDP_D_PERF_LUT_OFLOW_G0 "cdp_d_perf_lut_oflow_g0"
#define CDP_D_PERF_LUT_OFLOW_G1 "cdp_d_perf_lut_oflow_g1"
#define CDP_D_PERF_LUT_OFLOW_ADDR 0xf0a8
#define CDP_D_PERF_LUT_OFLOW_BWID ICFG_CSB_DATA_BWID

// Element number that for both LUT miss, one is over-flow and the other is
// overflow
#define CDP_D_PERF_LUT_HYBRID_G0 "cdp_d_perf_lut_hybrid_g0"
#define CDP_D_PERF_LUT_HYBRID_G1 "cdp_d_perf_lut_hybrid_g1"
#define CDP_D_PERF_LUT_HYBRID_ADDR 0xf0ac
#define CDP_D_PERF_LUT_HYBRID_BWID ICFG_CSB_DATA_BWID

// Element number that for LE_lut hit only
#define CDP_D_PERF_LUT_LE_HIT_G0 "cdp_d_perf_lut_le_hit_g0"
#define CDP_D_PERF_LUT_LE_HIT_G1 "cdp_d_perf_lut_le_hit_g1"
#define CDP_D_PERF_LUT_LE_HIT_ADDR 0xf0b0
#define CDP_D_PERF_LUT_LE_HIT_BWID ICFG_CSB_DATA_BWID

// Element number that for LO_lut hit only
#define CDP_D_PERF_LUT_LO_HIT_G0 "cdp_d_perf_lut_lo_hit_g0"
#define CDP_D_PERF_LUT_LO_HIT_G1 "cdp_d_perf_lut_lo_hit_g1"
#define CDP_D_PERF_LUT_LO_HIT_ADDR 0xf0b4
#define CDP_D_PERF_LUT_LO_HIT_BWID ICFG_CSB_DATA_BWID

}; // namespace ilang

#endif // STATE_INFO_CDP_H__
