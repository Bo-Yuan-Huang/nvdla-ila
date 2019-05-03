// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: state_init_csc.cc

#include <ilang/ilang++.h>
#include <nvdla/configs/state_info.h>
#include <nvdla/utils.h>

// namespace ilang
namespace ilang {

// FIXME this is auto-generated placeholder

void StateInitCsc(Ila& m) {
  // Idle status of two register groups
  m.AddInit(m.state(CSC_S_STATUS) == 0);

  // Pointer for CSB master and data path to access groups
  m.AddInit(m.state(CSC_S_POINTER) == 0);

  // Set it to 1 to kick off operation for current register group
  m.AddInit(m.state(CSC_D_OP_ENABLE_G0) == 0);
  m.AddInit(m.state(CSC_D_OP_ENABLE_G1) == 0);

  // Configuration of operation: convolution mode, precision, weight reuse, data
  // reuse.
  m.AddInit(m.state(CSC_D_MISC_CFG_G0) == 0);
  m.AddInit(m.state(CSC_D_MISC_CFG_G1) == 0);

  // Input data format and pixel format
  m.AddInit(m.state(CSC_D_DATAIN_FORMAT_G0) == 0);
  m.AddInit(m.state(CSC_D_DATAIN_FORMAT_G1) == 0);

  // Input cube’s width and height after extension
  m.AddInit(m.state(CSC_D_DATAIN_SIZE_EXT_0_G0) == 0);
  m.AddInit(m.state(CSC_D_DATAIN_SIZE_EXT_0_G1) == 0);

  // Input cube’s channel after extension
  m.AddInit(m.state(CSC_D_DATAIN_SIZE_EXT_1_G0) == 0);
  m.AddInit(m.state(CSC_D_DATAIN_SIZE_EXT_1_G1) == 0);

  // Number of batches
  m.AddInit(m.state(CSC_D_BATCH_NUMBER_G0) == 0);
  m.AddInit(m.state(CSC_D_BATCH_NUMBER_G1) == 0);

  // Post extension parameter for image-in
  m.AddInit(m.state(CSC_D_POST_Y_EXTENSION_G0) == 0);
  m.AddInit(m.state(CSC_D_POST_Y_EXTENSION_G1) == 0);

  // Number of CBUF entries used for one input slice
  m.AddInit(m.state(CSC_D_ENTRY_PER_SLICE_G0) == 0);
  m.AddInit(m.state(CSC_D_ENTRY_PER_SLICE_G1) == 0);

  // Whether weight is compressed or not
  m.AddInit(m.state(CSC_D_WEIGHT_FORMAT_G0) == 0);
  m.AddInit(m.state(CSC_D_WEIGHT_FORMAT_G1) == 0);

  // Weight’s width and height after extension
  m.AddInit(m.state(CSC_D_WEIGHT_SIZE_EXT_0_G0) == 0);
  m.AddInit(m.state(CSC_D_WEIGHT_SIZE_EXT_0_G1) == 0);

  // Weight’s channel after extension and number of weight kernels
  m.AddInit(m.state(CSC_D_WEIGHT_SIZE_EXT_1_G0) == 0);
  m.AddInit(m.state(CSC_D_WEIGHT_SIZE_EXT_1_G1) == 0);

  // Total bytes of Weight
  m.AddInit(m.state(CSC_D_WEIGHT_BYTES_G0) == 0);
  m.AddInit(m.state(CSC_D_WEIGHT_BYTES_G1) == 0);

  // Total bytes of WMB
  m.AddInit(m.state(CSC_D_WMB_BYTES_G0) == 0);
  m.AddInit(m.state(CSC_D_WMB_BYTES_G1) == 0);

  // Output cube’s width and height
  m.AddInit(m.state(CSC_D_DATAOUT_SIZE_0_G0) == 0);
  m.AddInit(m.state(CSC_D_DATAOUT_SIZE_0_G1) == 0);

  // Output cube’s channel
  m.AddInit(m.state(CSC_D_DATAOUT_SIZE_1_G0) == 0);
  m.AddInit(m.state(CSC_D_DATAOUT_SIZE_1_G1) == 0);

  // Equals to output_data_cube_width * output_data_cube_height - 1
  m.AddInit(m.state(CSC_D_ATOMICS_G0) == 0);
  m.AddInit(m.state(CSC_D_ATOMICS_G1) == 0);

  // Slices of CBUF to be released at the end of current layer
  m.AddInit(m.state(CSC_D_RELEASE_G0) == 0);
  m.AddInit(m.state(CSC_D_RELEASE_G1) == 0);

  // Convolution x stride and convolution y stride after extension
  m.AddInit(m.state(CSC_D_CONV_STRIDE_EXT_G0) == 0);
  m.AddInit(m.state(CSC_D_CONV_STRIDE_EXT_G1) == 0);

  // Dilation parameter
  m.AddInit(m.state(CSC_D_DILATION_EXT_G0) == 0);
  m.AddInit(m.state(CSC_D_DILATION_EXT_G1) == 0);

  // Left/right/top/bottom padding size
  m.AddInit(m.state(CSC_D_ZERO_PADDING_G0) == 0);
  m.AddInit(m.state(CSC_D_ZERO_PADDING_G1) == 0);

  // Padding value
  m.AddInit(m.state(CSC_D_ZERO_PADDING_VALUE_G0) == 0);
  m.AddInit(m.state(CSC_D_ZERO_PADDING_VALUE_G1) == 0);

  // Number of data banks and weight banks in CBUF
  m.AddInit(m.state(CSC_D_BANK_G0) == 0);
  m.AddInit(m.state(CSC_D_BANK_G1) == 0);

  // PRA truncate in Winograd mode, range: 0~2
  m.AddInit(m.state(CSC_D_PRA_CFG_G0) == 0);
  m.AddInit(m.state(CSC_D_PRA_CFG_G1) == 0);

  return;
}

}; // namespace ilang
