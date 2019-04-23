// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: state_info_sdp.h

#ifndef STATE_INFO_SDP_H__
#define STATE_INFO_SDP_H__

/// \namespace ilang
namespace ilang {

// Idle status of two register groups
#define SDP_S_STATUS_NAME "sdp_s_status"

// Pointer for CSB master and data path to access groups
#define SDP_S_POINTER_NAME "sdp_s_pointer"

// LUT access address and type
#define SDP_S_LUT_ACCESS_CFG_NAME "sdp_s_lut_access_cfg"

// Data register of read or write LUT
#define SDP_S_LUT_ACCESS_DATA_NAME "sdp_s_lut_access_data"

// LUT’s type: exponent or linear. And the selection between LE and LO tables.
#define SDP_S_LUT_CFG_NAME "sdp_s_lut_cfg"

// LE and LO LUT index offset and selection
#define SDP_S_LUT_INFO_NAME "sdp_s_lut_info"

// Start of LE LUT’s range
#define SDP_S_LUT_LE_START_NAME "sdp_s_lut_le_start"

// End of LE LUT’s range
#define SDP_S_LUT_LE_END_NAME "sdp_s_lut_le_end"

// Start of LO LUT’s range
#define SDP_S_LUT_LO_START_NAME "sdp_s_lut_lo_start"

// End of LO LUT’s range
#define SDP_S_LUT_LO_END_NAME "sdp_s_lut_lo_end"

// Slope scale parameter for LE LUT underflow and overflow, signed value
#define SDP_S_LUT_LE_SLOPE_SCALE_NAME "sdp_s_lut_le_slope_scale"

// Slope shift parameter for LE_LUT underflow and overflow, signed value
#define SDP_S_LUT_LE_SLOPE_SHIFT_NAME "sdp_s_lut_le_slope_shift"

// Slope scale parameter for LO LUT underflow and overflow, signed value
#define SDP_S_LUT_LO_SLOPE_SCALE_NAME "sdp_s_lut_lo_slope_scale"

// Slope shift parameter for LO_LUT underflow and overflow, signed value
#define SDP_S_LUT_LO_SLOPE_SHIFT_NAME "sdp_s_lut_lo_slope_shift"

// Set it to 1 to kick off operation for current register group
#define SDP_D_OP_ENABLE_NAME "sdp_d_op_enable"

// Input cube’s width
#define SDP_D_DATA_CUBE_WIDTH_NAME "sdp_d_data_cube_width"

// Input cube’s height
#define SDP_D_DATA_CUBE_HEIGHT_NAME "sdp_d_data_cube_height"

// Input cube’s channel
#define SDP_D_DATA_CUBE_CHANNEL_NAME "sdp_d_data_cube_channel"

// Lower 32bits of output data address
#define SDP_D_DST_BASE_ADDR_LOW_NAME "sdp_d_dst_base_addr_low"

// Higher 32bits of output data address when axi awaddr is 64bits
#define SDP_D_DST_BASE_ADDR_HIGH_NAME "sdp_d_dst_base_addr_high"

// Line stride of output data cube
#define SDP_D_DST_LINE_STRIDE_NAME "sdp_d_dst_line_stride"

// Surface stride of output data cube
#define SDP_D_DST_SURFACE_STRIDE_NAME "sdp_d_dst_surface_stride"

// Configurations of BS module: bypass, algorithm, etc.
#define SDP_D_DP_BS_CFG_NAME "sdp_d_dp_bs_cfg"

// Source type and shifter value of BS ALU
#define SDP_D_DP_BS_ALU_CFG_NAME "sdp_d_dp_bs_alu_cfg"

// Operand value of BS ALU
#define SDP_D_DP_BS_ALU_SRC_VALUE_NAME "sdp_d_dp_bs_alu_src_value"

// Source type and shifter value of BS MUL
#define SDP_D_DP_BS_MUL_CFG_NAME "sdp_d_dp_bs_mul_cfg"

// Operand value of BS MUL
#define SDP_D_DP_BS_MUL_SRC_VALUE_NAME "sdp_d_dp_bs_mul_src_value"

// Configurations of BN module: bypass, algorithm, etc.
#define SDP_D_DP_BN_CFG_NAME "sdp_d_dp_bn_cfg"

// Source type and shifter value of BN ALU
#define SDP_D_DP_BN_ALU_CFG_NAME "sdp_d_dp_bn_alu_cfg"

// Operand value of BN ALU
#define SDP_D_DP_BN_ALU_SRC_VALUE_NAME "sdp_d_dp_bn_alu_src_value"

// Source type and shifter value of BN MUL
#define SDP_D_DP_BN_MUL_CFG_NAME "sdp_d_dp_bn_mul_cfg"

// Operand value of BN MUL
#define SDP_D_DP_BN_MUL_SRC_VALUE_NAME "sdp_d_dp_bn_mul_src_value"

// Configurations of EW module: bypass, algorithm, etc.
#define SDP_D_DP_EW_CFG_NAME "sdp_d_dp_ew_cfg"

// Source type and bypass control of EW ALU
#define SDP_D_DP_EW_ALU_CFG_NAME "sdp_d_dp_ew_alu_cfg"

// Operand value of EW ALU
#define SDP_D_DP_EW_ALU_SRC_VALUE_NAME "sdp_d_dp_ew_alu_src_value"

// Converter offset of EW ALU
#define SDP_D_DP_EW_ALU_CVT_OFFSET_VALUE_NAME "sdp_d_dp_ew_alu_cvt_offset_value"

// Converter scale of EW ALU
#define SDP_D_DP_EW_ALU_CVT_SCALE_VALUE_NAME "sdp_d_dp_ew_alu_cvt_scale_value"

// Converter truncate of EW ALU
#define SDP_D_DP_EW_ALU_CVT_TRUNCATE_VALUE_NAME                                \
  "sdp_d_dp_ew_alu_cvt_truncate_value"

// Source type and bypass control of EW MUL
#define SDP_D_DP_EW_MUL_CFG_NAME "sdp_d_dp_ew_mul_cfg"

// Operand value of EW MUL
#define SDP_D_DP_EW_MUL_SRC_VALUE_NAME "sdp_d_dp_ew_mul_src_value"

// Converter offset of EW MUL
#define SDP_D_DP_EW_MUL_CVT_OFFSET_VALUE_NAME "sdp_d_dp_ew_mul_cvt_offset_value"

// Converter scale of EW MUL
#define SDP_D_DP_EW_MUL_CVT_SCALE_VALUE_NAME "sdp_d_dp_ew_mul_cvt_scale_value"

// Converter truncate of EW MUL
#define SDP_D_DP_EW_MUL_CVT_TRUNCATE_VALUE_NAME                                \
  "sdp_d_dp_ew_mul_cvt_truncate_value"

// Truncate of EW
#define SDP_D_DP_EW_TRUNCATE_VALUE_NAME "sdp_d_dp_ew_truncate_value"

// Operation configuration: flying mode, output destination, Direct or Winograd
// mode, flush NaN to zero, batch number.
#define SDP_D_FEATURE_MODE_CFG_NAME "sdp_d_feature_mode_cfg"

// Destination RAM type
#define SDP_D_DST_DMA_CFG_NAME "sdp_d_dst_dma_cfg"

// Stride of output cubes in batch mode
#define SDP_D_DST_BATCH_STRIDE_NAME "sdp_d_dst_batch_stride"

// Data precision
#define SDP_D_DATA_FORMAT_NAME "sdp_d_data_format"

// Output converter offset
#define SDP_D_CVT_OFFSET_NAME "sdp_d_cvt_offset"

// Output converter scale
#define SDP_D_CVT_SCALE_NAME "sdp_d_cvt_scale"

// Output converter shifter value
#define SDP_D_CVT_SHIFT_NAME "sdp_d_cvt_shift"

// Output of equal mode
#define SDP_D_STATUS_NAME "sdp_d_status"

// Input NaN element number
#define SDP_D_STATUS_NAN_INPUT_NUM_NAME "sdp_d_status_nan_input_num"

// Input Infinity element number
#define SDP_D_STATUS_INF_INPUT_NUM_NAME "sdp_d_status_inf_input_num"

// Output NaN element number
#define SDP_D_STATUS_NAN_OUTPUT_NUM_NAME "sdp_d_status_nan_output_num"

// Enable/Disable performance counting
#define SDP_D_PERF_ENABLE_NAME "sdp_d_perf_enable"

// Count stall cycles of write DMA for one layer
#define SDP_D_PERF_WDMA_WRITE_STALL_NAME "sdp_d_perf_wdma_write_stall"

// Element number of both table underflow
#define SDP_D_PERF_LUT_UFLOW_NAME "sdp_d_perf_lut_uflow"

// Element number of both table overflow
#define SDP_D_PERF_LUT_OFLOW_NAME "sdp_d_perf_lut_oflow"

// Element number of both table saturation
#define SDP_D_PERF_OUT_SATURATION_NAME "sdp_d_perf_out_saturation"

// Element number of both hit, or both miss situation that element underflow one
// table and at the same time overflow the other.
#define SDP_D_PERF_LUT_HYBRID_NAME "sdp_d_perf_lut_hybrid"

// Element number of only LE table hit
#define SDP_D_PERF_LUT_LE_HIT_NAME "sdp_d_perf_lut_le_hit"

// Element number of only LO table hit
#define SDP_D_PERF_LUT_LO_HIT_NAME "sdp_d_perf_lut_lo_hit"

}; // namespace ilang

#endif // STATE_INFO_SDP_H__
