// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" wich comes with this distribution for more information.
// ============================================================================

// File Name: addr_cdma.h

#ifndef NVDLA_ADDR_CDMA_H__
#define NVDLA_ADDR_CDMA_H__

/// \namespace ilang
namespace ilang {

// Idle status of two register groups
#define CDMA_S_STATUS 0x5000
// Pointer for CSB master and data path to access groups
#define CDMA_S_POINTER 0x5004
// WMB and Weight share same port to access external memory. This register
// controls the weight factor in the arbiter.
#define CDMA_S_ARBITER 0x5008
// Indicates whether CBUF flush is finished after reset.
#define CDMA_S_CBUF_FLUSH_STATUS 0x500c
// Set it to 1 to kick off operation for current register group
#define CDMA_D_OP_ENABLE 0x5010
// Configuration of operation: convolution mode, precision, weight reuse, data
// reuse.
#define CDMA_D_MISC_CFG 0x5014
// Input data format and pixel format
#define CDMA_D_DATAIN_FORMAT 0x5018
// Input cube’s width and height
#define CDMA_D_DATAIN_SIZE_0 0x501c
// Input cube’s channel
#define CDMA_D_DATAIN_SIZE_1 0x5020
// Input cube’s width and height after extension
#define CDMA_D_DATAIN_SIZE_EXT_0 0x5024
// For image-in mode, horizontal offset and vertical offset of the 1 st pixel.
#define CDMA_D_PIXEL_OFFSET 0x5028
// Ram type of input RAM
#define CDMA_D_DAIN_RAM_TYPE 0x502c
// Higher 32bits of input data address when axi araddr is 64bits
#define CDMA_D_DAIN_ADDR_HIGH_0 0x5030
// Lower 32bits of input data address
#define CDMA_D_DAIN_ADDR_LOW_0 0x5034
// Higher 32bits of input data address of UV plane when axi araddr is 64bits
#define CDMA_D_DAIN_ADDR_HIGH_1 0x5038
// Lower 32bits of input data address of UV plane
#define CDMA_D_DAIN_ADDR_LOW_1 0x503c
// Line stride of input cube
#define CDMA_D_LINE_STRIDE 0x5040
// Line stride of input cube’s UV plane
#define CDMA_D_LINE_UV_STRIDE 0x5044
// Surface stride of input cube
#define CDMA_D_SURF_STRIDE 0x5048
// Whether input cube is line packed or surface packed
#define CDMA_D_DAIN_MAP 0x504c
// This address is reserved
#define CDMA_RESERVED 0x5050
// Number of batches
#define CDMA_D_BATCH_NUMBER 0x5058
// The stride of input data cubes when batches > 1
#define CDMA_D_BATCH_STRIDE 0x505c
// Number of CBUF entries used for one input slice
#define CDMA_D_ENTRY_PER_SLICE 0x5060
// Number of slices to be fetched before sending update information to CSC
#define CDMA_D_FETCH_GRAIN 0x5064
// Whether weight is compressed or not
#define CDMA_D_WEIGHT_FORMAT 0x5068
// The size of one kernel in bytes
#define CDMA_D_WEIGHT_SIZE_0 0x506c
// Number of kernels
#define CDMA_D_WEIGHT_SIZE_1 0x5070
// Ram type of weight
#define CDMA_D_WEIGHT_RAM_TYPE 0x5074
// Higher 32bits of weight address when axi araddr is 64bits
#define CDMA_D_WEIGHT_ADDR_HIGH 0x5078
// Lower 32bits of weight address
#define CDMA_D_WEIGHT_ADDR_LOW 0x507c
// Total bytes of Weight
#define CDMA_D_WEIGHT_BYTES 0x5080
// Higher 32bits of wgs address when axi araddr is 64bits
#define CDMA_D_WGS_ADDR_HIGH 0x5084
// Lower 32bits of wgs address
#define CDMA_D_WGS_ADDR_LOW 0x5088
// Higher 32bits of wmb address when axi araddr is 64bits
#define CDMA_D_WMB_ADDR_HIGH 0x508c
// Lower 32bits of wmb address
#define CDMA_D_WMB_ADDR_LOW 0x5090
// Total bytes of WMB
#define CDMA_D_WMB_BYTES 0x5094
// Whether mean registers are used or not
#define CDMA_D_MEAN_FORMAT 0x5098
// Global mean value for red in RGB or Y in YUV. Global mean value for green in
// RGB or U in YUV
#define CDMA_D_MEAN_GLOBAL_0 0x509c
// Global mean value for blue in RGB or V in YUV. Global mean value for alpha in
// ARGB/AYUV or X in XRGB
#define CDMA_D_MEAN_GLOBAL_1 0x50a0
// Enable/disable input data converter in CDMA and number of bits to be
// truncated in the input data converter
#define CDMA_D_CVT_CFG 0x50a4
// Offset of input data convertor
#define CDMA_D_CVT_OFFSET 0x50a8
// Scale of input data convertor
#define CDMA_D_CVT_SCALE 0x50ac
// Convolution x stride and convolution y stride
#define CDMA_D_CONV_STRIDE 0x50b0
// Left/right/top/bottom padding size
#define CDMA_D_ZERO_PADDING 0x50b4
// Padding value
#define CDMA_D_ZERO_PADDING_VALUE 0x50b8
// Number of data banks and weight banks in CBUF
#define CDMA_D_BANK 0x50bc
// Enable/Disable flushing input NaN to zero
#define CDMA_D_NAN_FLUSH_TO_ZERO 0x50c0
// Count NaN number in input data cube, update per layer
#define CDMA_D_NAN_INPUT_DATA_NUM 0x50c4
// Count NaN number in weight kernels, update per layer
#define CDMA_D_NAN_INPUT_WEIGHT_NUM 0x50c8
// Count infinity number in input data cube, update per layer
#define CDMA_D_INF_INPUT_DATA_NUM 0x50cc
// Count infinity number in weight kernels, update per layer
#define CDMA_D_INF_INPUT_WEIGHT_NUM 0x50d0
// Enable/disable performance counter
#define CDMA_D_PERF_ENABLE 0x50d4
// Count blocking cycles of read request of input data, update per layer
#define CDMA_D_PERF_DAT_READ_STALL 0x50d8
// Count blocking cycles of read request of weight data, update per layer
#define CDMA_D_PERF_WT_READ_STALL 0x50dc
// Count total latency cycles of read response of input data, update per layer
#define CDMA_D_PERF_DAT_READ_LATENCY 0x50e0
// Count total latency cycles of read request of weight data, update per layer
#define CDMA_D_PERF_WT_READ_LATENCY 0x50e4

}; // namespace ilang

#endif // NVDLA_ADDR_CDMA_H__
