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
#define SDP_S_STATUS_BWID 32
// Pointer for CSB master and data path to access groups
#define SDP_S_POINTER_NAME "sdp_s_pointer"
#define SDP_S_POINTER_BWID 32
// LUT access address and type
#define SDP_S_LUT_ACCESS_CFG_NAME "sdp_s_lut_access_cfg"
#define SDP_S_LUT_ACCESS_CFG_BWID 32
// Data register of read or write LUT
#define SDP_S_LUT_ACCESS_DATA_NAME "sdp_s_lut_access_data"
#define SDP_S_LUT_ACCESS_DATA_BWID 32
// LUT’s type: exponent or linear. And the selection between LE and LO tables.
#define SDP_S_LUT_CFG_NAME "sdp_s_lut_cfg"
#define SDP_S_LUT_CFG_BWID 32
// LE and LO LUT index offset and selection
#define SDP_S_LUT_INFO_NAME "sdp_s_lut_info"
#define SDP_S_LUT_INFO_BWID 32
// Start of LE LUT’s range
#define SDP_S_LUT_LE_START_NAME "sdp_s_lut_le_start"
#define SDP_S_LUT_LE_START_BWID 32
// End of LE LUT’s range
#define SDP_S_LUT_LE_END_NAME "sdp_s_lut_le_end"
#define SDP_S_LUT_LE_END_BWID 32
// Start of LO LUT’s range
#define SDP_S_LUT_LO_START_NAME "sdp_s_lut_lo_start"
#define SDP_S_LUT_LO_START_BWID 32
// End of LO LUT’s range
#define SDP_S_LUT_LO_END_NAME "sdp_s_lut_lo_end"
#define SDP_S_LUT_LO_END_BWID 32
// Slope scale parameter for LE LUT underflow and overflow, signed value
#define SDP_S_LUT_LE_SLOPE_SCALE_NAME "sdp_s_lut_le_slope_scale"
#define SDP_S_LUT_LE_SLOPE_SCALE_BWID 32
// Slope shift parameter for LE_LUT underflow and overflow, signed value
#define SDP_S_LUT_LE_SLOPE_SHIFT_NAME "sdp_s_lut_le_slope_shift"
#define SDP_S_LUT_LE_SLOPE_SHIFT_BWID 32
// Slope scale parameter for LO LUT underflow and overflow, signed value
#define SDP_S_LUT_LO_SLOPE_SCALE_NAME "sdp_s_lut_lo_slope_scale"
#define SDP_S_LUT_LO_SLOPE_SCALE_BWID 32
// Slope shift parameter for LO_LUT underflow and overflow, signed value
#define SDP_S_LUT_LO_SLOPE_SHIFT_NAME "sdp_s_lut_lo_slope_shift"
#define SDP_S_LUT_LO_SLOPE_SHIFT_BWID 32
// Set it to 1 to kick off operation for current register group
#define SDP_D_OP_ENABLE_NAME "sdp_d_op_enable"
#define SDP_D_OP_ENABLE_BWID 32
// Input cube’s width
#define SDP_D_DATA_CUBE_WIDTH_NAME "sdp_d_data_cube_width"
#define SDP_D_DATA_CUBE_WIDTH_BWID 32
// Input cube’s height
#define SDP_D_DATA_CUBE_HEIGHT_NAME "sdp_d_data_cube_height"
#define SDP_D_DATA_CUBE_HEIGHT_BWID 32
// Input cube’s channel
#define SDP_D_DATA_CUBE_CHANNEL_NAME "sdp_d_data_cube_channel"
#define SDP_D_DATA_CUBE_CHANNEL_BWID 32
// Lower 32bits of output data address
#define SDP_D_DST_BASE_ADDR_LOW_NAME "sdp_d_dst_base_addr_low"
#define SDP_D_DST_BASE_ADDR_LOW_BWID 32
// Higher 32bits of output data address when axi awaddr is 64bits
#define SDP_D_DST_BASE_ADDR_HIGH_NAME "sdp_d_dst_base_addr_high"
#define SDP_D_DST_BASE_ADDR_HIGH_BWID 32
// Line stride of output data cube
#define SDP_D_DST_LINE_STRIDE_NAME "sdp_d_dst_line_stride"
#define SDP_D_DST_LINE_STRIDE_BWID 32
// Surface stride of output data cube
#define SDP_D_DST_SURFACE_STRIDE_NAME "sdp_d_dst_surface_stride"
#define SDP_D_DST_SURFACE_STRIDE_BWID 32
// Configurations of BS module: bypass, algorithm, etc.
#define SDP_D_DP_BS_CFG_NAME "sdp_d_dp_bs_cfg"
#define SDP_D_DP_BS_CFG_BWID 32
// Source type and shifter value of BS ALU
#define SDP_D_DP_BS_ALU_CFG_NAME "sdp_d_dp_bs_alu_cfg"
#define SDP_D_DP_BS_ALU_CFG_BWID 32
// Operand value of BS ALU
#define SDP_D_DP_BS_ALU_SRC_VALUE_NAME "sdp_d_dp_bs_alu_src_value"
#define SDP_D_DP_BS_ALU_SRC_VALUE_BWID 32
// Source type and shifter value of BS MUL
#define SDP_D_DP_BS_MUL_CFG_NAME "sdp_d_dp_bs_mul_cfg"
#define SDP_D_DP_BS_MUL_CFG_BWID 32
// Operand value of BS MUL
#define SDP_D_DP_BS_MUL_SRC_VALUE_NAME "sdp_d_dp_bs_mul_src_value"
#define SDP_D_DP_BS_MUL_SRC_VALUE_BWID 32
// Configurations of BN module: bypass, algorithm, etc.
#define SDP_D_DP_BN_CFG_NAME "sdp_d_dp_bn_cfg"
#define SDP_D_DP_BN_CFG_BWID 32
// Source type and shifter value of BN ALU
#define SDP_D_DP_BN_ALU_CFG_NAME "sdp_d_dp_bn_alu_cfg"
#define SDP_D_DP_BN_ALU_CFG_BWID 32
// Operand value of BN ALU
#define SDP_D_DP_BN_ALU_SRC_VALUE_NAME "sdp_d_dp_bn_alu_src_value"
#define SDP_D_DP_BN_ALU_SRC_VALUE_BWID 32
// Source type and shifter value of BN MUL
#define SDP_D_DP_BN_MUL_CFG_NAME "sdp_d_dp_bn_mul_cfg"
#define SDP_D_DP_BN_MUL_CFG_BWID 32
// Operand value of BN MUL
#define SDP_D_DP_BN_MUL_SRC_VALUE_NAME "sdp_d_dp_bn_mul_src_value"
#define SDP_D_DP_BN_MUL_SRC_VALUE_BWID 32
// Configurations of EW module: bypass, algorithm, etc.
#define SDP_D_DP_EW_CFG_NAME "sdp_d_dp_ew_cfg"
#define SDP_D_DP_EW_CFG_BWID 32
// Source type and bypass control of EW ALU
#define SDP_D_DP_EW_ALU_CFG_NAME "sdp_d_dp_ew_alu_cfg"
#define SDP_D_DP_EW_ALU_CFG_BWID 32
// Operand value of EW ALU
#define SDP_D_DP_EW_ALU_SRC_VALUE_NAME "sdp_d_dp_ew_alu_src_value"
#define SDP_D_DP_EW_ALU_SRC_VALUE_BWID 32
// Converter offset of EW ALU
#define SDP_D_DP_EW_ALU_CVT_OFFSET_VALUE_NAME "sdp_d_dp_ew_alu_cvt_offset_value"
#define SDP_D_DP_EW_ALU_CVT_OFFSET_VALUE_BWID 32
// Converter scale of EW ALU
#define SDP_D_DP_EW_ALU_CVT_SCALE_VALUE_NAME "sdp_d_dp_ew_alu_cvt_scale_value"
#define SDP_D_DP_EW_ALU_CVT_SCALE_VALUE_BWID 32
// Converter truncate of EW ALU
#define SDP_D_DP_EW_ALU_CVT_TRUNCATE_VALUE_NAME                                \
  "sdp_d_dp_ew_alu_cvt_truncate_value"
