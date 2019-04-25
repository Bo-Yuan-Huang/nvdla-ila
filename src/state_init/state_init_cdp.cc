// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: state_init_cdp.cc

#include <ilang/ilang++.h>
#include <nvdla/configs/state_info.h>
#include <nvdla/utils.h>

// namespace ilang
namespace ilang {

// FIXME this is auto-generated placeholder

void StateInitCdp(Ila& m) {
  // Idle status of two register groups
  m.AddInit(m.state(CDP_S_STATUS) == 0);

  // Pointer for CSB master and data path to access groups
  m.AddInit(m.state(CDP_S_POINTER) == 0);

  // LUT access address and type
  m.AddInit(m.state(CDP_S_LUT_ACCESS_CFG) == 0);

  // Data register of read or write LUT
  m.AddInit(m.state(CDP_S_LUT_ACCESS_DATA) == 0);

  // LUT’s type: exponent or linear. And the selection between LE and LO tables.
  m.AddInit(m.state(CDP_S_LUT_CFG) == 0);

  // LE and LO LUT index offset and selection
  m.AddInit(m.state(CDP_S_LUT_INFO) == 0);

  // Lower 32bits of start of LE LUT’s range
  m.AddInit(m.state(CDP_S_LUT_LE_START_LOW) == 0);

  // Higher 6bits of start of LE LUT’s range
  m.AddInit(m.state(CDP_S_LUT_LE_START_HIGH) == 0);

  // Lower 32bits of end of LE LUT’s range
  m.AddInit(m.state(CDP_S_LUT_LE_END_LOW) == 0);

  // Higher 6bits of end of LE LUT’s range
  m.AddInit(m.state(CDP_S_LUT_LE_END_HIGH) == 0);

  // Lower 32bits of start of LO LUT’s range
  m.AddInit(m.state(CDP_S_LUT_LO_START_LOW) == 0);

  // Higher 6bits of start of LO LUT’s range
  m.AddInit(m.state(CDP_S_LUT_LO_START_HIGH) == 0);

  // Lower 32bits of end of LO LUT’s range
  m.AddInit(m.state(CDP_S_LUT_LO_END_LOW) == 0);

  // Higher 6bits of end of LO LUT’s range
  m.AddInit(m.state(CDP_S_LUT_LO_END_HIGH) == 0);

  // Slope scale parameter for LE LUT underflow and overflow, signed value
  m.AddInit(m.state(CDP_S_LUT_LE_SLOPE_SCALE) == 0);

  // Slope shift parameter for LE_LUT underflow and overflow, signed value
  m.AddInit(m.state(CDP_S_LUT_LE_SLOPE_SHIFT) == 0);

  // Slope scale parameter for LO LUT underflow and overflow, signed value
  m.AddInit(m.state(CDP_S_LUT_LO_SLOPE_SCALE) == 0);

  // Slope shift parameter for LO_LUT underflow and overflow, signed value
  m.AddInit(m.state(CDP_S_LUT_LO_SLOPE_SHIFT) == 0);

  // Set it to 1 to kick off operation for current register group
  m.AddInit(m.state(CDP_D_OP_ENABLE) == 0);

  // Square sum process bypass control and multiplier after interpolator bypass
  // control
  m.AddInit(m.state(CDP_D_FUNC_BYPASS) == 0);

  // Lower 32bits of output data address
  m.AddInit(m.state(CDP_D_DST_BASE_ADDR_LOW) == 0);

  // Higher 32bits of output data address when axi awaddr is 64bits
  m.AddInit(m.state(CDP_D_DST_BASE_ADDR_HIGH) == 0);

  // Line stride of output cube
  m.AddInit(m.state(CDP_D_DST_LINE_STRIDE) == 0);

  // Surface stride of output cube
  m.AddInit(m.state(CDP_D_DST_SURFACE_STRIDE) == 0);

  // RAM type of output data cube
  m.AddInit(m.state(CDP_D_DST_DMA_CFG) == 0);

  // This register is not used in OpenDLA 1.0
  m.AddInit(m.state(CDP_D_DST_COMPRESSION_EN) == 0);

  // Precision of input data
  m.AddInit(m.state(CDP_D_DATA_FORMAT) == 0);

  // Option to flush input NaN to zero
  m.AddInit(m.state(CDP_D_NAN_FLUSH_TO_ZERO) == 0);

  // Normalization length
  m.AddInit(m.state(CDP_D_LRN_CFG) == 0);

  // Input data convertor offset
  m.AddInit(m.state(CDP_D_DATIN_OFFSET) == 0);

  // Input data convertor scale
  m.AddInit(m.state(CDP_D_DATIN_SCALE) == 0);

  // Input data convertor shifter value
  m.AddInit(m.state(CDP_D_DATIN_SHIFTER) == 0);

  // Output data convertor offset
  m.AddInit(m.state(CDP_D_DATOUT_OFFSET) == 0);

  // Output data convertor scale
  m.AddInit(m.state(CDP_D_DATOUT_SCALE) == 0);

  // Output data convertor shifter value
  m.AddInit(m.state(CDP_D_DATOUT_SHIFTER) == 0);

  // input NaN element number
  m.AddInit(m.state(CDP_D_NAN_INPUT_NUM) == 0);

  // input Infinity element number
  m.AddInit(m.state(CDP_D_INF_INPUT_NUM) == 0);

  // output NaN element number
  m.AddInit(m.state(CDP_D_NAN_OUTPUT_NUM) == 0);

  // saturated element number.
  m.AddInit(m.state(CDP_D_OUT_SATURATION) == 0);

  // Enable/Disable performance counting
  m.AddInit(m.state(CDP_D_PERF_ENABLE) == 0);

  // Element number that for both LUT under-flow
  m.AddInit(m.state(CDP_D_PERF_WRITE_STALL) == 0);

  // Element number that for both LUT under-flow
  m.AddInit(m.state(CDP_D_PERF_LUT_UFLOW) == 0);

  // Element number that for both LUT over-flow
  m.AddInit(m.state(CDP_D_PERF_LUT_OFLOW) == 0);

  // Element number that for both LUT miss, one is over-flow and the other is
  // overflow
  m.AddInit(m.state(CDP_D_PERF_LUT_HYBRID) == 0);

  // Element number that for LE_lut hit only
  m.AddInit(m.state(CDP_D_PERF_LUT_LE_HIT) == 0);

  // Element number that for LO_lut hit only
  m.AddInit(m.state(CDP_D_PERF_LUT_LO_HIT) == 0);

  return;
}

}; // namespace ilang
