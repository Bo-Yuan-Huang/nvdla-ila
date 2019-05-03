// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: state_define_sdp.cc

#include <ilang/ilang++.h>
#include <nvdla/configs/state_info.h>
#include <nvdla/utils.h>

// namespace ilang
namespace ilang {

void StateDefineSdp(Ila& m) {
  // Idle status of two register groups
  NewState(m, SDP_S_STATUS, SDP_S_STATUS_BWID);

  // Pointer for CSB master and data path to access groups
  NewState(m, SDP_S_POINTER, SDP_S_POINTER_BWID);

  // LUT access address and type
  NewState(m, SDP_S_LUT_ACCESS_CFG, SDP_S_LUT_ACCESS_CFG_BWID);

  // Data register of read or write LUT
  NewState(m, SDP_S_LUT_ACCESS_DATA, SDP_S_LUT_ACCESS_DATA_BWID);

  // LUT’s type: exponent or linear. And the selection between LE and LO tables.
  NewState(m, SDP_S_LUT_CFG, SDP_S_LUT_CFG_BWID);

  // LE and LO LUT index offset and selection
  NewState(m, SDP_S_LUT_INFO, SDP_S_LUT_INFO_BWID);

  // Start of LE LUT’s range
  NewState(m, SDP_S_LUT_LE_START, SDP_S_LUT_LE_START_BWID);

  // End of LE LUT’s range
  NewState(m, SDP_S_LUT_LE_END, SDP_S_LUT_LE_END_BWID);

  // Start of LO LUT’s range
  NewState(m, SDP_S_LUT_LO_START, SDP_S_LUT_LO_START_BWID);

  // End of LO LUT’s range
  NewState(m, SDP_S_LUT_LO_END, SDP_S_LUT_LO_END_BWID);

  // Slope scale parameter for LE LUT underflow and overflow, signed value
  NewState(m, SDP_S_LUT_LE_SLOPE_SCALE, SDP_S_LUT_LE_SLOPE_SCALE_BWID);

  // Slope shift parameter for LE_LUT underflow and overflow, signed value
  NewState(m, SDP_S_LUT_LE_SLOPE_SHIFT, SDP_S_LUT_LE_SLOPE_SHIFT_BWID);

  // Slope scale parameter for LO LUT underflow and overflow, signed value
  NewState(m, SDP_S_LUT_LO_SLOPE_SCALE, SDP_S_LUT_LO_SLOPE_SCALE_BWID);

  // Slope shift parameter for LO_LUT underflow and overflow, signed value
  NewState(m, SDP_S_LUT_LO_SLOPE_SHIFT, SDP_S_LUT_LO_SLOPE_SHIFT_BWID);

  // Set it to 1 to kick off operation for current register group
  NewState(m, SDP_D_OP_ENABLE_G0, SDP_D_OP_ENABLE_BWID);
  NewState(m, SDP_D_OP_ENABLE_G1, SDP_D_OP_ENABLE_BWID);

  // Input cube’s width
  NewState(m, SDP_D_DATA_CUBE_WIDTH_G0, SDP_D_DATA_CUBE_WIDTH_BWID);
  NewState(m, SDP_D_DATA_CUBE_WIDTH_G1, SDP_D_DATA_CUBE_WIDTH_BWID);

  // Input cube’s height
  NewState(m, SDP_D_DATA_CUBE_HEIGHT_G0, SDP_D_DATA_CUBE_HEIGHT_BWID);
  NewState(m, SDP_D_DATA_CUBE_HEIGHT_G1, SDP_D_DATA_CUBE_HEIGHT_BWID);

  // Input cube’s channel
  NewState(m, SDP_D_DATA_CUBE_CHANNEL_G0, SDP_D_DATA_CUBE_CHANNEL_BWID);
  NewState(m, SDP_D_DATA_CUBE_CHANNEL_G1, SDP_D_DATA_CUBE_CHANNEL_BWID);

  // Lower 32bits of output data address
  NewState(m, SDP_D_DST_BASE_ADDR_LOW_G0, SDP_D_DST_BASE_ADDR_LOW_BWID);
  NewState(m, SDP_D_DST_BASE_ADDR_LOW_G1, SDP_D_DST_BASE_ADDR_LOW_BWID);

  // Higher 32bits of output data address when axi awaddr is 64bits
  NewState(m, SDP_D_DST_BASE_ADDR_HIGH_G0, SDP_D_DST_BASE_ADDR_HIGH_BWID);
  NewState(m, SDP_D_DST_BASE_ADDR_HIGH_G1, SDP_D_DST_BASE_ADDR_HIGH_BWID);

  // Line stride of output data cube
  NewState(m, SDP_D_DST_LINE_STRIDE_G0, SDP_D_DST_LINE_STRIDE_BWID);
  NewState(m, SDP_D_DST_LINE_STRIDE_G1, SDP_D_DST_LINE_STRIDE_BWID);

  // Surface stride of output data cube
  NewState(m, SDP_D_DST_SURFACE_STRIDE_G0, SDP_D_DST_SURFACE_STRIDE_BWID);
  NewState(m, SDP_D_DST_SURFACE_STRIDE_G1, SDP_D_DST_SURFACE_STRIDE_BWID);

  // Configurations of BS module: bypass, algorithm, etc.
  NewState(m, SDP_D_DP_BS_CFG_G0, SDP_D_DP_BS_CFG_BWID);
  NewState(m, SDP_D_DP_BS_CFG_G1, SDP_D_DP_BS_CFG_BWID);

  // Source type and shifter value of BS ALU
  NewState(m, SDP_D_DP_BS_ALU_CFG_G0, SDP_D_DP_BS_ALU_CFG_BWID);
  NewState(m, SDP_D_DP_BS_ALU_CFG_G1, SDP_D_DP_BS_ALU_CFG_BWID);

  // Operand value of BS ALU
  NewState(m, SDP_D_DP_BS_ALU_SRC_VALUE_G0, SDP_D_DP_BS_ALU_SRC_VALUE_BWID);
  NewState(m, SDP_D_DP_BS_ALU_SRC_VALUE_G1, SDP_D_DP_BS_ALU_SRC_VALUE_BWID);

  // Source type and shifter value of BS MUL
  NewState(m, SDP_D_DP_BS_MUL_CFG_G0, SDP_D_DP_BS_MUL_CFG_BWID);
  NewState(m, SDP_D_DP_BS_MUL_CFG_G1, SDP_D_DP_BS_MUL_CFG_BWID);

  // Operand value of BS MUL
  NewState(m, SDP_D_DP_BS_MUL_SRC_VALUE_G0, SDP_D_DP_BS_MUL_SRC_VALUE_BWID);
  NewState(m, SDP_D_DP_BS_MUL_SRC_VALUE_G1, SDP_D_DP_BS_MUL_SRC_VALUE_BWID);

  // Configurations of BN module: bypass, algorithm, etc.
  NewState(m, SDP_D_DP_BN_CFG_G0, SDP_D_DP_BN_CFG_BWID);
  NewState(m, SDP_D_DP_BN_CFG_G1, SDP_D_DP_BN_CFG_BWID);

  // Source type and shifter value of BN ALU
  NewState(m, SDP_D_DP_BN_ALU_CFG_G0, SDP_D_DP_BN_ALU_CFG_BWID);
  NewState(m, SDP_D_DP_BN_ALU_CFG_G1, SDP_D_DP_BN_ALU_CFG_BWID);

  // Operand value of BN ALU
  NewState(m, SDP_D_DP_BN_ALU_SRC_VALUE_G0, SDP_D_DP_BN_ALU_SRC_VALUE_BWID);
  NewState(m, SDP_D_DP_BN_ALU_SRC_VALUE_G1, SDP_D_DP_BN_ALU_SRC_VALUE_BWID);

  // Source type and shifter value of BN MUL
  NewState(m, SDP_D_DP_BN_MUL_CFG_G0, SDP_D_DP_BN_MUL_CFG_BWID);
  NewState(m, SDP_D_DP_BN_MUL_CFG_G1, SDP_D_DP_BN_MUL_CFG_BWID);

  // Operand value of BN MUL
  NewState(m, SDP_D_DP_BN_MUL_SRC_VALUE_G0, SDP_D_DP_BN_MUL_SRC_VALUE_BWID);
  NewState(m, SDP_D_DP_BN_MUL_SRC_VALUE_G1, SDP_D_DP_BN_MUL_SRC_VALUE_BWID);

  // Configurations of EW module: bypass, algorithm, etc.
  NewState(m, SDP_D_DP_EW_CFG_G0, SDP_D_DP_EW_CFG_BWID);
  NewState(m, SDP_D_DP_EW_CFG_G1, SDP_D_DP_EW_CFG_BWID);

  // Source type and bypass control of EW ALU
  NewState(m, SDP_D_DP_EW_ALU_CFG_G0, SDP_D_DP_EW_ALU_CFG_BWID);
  NewState(m, SDP_D_DP_EW_ALU_CFG_G1, SDP_D_DP_EW_ALU_CFG_BWID);

  // Operand value of EW ALU
  NewState(m, SDP_D_DP_EW_ALU_SRC_VALUE_G0, SDP_D_DP_EW_ALU_SRC_VALUE_BWID);
  NewState(m, SDP_D_DP_EW_ALU_SRC_VALUE_G1, SDP_D_DP_EW_ALU_SRC_VALUE_BWID);

  // Converter offset of EW ALU
  NewState(m, SDP_D_DP_EW_ALU_CVT_OFFSET_VALUE_G0,
           SDP_D_DP_EW_ALU_CVT_OFFSET_VALUE_BWID);
  NewState(m, SDP_D_DP_EW_ALU_CVT_OFFSET_VALUE_G1,
           SDP_D_DP_EW_ALU_CVT_OFFSET_VALUE_BWID);

  // Converter scale of EW ALU
  NewState(m, SDP_D_DP_EW_ALU_CVT_SCALE_VALUE_G0,
           SDP_D_DP_EW_ALU_CVT_SCALE_VALUE_BWID);
  NewState(m, SDP_D_DP_EW_ALU_CVT_SCALE_VALUE_G1,
           SDP_D_DP_EW_ALU_CVT_SCALE_VALUE_BWID);

  // Converter truncate of EW ALU
  NewState(m, SDP_D_DP_EW_ALU_CVT_TRUNCATE_VALUE_G0,
           SDP_D_DP_EW_ALU_CVT_TRUNCATE_VALUE_BWID);
  NewState(m, SDP_D_DP_EW_ALU_CVT_TRUNCATE_VALUE_G1,
           SDP_D_DP_EW_ALU_CVT_TRUNCATE_VALUE_BWID);

  // Source type and bypass control of EW MUL
  NewState(m, SDP_D_DP_EW_MUL_CFG_G0, SDP_D_DP_EW_MUL_CFG_BWID);
  NewState(m, SDP_D_DP_EW_MUL_CFG_G1, SDP_D_DP_EW_MUL_CFG_BWID);

  // Operand value of EW MUL
  NewState(m, SDP_D_DP_EW_MUL_SRC_VALUE_G0, SDP_D_DP_EW_MUL_SRC_VALUE_BWID);
  NewState(m, SDP_D_DP_EW_MUL_SRC_VALUE_G1, SDP_D_DP_EW_MUL_SRC_VALUE_BWID);

  // Converter offset of EW MUL
  NewState(m, SDP_D_DP_EW_MUL_CVT_OFFSET_VALUE_G0,
           SDP_D_DP_EW_MUL_CVT_OFFSET_VALUE_BWID);
  NewState(m, SDP_D_DP_EW_MUL_CVT_OFFSET_VALUE_G1,
           SDP_D_DP_EW_MUL_CVT_OFFSET_VALUE_BWID);

  // Converter scale of EW MUL
  NewState(m, SDP_D_DP_EW_MUL_CVT_SCALE_VALUE_G0,
           SDP_D_DP_EW_MUL_CVT_SCALE_VALUE_BWID);
  NewState(m, SDP_D_DP_EW_MUL_CVT_SCALE_VALUE_G1,
           SDP_D_DP_EW_MUL_CVT_SCALE_VALUE_BWID);

  // Converter truncate of EW MUL
  NewState(m, SDP_D_DP_EW_MUL_CVT_TRUNCATE_VALUE_G0,
           SDP_D_DP_EW_MUL_CVT_TRUNCATE_VALUE_BWID);
  NewState(m, SDP_D_DP_EW_MUL_CVT_TRUNCATE_VALUE_G1,
           SDP_D_DP_EW_MUL_CVT_TRUNCATE_VALUE_BWID);

  // Truncate of EW
  NewState(m, SDP_D_DP_EW_TRUNCATE_VALUE_G0, SDP_D_DP_EW_TRUNCATE_VALUE_BWID);
  NewState(m, SDP_D_DP_EW_TRUNCATE_VALUE_G1, SDP_D_DP_EW_TRUNCATE_VALUE_BWID);

  // Operation configuration: flying mode, output destination, Direct or
  // Winograd mode, flush NaN to zero, batch number.
  NewState(m, SDP_D_FEATURE_MODE_CFG_G0, SDP_D_FEATURE_MODE_CFG_BWID);
  NewState(m, SDP_D_FEATURE_MODE_CFG_G1, SDP_D_FEATURE_MODE_CFG_BWID);

  // Destination RAM type
  NewState(m, SDP_D_DST_DMA_CFG_G0, SDP_D_DST_DMA_CFG_BWID);
  NewState(m, SDP_D_DST_DMA_CFG_G1, SDP_D_DST_DMA_CFG_BWID);

  // Stride of output cubes in batch mode
  NewState(m, SDP_D_DST_BATCH_STRIDE_G0, SDP_D_DST_BATCH_STRIDE_BWID);
  NewState(m, SDP_D_DST_BATCH_STRIDE_G1, SDP_D_DST_BATCH_STRIDE_BWID);

  // Data precision
  NewState(m, SDP_D_DATA_FORMAT_G0, SDP_D_DATA_FORMAT_BWID);
  NewState(m, SDP_D_DATA_FORMAT_G1, SDP_D_DATA_FORMAT_BWID);

  // Output converter offset
  NewState(m, SDP_D_CVT_OFFSET_G0, SDP_D_CVT_OFFSET_BWID);
  NewState(m, SDP_D_CVT_OFFSET_G1, SDP_D_CVT_OFFSET_BWID);

  // Output converter scale
  NewState(m, SDP_D_CVT_SCALE_G0, SDP_D_CVT_SCALE_BWID);
  NewState(m, SDP_D_CVT_SCALE_G1, SDP_D_CVT_SCALE_BWID);

  // Output converter shifter value
  NewState(m, SDP_D_CVT_SHIFT_G0, SDP_D_CVT_SHIFT_BWID);
  NewState(m, SDP_D_CVT_SHIFT_G1, SDP_D_CVT_SHIFT_BWID);

  // Output of equal mode
  NewState(m, SDP_D_STATUS_G0, SDP_D_STATUS_BWID);
  NewState(m, SDP_D_STATUS_G1, SDP_D_STATUS_BWID);

  // Input NaN element number
  NewState(m, SDP_D_STATUS_NAN_INPUT_NUM_G0, SDP_D_STATUS_NAN_INPUT_NUM_BWID);
  NewState(m, SDP_D_STATUS_NAN_INPUT_NUM_G1, SDP_D_STATUS_NAN_INPUT_NUM_BWID);

  // Input Infinity element number
  NewState(m, SDP_D_STATUS_INF_INPUT_NUM_G0, SDP_D_STATUS_INF_INPUT_NUM_BWID);
  NewState(m, SDP_D_STATUS_INF_INPUT_NUM_G1, SDP_D_STATUS_INF_INPUT_NUM_BWID);

  // Output NaN element number
  NewState(m, SDP_D_STATUS_NAN_OUTPUT_NUM_G0, SDP_D_STATUS_NAN_OUTPUT_NUM_BWID);
  NewState(m, SDP_D_STATUS_NAN_OUTPUT_NUM_G1, SDP_D_STATUS_NAN_OUTPUT_NUM_BWID);

  // Enable/Disable performance counting
  NewState(m, SDP_D_PERF_ENABLE_G0, SDP_D_PERF_ENABLE_BWID);
  NewState(m, SDP_D_PERF_ENABLE_G1, SDP_D_PERF_ENABLE_BWID);

  // Count stall cycles of write DMA for one layer
  NewState(m, SDP_D_PERF_WDMA_WRITE_STALL_G0, SDP_D_PERF_WDMA_WRITE_STALL_BWID);
  NewState(m, SDP_D_PERF_WDMA_WRITE_STALL_G1, SDP_D_PERF_WDMA_WRITE_STALL_BWID);

  // Element number of both table underflow
  NewState(m, SDP_D_PERF_LUT_UFLOW_G0, SDP_D_PERF_LUT_UFLOW_BWID);
  NewState(m, SDP_D_PERF_LUT_UFLOW_G1, SDP_D_PERF_LUT_UFLOW_BWID);

  // Element number of both table overflow
  NewState(m, SDP_D_PERF_LUT_OFLOW_G0, SDP_D_PERF_LUT_OFLOW_BWID);
  NewState(m, SDP_D_PERF_LUT_OFLOW_G1, SDP_D_PERF_LUT_OFLOW_BWID);

  // Element number of both table saturation
  NewState(m, SDP_D_PERF_OUT_SATURATION_G0, SDP_D_PERF_OUT_SATURATION_BWID);
  NewState(m, SDP_D_PERF_OUT_SATURATION_G1, SDP_D_PERF_OUT_SATURATION_BWID);

  // Element number of both hit, or both miss situation that element underflow
  // one table and at the same time overflow the other.
  NewState(m, SDP_D_PERF_LUT_HYBRID_G0, SDP_D_PERF_LUT_HYBRID_BWID);
  NewState(m, SDP_D_PERF_LUT_HYBRID_G1, SDP_D_PERF_LUT_HYBRID_BWID);

  // Element number of only LE table hit
  NewState(m, SDP_D_PERF_LUT_LE_HIT_G0, SDP_D_PERF_LUT_LE_HIT_BWID);
  NewState(m, SDP_D_PERF_LUT_LE_HIT_G1, SDP_D_PERF_LUT_LE_HIT_BWID);

  // Element number of only LO table hit
  NewState(m, SDP_D_PERF_LUT_LO_HIT_G0, SDP_D_PERF_LUT_LO_HIT_BWID);
  NewState(m, SDP_D_PERF_LUT_LO_HIT_G1, SDP_D_PERF_LUT_LO_HIT_BWID);

  return;
}

}; // namespace ilang
