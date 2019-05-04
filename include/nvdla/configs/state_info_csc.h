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

#include <nvdla/configs/modeling_config.h>

// namespace ilang
namespace ilang {

// Idle status of two register groups
#define CSC_S_STATUS "csc_s_status"
#define CSC_S_STATUS_ADDR 0x6000
#define CSC_S_STATUS_BWID ICFG_CSB_DATA_BWID

// Pointer for CSB master and data path to access groups
#define CSC_S_POINTER "csc_s_pointer"
#define CSC_S_POINTER_ADDR 0x6004
#define CSC_S_POINTER_BWID ICFG_CSB_DATA_BWID

// Set it to 1 to kick off operation for current register group
#define CSC_D_OP_ENABLE_G0 "csc_d_op_enable_g0"
#define CSC_D_OP_ENABLE_G1 "csc_d_op_enable_g1"
#define CSC_D_OP_ENABLE_ADDR 0x6008
#define CSC_D_OP_ENABLE_BWID ICFG_CSB_DATA_BWID

// Configuration of operation: convolution mode, precision, weight reuse, data
// reuse.
#define CSC_D_MISC_CFG_G0 "csc_d_misc_cfg_g0"
#define CSC_D_MISC_CFG_G1 "csc_d_misc_cfg_g1"
#define CSC_D_MISC_CFG_ADDR 0x600c
#define CSC_D_MISC_CFG_BWID ICFG_CSB_DATA_BWID

// Input data format and pixel format
#define CSC_D_DATAIN_FORMAT_G0 "csc_d_datain_format_g0"
#define CSC_D_DATAIN_FORMAT_G1 "csc_d_datain_format_g1"
#define CSC_D_DATAIN_FORMAT_ADDR 0x6010
#define CSC_D_DATAIN_FORMAT_BWID ICFG_CSB_DATA_BWID

// Input cube’s width and height after extension
#define CSC_D_DATAIN_SIZE_EXT_0_G0 "csc_d_datain_size_ext_0_g0"
#define CSC_D_DATAIN_SIZE_EXT_0_G1 "csc_d_datain_size_ext_0_g1"
#define CSC_D_DATAIN_SIZE_EXT_0_ADDR 0x6014
#define CSC_D_DATAIN_SIZE_EXT_0_BWID ICFG_CSB_DATA_BWID

// Input cube’s channel after extension
#define CSC_D_DATAIN_SIZE_EXT_1_G0 "csc_d_datain_size_ext_1_g0"
#define CSC_D_DATAIN_SIZE_EXT_1_G1 "csc_d_datain_size_ext_1_g1"
#define CSC_D_DATAIN_SIZE_EXT_1_ADDR 0x6018
#define CSC_D_DATAIN_SIZE_EXT_1_BWID ICFG_CSB_DATA_BWID

// Number of batches
#define CSC_D_BATCH_NUMBER_G0 "csc_d_batch_number_g0"
#define CSC_D_BATCH_NUMBER_G1 "csc_d_batch_number_g1"
#define CSC_D_BATCH_NUMBER_ADDR 0x601c
#define CSC_D_BATCH_NUMBER_BWID ICFG_CSB_DATA_BWID

// Post extension parameter for image-in
#define CSC_D_POST_Y_EXTENSION_G0 "csc_d_post_y_extension_g0"
#define CSC_D_POST_Y_EXTENSION_G1 "csc_d_post_y_extension_g1"
#define CSC_D_POST_Y_EXTENSION_ADDR 0x6020
#define CSC_D_POST_Y_EXTENSION_BWID ICFG_CSB_DATA_BWID

// Number of CBUF entries used for one input slice
#define CSC_D_ENTRY_PER_SLICE_G0 "csc_d_entry_per_slice_g0"
#define CSC_D_ENTRY_PER_SLICE_G1 "csc_d_entry_per_slice_g1"
#define CSC_D_ENTRY_PER_SLICE_ADDR 0x6024
#define CSC_D_ENTRY_PER_SLICE_BWID ICFG_CSB_DATA_BWID

// Whether weight is compressed or not
#define CSC_D_WEIGHT_FORMAT_G0 "csc_d_weight_format_g0"
#define CSC_D_WEIGHT_FORMAT_G1 "csc_d_weight_format_g1"
#define CSC_D_WEIGHT_FORMAT_ADDR 0x6028
#define CSC_D_WEIGHT_FORMAT_BWID ICFG_CSB_DATA_BWID

// Weight’s width and height after extension
#define CSC_D_WEIGHT_SIZE_EXT_0_G0 "csc_d_weight_size_ext_0_g0"
#define CSC_D_WEIGHT_SIZE_EXT_0_G1 "csc_d_weight_size_ext_0_g1"
#define CSC_D_WEIGHT_SIZE_EXT_0_ADDR 0x602c
#define CSC_D_WEIGHT_SIZE_EXT_0_BWID ICFG_CSB_DATA_BWID

// Weight’s channel after extension and number of weight kernels
#define CSC_D_WEIGHT_SIZE_EXT_1_G0 "csc_d_weight_size_ext_1_g0"
#define CSC_D_WEIGHT_SIZE_EXT_1_G1 "csc_d_weight_size_ext_1_g1"
#define CSC_D_WEIGHT_SIZE_EXT_1_ADDR 0x6030
#define CSC_D_WEIGHT_SIZE_EXT_1_BWID ICFG_CSB_DATA_BWID

// Total bytes of Weight
#define CSC_D_WEIGHT_BYTES_G0 "csc_d_weight_bytes_g0"
#define CSC_D_WEIGHT_BYTES_G1 "csc_d_weight_bytes_g1"
#define CSC_D_WEIGHT_BYTES_ADDR 0x6034
#define CSC_D_WEIGHT_BYTES_BWID ICFG_CSB_DATA_BWID

// Total bytes of WMB
#define CSC_D_WMB_BYTES_G0 "csc_d_wmb_bytes_g0"
#define CSC_D_WMB_BYTES_G1 "csc_d_wmb_bytes_g1"
#define CSC_D_WMB_BYTES_ADDR 0x6038
#define CSC_D_WMB_BYTES_BWID ICFG_CSB_DATA_BWID

// Output cube’s width and height
#define CSC_D_DATAOUT_SIZE_0_G0 "csc_d_dataout_size_0_g0"
#define CSC_D_DATAOUT_SIZE_0_G1 "csc_d_dataout_size_0_g1"
#define CSC_D_DATAOUT_SIZE_0_ADDR 0x603c
#define CSC_D_DATAOUT_SIZE_0_BWID ICFG_CSB_DATA_BWID

// Output cube’s channel
#define CSC_D_DATAOUT_SIZE_1_G0 "csc_d_dataout_size_1_g0"
#define CSC_D_DATAOUT_SIZE_1_G1 "csc_d_dataout_size_1_g1"
#define CSC_D_DATAOUT_SIZE_1_ADDR 0x6040
#define CSC_D_DATAOUT_SIZE_1_BWID ICFG_CSB_DATA_BWID

// Equals to output_data_cube_width * output_data_cube_height - 1
#define CSC_D_ATOMICS_G0 "csc_d_atomics_g0"
#define CSC_D_ATOMICS_G1 "csc_d_atomics_g1"
#define CSC_D_ATOMICS_ADDR 0x6044
#define CSC_D_ATOMICS_BWID ICFG_CSB_DATA_BWID

// Slices of CBUF to be released at the end of current layer
#define CSC_D_RELEASE_G0 "csc_d_release_g0"
#define CSC_D_RELEASE_G1 "csc_d_release_g1"
#define CSC_D_RELEASE_ADDR 0x6048
#define CSC_D_RELEASE_BWID ICFG_CSB_DATA_BWID

// Convolution x stride and convolution y stride after extension
#define CSC_D_CONV_STRIDE_EXT_G0 "csc_d_conv_stride_ext_g0"
#define CSC_D_CONV_STRIDE_EXT_G1 "csc_d_conv_stride_ext_g1"
#define CSC_D_CONV_STRIDE_EXT_ADDR 0x604c
#define CSC_D_CONV_STRIDE_EXT_BWID ICFG_CSB_DATA_BWID

// Dilation parameter
#define CSC_D_DILATION_EXT_G0 "csc_d_dilation_ext_g0"
#define CSC_D_DILATION_EXT_G1 "csc_d_dilation_ext_g1"
#define CSC_D_DILATION_EXT_ADDR 0x6050
#define CSC_D_DILATION_EXT_BWID ICFG_CSB_DATA_BWID

// Left/right/top/bottom padding size
#define CSC_D_ZERO_PADDING_G0 "csc_d_zero_padding_g0"
#define CSC_D_ZERO_PADDING_G1 "csc_d_zero_padding_g1"
#define CSC_D_ZERO_PADDING_ADDR 0x6054
#define CSC_D_ZERO_PADDING_BWID ICFG_CSB_DATA_BWID

// Padding value
#define CSC_D_ZERO_PADDING_VALUE_G0 "csc_d_zero_padding_value_g0"
#define CSC_D_ZERO_PADDING_VALUE_G1 "csc_d_zero_padding_value_g1"
#define CSC_D_ZERO_PADDING_VALUE_ADDR 0x6058
#define CSC_D_ZERO_PADDING_VALUE_BWID ICFG_CSB_DATA_BWID

// Number of data banks and weight banks in CBUF
#define CSC_D_BANK_G0 "csc_d_bank_g0"
#define CSC_D_BANK_G1 "csc_d_bank_g1"
#define CSC_D_BANK_ADDR 0x605c
#define CSC_D_BANK_BWID ICFG_CSB_DATA_BWID

// PRA truncate in Winograd mode, range: 0~2
#define CSC_D_PRA_CFG_G0 "csc_d_pra_cfg_g0"
#define CSC_D_PRA_CFG_G1 "csc_d_pra_cfg_g1"
#define CSC_D_PRA_CFG_ADDR 0x6060
#define CSC_D_PRA_CFG_BWID ICFG_CSB_DATA_BWID

}; // namespace ilang

#endif // STATE_INFO_CSC_H__
