// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: addr_sdp.h

#ifndef NVDLA_ADDR_SDP_H__
#define NVDLA_ADDR_SDP_H__

/// \namespace ilang
namespace ilang {

// Idle status of two register groups
#define SDP_S_STATUS_ADDR 0xb000
// Pointer for CSB master and data path to access groups
#define SDP_S_POINTER_ADDR 0xb004
// LUT access address and type
#define SDP_S_LUT_ACCESS_CFG_ADDR 0xb008
// Data register of read or write LUT
#define SDP_S_LUT_ACCESS_DATA_ADDR 0xb00c
// LUT’s type: exponent or linear. And the selection between LE and LO tables.
#define SDP_S_LUT_CFG_ADDR 0xb010
// LE and LO LUT index offset and selection
#define SDP_S_LUT_INFO_ADDR 0xb014
// Start of LE LUT’s range
#define SDP_S_LUT_LE_START_ADDR 0xb018
// End of LE LUT’s range
#define SDP_S_LUT_LE_END_ADDR 0xb01c
// Start of LO LUT’s range
#define SDP_S_LUT_LO_START_ADDR 0xb020
// End of LO LUT’s range
#define SDP_S_LUT_LO_END_ADDR 0xb024
// Slope scale parameter for LE LUT underflow and overflow, signed value
#define SDP_S_LUT_LE_SLOPE_SCALE_ADDR 0xb028
// Slope shift parameter for LE_LUT underflow and overflow, signed value
#define SDP_S_LUT_LE_SLOPE_SHIFT_ADDR 0xb02c
// Slope scale parameter for LO LUT underflow and overflow, signed value
#define SDP_S_LUT_LO_SLOPE_SCALE_ADDR 0xb030
// Slope shift parameter for LO_LUT underflow and overflow, signed value
#define SDP_S_LUT_LO_SLOPE_SHIFT_ADDR 0xb034
// Set it to 1 to kick off operation for current register group
#define SDP_D_OP_ENABLE_ADDR 0xb038
// Input cube’s width
#define SDP_D_DATA_CUBE_WIDTH_ADDR 0xb03c
// Input cube’s height
#define SDP_D_DATA_CUBE_HEIGHT_ADDR 0xb040
// Input cube’s channel
#define SDP_D_DATA_CUBE_CHANNEL_ADDR 0xb044
// Lower 32bits of output data address
#define SDP_D_DST_BASE_ADDR_LOW_ADDR 0xb048
// Higher 32bits of output data address when axi awaddr is 64bits
#define SDP_D_DST_BASE_ADDR_HIGH_ADDR 0xb04c
// Line stride of output data cube
#define SDP_D_DST_LINE_STRIDE_ADDR 0xb050
// Surface stride of output data cube
#define SDP_D_DST_SURFACE_STRIDE_ADDR 0xb054
// Configurations of BS module: bypass, algorithm, etc.
#define SDP_D_DP_BS_CFG_ADDR 0xb058
// Source type and shifter value of BS ALU
#define SDP_D_DP_BS_ALU_CFG_ADDR 0xb05c
// Operand value of BS ALU
#define SDP_D_DP_BS_ALU_SRC_VALUE_ADDR 0xb060
// Source type and shifter value of BS MUL
#define SDP_D_DP_BS_MUL_CFG_ADDR 0xb064
// Operand value of BS MUL
#define SDP_D_DP_BS_MUL_SRC_VALUE_ADDR 0xb068
// Configurations of BN module: bypass, algorithm, etc.
#define SDP_D_DP_BN_CFG_ADDR 0xb06c
// Source type and shifter value of BN ALU
#define SDP_D_DP_BN_ALU_CFG_ADDR 0xb070
// Operand value of BN ALU
#define SDP_D_DP_BN_ALU_SRC_VALUE_ADDR 0xb074
// Source type and shifter value of BN MUL
#define SDP_D_DP_BN_MUL_CFG_ADDR 0xb078
// Operand value of BN MUL
#define SDP_D_DP_BN_MUL_SRC_VALUE_ADDR 0xb07c
// Configurations of EW module: bypass, algorithm, etc.
#define SDP_D_DP_EW_CFG_ADDR 0xb080
// Source type and bypass control of EW ALU
#define SDP_D_DP_EW_ALU_CFG_ADDR 0xb084
// Operand value of EW ALU
#define SDP_D_DP_EW_ALU_SRC_VALUE_ADDR 0xb088
// Converter offset of EW ALU
#define SDP_D_DP_EW_ALU_CVT_OFFSET_VALUE_ADDR 0xb08c
// Converter scale of EW ALU
#define SDP_D_DP_EW_ALU_CVT_SCALE_VALUE_ADDR 0xb090
// Converter truncate of EW ALU
#define SDP_D_DP_EW_ALU_CVT_TRUNCATE_VALUE_ADDR 0xb094
// Source type and bypass control of EW MUL
#define SDP_D_DP_EW_MUL_CFG_ADDR 0xb098
// Operand value of EW MUL
#define SDP_D_DP_EW_MUL_SRC_VALUE_ADDR 0xb09c
// Converter offset of EW MUL
#define SDP_D_DP_EW_MUL_CVT_OFFSET_VALUE_ADDR 0xb0a0
// Converter scale of EW MUL
#define SDP_D_DP_EW_MUL_CVT_SCALE_VALUE_ADDR 0xb0a4
// Converter truncate of EW MUL
#define SDP_D_DP_EW_MUL_CVT_TRUNCATE_VALUE_ADDR 0xb0a8
// Truncate of EW
#define SDP_D_DP_EW_TRUNCATE_VALUE_ADDR 0xb0ac
// Operation configuration: flying mode, output destination, Direct or Winograd
// mode, flush NaN to zero, batch number.
#define SDP_D_FEATURE_MODE_CFG_ADDR 0xb0b0
// Destination RAM type
#define SDP_D_DST_DMA_CFG_ADDR 0xb0b4
// Stride of output cubes in batch mode
#define SDP_D_DST_BATCH_STRIDE_ADDR 0xb0b8
// Data precision
#define SDP_D_DATA_FORMAT_ADDR 0xb0bc
// Output converter offset
#define SDP_D_CVT_OFFSET_ADDR 0xb0c0
// Output converter scale
#define SDP_D_CVT_SCALE_ADDR 0xb0c4
// Output converter shifter value
#define SDP_D_CVT_SHIFT_ADDR 0xb0c8
// Output of equal mode
#define SDP_D_STATUS_ADDR 0xb0cc
// Input NaN element number
#define SDP_D_STATUS_NAN_INPUT_NUM_ADDR 0xb0d0
// Input Infinity element number
#define SDP_D_STATUS_INF_INPUT_NUM_ADDR 0xb0d4
// Output NaN element number
#define SDP_D_STATUS_NAN_OUTPUT_NUM_ADDR 0xb0d8
// Enable/Disable performance counting
#define SDP_D_PERF_ENABLE_ADDR 0xb0dc
// Count stall cycles of write DMA for one layer
#define SDP_D_PERF_WDMA_WRITE_STALL_ADDR 0xb0e0
// Element number of both table underflow
#define SDP_D_PERF_LUT_UFLOW_ADDR 0xb0e4
// Element number of both table overflow
#define SDP_D_PERF_LUT_OFLOW_ADDR 0xb0e8
// Element number of both table saturation
#define SDP_D_PERF_OUT_SATURATION_ADDR 0xb0ec
// Element number of both hit, or both miss situation that element underflow one
// table and at the same time overflow the other.
#define SDP_D_PERF_LUT_HYBRID_ADDR 0xb0f0
// Element number of only LE table hit
#define SDP_D_PERF_LUT_LE_HIT_ADDR 0xb0f4
// Element number of only LO table hit
#define SDP_D_PERF_LUT_LO_HIT_ADDR 0xb0f8

}; // namespace ilang

#endif // NVDLA_ADDR_SDP_H__
