// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" wich comes with this distribution for more information.
// ============================================================================

// File Name: addr_pdp.h

#ifndef NVDLA_ADDR_PDP_H__
#define NVDLA_ADDR_PDP_H__

/// \namespace ilang
namespace ilang {

// Idle status of two register groups
#define PDP_S_STATUS 0xd000
// Pointer for CSB master and data path to access groups
#define PDP_S_POINTER 0xd004
// Set it to 1 to kick off operation for current register group
#define PDP_D_OP_ENABLE 0xd008
// Input data cube’s width
#define PDP_D_DATA_CUBE_IN_WIDTH 0xd00c
// Input data cube’s height
#define PDP_D_DATA_CUBE_IN_HEIGHT 0xd010
// Input data cube’s channel
#define PDP_D_DATA_CUBE_IN_CHANNEL 0xd014
// Output data cube’s width
#define PDP_D_DATA_CUBE_OUT_WIDTH 0xd018
// Output data cube’s height
#define PDP_D_DATA_CUBE_OUT_HEIGHT 0xd01c
// Output data cube’s channel
#define PDP_D_DATA_CUBE_OUT_CHANNEL 0xd020
// Split number
#define PDP_D_OPERATION_MODE_CFG 0xd024
// Option to flush input NaN to zero
#define PDP_D_NAN_FLUSH_TO_ZERO 0xd028
// Partial width for first, last and middle partitions of input cube
#define PDP_D_PARTIAL_WIDTH_IN 0xd02c
// Partial width for first, last and middle partitions of output cube
#define PDP_D_PARTIAL_WIDTH_OUT 0xd030
// Kernel width and kernel stride
#define PDP_D_POOLING_KERNEL_CFG 0xd034
// Reciprocal of pooling kernel width, set to actual value * (2^16) when
// INT8/INT16 format enabled. and set to actual value for fp16 precision mode
// with fp17 data format.
#define PDP_D_RECIP_KERNEL_WIDTH 0xd038
// Reciprocal of pooling kernel height, set to actual value * (2^16) when
// INT8/INT16 format enabled. and set to actual value for fp16 precision mode
// with fp17 data format.
#define PDP_D_RECIP_KERNEL_HEIGHT 0xd03c
// Left/right/top/bottom padding size
#define PDP_D_POOLING_PADDING_CFG 0xd040
// Padding_value*1
#define PDP_D_POOLING_PADDING_VALUE_1_CFG 0xd044
// Padding_value*2
#define PDP_D_POOLING_PADDING_VALUE_2_CFG 0xd048
// Padding_value*3
#define PDP_D_POOLING_PADDING_VALUE_3_CFG 0xd04c
// Padding_value*4
#define PDP_D_POOLING_PADDING_VALUE_4_CFG 0xd050
// Padding_value*5
#define PDP_D_POOLING_PADDING_VALUE_5_CFG 0xd054
// Padding_value*6
#define PDP_D_POOLING_PADDING_VALUE_6_CFG 0xd058
// Padding_value*7
#define PDP_D_POOLING_PADDING_VALUE_7_CFG 0xd05c
// Lower 32bits of input data address
#define PDP_D_SRC_BASE_ADDR_LOW 0xd060
// Higher 32bits of input data address when axi araddr is 64bits
#define PDP_D_SRC_BASE_ADDR_HIGH 0xd064
// Line stride of input cube
#define PDP_D_SRC_LINE_STRIDE 0xd068
// Surface stride of input cube
#define PDP_D_SRC_SURFACE_STRIDE 0xd06c
// Lower 32bits of output data address
#define PDP_D_DST_BASE_ADDR_LOW 0xd070
// Higher 32bits of output data address when axi awaddr is 64bits
#define PDP_D_DST_BASE_ADDR_HIGH 0xd074
// Line stride of output cube
#define PDP_D_DST_LINE_STRIDE 0xd078
// Surface stride of output cube
#define PDP_D_DST_SURFACE_STRIDE 0xd07c
// RAM type of destination cube
#define PDP_D_DST_RAM_CFG 0xd080
// Precision of input data
#define PDP_D_DATA_FORMAT 0xd084
// Input infinity element number
#define PDP_D_INF_INPUT_NUM 0xd088
// Input NaN element number
#define PDP_D_NAN_INPUT_NUM 0xd08c
// Output NaN element number
#define PDP_D_NAN_OUTPUT_NUM 0xd090
// Enable/disable performance counting
#define PDP_D_PERF_ENABLE 0xd094
// Counting stalls of write requests
#define PDP_D_PERF_WRITE_STALL 0xd098

}; // namespace ilang

#endif // NVDLA_ADDR_PDP_H__
