// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: state_define_cdma.cc

#include <ilang/ilang++.h>
#include <nvdla/configs/state_info.h>
#include <nvdla/utils.h>

// namespace ilang
namespace ilang {

void StateDefine_cdma(Ila& m) {
  // Idle status of two register groups
  NewState(m, CDMA_S_STATUS, CDMA_S_STATUS_BWID);

  // Pointer for CSB master and data path to access groups
  NewState(m, CDMA_S_POINTER, CDMA_S_POINTER_BWID);

  // WMB and Weight share same port to access external memory. This register
  // controls the weight factor in the arbiter.
  NewState(m, CDMA_S_ARBITER, CDMA_S_ARBITER_BWID);

  // Indicates whether CBUF flush is finished after reset.
  NewState(m, CDMA_S_CBUF_FLUSH_STATUS, CDMA_S_CBUF_FLUSH_STATUS_BWID);

  // Set it to 1 to kick off operation for current register group
  NewState(m, CDMA_D_OP_ENABLE, CDMA_D_OP_ENABLE_BWID);

  // Configuration of operation: convolution mode, precision, weight reuse, data
  // reuse.
  NewState(m, CDMA_D_MISC_CFG, CDMA_D_MISC_CFG_BWID);

  // Input data format and pixel format
  NewState(m, CDMA_D_DATAIN_FORMAT, CDMA_D_DATAIN_FORMAT_BWID);

  // Input cube’s width and height
  NewState(m, CDMA_D_DATAIN_SIZE_0, CDMA_D_DATAIN_SIZE_0_BWID);

  // Input cube’s channel
  NewState(m, CDMA_D_DATAIN_SIZE_1, CDMA_D_DATAIN_SIZE_1_BWID);

  // Input cube’s width and height after extension
  NewState(m, CDMA_D_DATAIN_SIZE_EXT_0, CDMA_D_DATAIN_SIZE_EXT_0_BWID);

  // For image-in mode, horizontal offset and vertical offset of the 1 st pixel.
  NewState(m, CDMA_D_PIXEL_OFFSET, CDMA_D_PIXEL_OFFSET_BWID);

  // Ram type of input RAM
  NewState(m, CDMA_D_DAIN_RAM_TYPE, CDMA_D_DAIN_RAM_TYPE_BWID);

  // Higher 32bits of input data address when axi araddr is 64bits
  NewState(m, CDMA_D_DAIN_ADDR_HIGH_0, CDMA_D_DAIN_ADDR_HIGH_0_BWID);

  // Lower 32bits of input data address
  NewState(m, CDMA_D_DAIN_ADDR_LOW_0, CDMA_D_DAIN_ADDR_LOW_0_BWID);

  // Higher 32bits of input data address of UV plane when axi araddr is 64bits
  NewState(m, CDMA_D_DAIN_ADDR_HIGH_1, CDMA_D_DAIN_ADDR_HIGH_1_BWID);

  // Lower 32bits of input data address of UV plane
  NewState(m, CDMA_D_DAIN_ADDR_LOW_1, CDMA_D_DAIN_ADDR_LOW_1_BWID);

  // Line stride of input cube
  NewState(m, CDMA_D_LINE_STRIDE, CDMA_D_LINE_STRIDE_BWID);

  // Line stride of input cube’s UV plane
  NewState(m, CDMA_D_LINE_UV_STRIDE, CDMA_D_LINE_UV_STRIDE_BWID);

  // Surface stride of input cube
  NewState(m, CDMA_D_SURF_STRIDE, CDMA_D_SURF_STRIDE_BWID);

  // Whether input cube is line packed or surface packed
  NewState(m, CDMA_D_DAIN_MAP, CDMA_D_DAIN_MAP_BWID);

  // This address is reserved
  NewState(m, CDMA_RESERVED, CDMA_RESERVED_BWID);

  // Number of batches
  NewState(m, CDMA_D_BATCH_NUMBER, CDMA_D_BATCH_NUMBER_BWID);

  // The stride of input data cubes when batches > 1
  NewState(m, CDMA_D_BATCH_STRIDE, CDMA_D_BATCH_STRIDE_BWID);

  // Number of CBUF entries used for one input slice
  NewState(m, CDMA_D_ENTRY_PER_SLICE, CDMA_D_ENTRY_PER_SLICE_BWID);

  // Number of slices to be fetched before sending update information to CSC
  NewState(m, CDMA_D_FETCH_GRAIN, CDMA_D_FETCH_GRAIN_BWID);

  // Whether weight is compressed or not
  NewState(m, CDMA_D_WEIGHT_FORMAT, CDMA_D_WEIGHT_FORMAT_BWID);

  // The size of one kernel in bytes
  NewState(m, CDMA_D_WEIGHT_SIZE_0, CDMA_D_WEIGHT_SIZE_0_BWID);

  // Number of kernels
  NewState(m, CDMA_D_WEIGHT_SIZE_1, CDMA_D_WEIGHT_SIZE_1_BWID);

  // Ram type of weight
  NewState(m, CDMA_D_WEIGHT_RAM_TYPE, CDMA_D_WEIGHT_RAM_TYPE_BWID);

  // Higher 32bits of weight address when axi araddr is 64bits
  NewState(m, CDMA_D_WEIGHT_ADDR_HIGH, CDMA_D_WEIGHT_ADDR_HIGH_BWID);

  // Lower 32bits of weight address
  NewState(m, CDMA_D_WEIGHT_ADDR_LOW, CDMA_D_WEIGHT_ADDR_LOW_BWID);

  // Total bytes of Weight
  NewState(m, CDMA_D_WEIGHT_BYTES, CDMA_D_WEIGHT_BYTES_BWID);

  // Higher 32bits of wgs address when axi araddr is 64bits
  NewState(m, CDMA_D_WGS_ADDR_HIGH, CDMA_D_WGS_ADDR_HIGH_BWID);

  // Lower 32bits of wgs address
  NewState(m, CDMA_D_WGS_ADDR_LOW, CDMA_D_WGS_ADDR_LOW_BWID);

  // Higher 32bits of wmb address when axi araddr is 64bits
  NewState(m, CDMA_D_WMB_ADDR_HIGH, CDMA_D_WMB_ADDR_HIGH_BWID);

  // Lower 32bits of wmb address
  NewState(m, CDMA_D_WMB_ADDR_LOW, CDMA_D_WMB_ADDR_LOW_BWID);

  // Total bytes of WMB
  NewState(m, CDMA_D_WMB_BYTES, CDMA_D_WMB_BYTES_BWID);

  // Whether mean registers are used or not
  NewState(m, CDMA_D_MEAN_FORMAT, CDMA_D_MEAN_FORMAT_BWID);

  // Global mean value for red in RGB or Y in YUV. Global mean value for green
  // in RGB or U in YUV
  NewState(m, CDMA_D_MEAN_GLOBAL_0, CDMA_D_MEAN_GLOBAL_0_BWID);

  // Global mean value for blue in RGB or V in YUV. Global mean value for alpha
  // in ARGB/AYUV or X in XRGB
  NewState(m, CDMA_D_MEAN_GLOBAL_1, CDMA_D_MEAN_GLOBAL_1_BWID);

  // Enable/disable input data converter in CDMA and number of bits to be
  // truncated in the input data converter
  NewState(m, CDMA_D_CVT_CFG, CDMA_D_CVT_CFG_BWID);

  // Offset of input data convertor
  NewState(m, CDMA_D_CVT_OFFSET, CDMA_D_CVT_OFFSET_BWID);

  // Scale of input data convertor
  NewState(m, CDMA_D_CVT_SCALE, CDMA_D_CVT_SCALE_BWID);

  // Convolution x stride and convolution y stride
  NewState(m, CDMA_D_CONV_STRIDE, CDMA_D_CONV_STRIDE_BWID);

  // Left/right/top/bottom padding size
  NewState(m, CDMA_D_ZERO_PADDING, CDMA_D_ZERO_PADDING_BWID);

  // Padding value
  NewState(m, CDMA_D_ZERO_PADDING_VALUE, CDMA_D_ZERO_PADDING_VALUE_BWID);

  // Number of data banks and weight banks in CBUF
  NewState(m, CDMA_D_BANK, CDMA_D_BANK_BWID);

  // Enable/Disable flushing input NaN to zero
  NewState(m, CDMA_D_NAN_FLUSH_TO_ZERO, CDMA_D_NAN_FLUSH_TO_ZERO_BWID);

  // Count NaN number in input data cube, update per layer
  NewState(m, CDMA_D_NAN_INPUT_DATA_NUM, CDMA_D_NAN_INPUT_DATA_NUM_BWID);

  // Count NaN number in weight kernels, update per layer
  NewState(m, CDMA_D_NAN_INPUT_WEIGHT_NUM, CDMA_D_NAN_INPUT_WEIGHT_NUM_BWID);

  // Count infinity number in input data cube, update per layer
  NewState(m, CDMA_D_INF_INPUT_DATA_NUM, CDMA_D_INF_INPUT_DATA_NUM_BWID);

  // Count infinity number in weight kernels, update per layer
  NewState(m, CDMA_D_INF_INPUT_WEIGHT_NUM, CDMA_D_INF_INPUT_WEIGHT_NUM_BWID);

  // Enable/disable performance counter
  NewState(m, CDMA_D_PERF_ENABLE, CDMA_D_PERF_ENABLE_BWID);

  // Count blocking cycles of read request of input data, update per layer
  NewState(m, CDMA_D_PERF_DAT_READ_STALL, CDMA_D_PERF_DAT_READ_STALL_BWID);

  // Count blocking cycles of read request of weight data, update per layer
  NewState(m, CDMA_D_PERF_WT_READ_STALL, CDMA_D_PERF_WT_READ_STALL_BWID);

  // Count total latency cycles of read response of input data, update per layer
  NewState(m, CDMA_D_PERF_DAT_READ_LATENCY, CDMA_D_PERF_DAT_READ_LATENCY_BWID);

  // Count total latency cycles of read request of weight data, update per layer
  NewState(m, CDMA_D_PERF_WT_READ_LATENCY, CDMA_D_PERF_WT_READ_LATENCY_BWID);

  return;
}

}; // namespace ilang
