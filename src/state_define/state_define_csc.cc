// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: state_define_csc.cc

#include <ilang/ilang++.h>
#include <nvdla/configs/state_info.h>
#include <nvdla/utils.h>

// namespace ilang
namespace ilang {

void StateDefine_csc(Ila& m) {
  // Idle status of two register groups
  NewState(m, CSC_S_STATUS, CSC_S_STATUS_BWID);

  // Pointer for CSB master and data path to access groups
  NewState(m, CSC_S_POINTER, CSC_S_POINTER_BWID);

  // Set it to 1 to kick off operation for current register group
  NewState(m, CSC_D_OP_ENABLE, CSC_D_OP_ENABLE_BWID);

  // Configuration of operation: convolution mode, precision, weight reuse, data
  // reuse.
  NewState(m, CSC_D_MISC_CFG, CSC_D_MISC_CFG_BWID);

  // Input data format and pixel format
  NewState(m, CSC_D_DATAIN_FORMAT, CSC_D_DATAIN_FORMAT_BWID);

  // Input cube’s width and height after extension
  NewState(m, CSC_D_DATAIN_SIZE_EXT_0, CSC_D_DATAIN_SIZE_EXT_0_BWID);

  // Input cube’s channel after extension
  NewState(m, CSC_D_DATAIN_SIZE_EXT_1, CSC_D_DATAIN_SIZE_EXT_1_BWID);

  // Number of batches
  NewState(m, CSC_D_BATCH_NUMBER, CSC_D_BATCH_NUMBER_BWID);

  // Post extension parameter for image-in
  NewState(m, CSC_D_POST_Y_EXTENSION, CSC_D_POST_Y_EXTENSION_BWID);

  // Number of CBUF entries used for one input slice
  NewState(m, CSC_D_ENTRY_PER_SLICE, CSC_D_ENTRY_PER_SLICE_BWID);

  // Whether weight is compressed or not
  NewState(m, CSC_D_WEIGHT_FORMAT, CSC_D_WEIGHT_FORMAT_BWID);

  // Weight’s width and height after extension
  NewState(m, CSC_D_WEIGHT_SIZE_EXT_0, CSC_D_WEIGHT_SIZE_EXT_0_BWID);

  // Weight’s channel after extension and number of weight kernels
  NewState(m, CSC_D_WEIGHT_SIZE_EXT_1, CSC_D_WEIGHT_SIZE_EXT_1_BWID);

  // Total bytes of Weight
  NewState(m, CSC_D_WEIGHT_BYTES, CSC_D_WEIGHT_BYTES_BWID);

  // Total bytes of WMB
  NewState(m, CSC_D_WMB_BYTES, CSC_D_WMB_BYTES_BWID);

  // Output cube’s width and height
  NewState(m, CSC_D_DATAOUT_SIZE_0, CSC_D_DATAOUT_SIZE_0_BWID);

  // Output cube’s channel
  NewState(m, CSC_D_DATAOUT_SIZE_1, CSC_D_DATAOUT_SIZE_1_BWID);

  // Equals to output_data_cube_width * output_data_cube_height - 1
  NewState(m, CSC_D_ATOMICS, CSC_D_ATOMICS_BWID);

  // Slices of CBUF to be released at the end of current layer
  NewState(m, CSC_D_RELEASE, CSC_D_RELEASE_BWID);

  // Convolution x stride and convolution y stride after extension
  NewState(m, CSC_D_CONV_STRIDE_EXT, CSC_D_CONV_STRIDE_EXT_BWID);

  // Dilation parameter
  NewState(m, CSC_D_DILATION_EXT, CSC_D_DILATION_EXT_BWID);

  // Left/right/top/bottom padding size
  NewState(m, CSC_D_ZERO_PADDING, CSC_D_ZERO_PADDING_BWID);

  // Padding value
  NewState(m, CSC_D_ZERO_PADDING_VALUE, CSC_D_ZERO_PADDING_VALUE_BWID);

  // Number of data banks and weight banks in CBUF
  NewState(m, CSC_D_BANK, CSC_D_BANK_BWID);

  // PRA truncate in Winograd mode, range: 0~2
  NewState(m, CSC_D_PRA_CFG, CSC_D_PRA_CFG_BWID);

  return;
}

}; // namespace ilang
