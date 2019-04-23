// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: state_define_rubik.cc

#include <ilang/ilang++.h>
#include <nvdla/configs/state_info.h>
#include <nvdla/utils.h>

// namespace ilang
namespace ilang {

void StateDefine_rubik(Ila& m) {
  // Idle status of two register groups
  NewState(m, RUBIK_S_STATUS, RUBIK_S_STATUS_BWID);

  // Pointer for CSB master and data path to access groups
  NewState(m, RUBIK_S_POINTER, RUBIK_S_POINTER_BWID);

  // Set it to 1 to kick off operation for current register group
  NewState(m, RUBIK_D_OP_ENABLE, RUBIK_D_OP_ENABLE_BWID);

  // Operation mode and precision
  NewState(m, RUBIK_D_MISC_CFG, RUBIK_D_MISC_CFG_BWID);

  // RAM type of input cube
  NewState(m, RUBIK_D_DAIN_RAM_TYPE, RUBIK_D_DAIN_RAM_TYPE_BWID);

  // Input data cube’s width and height
  NewState(m, RUBIK_D_DATAIN_SIZE_0, RUBIK_D_DATAIN_SIZE_0_BWID);

  // Input data cube’s channel
  NewState(m, RUBIK_D_DATAIN_SIZE_1, RUBIK_D_DATAIN_SIZE_1_BWID);

  // Higher 32bits of input data address when axi araddr is 64bits
  NewState(m, RUBIK_D_DAIN_ADDR_HIGH, RUBIK_D_DAIN_ADDR_HIGH_BWID);

  // Lower 32bits of input data address
  NewState(m, RUBIK_D_DAIN_ADDR_LOW, RUBIK_D_DAIN_ADDR_LOW_BWID);

  // Line stride of input data cube
  NewState(m, RUBIK_D_DAIN_LINE_STRIDE, RUBIK_D_DAIN_LINE_STRIDE_BWID);

  // Surface stride of input data cube
  NewState(m, RUBIK_D_DAIN_SURF_STRIDE, RUBIK_D_DAIN_SURF_STRIDE_BWID);

  // Input data planar stride, for merge mode only
  NewState(m, RUBIK_D_DAIN_PLANAR_STRIDE, RUBIK_D_DAIN_PLANAR_STRIDE_BWID);

  // RAM type of output cube
  NewState(m, RUBIK_D_DAOUT_RAM_TYPE, RUBIK_D_DAOUT_RAM_TYPE_BWID);

  // Output data cube’s channel
  NewState(m, RUBIK_D_DATAOUT_SIZE_1, RUBIK_D_DATAOUT_SIZE_1_BWID);

  // Higher 32bits of output data address when axi awaddr is 64bits
  NewState(m, RUBIK_D_DAOUT_ADDR_HIGH, RUBIK_D_DAOUT_ADDR_HIGH_BWID);

  // Lower 32bits of output data address
  NewState(m, RUBIK_D_DAOUT_ADDR_LOW, RUBIK_D_DAOUT_ADDR_LOW_BWID);

  // Line stride of output data cube
  NewState(m, RUBIK_D_DAOUT_LINE_STRIDE, RUBIK_D_DAOUT_LINE_STRIDE_BWID);

  // Input stride for each X step. Equals to (DATAOUT_CHANNEL+1) * BPE / 32 *
  // DAIN_SURF_STRIDE. (BPE = (IN_PRECISION == INT8) ? 1 : 2;)
  NewState(m, RUBIK_D_CONTRACT_STRIDE_0, RUBIK_D_CONTRACT_STRIDE_0_BWID);

  // Output stride corresponding to each line in input cube. equals to
  // (DECONV_Y_STRIDE+1) * DAOUT_LINE_STRIDE
  NewState(m, RUBIK_D_CONTRACT_STRIDE_1, RUBIK_D_CONTRACT_STRIDE_1_BWID);

  // Surface stride of output data cube
  NewState(m, RUBIK_D_DAOUT_SURF_STRIDE, RUBIK_D_DAOUT_SURF_STRIDE_BWID);

  // Output data planar stride, for split mode only
  NewState(m, RUBIK_D_DAOUT_PLANAR_STRIDE, RUBIK_D_DAOUT_PLANAR_STRIDE_BWID);

  // Deconvolution x stride and y stride
  NewState(m, RUBIK_D_DECONV_STRIDE, RUBIK_D_DECONV_STRIDE_BWID);

  // Enable/Disable performance counting
  NewState(m, RUBIK_D_PERF_ENABLE, RUBIK_D_PERF_ENABLE_BWID);

  // RD_STALL Count stall cycles of read DMA for one layer
  NewState(m, RUBIK_D_PERF_READ_STALL, RUBIK_D_PERF_READ_STALL_BWID);

  // WR_STALL Count stall cycles of write DMA for one layer
  NewState(m, RUBIK_D_PERF_WRITE_STALL, RUBIK_D_PERF_WRITE_STALL_BWID);

  return;
}

}; // namespace ilang
