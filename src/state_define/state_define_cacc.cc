// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: state_define_cacc.cc

#include <ilang/ilang++.h>
#include <nvdla/configs/state_info.h>
#include <nvdla/utils.h>

// namespace ilang
namespace ilang {

void StateDefineCacc(Ila& m) {
  // Idle status of two register groups
  NewState(m, CACC_S_STATUS, CACC_S_STATUS_BWID);

  // Pointer for CSB master and data path to access groups
  NewState(m, CACC_S_POINTER, CACC_S_POINTER_BWID);

  // Set it to 1 to kick off operation for current register group
  NewState(m, CACC_D_OP_ENABLE_G0, CACC_D_OP_ENABLE_BWID);
  NewState(m, CACC_D_OP_ENABLE_G1, CACC_D_OP_ENABLE_BWID);

  // Configuration of operation: convolution mode, precision, etc.
  NewState(m, CACC_D_MISC_CFG_G0, CACC_D_MISC_CFG_BWID);
  NewState(m, CACC_D_MISC_CFG_G1, CACC_D_MISC_CFG_BWID);

  // Input cube’s width and height after extension
  NewState(m, CACC_D_DATAOUT_SIZE_0_G0, CACC_D_DATAOUT_SIZE_0_BWID);
  NewState(m, CACC_D_DATAOUT_SIZE_0_G1, CACC_D_DATAOUT_SIZE_0_BWID);

  // Input cube’s channel after extension
  NewState(m, CACC_D_DATAOUT_SIZE_1_G0, CACC_D_DATAOUT_SIZE_1_BWID);
  NewState(m, CACC_D_DATAOUT_SIZE_1_G1, CACC_D_DATAOUT_SIZE_1_BWID);

  // Address of output cube
  NewState(m, CACC_D_DATAOUT_ADDR_G0, CACC_D_DATAOUT_ADDR_BWID);
  NewState(m, CACC_D_DATAOUT_ADDR_G1, CACC_D_DATAOUT_ADDR_BWID);

  // Number of batches
  NewState(m, CACC_D_BATCH_NUMBER_G0, CACC_D_BATCH_NUMBER_BWID);
  NewState(m, CACC_D_BATCH_NUMBER_G1, CACC_D_BATCH_NUMBER_BWID);

  // Line stride of output cube
  NewState(m, CACC_D_LINE_STRIDE_G0, CACC_D_LINE_STRIDE_BWID);
  NewState(m, CACC_D_LINE_STRIDE_G1, CACC_D_LINE_STRIDE_BWID);

  // Line stride of surface cube
  NewState(m, CACC_D_SURF_STRIDE_G0, CACC_D_SURF_STRIDE_BWID);
  NewState(m, CACC_D_SURF_STRIDE_G1, CACC_D_SURF_STRIDE_BWID);

  // Whether output cube is line packed or surface packed
  NewState(m, CACC_D_DATAOUT_MAP_G0, CACC_D_DATAOUT_MAP_BWID);
  NewState(m, CACC_D_DATAOUT_MAP_G1, CACC_D_DATAOUT_MAP_BWID);

  // Number of bits to be truncated before sending to SDP
  NewState(m, CACC_D_CLIP_CFG_G0, CACC_D_CLIP_CFG_BWID);
  NewState(m, CACC_D_CLIP_CFG_G1, CACC_D_CLIP_CFG_BWID);

  // Output saturation count
  NewState(m, CACC_D_OUT_SATURATION_G0, CACC_D_OUT_SATURATION_BWID);
  NewState(m, CACC_D_OUT_SATURATION_G1, CACC_D_OUT_SATURATION_BWID);

  return;
}

}; // namespace ilang
