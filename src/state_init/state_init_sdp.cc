// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: state_init_sdp.cc

#include <ilang/ilang++.h>
#include <nvdla/configs/state_info.h>
#include <nvdla/utils.h>

// namespace ilang
namespace ilang {

// FIXME this is auto-generated placeholder

void StateInitSdp(Ila& m) {
  // Idle status of two register groups
  m.AddInit(m.state(SDP_S_STATUS) == 0);

  // Pointer for CSB master and data path to access groups
  m.AddInit(m.state(SDP_S_POINTER) == 0);

  // LUT access address and type
  m.AddInit(m.state(SDP_S_LUT_ACCESS_CFG) == 0);

  // Data register of read or write LUT
  m.AddInit(m.state(SDP_S_LUT_ACCESS_DATA) == 0);

  // LUT’s type: exponent or linear. And the selection between LE and LO tables.
  m.AddInit(m.state(SDP_S_LUT_CFG) == 0);

  // LE and LO LUT index offset and selection
  m.AddInit(m.state(SDP_S_LUT_INFO) == 0);

  // Start of LE LUT’s range
  m.AddInit(m.state(SDP_S_LUT_LE_START) == 0);

  // End of LE LUT’s range
  m.AddInit(m.state(SDP_S_LUT_LE_END) == 0);

  // Start of LO LUT’s range
  m.AddInit(m.state(SDP_S_LUT_LO_START) == 0);

  // End of LO LUT’s range
  m.AddInit(m.state(SDP_S_LUT_LO_END) == 0);

  // Slope scale parameter for LE LUT underflow and overflow, signed value
  m.AddInit(m.state(SDP_S_LUT_LE_SLOPE_SCALE) == 0);

  // Slope shift parameter for LE_LUT underflow and overflow, signed value
  m.AddInit(m.state(SDP_S_LUT_LE_SLOPE_SHIFT) == 0);

  // Slope scale parameter for LO LUT underflow and overflow, signed value
  m.AddInit(m.state(SDP_S_LUT_LO_SLOPE_SCALE) == 0);

  // Slope shift parameter for LO_LUT underflow and overflow, signed value
  m.AddInit(m.state(SDP_S_LUT_LO_SLOPE_SHIFT) == 0);

  // Set it to 1 to kick off operation for current register group
  m.AddInit(m.state(SDP_D_OP_ENABLE) == 0);

  // Input cube’s width
  m.AddInit(m.state(SDP_D_DATA_CUBE_WIDTH) == 0);

  // Input cube’s height
  m.AddInit(m.state(SDP_D_DATA_CUBE_HEIGHT) == 0);

  // Input cube’s channel
  m.AddInit(m.state(SDP_D_DATA_CUBE_CHANNEL) == 0);

  // Lower 32bits of output data address
  m.AddInit(m.state(SDP_D_DST_BASE_ADDR_LOW) == 0);

  // Higher 32bits of output data address when axi awaddr is 64bits
  m.AddInit(m.state(SDP_D_DST_BASE_ADDR_HIGH) == 0);

  // Line stride of output data cube
  m.AddInit(m.state(SDP_D_DST_LINE_STRIDE) == 0);

  // Surface stride of output data cube
  m.AddInit(m.state(SDP_D_DST_SURFACE_STRIDE) == 0);

  // Configurations of BS module: bypass, algorithm, etc.
  m.AddInit(m.state(SDP_D_DP_BS_CFG) == 0);

  // Source type and shifter value of BS ALU
  m.AddInit(m.state(SDP_D_DP_BS_ALU_CFG) == 0);

  // Operand value of BS ALU
  m.AddInit(m.state(SDP_D_DP_BS_ALU_SRC_VALUE) == 0);

  // Source type and shifter value of BS MUL
  m.AddInit(m.state(SDP_D_DP_BS_MUL_CFG) == 0);

  // Operand value of BS MUL
  m.AddInit(m.state(SDP_D_DP_BS_MUL_SRC_VALUE) == 0);

  // Configurations of BN module: bypass, algorithm, etc.
  m.AddInit(m.state(SDP_D_DP_BN_CFG) == 0);

  // Source type and shifter value of BN ALU
  m.AddInit(m.state(SDP_D_DP_BN_ALU_CFG) == 0);

  // Operand value of BN ALU
  m.AddInit(m.state(SDP_D_DP_BN_ALU_SRC_VALUE) == 0);

  // Source type and shifter value of BN MUL
  m.AddInit(m.state(SDP_D_DP_BN_MUL_CFG) == 0);

  // Operand value of BN MUL
  m.AddInit(m.state(SDP_D_DP_BN_MUL_SRC_VALUE) == 0);

  // Configurations of EW module: bypass, algorithm, etc.
  m.AddInit(m.state(SDP_D_DP_EW_CFG) == 0);

  // Source type and bypass control of EW ALU
  m.AddInit(m.state(SDP_D_DP_EW_ALU_CFG) == 0);

  // Operand value of EW ALU
  m.AddInit(m.state(SDP_D_DP_EW_ALU_SRC_VALUE) == 0);

  // Converter offset of EW ALU
  m.AddInit(m.state(SDP_D_DP_EW_ALU_CVT_OFFSET_VALUE) == 0);

  // Converter scale of EW ALU
  m.AddInit(m.state(SDP_D_DP_EW_ALU_CVT_SCALE_VALUE) == 0);

  // Converter truncate of EW ALU
  m.AddInit(m.state(SDP_D_DP_EW_ALU_CVT_TRUNCATE_VALUE) == 0);

  // Source type and bypass control of EW MUL
  m.AddInit(m.state(SDP_D_DP_EW_MUL_CFG) == 0);

  // Operand value of EW MUL
  m.AddInit(m.state(SDP_D_DP_EW_MUL_SRC_VALUE) == 0);

  // Converter offset of EW MUL
  m.AddInit(m.state(SDP_D_DP_EW_MUL_CVT_OFFSET_VALUE) == 0);

  // Converter scale of EW MUL
  m.AddInit(m.state(SDP_D_DP_EW_MUL_CVT_SCALE_VALUE) == 0);

  // Converter truncate of EW MUL
  m.AddInit(m.state(SDP_D_DP_EW_MUL_CVT_TRUNCATE_VALUE) == 0);

  // Truncate of EW
  m.AddInit(m.state(SDP_D_DP_EW_TRUNCATE_VALUE) == 0);

  // Operation configuration: flying mode, output destination, Direct or
  // Winograd mode, flush NaN to zero, batch number.
  m.AddInit(m.state(SDP_D_FEATURE_MODE_CFG) == 0);

  // Destination RAM type
  m.AddInit(m.state(SDP_D_DST_DMA_CFG) == 0);

  // Stride of output cubes in batch mode
  m.AddInit(m.state(SDP_D_DST_BATCH_STRIDE) == 0);

  // Data precision
  m.AddInit(m.state(SDP_D_DATA_FORMAT) == 0);

  // Output converter offset
  m.AddInit(m.state(SDP_D_CVT_OFFSET) == 0);

  // Output converter scale
  m.AddInit(m.state(SDP_D_CVT_SCALE) == 0);

  // Output converter shifter value
  m.AddInit(m.state(SDP_D_CVT_SHIFT) == 0);

  // Output of equal mode
  m.AddInit(m.state(SDP_D_STATUS) == 0);

  // Input NaN element number
  m.AddInit(m.state(SDP_D_STATUS_NAN_INPUT_NUM) == 0);

  // Input Infinity element number
  m.AddInit(m.state(SDP_D_STATUS_INF_INPUT_NUM) == 0);

  // Output NaN element number
  m.AddInit(m.state(SDP_D_STATUS_NAN_OUTPUT_NUM) == 0);

  // Enable/Disable performance counting
  m.AddInit(m.state(SDP_D_PERF_ENABLE) == 0);

  // Count stall cycles of write DMA for one layer
  m.AddInit(m.state(SDP_D_PERF_WDMA_WRITE_STALL) == 0);

  // Element number of both table underflow
  m.AddInit(m.state(SDP_D_PERF_LUT_UFLOW) == 0);

  // Element number of both table overflow
  m.AddInit(m.state(SDP_D_PERF_LUT_OFLOW) == 0);

  // Element number of both table saturation
  m.AddInit(m.state(SDP_D_PERF_OUT_SATURATION) == 0);

  // Element number of both hit, or both miss situation that element underflow
  // one table and at the same time overflow the other.
  m.AddInit(m.state(SDP_D_PERF_LUT_HYBRID) == 0);

  // Element number of only LE table hit
  m.AddInit(m.state(SDP_D_PERF_LUT_LE_HIT) == 0);

  // Element number of only LO table hit
  m.AddInit(m.state(SDP_D_PERF_LUT_LO_HIT) == 0);

  return;
}

}; // namespace ilang
