// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: state_define_pdp.cc

#include <ilang/ilang++.h>
#include <nvdla/configs/state_info.h>
#include <nvdla/utils.h>

// namespace ilang
namespace ilang {

void StateDefinePdp(Ila& m) {
  // Idle status of two register groups
  NewState(m, PDP_S_STATUS, PDP_S_STATUS_BWID);

  // Pointer for CSB master and data path to access groups
  NewState(m, PDP_S_POINTER, PDP_S_POINTER_BWID);

  // Set it to 1 to kick off operation for current register group
  NewState(m, PDP_D_OP_ENABLE_G0, PDP_D_OP_ENABLE_BWID);
  NewState(m, PDP_D_OP_ENABLE_G1, PDP_D_OP_ENABLE_BWID);

  // Input data cube’s width
  NewState(m, PDP_D_DATA_CUBE_IN_WIDTH_G0, PDP_D_DATA_CUBE_IN_WIDTH_BWID);
  NewState(m, PDP_D_DATA_CUBE_IN_WIDTH_G1, PDP_D_DATA_CUBE_IN_WIDTH_BWID);

  // Input data cube’s height
  NewState(m, PDP_D_DATA_CUBE_IN_HEIGHT_G0, PDP_D_DATA_CUBE_IN_HEIGHT_BWID);
  NewState(m, PDP_D_DATA_CUBE_IN_HEIGHT_G1, PDP_D_DATA_CUBE_IN_HEIGHT_BWID);

  // Input data cube’s channel
  NewState(m, PDP_D_DATA_CUBE_IN_CHANNEL_G0, PDP_D_DATA_CUBE_IN_CHANNEL_BWID);
  NewState(m, PDP_D_DATA_CUBE_IN_CHANNEL_G1, PDP_D_DATA_CUBE_IN_CHANNEL_BWID);

  // Output data cube’s width
  NewState(m, PDP_D_DATA_CUBE_OUT_WIDTH_G0, PDP_D_DATA_CUBE_OUT_WIDTH_BWID);
  NewState(m, PDP_D_DATA_CUBE_OUT_WIDTH_G1, PDP_D_DATA_CUBE_OUT_WIDTH_BWID);

  // Output data cube’s height
  NewState(m, PDP_D_DATA_CUBE_OUT_HEIGHT_G0, PDP_D_DATA_CUBE_OUT_HEIGHT_BWID);
  NewState(m, PDP_D_DATA_CUBE_OUT_HEIGHT_G1, PDP_D_DATA_CUBE_OUT_HEIGHT_BWID);

  // Output data cube’s channel
  NewState(m, PDP_D_DATA_CUBE_OUT_CHANNEL_G0, PDP_D_DATA_CUBE_OUT_CHANNEL_BWID);
  NewState(m, PDP_D_DATA_CUBE_OUT_CHANNEL_G1, PDP_D_DATA_CUBE_OUT_CHANNEL_BWID);

  // Split number
  NewState(m, PDP_D_OPERATION_MODE_CFG_G0, PDP_D_OPERATION_MODE_CFG_BWID);
  NewState(m, PDP_D_OPERATION_MODE_CFG_G1, PDP_D_OPERATION_MODE_CFG_BWID);

  // Option to flush input NaN to zero
  NewState(m, PDP_D_NAN_FLUSH_TO_ZERO_G0, PDP_D_NAN_FLUSH_TO_ZERO_BWID);
  NewState(m, PDP_D_NAN_FLUSH_TO_ZERO_G1, PDP_D_NAN_FLUSH_TO_ZERO_BWID);

  // Partial width for first, last and middle partitions of input cube
  NewState(m, PDP_D_PARTIAL_WIDTH_IN_G0, PDP_D_PARTIAL_WIDTH_IN_BWID);
  NewState(m, PDP_D_PARTIAL_WIDTH_IN_G1, PDP_D_PARTIAL_WIDTH_IN_BWID);

  // Partial width for first, last and middle partitions of output cube
  NewState(m, PDP_D_PARTIAL_WIDTH_OUT_G0, PDP_D_PARTIAL_WIDTH_OUT_BWID);
  NewState(m, PDP_D_PARTIAL_WIDTH_OUT_G1, PDP_D_PARTIAL_WIDTH_OUT_BWID);

  // Kernel width and kernel stride
  NewState(m, PDP_D_POOLING_KERNEL_CFG_G0, PDP_D_POOLING_KERNEL_CFG_BWID);
  NewState(m, PDP_D_POOLING_KERNEL_CFG_G1, PDP_D_POOLING_KERNEL_CFG_BWID);

  // Reciprocal of pooling kernel width, set to actual value * (2^16) when
  // INT8/INT16 format enabled. and set to actual value for fp16 precision mode
  // with fp17 data format.
  NewState(m, PDP_D_RECIP_KERNEL_WIDTH_G0, PDP_D_RECIP_KERNEL_WIDTH_BWID);
  NewState(m, PDP_D_RECIP_KERNEL_WIDTH_G1, PDP_D_RECIP_KERNEL_WIDTH_BWID);

  // Reciprocal of pooling kernel height, set to actual value * (2^16) when
  // INT8/INT16 format enabled. and set to actual value for fp16 precision mode
  // with fp17 data format.
  NewState(m, PDP_D_RECIP_KERNEL_HEIGHT_G0, PDP_D_RECIP_KERNEL_HEIGHT_BWID);
  NewState(m, PDP_D_RECIP_KERNEL_HEIGHT_G1, PDP_D_RECIP_KERNEL_HEIGHT_BWID);

  // Left/right/top/bottom padding size
  NewState(m, PDP_D_POOLING_PADDING_CFG_G0, PDP_D_POOLING_PADDING_CFG_BWID);
  NewState(m, PDP_D_POOLING_PADDING_CFG_G1, PDP_D_POOLING_PADDING_CFG_BWID);

  // Padding_value*1
  NewState(m, PDP_D_POOLING_PADDING_VALUE_1_CFG_G0,
           PDP_D_POOLING_PADDING_VALUE_1_CFG_BWID);
  NewState(m, PDP_D_POOLING_PADDING_VALUE_1_CFG_G1,
           PDP_D_POOLING_PADDING_VALUE_1_CFG_BWID);

  // Padding_value*2
  NewState(m, PDP_D_POOLING_PADDING_VALUE_2_CFG_G0,
           PDP_D_POOLING_PADDING_VALUE_2_CFG_BWID);
  NewState(m, PDP_D_POOLING_PADDING_VALUE_2_CFG_G1,
           PDP_D_POOLING_PADDING_VALUE_2_CFG_BWID);

  // Padding_value*3
  NewState(m, PDP_D_POOLING_PADDING_VALUE_3_CFG_G0,
           PDP_D_POOLING_PADDING_VALUE_3_CFG_BWID);
  NewState(m, PDP_D_POOLING_PADDING_VALUE_3_CFG_G1,
           PDP_D_POOLING_PADDING_VALUE_3_CFG_BWID);

  // Padding_value*4
  NewState(m, PDP_D_POOLING_PADDING_VALUE_4_CFG_G0,
           PDP_D_POOLING_PADDING_VALUE_4_CFG_BWID);
  NewState(m, PDP_D_POOLING_PADDING_VALUE_4_CFG_G1,
           PDP_D_POOLING_PADDING_VALUE_4_CFG_BWID);

  // Padding_value*5
  NewState(m, PDP_D_POOLING_PADDING_VALUE_5_CFG_G0,
           PDP_D_POOLING_PADDING_VALUE_5_CFG_BWID);
  NewState(m, PDP_D_POOLING_PADDING_VALUE_5_CFG_G1,
           PDP_D_POOLING_PADDING_VALUE_5_CFG_BWID);

  // Padding_value*6
  NewState(m, PDP_D_POOLING_PADDING_VALUE_6_CFG_G0,
           PDP_D_POOLING_PADDING_VALUE_6_CFG_BWID);
  NewState(m, PDP_D_POOLING_PADDING_VALUE_6_CFG_G1,
           PDP_D_POOLING_PADDING_VALUE_6_CFG_BWID);

  // Padding_value*7
  NewState(m, PDP_D_POOLING_PADDING_VALUE_7_CFG_G0,
           PDP_D_POOLING_PADDING_VALUE_7_CFG_BWID);
  NewState(m, PDP_D_POOLING_PADDING_VALUE_7_CFG_G1,
           PDP_D_POOLING_PADDING_VALUE_7_CFG_BWID);

  // Lower 32bits of input data address
  NewState(m, PDP_D_SRC_BASE_ADDR_LOW_G0, PDP_D_SRC_BASE_ADDR_LOW_BWID);
  NewState(m, PDP_D_SRC_BASE_ADDR_LOW_G1, PDP_D_SRC_BASE_ADDR_LOW_BWID);

  // Higher 32bits of input data address when axi araddr is 64bits
  NewState(m, PDP_D_SRC_BASE_ADDR_HIGH_G0, PDP_D_SRC_BASE_ADDR_HIGH_BWID);
  NewState(m, PDP_D_SRC_BASE_ADDR_HIGH_G1, PDP_D_SRC_BASE_ADDR_HIGH_BWID);

  // Line stride of input cube
  NewState(m, PDP_D_SRC_LINE_STRIDE_G0, PDP_D_SRC_LINE_STRIDE_BWID);
  NewState(m, PDP_D_SRC_LINE_STRIDE_G1, PDP_D_SRC_LINE_STRIDE_BWID);

  // Surface stride of input cube
  NewState(m, PDP_D_SRC_SURFACE_STRIDE_G0, PDP_D_SRC_SURFACE_STRIDE_BWID);
  NewState(m, PDP_D_SRC_SURFACE_STRIDE_G1, PDP_D_SRC_SURFACE_STRIDE_BWID);

  // Lower 32bits of output data address
  NewState(m, PDP_D_DST_BASE_ADDR_LOW_G0, PDP_D_DST_BASE_ADDR_LOW_BWID);
  NewState(m, PDP_D_DST_BASE_ADDR_LOW_G1, PDP_D_DST_BASE_ADDR_LOW_BWID);

  // Higher 32bits of output data address when axi awaddr is 64bits
  NewState(m, PDP_D_DST_BASE_ADDR_HIGH_G0, PDP_D_DST_BASE_ADDR_HIGH_BWID);
  NewState(m, PDP_D_DST_BASE_ADDR_HIGH_G1, PDP_D_DST_BASE_ADDR_HIGH_BWID);

  // Line stride of output cube
  NewState(m, PDP_D_DST_LINE_STRIDE_G0, PDP_D_DST_LINE_STRIDE_BWID);
  NewState(m, PDP_D_DST_LINE_STRIDE_G1, PDP_D_DST_LINE_STRIDE_BWID);

  // Surface stride of output cube
  NewState(m, PDP_D_DST_SURFACE_STRIDE_G0, PDP_D_DST_SURFACE_STRIDE_BWID);
  NewState(m, PDP_D_DST_SURFACE_STRIDE_G1, PDP_D_DST_SURFACE_STRIDE_BWID);

  // RAM type of destination cube
  NewState(m, PDP_D_DST_RAM_CFG_G0, PDP_D_DST_RAM_CFG_BWID);
  NewState(m, PDP_D_DST_RAM_CFG_G1, PDP_D_DST_RAM_CFG_BWID);

  // Precision of input data
  NewState(m, PDP_D_DATA_FORMAT_G0, PDP_D_DATA_FORMAT_BWID);
  NewState(m, PDP_D_DATA_FORMAT_G1, PDP_D_DATA_FORMAT_BWID);

  // Input infinity element number
  NewState(m, PDP_D_INF_INPUT_NUM_G0, PDP_D_INF_INPUT_NUM_BWID);
  NewState(m, PDP_D_INF_INPUT_NUM_G1, PDP_D_INF_INPUT_NUM_BWID);

  // Input NaN element number
  NewState(m, PDP_D_NAN_INPUT_NUM_G0, PDP_D_NAN_INPUT_NUM_BWID);
  NewState(m, PDP_D_NAN_INPUT_NUM_G1, PDP_D_NAN_INPUT_NUM_BWID);

  // Output NaN element number
  NewState(m, PDP_D_NAN_OUTPUT_NUM_G0, PDP_D_NAN_OUTPUT_NUM_BWID);
  NewState(m, PDP_D_NAN_OUTPUT_NUM_G1, PDP_D_NAN_OUTPUT_NUM_BWID);

  // Enable/disable performance counting
  NewState(m, PDP_D_PERF_ENABLE_G0, PDP_D_PERF_ENABLE_BWID);
  NewState(m, PDP_D_PERF_ENABLE_G1, PDP_D_PERF_ENABLE_BWID);

  // Counting stalls of write requests
  NewState(m, PDP_D_PERF_WRITE_STALL_G0, PDP_D_PERF_WRITE_STALL_BWID);
  NewState(m, PDP_D_PERF_WRITE_STALL_G1, PDP_D_PERF_WRITE_STALL_BWID);

  return;
}

}; // namespace ilang
