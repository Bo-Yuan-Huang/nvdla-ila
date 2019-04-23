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

/// \namespace ilang
namespace ilang {

// Idle status of two register groups
#define CDP_S_STATUS_NAME "cdp_s_status"

// Pointer for CSB master and data path to access groups
#define CDP_S_POINTER_NAME "cdp_s_pointer"

// LUT access address and type
#define CDP_S_LUT_ACCESS_CFG_NAME "cdp_s_lut_access_cfg"

// Data register of read or write LUT
#define CDP_S_LUT_ACCESS_DATA_NAME "cdp_s_lut_access_data"

// LUT’s type: exponent or linear. And the selection between LE and LO tables.
#define CDP_S_LUT_CFG_NAME "cdp_s_lut_cfg"

// LE and LO LUT index offset and selection
#define CDP_S_LUT_INFO_NAME "cdp_s_lut_info"

// Lower 32bits of start of LE LUT’s range
#define CDP_S_LUT_LE_START_LOW_NAME "cdp_s_lut_le_start_low"

// Higher 6bits of start of LE LUT’s range
#define CDP_S_LUT_LE_START_HIGH_NAME "cdp_s_lut_le_start_high"

// Lower 32bits of end of LE LUT’s range
#define CDP_S_LUT_LE_END_LOW_NAME "cdp_s_lut_le_end_low"

// Higher 6bits of end of LE LUT’s range
#define CDP_S_LUT_LE_END_HIGH_NAME "cdp_s_lut_le_end_high"

// Lower 32bits of start of LO LUT’s range
#define CDP_S_LUT_LO_START_LOW_NAME "cdp_s_lut_lo_start_low"

// Higher 6bits of start of LO LUT’s range
#define CDP_S_LUT_LO_START_HIGH_NAME "cdp_s_lut_lo_start_high"

// Lower 32bits of end of LO LUT’s range
#define CDP_S_LUT_LO_END_LOW_NAME "cdp_s_lut_lo_end_low"

// Higher 6bits of end of LO LUT’s range
#define CDP_S_LUT_LO_END_HIGH_NAME "cdp_s_lut_lo_end_high"

// Slope scale parameter for LE LUT underflow and overflow, signed value
#define CDP_S_LUT_LE_SLOPE_SCALE_NAME "cdp_s_lut_le_slope_scale"

// Slope shift parameter for LE_LUT underflow and overflow, signed value
#define CDP_S_LUT_LE_SLOPE_SHIFT_NAME "cdp_s_lut_le_slope_shift"

// Slope scale parameter for LO LUT underflow and overflow, signed value
#define CDP_S_LUT_LO_SLOPE_SCALE_NAME "cdp_s_lut_lo_slope_scale"

// Slope shift parameter for LO_LUT underflow and overflow, signed value
#define CDP_S_LUT_LO_SLOPE_SHIFT_NAME "cdp_s_lut_lo_slope_shift"

// Set it to 1 to kick off operation for current register group
#define CDP_D_OP_ENABLE_NAME "cdp_d_op_enable"

// Square sum process bypass control and multiplier after interpolator bypass
// control
#define CDP_D_FUNC_BYPASS_NAME "cdp_d_func_bypass"

// Lower 32bits of output data address
#define CDP_D_DST_BASE_ADDR_LOW_NAME "cdp_d_dst_base_addr_low"

// Higher 32bits of output data address when axi awaddr is 64bits
#define CDP_D_DST_BASE_ADDR_HIGH_NAME "cdp_d_dst_base_addr_high"

// Line stride of output cube
#define CDP_D_DST_LINE_STRIDE_NAME "cdp_d_dst_line_stride"

// Surface stride of output cube
#define CDP_D_DST_SURFACE_STRIDE_NAME "cdp_d_dst_surface_stride"

// RAM type of output data cube
#define CDP_D_DST_DMA_CFG_NAME "cdp_d_dst_dma_cfg"

// This register is not used in OpenDLA 1.0
#define CDP_D_DST_COMPRESSION_EN_NAME "cdp_d_dst_compression_en"

// Precision of input data
#define CDP_D_DATA_FORMAT_NAME "cdp_d_data_format"

// Option to flush input NaN to zero
#define CDP_D_NAN_FLUSH_TO_ZERO_NAME "cdp_d_nan_flush_to_zero"

// Normalization length
#define CDP_D_LRN_CFG_NAME "cdp_d_lrn_cfg"

// Input data convertor offset
#define CDP_D_DATIN_OFFSET_NAME "cdp_d_datin_offset"

// Input data convertor scale
#define CDP_D_DATIN_SCALE_NAME "cdp_d_datin_scale"

// Input data convertor shifter value
#define CDP_D_DATIN_SHIFTER_NAME "cdp_d_datin_shifter"

// Output data convertor offset
#define CDP_D_DATOUT_OFFSET_NAME "cdp_d_datout_offset"

// Output data convertor scale
#define CDP_D_DATOUT_SCALE_NAME "cdp_d_datout_scale"

// Output data convertor shifter value
#define CDP_D_DATOUT_SHIFTER_NAME "cdp_d_datout_shifter"

// input NaN element number
#define CDP_D_NAN_INPUT_NUM_NAME "cdp_d_nan_input_num"

// input Infinity element number
#define CDP_D_INF_INPUT_NUM_NAME "cdp_d_inf_input_num"

// output NaN element number
#define CDP_D_NAN_OUTPUT_NUM_NAME "cdp_d_nan_output_num"

// saturated element number.
#define CDP_D_OUT_SATURATION_NAME "cdp_d_out_saturation"

// Enable/Disable performance counting
#define CDP_D_PERF_ENABLE_NAME "cdp_d_perf_enable"

// Element number that for both LUT under-flow
#define CDP_D_PERF_WRITE_STALL_NAME "cdp_d_perf_write_stall"

// Element number that for both LUT under-flow
#define CDP_D_PERF_LUT_UFLOW_NAME "cdp_d_perf_lut_uflow"

// Element number that for both LUT over-flow
#define CDP_D_PERF_LUT_OFLOW_NAME "cdp_d_perf_lut_oflow"

// Element number that for both LUT miss, one is over-flow and the other is
// overflow
#define CDP_D_PERF_LUT_HYBRID_NAME "cdp_d_perf_lut_hybrid"

// Element number that for LE_lut hit only
#define CDP_D_PERF_LUT_LE_HIT_NAME "cdp_d_perf_lut_le_hit"

// Element number that for LO_lut hit only
#define CDP_D_PERF_LUT_LO_HIT_NAME "cdp_d_perf_lut_lo_hit"

}; // namespace ilang

#endif // STATE_INFO_CDP_H__
