// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: state_init_cdma.cc

#include <ilang/ilang++.h>
#include <nvdla/configs/state_info.h>
#include <nvdla/utils.h>

// namespace ilang
namespace ilang {

// FIXME this is auto-generated placeholder

void StateInitCdma(Ila& m) {
  // Idle status of two register groups
  m.AddInit(m.state(CDMA_S_STATUS) == 0);

  // Pointer for CSB master and data path to access groups
  m.AddInit(m.state(CDMA_S_POINTER) == 0);

  // WMB and Weight share same port to access external memory. This register
  // controls the weight factor in the arbiter.
  m.AddInit(m.state(CDMA_S_ARBITER) == 0);

  // Indicates whether CBUF flush is finished after reset.
  m.AddInit(m.state(CDMA_S_CBUF_FLUSH_STATUS) == 0);

  // Set it to 1 to kick off operation for current register group
  m.AddInit(m.state(CDMA_D_OP_ENABLE_G0) == 0);
  m.AddInit(m.state(CDMA_D_OP_ENABLE_G1) == 0);

  // Configuration of operation: convolution mode, precision, weight reuse, data
  // reuse.
  m.AddInit(m.state(CDMA_D_MISC_CFG_G0) == 0);
  m.AddInit(m.state(CDMA_D_MISC_CFG_G1) == 0);

  // Input data format and pixel format
  m.AddInit(m.state(CDMA_D_DATAIN_FORMAT_G0) == 0);
  m.AddInit(m.state(CDMA_D_DATAIN_FORMAT_G1) == 0);

  // Input cube’s width and height
  m.AddInit(m.state(CDMA_D_DATAIN_SIZE_0_G0) == 0);
  m.AddInit(m.state(CDMA_D_DATAIN_SIZE_0_G1) == 0);

  // Input cube’s channel
  m.AddInit(m.state(CDMA_D_DATAIN_SIZE_1_G0) == 0);
  m.AddInit(m.state(CDMA_D_DATAIN_SIZE_1_G1) == 0);

  // Input cube’s width and height after extension
  m.AddInit(m.state(CDMA_D_DATAIN_SIZE_EXT_0_G0) == 0);
  m.AddInit(m.state(CDMA_D_DATAIN_SIZE_EXT_0_G1) == 0);

  // For image-in mode, horizontal offset and vertical offset of the 1 st pixel.
  m.AddInit(m.state(CDMA_D_PIXEL_OFFSET_G0) == 0);
  m.AddInit(m.state(CDMA_D_PIXEL_OFFSET_G1) == 0);

  // Ram type of input RAM
  m.AddInit(m.state(CDMA_D_DAIN_RAM_TYPE_G0) == 0);
  m.AddInit(m.state(CDMA_D_DAIN_RAM_TYPE_G1) == 0);

  // Higher 32bits of input data address when axi araddr is 64bits
  m.AddInit(m.state(CDMA_D_DAIN_ADDR_HIGH_0_G0) == 0);
  m.AddInit(m.state(CDMA_D_DAIN_ADDR_HIGH_0_G1) == 0);

  // Lower 32bits of input data address
  m.AddInit(m.state(CDMA_D_DAIN_ADDR_LOW_0_G0) == 0);
  m.AddInit(m.state(CDMA_D_DAIN_ADDR_LOW_0_G1) == 0);

  // Higher 32bits of input data address of UV plane when axi araddr is 64bits
  m.AddInit(m.state(CDMA_D_DAIN_ADDR_HIGH_1_G0) == 0);
  m.AddInit(m.state(CDMA_D_DAIN_ADDR_HIGH_1_G1) == 0);

  // Lower 32bits of input data address of UV plane
  m.AddInit(m.state(CDMA_D_DAIN_ADDR_LOW_1_G0) == 0);
  m.AddInit(m.state(CDMA_D_DAIN_ADDR_LOW_1_G1) == 0);

  // Line stride of input cube
  m.AddInit(m.state(CDMA_D_LINE_STRIDE_G0) == 0);
  m.AddInit(m.state(CDMA_D_LINE_STRIDE_G1) == 0);

  // Line stride of input cube’s UV plane
  m.AddInit(m.state(CDMA_D_LINE_UV_STRIDE_G0) == 0);
  m.AddInit(m.state(CDMA_D_LINE_UV_STRIDE_G1) == 0);

  // Surface stride of input cube
  m.AddInit(m.state(CDMA_D_SURF_STRIDE_G0) == 0);
  m.AddInit(m.state(CDMA_D_SURF_STRIDE_G1) == 0);

  // Whether input cube is line packed or surface packed
  m.AddInit(m.state(CDMA_D_DAIN_MAP_G0) == 0);
  m.AddInit(m.state(CDMA_D_DAIN_MAP_G1) == 0);

  // This address is reserved
  m.AddInit(m.state(CDMA_RESERVED) == 0);

  // Number of batches
  m.AddInit(m.state(CDMA_D_BATCH_NUMBER_G0) == 0);
  m.AddInit(m.state(CDMA_D_BATCH_NUMBER_G1) == 0);

  // The stride of input data cubes when batches > 1
  m.AddInit(m.state(CDMA_D_BATCH_STRIDE_G0) == 0);
  m.AddInit(m.state(CDMA_D_BATCH_STRIDE_G1) == 0);

  // Number of CBUF entries used for one input slice
  m.AddInit(m.state(CDMA_D_ENTRY_PER_SLICE_G0) == 0);
  m.AddInit(m.state(CDMA_D_ENTRY_PER_SLICE_G1) == 0);

  // Number of slices to be fetched before sending update information to CSC
  m.AddInit(m.state(CDMA_D_FETCH_GRAIN_G0) == 0);
  m.AddInit(m.state(CDMA_D_FETCH_GRAIN_G1) == 0);

  // Whether weight is compressed or not
  m.AddInit(m.state(CDMA_D_WEIGHT_FORMAT_G0) == 0);
  m.AddInit(m.state(CDMA_D_WEIGHT_FORMAT_G1) == 0);

  // The size of one kernel in bytes
  m.AddInit(m.state(CDMA_D_WEIGHT_SIZE_0_G0) == 0);
  m.AddInit(m.state(CDMA_D_WEIGHT_SIZE_0_G1) == 0);

  // Number of kernels
  m.AddInit(m.state(CDMA_D_WEIGHT_SIZE_1_G0) == 0);
  m.AddInit(m.state(CDMA_D_WEIGHT_SIZE_1_G1) == 0);

  // Ram type of weight
  m.AddInit(m.state(CDMA_D_WEIGHT_RAM_TYPE_G0) == 0);
  m.AddInit(m.state(CDMA_D_WEIGHT_RAM_TYPE_G1) == 0);

  // Higher 32bits of weight address when axi araddr is 64bits
  m.AddInit(m.state(CDMA_D_WEIGHT_ADDR_HIGH_G0) == 0);
  m.AddInit(m.state(CDMA_D_WEIGHT_ADDR_HIGH_G1) == 0);

  // Lower 32bits of weight address
  m.AddInit(m.state(CDMA_D_WEIGHT_ADDR_LOW_G0) == 0);
  m.AddInit(m.state(CDMA_D_WEIGHT_ADDR_LOW_G1) == 0);

  // Total bytes of Weight
  m.AddInit(m.state(CDMA_D_WEIGHT_BYTES_G0) == 0);
  m.AddInit(m.state(CDMA_D_WEIGHT_BYTES_G1) == 0);

  // Higher 32bits of wgs address when axi araddr is 64bits
  m.AddInit(m.state(CDMA_D_WGS_ADDR_HIGH_G0) == 0);
  m.AddInit(m.state(CDMA_D_WGS_ADDR_HIGH_G1) == 0);

  // Lower 32bits of wgs address
  m.AddInit(m.state(CDMA_D_WGS_ADDR_LOW_G0) == 0);
  m.AddInit(m.state(CDMA_D_WGS_ADDR_LOW_G1) == 0);

  // Higher 32bits of wmb address when axi araddr is 64bits
  m.AddInit(m.state(CDMA_D_WMB_ADDR_HIGH_G0) == 0);
  m.AddInit(m.state(CDMA_D_WMB_ADDR_HIGH_G1) == 0);

  // Lower 32bits of wmb address
  m.AddInit(m.state(CDMA_D_WMB_ADDR_LOW_G0) == 0);
  m.AddInit(m.state(CDMA_D_WMB_ADDR_LOW_G1) == 0);

  // Total bytes of WMB
  m.AddInit(m.state(CDMA_D_WMB_BYTES_G0) == 0);
  m.AddInit(m.state(CDMA_D_WMB_BYTES_G1) == 0);

  // Whether mean registers are used or not
  m.AddInit(m.state(CDMA_D_MEAN_FORMAT_G0) == 0);
  m.AddInit(m.state(CDMA_D_MEAN_FORMAT_G1) == 0);

  // Global mean value for red in RGB or Y in YUV. Global mean value for green
  // in RGB or U in YUV
  m.AddInit(m.state(CDMA_D_MEAN_GLOBAL_0_G0) == 0);
  m.AddInit(m.state(CDMA_D_MEAN_GLOBAL_0_G1) == 0);

  // Global mean value for blue in RGB or V in YUV. Global mean value for alpha
  // in ARGB/AYUV or X in XRGB
  m.AddInit(m.state(CDMA_D_MEAN_GLOBAL_1_G0) == 0);
  m.AddInit(m.state(CDMA_D_MEAN_GLOBAL_1_G1) == 0);

  // Enable/disable input data converter in CDMA and number of bits to be
  // truncated in the input data converter
  m.AddInit(m.state(CDMA_D_CVT_CFG_G0) == 0);
  m.AddInit(m.state(CDMA_D_CVT_CFG_G1) == 0);

  // Offset of input data convertor
  m.AddInit(m.state(CDMA_D_CVT_OFFSET_G0) == 0);
  m.AddInit(m.state(CDMA_D_CVT_OFFSET_G1) == 0);

  // Scale of input data convertor
  m.AddInit(m.state(CDMA_D_CVT_SCALE_G0) == 0);
  m.AddInit(m.state(CDMA_D_CVT_SCALE_G1) == 0);

  // Convolution x stride and convolution y stride
  m.AddInit(m.state(CDMA_D_CONV_STRIDE_G0) == 0);
  m.AddInit(m.state(CDMA_D_CONV_STRIDE_G1) == 0);

  // Left/right/top/bottom padding size
  m.AddInit(m.state(CDMA_D_ZERO_PADDING_G0) == 0);
  m.AddInit(m.state(CDMA_D_ZERO_PADDING_G1) == 0);

  // Padding value
  m.AddInit(m.state(CDMA_D_ZERO_PADDING_VALUE_G0) == 0);
  m.AddInit(m.state(CDMA_D_ZERO_PADDING_VALUE_G1) == 0);

  // Number of data banks and weight banks in CBUF
  m.AddInit(m.state(CDMA_D_BANK_G0) == 0);
  m.AddInit(m.state(CDMA_D_BANK_G1) == 0);

  // Enable/Disable flushing input NaN to zero
  m.AddInit(m.state(CDMA_D_NAN_FLUSH_TO_ZERO_G0) == 0);
  m.AddInit(m.state(CDMA_D_NAN_FLUSH_TO_ZERO_G1) == 0);

  // Count NaN number in input data cube, update per layer
  m.AddInit(m.state(CDMA_D_NAN_INPUT_DATA_NUM_G0) == 0);
  m.AddInit(m.state(CDMA_D_NAN_INPUT_DATA_NUM_G1) == 0);

  // Count NaN number in weight kernels, update per layer
  m.AddInit(m.state(CDMA_D_NAN_INPUT_WEIGHT_NUM_G0) == 0);
  m.AddInit(m.state(CDMA_D_NAN_INPUT_WEIGHT_NUM_G1) == 0);

  // Count infinity number in input data cube, update per layer
  m.AddInit(m.state(CDMA_D_INF_INPUT_DATA_NUM_G0) == 0);
  m.AddInit(m.state(CDMA_D_INF_INPUT_DATA_NUM_G1) == 0);

  // Count infinity number in weight kernels, update per layer
  m.AddInit(m.state(CDMA_D_INF_INPUT_WEIGHT_NUM_G0) == 0);
  m.AddInit(m.state(CDMA_D_INF_INPUT_WEIGHT_NUM_G1) == 0);

  // Enable/disable performance counter
  m.AddInit(m.state(CDMA_D_PERF_ENABLE_G0) == 0);
  m.AddInit(m.state(CDMA_D_PERF_ENABLE_G1) == 0);

  // Count blocking cycles of read request of input data, update per layer
  m.AddInit(m.state(CDMA_D_PERF_DAT_READ_STALL_G0) == 0);
  m.AddInit(m.state(CDMA_D_PERF_DAT_READ_STALL_G1) == 0);

  // Count blocking cycles of read request of weight data, update per layer
  m.AddInit(m.state(CDMA_D_PERF_WT_READ_STALL_G0) == 0);
  m.AddInit(m.state(CDMA_D_PERF_WT_READ_STALL_G1) == 0);

  // Count total latency cycles of read response of input data, update per layer
  m.AddInit(m.state(CDMA_D_PERF_DAT_READ_LATENCY_G0) == 0);
  m.AddInit(m.state(CDMA_D_PERF_DAT_READ_LATENCY_G1) == 0);

  // Count total latency cycles of read request of weight data, update per layer
  m.AddInit(m.state(CDMA_D_PERF_WT_READ_LATENCY_G0) == 0);
  m.AddInit(m.state(CDMA_D_PERF_WT_READ_LATENCY_G1) == 0);

  return;
}

}; // namespace ilang