#define SDP_D_DP_EW_ALU_CVT_TRUNCATE_VALUE_BWID 32
// Source type and bypass control of EW MUL
#define SDP_D_DP_EW_MUL_CFG_NAME "sdp_d_dp_ew_mul_cfg"
#define SDP_D_DP_EW_MUL_CFG_BWID 32
// Operand value of EW MUL
#define SDP_D_DP_EW_MUL_SRC_VALUE_NAME "sdp_d_dp_ew_mul_src_value"
#define SDP_D_DP_EW_MUL_SRC_VALUE_BWID 32
// Converter offset of EW MUL
#define SDP_D_DP_EW_MUL_CVT_OFFSET_VALUE_NAME "sdp_d_dp_ew_mul_cvt_offset_value"
#define SDP_D_DP_EW_MUL_CVT_OFFSET_VALUE_BWID 32
// Converter scale of EW MUL
#define SDP_D_DP_EW_MUL_CVT_SCALE_VALUE_NAME "sdp_d_dp_ew_mul_cvt_scale_value"
#define SDP_D_DP_EW_MUL_CVT_SCALE_VALUE_BWID 32
// Converter truncate of EW MUL
#define SDP_D_DP_EW_MUL_CVT_TRUNCATE_VALUE_NAME                                \
  "sdp_d_dp_ew_mul_cvt_truncate_value"
