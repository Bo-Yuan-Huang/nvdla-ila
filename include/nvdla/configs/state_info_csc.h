// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: state_info_csc.h

#ifndef STATE_INFO_CSC_H__
#define STATE_INFO_CSC_H__

/// \namespace ilang
namespace ilang {

// Idle status of two register groups
#define CSC_S_STATUS_NAME "csc_s_status"

// Pointer for CSB master and data path to access groups
#define CSC_S_POINTER_NAME "csc_s_pointer"

// Set it to 1 to kick off operation for current register group
#define CSC_D_OP_ENABLE_NAME "csc_d_op_enable"

// Configuration of operation: convolution mode, precision, weight reuse, data
// reuse.
#define CSC_D_MISC_CFG_NAME "csc_d_misc_cfg"

// Input data format and pixel format
#define CSC_D_DATAIN_FORMAT_NAME "csc_d_datain_format"

// Input cube’s width and height after extension
#define CSC_D_DATAIN_SIZE_EXT_0_NAME "csc_d_datain_size_ext_0"

// Input cube’s channel after extension
#define CSC_D_DATAIN_SIZE_EXT_1_NAME "csc_d_datain_size_ext_1"

// Number of batches
#define CSC_D_BATCH_NUMBER_NAME "csc_d_batch_number"

// Post extension parameter for image-in
#define CSC_D_POST_Y_EXTENSION_NAME "csc_d_post_y_extension"

// Number of CBUF entries used for one input slice
#define CSC_D_ENTRY_PER_SLICE_NAME "csc_d_entry_per_slice"

// Whether weight is compressed or not
#define CSC_D_WEIGHT_FORMAT_NAME "csc_d_weight_format"

// Weight’s width and height after extension
#define CSC_D_WEIGHT_SIZE_EXT_0_NAME "csc_d_weight_size_ext_0"

// Weight’s channel after extension and number of weight kernels
#define CSC_D_WEIGHT_SIZE_EXT_1_NAME "csc_d_weight_size_ext_1"

// Total bytes of Weight
#define CSC_D_WEIGHT_BYTES_NAME "csc_d_weight_bytes"

// Total bytes of WMB
#define CSC_D_WMB_BYTES_NAME "csc_d_wmb_bytes"

// Output cube’s width and height
#define CSC_D_DATAOUT_SIZE_0_NAME "csc_d_dataout_size_0"

// Output cube’s channel
#define CSC_D_DATAOUT_SIZE_1_NAME "csc_d_dataout_size_1"

// Equals to output_data_cube_width * output_data_cube_height - 1
#define CSC_D_ATOMICS_NAME "csc_d_atomics"

// Slices of CBUF to be released at the end of current layer
#define CSC_D_RELEASE_NAME "csc_d_release"

// Convolution x stride and convolution y stride after extension
#define CSC_D_CONV_STRIDE_EXT_NAME "csc_d_conv_stride_ext"

// Dilation parameter
#define CSC_D_DILATION_EXT_NAME "csc_d_dilation_ext"

// Left/right/top/bottom padding size
#define CSC_D_ZERO_PADDING_NAME "csc_d_zero_padding"

// Padding value
#define CSC_D_ZERO_PADDING_VALUE_NAME "csc_d_zero_padding_value"

// Number of data banks and weight banks in CBUF
#define CSC_D_BANK_NAME "csc_d_bank"

// PRA truncate in Winograd mode, range: 0~2
#define CSC_D_PRA_CFG_NAME "csc_d_pra_cfg"

}; // namespace ilang

#endif // STATE_INFO_CSC_H__
