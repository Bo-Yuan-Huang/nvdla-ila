// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: state_init_cacc.cc

#include <ilang/ilang++.h>
#include <nvdla/configs/state_info.h>
#include <nvdla/utils.h>

// namespace ilang
namespace ilang {

// FIXME this is auto-generated placeholder

void StateInitCacc(Ila& m) {
  // Idle status of two register groups
  m.AddInit(m.state(CACC_S_STATUS) == 0);

  // Pointer for CSB master and data path to access groups
  m.AddInit(m.state(CACC_S_POINTER) == 0);

  // Set it to 1 to kick off operation for current register group
  m.AddInit(m.state(CACC_D_OP_ENABLE_G0) == 0);
  m.AddInit(m.state(CACC_D_OP_ENABLE_G1) == 0);

  // Configuration of operation: convolution mode, precision, etc.
  m.AddInit(m.state(CACC_D_MISC_CFG_G0) == 0);
  m.AddInit(m.state(CACC_D_MISC_CFG_G1) == 0);

  // Input cube’s width and height after extension
  m.AddInit(m.state(CACC_D_DATAOUT_SIZE_0_G0) == 0);
  m.AddInit(m.state(CACC_D_DATAOUT_SIZE_0_G1) == 0);

  // Input cube’s channel after extension
  m.AddInit(m.state(CACC_D_DATAOUT_SIZE_1_G0) == 0);
  m.AddInit(m.state(CACC_D_DATAOUT_SIZE_1_G1) == 0);

  // Address of output cube
  m.AddInit(m.state(CACC_D_DATAOUT_ADDR_G0) == 0);
  m.AddInit(m.state(CACC_D_DATAOUT_ADDR_G1) == 0);

  // Number of batches
  m.AddInit(m.state(CACC_D_BATCH_NUMBER_G0) == 0);
  m.AddInit(m.state(CACC_D_BATCH_NUMBER_G1) == 0);

  // Line stride of output cube
  m.AddInit(m.state(CACC_D_LINE_STRIDE_G0) == 0);
  m.AddInit(m.state(CACC_D_LINE_STRIDE_G1) == 0);

  // Line stride of surface cube
  m.AddInit(m.state(CACC_D_SURF_STRIDE_G0) == 0);
  m.AddInit(m.state(CACC_D_SURF_STRIDE_G1) == 0);

  // Whether output cube is line packed or surface packed
  m.AddInit(m.state(CACC_D_DATAOUT_MAP_G0) == 0);
  m.AddInit(m.state(CACC_D_DATAOUT_MAP_G1) == 0);

  // Number of bits to be truncated before sending to SDP
  m.AddInit(m.state(CACC_D_CLIP_CFG_G0) == 0);
  m.AddInit(m.state(CACC_D_CLIP_CFG_G1) == 0);

  // Output saturation count
  m.AddInit(m.state(CACC_D_OUT_SATURATION_G0) == 0);
  m.AddInit(m.state(CACC_D_OUT_SATURATION_G1) == 0);

  return;
}

}; // namespace ilang
