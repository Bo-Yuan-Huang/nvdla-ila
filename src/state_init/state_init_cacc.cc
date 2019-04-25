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
  m.AddInit(m.state(CACC_D_OP_ENABLE) == 0);

  // Configuration of operation: convolution mode, precision, etc.
  m.AddInit(m.state(CACC_D_MISC_CFG) == 0);

  // Input cube’s width and height after extension
  m.AddInit(m.state(CACC_D_DATAOUT_SIZE_0) == 0);

  // Input cube’s channel after extension
  m.AddInit(m.state(CACC_D_DATAOUT_SIZE_1) == 0);

  // Address of output cube
  m.AddInit(m.state(CACC_D_DATAOUT_ADDR) == 0);

  // Number of batches
  m.AddInit(m.state(CACC_D_BATCH_NUMBER) == 0);

  // Line stride of output cube
  m.AddInit(m.state(CACC_D_LINE_STRIDE) == 0);

  // Line stride of surface cube
  m.AddInit(m.state(CACC_D_SURF_STRIDE) == 0);

  // Whether output cube is line packed or surface packed
  m.AddInit(m.state(CACC_D_DATAOUT_MAP) == 0);

  // Number of bits to be truncated before sending to SDP
  m.AddInit(m.state(CACC_D_CLIP_CFG) == 0);

  // Output saturation count
  m.AddInit(m.state(CACC_D_OUT_SATURATION) == 0);

  return;
}

}; // namespace ilang
