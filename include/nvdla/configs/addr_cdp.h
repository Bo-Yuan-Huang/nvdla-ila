// File Name: addr_cdp.h

#ifndef NVDLA_ADDR_CDP_H__
#define NVDLA_ADDR_CDP_H__

/// \namespace ilang
namespace ilang {

// Idle status of two register groups
#define CDP_S_STATUS_ADDR 0xf000
// Pointer for CSB master and data path to access groups
#define CDP_S_POINTER_ADDR 0xf004
// LUT access address and type
#define CDP_S_LUT_ACCESS_CFG_ADDR 0xf008
// Data register of read or write LUT
#define CDP_S_LUT_ACCESS_DATA_ADDR 0xf00c
// LUT’s type: exponent or linear. And the selection between LE and LO tables.
#define CDP_S_LUT_CFG_ADDR 0xf010
// LE and LO LUT index offset and selection
#define CDP_S_LUT_INFO_ADDR 0xf014
// Lower 32bits of start of LE LUT’s range
#define CDP_S_LUT_LE_START_LOW_ADDR 0xf018
// Higher 6bits of start of LE LUT’s range
#define CDP_S_LUT_LE_START_HIGH_ADDR 0xf01c
// Lower 32bits of end of LE LUT’s range
#define CDP_S_LUT_LE_END_LOW_ADDR 0xf020
// Higher 6bits of end of LE LUT’s range
#define CDP_S_LUT_LE_END_HIGH_ADDR 0xf024
// Lower 32bits of start of LO LUT’s range
#define CDP_S_LUT_LO_START_LOW_ADDR 0xf028
// Higher 6bits of start of LO LUT’s range
#define CDP_S_LUT_LO_START_HIGH_ADDR 0xf02c
// Lower 32bits of end of LO LUT’s range
#define CDP_S_LUT_LO_END_LOW_ADDR 0xf030
// Higher 6bits of end of LO LUT’s range
#define CDP_S_LUT_LO_END_HIGH_ADDR 0xf034
// Slope scale parameter for LE LUT underflow and overflow, signed value
#define CDP_S_LUT_LE_SLOPE_SCALE_ADDR 0xf038
// Slope shift parameter for LE_LUT underflow and overflow, signed value
#define CDP_S_LUT_LE_SLOPE_SHIFT_ADDR 0xf03c
// Slope scale parameter for LO LUT underflow and overflow, signed value
#define CDP_S_LUT_LO_SLOPE_SCALE_ADDR 0xf040
// Slope shift parameter for LO_LUT underflow and overflow, signed value
#define CDP_S_LUT_LO_SLOPE_SHIFT_ADDR 0xf044
// Set it to 1 to kick off operation for current register group
#define CDP_D_OP_ENABLE_ADDR 0xf048
// Square sum process bypass control and multiplier after interpolator bypass
// control
#define CDP_D_FUNC_BYPASS_ADDR 0xf04c
// Lower 32bits of output data address
#define CDP_D_DST_BASE_ADDR_LOW_ADDR 0xf050
// Higher 32bits of output data address when axi awaddr is 64bits
#define CDP_D_DST_BASE_ADDR_HIGH_ADDR 0xf054
// Line stride of output cube
#define CDP_D_DST_LINE_STRIDE_ADDR 0xf058
// Surface stride of output cube
#define CDP_D_DST_SURFACE_STRIDE_ADDR 0xf05c
// RAM type of output data cube
#define CDP_D_DST_DMA_CFG_ADDR 0xf060
// This register is not used in OpenDLA 1.0
#define CDP_D_DST_COMPRESSION_EN_ADDR 0xf064
// Precision of input data
#define CDP_D_DATA_FORMAT_ADDR 0xf068
// Option to flush input NaN to zero
#define CDP_D_NAN_FLUSH_TO_ZERO_ADDR 0xf06c
// Normalization length
#define CDP_D_LRN_CFG_ADDR 0xf070
// Input data convertor offset
#define CDP_D_DATIN_OFFSET_ADDR 0xf074
// Input data convertor scale
#define CDP_D_DATIN_SCALE_ADDR 0xf078
// Input data convertor shifter value
#define CDP_D_DATIN_SHIFTER_ADDR 0xf07c
// Output data convertor offset
#define CDP_D_DATOUT_OFFSET_ADDR 0xf080
// Output data convertor scale
#define CDP_D_DATOUT_SCALE_ADDR 0xf084
// Output data convertor shifter value
#define CDP_D_DATOUT_SHIFTER_ADDR 0xf088
// input NaN element number
#define CDP_D_NAN_INPUT_NUM_ADDR 0xf08c
// input Infinity element number
#define CDP_D_INF_INPUT_NUM_ADDR 0xf090
// output NaN element number
#define CDP_D_NAN_OUTPUT_NUM_ADDR 0xf094
// saturated element number.
#define CDP_D_OUT_SATURATION_ADDR 0xf098
// Enable/Disable performance counting
#define CDP_D_PERF_ENABLE_ADDR 0xf09c
// Element number that for both LUT under-flow
#define CDP_D_PERF_WRITE_STALL_ADDR 0xf0a0
// Element number that for both LUT under-flow
#define CDP_D_PERF_LUT_UFLOW_ADDR 0xf0a4
// Element number that for both LUT over-flow
#define CDP_D_PERF_LUT_OFLOW_ADDR 0xf0a8
// Element number that for both LUT miss, one is over-flow and the other is
// overflow
#define CDP_D_PERF_LUT_HYBRID_ADDR 0xf0ac
// Element number that for LE_lut hit only
#define CDP_D_PERF_LUT_LE_HIT_ADDR 0xf0b0
// Element number that for LO_lut hit only
#define CDP_D_PERF_LUT_LO_HIT_ADDR 0xf0b4

}; // namespace ilang

#endif // NVDLA_ADDR_CDP_H__
