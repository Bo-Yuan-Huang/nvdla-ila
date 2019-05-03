// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: state_define_cdp.cc

#include <ilang/ilang++.h>
#include <nvdla/configs/state_info.h>
#include <nvdla/utils.h>

// namespace ilang
namespace ilang {

void StateDefineCdp(Ila& m) {
  // Idle status of two register groups
  NewState(m, CDP_S_STATUS, CDP_S_STATUS_BWID);

  // Pointer for CSB master and data path to access groups
  NewState(m, CDP_S_POINTER, CDP_S_POINTER_BWID);

  // LUT access address and type
  NewState(m, CDP_S_LUT_ACCESS_CFG, CDP_S_LUT_ACCESS_CFG_BWID);

  // Data register of read or write LUT
  NewState(m, CDP_S_LUT_ACCESS_DATA, CDP_S_LUT_ACCESS_DATA_BWID);

  // LUT’s type: exponent or linear. And the selection between LE and LO tables.
  NewState(m, CDP_S_LUT_CFG, CDP_S_LUT_CFG_BWID);

  // LE and LO LUT index offset and selection
  NewState(m, CDP_S_LUT_INFO, CDP_S_LUT_INFO_BWID);

  // Lower 32bits of start of LE LUT’s range
  NewState(m, CDP_S_LUT_LE_START_LOW, CDP_S_LUT_LE_START_LOW_BWID);

  // Higher 6bits of start of LE LUT’s range
  NewState(m, CDP_S_LUT_LE_START_HIGH, CDP_S_LUT_LE_START_HIGH_BWID);

  // Lower 32bits of end of LE LUT’s range
  NewState(m, CDP_S_LUT_LE_END_LOW, CDP_S_LUT_LE_END_LOW_BWID);

  // Higher 6bits of end of LE LUT’s range
  NewState(m, CDP_S_LUT_LE_END_HIGH, CDP_S_LUT_LE_END_HIGH_BWID);

  // Lower 32bits of start of LO LUT’s range
  NewState(m, CDP_S_LUT_LO_START_LOW, CDP_S_LUT_LO_START_LOW_BWID);

  // Higher 6bits of start of LO LUT’s range
  NewState(m, CDP_S_LUT_LO_START_HIGH, CDP_S_LUT_LO_START_HIGH_BWID);

  // Lower 32bits of end of LO LUT’s range
  NewState(m, CDP_S_LUT_LO_END_LOW, CDP_S_LUT_LO_END_LOW_BWID);

  // Higher 6bits of end of LO LUT’s range
  NewState(m, CDP_S_LUT_LO_END_HIGH, CDP_S_LUT_LO_END_HIGH_BWID);

  // Slope scale parameter for LE LUT underflow and overflow, signed value
  NewState(m, CDP_S_LUT_LE_SLOPE_SCALE, CDP_S_LUT_LE_SLOPE_SCALE_BWID);

  // Slope shift parameter for LE_LUT underflow and overflow, signed value
  NewState(m, CDP_S_LUT_LE_SLOPE_SHIFT, CDP_S_LUT_LE_SLOPE_SHIFT_BWID);

  // Slope scale parameter for LO LUT underflow and overflow, signed value
  NewState(m, CDP_S_LUT_LO_SLOPE_SCALE, CDP_S_LUT_LO_SLOPE_SCALE_BWID);

  // Slope shift parameter for LO_LUT underflow and overflow, signed value
  NewState(m, CDP_S_LUT_LO_SLOPE_SHIFT, CDP_S_LUT_LO_SLOPE_SHIFT_BWID);

  // Set it to 1 to kick off operation for current register group
  NewState(m, CDP_D_OP_ENABLE_G0, CDP_D_OP_ENABLE_BWID);
  NewState(m, CDP_D_OP_ENABLE_G1, CDP_D_OP_ENABLE_BWID);

  // Square sum process bypass control and multiplier after interpolator bypass
  // control
  NewState(m, CDP_D_FUNC_BYPASS_G0, CDP_D_FUNC_BYPASS_BWID);
  NewState(m, CDP_D_FUNC_BYPASS_G1, CDP_D_FUNC_BYPASS_BWID);

  // Lower 32bits of output data address
  NewState(m, CDP_D_DST_BASE_ADDR_LOW_G0, CDP_D_DST_BASE_ADDR_LOW_BWID);
  NewState(m, CDP_D_DST_BASE_ADDR_LOW_G1, CDP_D_DST_BASE_ADDR_LOW_BWID);

  // Higher 32bits of output data address when axi awaddr is 64bits
  NewState(m, CDP_D_DST_BASE_ADDR_HIGH_G0, CDP_D_DST_BASE_ADDR_HIGH_BWID);
  NewState(m, CDP_D_DST_BASE_ADDR_HIGH_G1, CDP_D_DST_BASE_ADDR_HIGH_BWID);

  // Line stride of output cube
  NewState(m, CDP_D_DST_LINE_STRIDE_G0, CDP_D_DST_LINE_STRIDE_BWID);
  NewState(m, CDP_D_DST_LINE_STRIDE_G1, CDP_D_DST_LINE_STRIDE_BWID);

  // Surface stride of output cube
  NewState(m, CDP_D_DST_SURFACE_STRIDE_G0, CDP_D_DST_SURFACE_STRIDE_BWID);
  NewState(m, CDP_D_DST_SURFACE_STRIDE_G1, CDP_D_DST_SURFACE_STRIDE_BWID);

  // RAM type of output data cube
  NewState(m, CDP_D_DST_DMA_CFG_G0, CDP_D_DST_DMA_CFG_BWID);
  NewState(m, CDP_D_DST_DMA_CFG_G1, CDP_D_DST_DMA_CFG_BWID);

  // This register is not used in OpenDLA 1.0
  NewState(m, CDP_D_DST_COMPRESSION_EN_G0, CDP_D_DST_COMPRESSION_EN_BWID);
  NewState(m, CDP_D_DST_COMPRESSION_EN_G1, CDP_D_DST_COMPRESSION_EN_BWID);

  // Precision of input data
  NewState(m, CDP_D_DATA_FORMAT_G0, CDP_D_DATA_FORMAT_BWID);
  NewState(m, CDP_D_DATA_FORMAT_G1, CDP_D_DATA_FORMAT_BWID);

  // Option to flush input NaN to zero
  NewState(m, CDP_D_NAN_FLUSH_TO_ZERO_G0, CDP_D_NAN_FLUSH_TO_ZERO_BWID);
  NewState(m, CDP_D_NAN_FLUSH_TO_ZERO_G1, CDP_D_NAN_FLUSH_TO_ZERO_BWID);

  // Normalization length
  NewState(m, CDP_D_LRN_CFG_G0, CDP_D_LRN_CFG_BWID);
  NewState(m, CDP_D_LRN_CFG_G1, CDP_D_LRN_CFG_BWID);

  // Input data convertor offset
  NewState(m, CDP_D_DATIN_OFFSET_G0, CDP_D_DATIN_OFFSET_BWID);
  NewState(m, CDP_D_DATIN_OFFSET_G1, CDP_D_DATIN_OFFSET_BWID);

  // Input data convertor scale
  NewState(m, CDP_D_DATIN_SCALE_G0, CDP_D_DATIN_SCALE_BWID);
  NewState(m, CDP_D_DATIN_SCALE_G1, CDP_D_DATIN_SCALE_BWID);

  // Input data convertor shifter value
  NewState(m, CDP_D_DATIN_SHIFTER_G0, CDP_D_DATIN_SHIFTER_BWID);
  NewState(m, CDP_D_DATIN_SHIFTER_G1, CDP_D_DATIN_SHIFTER_BWID);

  // Output data convertor offset
  NewState(m, CDP_D_DATOUT_OFFSET_G0, CDP_D_DATOUT_OFFSET_BWID);
  NewState(m, CDP_D_DATOUT_OFFSET_G1, CDP_D_DATOUT_OFFSET_BWID);

  // Output data convertor scale
  NewState(m, CDP_D_DATOUT_SCALE_G0, CDP_D_DATOUT_SCALE_BWID);
  NewState(m, CDP_D_DATOUT_SCALE_G1, CDP_D_DATOUT_SCALE_BWID);

  // Output data convertor shifter value
  NewState(m, CDP_D_DATOUT_SHIFTER_G0, CDP_D_DATOUT_SHIFTER_BWID);
  NewState(m, CDP_D_DATOUT_SHIFTER_G1, CDP_D_DATOUT_SHIFTER_BWID);

  // input NaN element number
  NewState(m, CDP_D_NAN_INPUT_NUM_G0, CDP_D_NAN_INPUT_NUM_BWID);
  NewState(m, CDP_D_NAN_INPUT_NUM_G1, CDP_D_NAN_INPUT_NUM_BWID);

  // input Infinity element number
  NewState(m, CDP_D_INF_INPUT_NUM_G0, CDP_D_INF_INPUT_NUM_BWID);
  NewState(m, CDP_D_INF_INPUT_NUM_G1, CDP_D_INF_INPUT_NUM_BWID);

  // output NaN element number
  NewState(m, CDP_D_NAN_OUTPUT_NUM_G0, CDP_D_NAN_OUTPUT_NUM_BWID);
  NewState(m, CDP_D_NAN_OUTPUT_NUM_G1, CDP_D_NAN_OUTPUT_NUM_BWID);

  // saturated element number.
  NewState(m, CDP_D_OUT_SATURATION_G0, CDP_D_OUT_SATURATION_BWID);
  NewState(m, CDP_D_OUT_SATURATION_G1, CDP_D_OUT_SATURATION_BWID);

  // Enable/Disable performance counting
  NewState(m, CDP_D_PERF_ENABLE_G0, CDP_D_PERF_ENABLE_BWID);
  NewState(m, CDP_D_PERF_ENABLE_G1, CDP_D_PERF_ENABLE_BWID);

  // Element number that for both LUT under-flow
  NewState(m, CDP_D_PERF_WRITE_STALL_G0, CDP_D_PERF_WRITE_STALL_BWID);
  NewState(m, CDP_D_PERF_WRITE_STALL_G1, CDP_D_PERF_WRITE_STALL_BWID);

  // Element number that for both LUT under-flow
  NewState(m, CDP_D_PERF_LUT_UFLOW_G0, CDP_D_PERF_LUT_UFLOW_BWID);
  NewState(m, CDP_D_PERF_LUT_UFLOW_G1, CDP_D_PERF_LUT_UFLOW_BWID);

  // Element number that for both LUT over-flow
  NewState(m, CDP_D_PERF_LUT_OFLOW_G0, CDP_D_PERF_LUT_OFLOW_BWID);
  NewState(m, CDP_D_PERF_LUT_OFLOW_G1, CDP_D_PERF_LUT_OFLOW_BWID);

  // Element number that for both LUT miss, one is over-flow and the other is
  // overflow
  NewState(m, CDP_D_PERF_LUT_HYBRID_G0, CDP_D_PERF_LUT_HYBRID_BWID);
  NewState(m, CDP_D_PERF_LUT_HYBRID_G1, CDP_D_PERF_LUT_HYBRID_BWID);

  // Element number that for LE_lut hit only
  NewState(m, CDP_D_PERF_LUT_LE_HIT_G0, CDP_D_PERF_LUT_LE_HIT_BWID);
  NewState(m, CDP_D_PERF_LUT_LE_HIT_G1, CDP_D_PERF_LUT_LE_HIT_BWID);

  // Element number that for LO_lut hit only
  NewState(m, CDP_D_PERF_LUT_LO_HIT_G0, CDP_D_PERF_LUT_LO_HIT_BWID);
  NewState(m, CDP_D_PERF_LUT_LO_HIT_G1, CDP_D_PERF_LUT_LO_HIT_BWID);

  return;
}

}; // namespace ilang
