// File Name: addr_csc.h

#ifndef NVDLA_ADDR_CSC_H__
#define NVDLA_ADDR_CSC_H__

/// \namespace ilang
namespace ilang {

// Idle status of two register groups
#define CSC_S_STATUS_ADDR 0x6000
// Pointer for CSB master and data path to access groups
#define CSC_S_POINTER_ADDR 0x6004
// Set it to 1 to kick off operation for current register group
#define CSC_D_OP_ENABLE_ADDR 0x6008
// Configuration of operation: convolution mode, precision, weight reuse, data
// reuse.
#define CSC_D_MISC_CFG_ADDR 0x600c
// Input data format and pixel format
#define CSC_D_DATAIN_FORMAT_ADDR 0x6010
// Input cube’s width and height after extension
#define CSC_D_DATAIN_SIZE_EXT_0_ADDR 0x6014
// Input cube’s channel after extension
#define CSC_D_DATAIN_SIZE_EXT_1_ADDR 0x6018
// Number of batches
#define CSC_D_BATCH_NUMBER_ADDR 0x601c
// Post extension parameter for image-in
#define CSC_D_POST_Y_EXTENSION_ADDR 0x6020
// Number of CBUF entries used for one input slice
#define CSC_D_ENTRY_PER_SLICE_ADDR 0x6024
// Whether weight is compressed or not
#define CSC_D_WEIGHT_FORMAT_ADDR 0x6028
// Weight’s width and height after extension
#define CSC_D_WEIGHT_SIZE_EXT_0_ADDR 0x602c
// Weight’s channel after extension and number of weight kernels
#define CSC_D_WEIGHT_SIZE_EXT_1_ADDR 0x6030
// Total bytes of Weight
#define CSC_D_WEIGHT_BYTES_ADDR 0x6034
// Total bytes of WMB
#define CSC_D_WMB_BYTES_ADDR 0x6038
// Output cube’s width and height
#define CSC_D_DATAOUT_SIZE_0_ADDR 0x603c
// Output cube’s channel
#define CSC_D_DATAOUT_SIZE_1_ADDR 0x6040
// Equals to output_data_cube_width * output_data_cube_height - 1
#define CSC_D_ATOMICS_ADDR 0x6044
// Slices of CBUF to be released at the end of current layer
#define CSC_D_RELEASE_ADDR 0x6048
// Convolution x stride and convolution y stride after extension
#define CSC_D_CONV_STRIDE_EXT_ADDR 0x604c
// Dilation parameter
#define CSC_D_DILATION_EXT_ADDR 0x6050
// Left/right/top/bottom padding size
#define CSC_D_ZERO_PADDING_ADDR 0x6054
// Padding value
#define CSC_D_ZERO_PADDING_VALUE_ADDR 0x6058
// Number of data banks and weight banks in CBUF
#define CSC_D_BANK_ADDR 0x605c
// PRA truncate in Winograd mode, range: 0~2
#define CSC_D_PRA_CFG_ADDR 0x6060

}; // namespace ilang

#endif // NVDLA_ADDR_CSC_H__