#define SDP_D_DP_EW_MUL_CVT_TRUNCATE_VALUE_BWID 32
// Truncate of EW
#define SDP_D_DP_EW_TRUNCATE_VALUE_NAME "sdp_d_dp_ew_truncate_value"
#define SDP_D_DP_EW_TRUNCATE_VALUE_BWID 32
// Operation configuration: flying mode, output destination, Direct or Winograd
// mode, flush NaN to zero, batch number.
#define SDP_D_FEATURE_MODE_CFG_NAME "sdp_d_feature_mode_cfg"
#define SDP_D_FEATURE_MODE_CFG_BWID 32
// Destination RAM type
#define SDP_D_DST_DMA_CFG_NAME "sdp_d_dst_dma_cfg"
#define SDP_D_DST_DMA_CFG_BWID 32
// Stride of output cubes in batch mode
#define SDP_D_DST_BATCH_STRIDE_NAME "sdp_d_dst_batch_stride"
#define SDP_D_DST_BATCH_STRIDE_BWID 32
// Data precision
#define SDP_D_DATA_FORMAT_NAME "sdp_d_data_format"
#define SDP_D_DATA_FORMAT_BWID 32
// Output converter offset
#define SDP_D_CVT_OFFSET_NAME "sdp_d_cvt_offset"
#define SDP_D_CVT_OFFSET_BWID 32
// Output converter scale
#define SDP_D_CVT_SCALE_NAME "sdp_d_cvt_scale"
#define SDP_D_CVT_SCALE_BWID 32
// Output converter shifter value
#define SDP_D_CVT_SHIFT_NAME "sdp_d_cvt_shift"
#define SDP_D_CVT_SHIFT_BWID 32
// Output of equal mode
#define SDP_D_STATUS_NAME "sdp_d_status"
#define SDP_D_STATUS_BWID 32
// Input NaN element number
#define SDP_D_STATUS_NAN_INPUT_NUM_NAME "sdp_d_status_nan_input_num"
#define SDP_D_STATUS_NAN_INPUT_NUM_BWID 32
// Input Infinity element number
#define SDP_D_STATUS_INF_INPUT_NUM_NAME "sdp_d_status_inf_input_num"
#define SDP_D_STATUS_INF_INPUT_NUM_BWID 32
// Output NaN element number
#define SDP_D_STATUS_NAN_OUTPUT_NUM_NAME "sdp_d_status_nan_output_num"
#define SDP_D_STATUS_NAN_OUTPUT_NUM_BWID 32
// Enable/Disable performance counting
#define SDP_D_PERF_ENABLE_NAME "sdp_d_perf_enable"
#define SDP_D_PERF_ENABLE_BWID 32
// Count stall cycles of write DMA for one layer
#define SDP_D_PERF_WDMA_WRITE_STALL_NAME "sdp_d_perf_wdma_write_stall"
#define SDP_D_PERF_WDMA_WRITE_STALL_BWID 32
// Element number of both table underflow
#define SDP_D_PERF_LUT_UFLOW_NAME "sdp_d_perf_lut_uflow"
#define SDP_D_PERF_LUT_UFLOW_BWID 32
// Element number of both table overflow
#define SDP_D_PERF_LUT_OFLOW_NAME "sdp_d_perf_lut_oflow"
#define SDP_D_PERF_LUT_OFLOW_BWID 32
// Element number of both table saturation
#define SDP_D_PERF_OUT_SATURATION_NAME "sdp_d_perf_out_saturation"
#define SDP_D_PERF_OUT_SATURATION_BWID 32
// Element number of both hit, or both miss situation that element underflow one
// table and at the same time overflow the other.
#define SDP_D_PERF_LUT_HYBRID_NAME "sdp_d_perf_lut_hybrid"
#define SDP_D_PERF_LUT_HYBRID_BWID 32
// Element number of only LE table hit
#define SDP_D_PERF_LUT_LE_HIT_NAME "sdp_d_perf_lut_le_hit"
#define SDP_D_PERF_LUT_LE_HIT_BWID 32
// Element number of only LO table hit
#define SDP_D_PERF_LUT_LO_HIT_NAME "sdp_d_perf_lut_lo_hit"
#define SDP_D_PERF_LUT_LO_HIT_BWID 32

}; // namespace ilang

#endif // STATE_INFO_SDP_H__
