// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: state_init_pdp.cc

#include <ilang/ilang++.h>
#include <nvdla/configs/state_info.h>
#include <nvdla/utils.h>

// namespace ilang
namespace ilang {

// FIXME this is auto-generated placeholder

void StateInitPdp(Ila& m) {
  // Idle status of two register groups
  m.AddInit(m.state(PDP_S_STATUS) == 0);

  // Pointer for CSB master and data path to access groups
  m.AddInit(m.state(PDP_S_POINTER) == 0);

  // Set it to 1 to kick off operation for current register group
  m.AddInit(m.state(PDP_D_OP_ENABLE_G0) == 0);
  m.AddInit(m.state(PDP_D_OP_ENABLE_G1) == 0);

  // Input data cube’s width
  m.AddInit(m.state(PDP_D_DATA_CUBE_IN_WIDTH_G0) == 0);
  m.AddInit(m.state(PDP_D_DATA_CUBE_IN_WIDTH_G1) == 0);

  // Input data cube’s height
  m.AddInit(m.state(PDP_D_DATA_CUBE_IN_HEIGHT_G0) == 0);
  m.AddInit(m.state(PDP_D_DATA_CUBE_IN_HEIGHT_G1) == 0);

  // Input data cube’s channel
  m.AddInit(m.state(PDP_D_DATA_CUBE_IN_CHANNEL_G0) == 0);
  m.AddInit(m.state(PDP_D_DATA_CUBE_IN_CHANNEL_G1) == 0);

  // Output data cube’s width
  m.AddInit(m.state(PDP_D_DATA_CUBE_OUT_WIDTH_G0) == 0);
  m.AddInit(m.state(PDP_D_DATA_CUBE_OUT_WIDTH_G1) == 0);

  // Output data cube’s height
  m.AddInit(m.state(PDP_D_DATA_CUBE_OUT_HEIGHT_G0) == 0);
  m.AddInit(m.state(PDP_D_DATA_CUBE_OUT_HEIGHT_G1) == 0);

  // Output data cube’s channel
  m.AddInit(m.state(PDP_D_DATA_CUBE_OUT_CHANNEL_G0) == 0);
  m.AddInit(m.state(PDP_D_DATA_CUBE_OUT_CHANNEL_G1) == 0);

  // Split number
  m.AddInit(m.state(PDP_D_OPERATION_MODE_CFG_G0) == 0);
  m.AddInit(m.state(PDP_D_OPERATION_MODE_CFG_G1) == 0);

  // Option to flush input NaN to zero
  m.AddInit(m.state(PDP_D_NAN_FLUSH_TO_ZERO_G0) == 0);
  m.AddInit(m.state(PDP_D_NAN_FLUSH_TO_ZERO_G1) == 0);

  // Partial width for first, last and middle partitions of input cube
  m.AddInit(m.state(PDP_D_PARTIAL_WIDTH_IN_G0) == 0);
  m.AddInit(m.state(PDP_D_PARTIAL_WIDTH_IN_G1) == 0);

  // Partial width for first, last and middle partitions of output cube
  m.AddInit(m.state(PDP_D_PARTIAL_WIDTH_OUT_G0) == 0);
  m.AddInit(m.state(PDP_D_PARTIAL_WIDTH_OUT_G1) == 0);

  // Kernel width and kernel stride
  m.AddInit(m.state(PDP_D_POOLING_KERNEL_CFG_G0) == 0);
  m.AddInit(m.state(PDP_D_POOLING_KERNEL_CFG_G1) == 0);

  // Reciprocal of pooling kernel width, set to actual value * (2^16) when
  // INT8/INT16 format enabled. and set to actual value for fp16 precision mode
  // with fp17 data format.
  m.AddInit(m.state(PDP_D_RECIP_KERNEL_WIDTH_G0) == 0);
  m.AddInit(m.state(PDP_D_RECIP_KERNEL_WIDTH_G1) == 0);

  // Reciprocal of pooling kernel height, set to actual value * (2^16) when
  // INT8/INT16 format enabled. and set to actual value for fp16 precision mode
  // with fp17 data format.
  m.AddInit(m.state(PDP_D_RECIP_KERNEL_HEIGHT_G0) == 0);
  m.AddInit(m.state(PDP_D_RECIP_KERNEL_HEIGHT_G1) == 0);

  // Left/right/top/bottom padding size
  m.AddInit(m.state(PDP_D_POOLING_PADDING_CFG_G0) == 0);
  m.AddInit(m.state(PDP_D_POOLING_PADDING_CFG_G1) == 0);

  // Padding_value*1
  m.AddInit(m.state(PDP_D_POOLING_PADDING_VALUE_1_CFG_G0) == 0);
  m.AddInit(m.state(PDP_D_POOLING_PADDING_VALUE_1_CFG_G1) == 0);

  // Padding_value*2
  m.AddInit(m.state(PDP_D_POOLING_PADDING_VALUE_2_CFG_G0) == 0);
  m.AddInit(m.state(PDP_D_POOLING_PADDING_VALUE_2_CFG_G1) == 0);

  // Padding_value*3
  m.AddInit(m.state(PDP_D_POOLING_PADDING_VALUE_3_CFG_G0) == 0);
  m.AddInit(m.state(PDP_D_POOLING_PADDING_VALUE_3_CFG_G1) == 0);

  // Padding_value*4
  m.AddInit(m.state(PDP_D_POOLING_PADDING_VALUE_4_CFG_G0) == 0);
  m.AddInit(m.state(PDP_D_POOLING_PADDING_VALUE_4_CFG_G1) == 0);

  // Padding_value*5
  m.AddInit(m.state(PDP_D_POOLING_PADDING_VALUE_5_CFG_G0) == 0);
  m.AddInit(m.state(PDP_D_POOLING_PADDING_VALUE_5_CFG_G1) == 0);

  // Padding_value*6
  m.AddInit(m.state(PDP_D_POOLING_PADDING_VALUE_6_CFG_G0) == 0);
  m.AddInit(m.state(PDP_D_POOLING_PADDING_VALUE_6_CFG_G1) == 0);

  // Padding_value*7
  m.AddInit(m.state(PDP_D_POOLING_PADDING_VALUE_7_CFG_G0) == 0);
  m.AddInit(m.state(PDP_D_POOLING_PADDING_VALUE_7_CFG_G1) == 0);

  // Lower 32bits of input data address
  m.AddInit(m.state(PDP_D_SRC_BASE_ADDR_LOW_G0) == 0);
  m.AddInit(m.state(PDP_D_SRC_BASE_ADDR_LOW_G1) == 0);

  // Higher 32bits of input data address when axi araddr is 64bits
  m.AddInit(m.state(PDP_D_SRC_BASE_ADDR_HIGH_G0) == 0);
  m.AddInit(m.state(PDP_D_SRC_BASE_ADDR_HIGH_G1) == 0);

  // Line stride of input cube
  m.AddInit(m.state(PDP_D_SRC_LINE_STRIDE_G0) == 0);
  m.AddInit(m.state(PDP_D_SRC_LINE_STRIDE_G1) == 0);

  // Surface stride of input cube
  m.AddInit(m.state(PDP_D_SRC_SURFACE_STRIDE_G0) == 0);
  m.AddInit(m.state(PDP_D_SRC_SURFACE_STRIDE_G1) == 0);

  // Lower 32bits of output data address
  m.AddInit(m.state(PDP_D_DST_BASE_ADDR_LOW_G0) == 0);
  m.AddInit(m.state(PDP_D_DST_BASE_ADDR_LOW_G1) == 0);

  // Higher 32bits of output data address when axi awaddr is 64bits
  m.AddInit(m.state(PDP_D_DST_BASE_ADDR_HIGH_G0) == 0);
  m.AddInit(m.state(PDP_D_DST_BASE_ADDR_HIGH_G1) == 0);

  // Line stride of output cube
  m.AddInit(m.state(PDP_D_DST_LINE_STRIDE_G0) == 0);
  m.AddInit(m.state(PDP_D_DST_LINE_STRIDE_G1) == 0);

  // Surface stride of output cube
  m.AddInit(m.state(PDP_D_DST_SURFACE_STRIDE_G0) == 0);
  m.AddInit(m.state(PDP_D_DST_SURFACE_STRIDE_G1) == 0);

  // RAM type of destination cube
  m.AddInit(m.state(PDP_D_DST_RAM_CFG_G0) == 0);
  m.AddInit(m.state(PDP_D_DST_RAM_CFG_G1) == 0);

  // Precision of input data
  m.AddInit(m.state(PDP_D_DATA_FORMAT_G0) == 0);
  m.AddInit(m.state(PDP_D_DATA_FORMAT_G1) == 0);

  // Input infinity element number
  m.AddInit(m.state(PDP_D_INF_INPUT_NUM_G0) == 0);
  m.AddInit(m.state(PDP_D_INF_INPUT_NUM_G1) == 0);

  // Input NaN element number
  m.AddInit(m.state(PDP_D_NAN_INPUT_NUM_G0) == 0);
  m.AddInit(m.state(PDP_D_NAN_INPUT_NUM_G1) == 0);

  // Output NaN element number
  m.AddInit(m.state(PDP_D_NAN_OUTPUT_NUM_G0) == 0);
  m.AddInit(m.state(PDP_D_NAN_OUTPUT_NUM_G1) == 0);

  // Enable/disable performance counting
  m.AddInit(m.state(PDP_D_PERF_ENABLE_G0) == 0);
  m.AddInit(m.state(PDP_D_PERF_ENABLE_G1) == 0);

  // Counting stalls of write requests
  m.AddInit(m.state(PDP_D_PERF_WRITE_STALL_G0) == 0);
  m.AddInit(m.state(PDP_D_PERF_WRITE_STALL_G1) == 0);

  return;
}

}; // namespace ilang
