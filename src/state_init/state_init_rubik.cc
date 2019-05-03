// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: state_init_rubik.cc

#include <ilang/ilang++.h>
#include <nvdla/configs/state_info.h>
#include <nvdla/utils.h>

// namespace ilang
namespace ilang {

// FIXME this is auto-generated placeholder

void StateInitRubik(Ila& m) {
  // Idle status of two register groups
  m.AddInit(m.state(RUBIK_S_STATUS) == 0);

  // Pointer for CSB master and data path to access groups
  m.AddInit(m.state(RUBIK_S_POINTER) == 0);

  // Set it to 1 to kick off operation for current register group
  m.AddInit(m.state(RUBIK_D_OP_ENABLE_G0) == 0);
  m.AddInit(m.state(RUBIK_D_OP_ENABLE_G1) == 0);

  // Operation mode and precision
  m.AddInit(m.state(RUBIK_D_MISC_CFG_G0) == 0);
  m.AddInit(m.state(RUBIK_D_MISC_CFG_G1) == 0);

  // RAM type of input cube
  m.AddInit(m.state(RUBIK_D_DAIN_RAM_TYPE_G0) == 0);
  m.AddInit(m.state(RUBIK_D_DAIN_RAM_TYPE_G1) == 0);

  // Input data cube’s width and height
  m.AddInit(m.state(RUBIK_D_DATAIN_SIZE_0_G0) == 0);
  m.AddInit(m.state(RUBIK_D_DATAIN_SIZE_0_G1) == 0);

  // Input data cube’s channel
  m.AddInit(m.state(RUBIK_D_DATAIN_SIZE_1_G0) == 0);
  m.AddInit(m.state(RUBIK_D_DATAIN_SIZE_1_G1) == 0);

  // Higher 32bits of input data address when axi araddr is 64bits
  m.AddInit(m.state(RUBIK_D_DAIN_ADDR_HIGH_G0) == 0);
  m.AddInit(m.state(RUBIK_D_DAIN_ADDR_HIGH_G1) == 0);

  // Lower 32bits of input data address
  m.AddInit(m.state(RUBIK_D_DAIN_ADDR_LOW_G0) == 0);
  m.AddInit(m.state(RUBIK_D_DAIN_ADDR_LOW_G1) == 0);

  // Line stride of input data cube
  m.AddInit(m.state(RUBIK_D_DAIN_LINE_STRIDE_G0) == 0);
  m.AddInit(m.state(RUBIK_D_DAIN_LINE_STRIDE_G1) == 0);

  // Surface stride of input data cube
  m.AddInit(m.state(RUBIK_D_DAIN_SURF_STRIDE_G0) == 0);
  m.AddInit(m.state(RUBIK_D_DAIN_SURF_STRIDE_G1) == 0);

  // Input data planar stride, for merge mode only
  m.AddInit(m.state(RUBIK_D_DAIN_PLANAR_STRIDE_G0) == 0);
  m.AddInit(m.state(RUBIK_D_DAIN_PLANAR_STRIDE_G1) == 0);

  // RAM type of output cube
  m.AddInit(m.state(RUBIK_D_DAOUT_RAM_TYPE_G0) == 0);
  m.AddInit(m.state(RUBIK_D_DAOUT_RAM_TYPE_G1) == 0);

  // Output data cube’s channel
  m.AddInit(m.state(RUBIK_D_DATAOUT_SIZE_1_G0) == 0);
  m.AddInit(m.state(RUBIK_D_DATAOUT_SIZE_1_G1) == 0);

  // Higher 32bits of output data address when axi awaddr is 64bits
  m.AddInit(m.state(RUBIK_D_DAOUT_ADDR_HIGH_G0) == 0);
  m.AddInit(m.state(RUBIK_D_DAOUT_ADDR_HIGH_G1) == 0);

  // Lower 32bits of output data address
  m.AddInit(m.state(RUBIK_D_DAOUT_ADDR_LOW_G0) == 0);
  m.AddInit(m.state(RUBIK_D_DAOUT_ADDR_LOW_G1) == 0);

  // Line stride of output data cube
  m.AddInit(m.state(RUBIK_D_DAOUT_LINE_STRIDE_G0) == 0);
  m.AddInit(m.state(RUBIK_D_DAOUT_LINE_STRIDE_G1) == 0);

  // Input stride for each X step. Equals to (DATAOUT_CHANNEL+1) * BPE / 32 *
  // DAIN_SURF_STRIDE. (BPE = (IN_PRECISION == INT8) ? 1 : 2;)
  m.AddInit(m.state(RUBIK_D_CONTRACT_STRIDE_0_G0) == 0);
  m.AddInit(m.state(RUBIK_D_CONTRACT_STRIDE_0_G1) == 0);

  // Output stride corresponding to each line in input cube. equals to
  // (DECONV_Y_STRIDE+1) * DAOUT_LINE_STRIDE
  m.AddInit(m.state(RUBIK_D_CONTRACT_STRIDE_1_G0) == 0);
  m.AddInit(m.state(RUBIK_D_CONTRACT_STRIDE_1_G1) == 0);

  // Surface stride of output data cube
  m.AddInit(m.state(RUBIK_D_DAOUT_SURF_STRIDE_G0) == 0);
  m.AddInit(m.state(RUBIK_D_DAOUT_SURF_STRIDE_G1) == 0);

  // Output data planar stride, for split mode only
  m.AddInit(m.state(RUBIK_D_DAOUT_PLANAR_STRIDE_G0) == 0);
  m.AddInit(m.state(RUBIK_D_DAOUT_PLANAR_STRIDE_G1) == 0);

  // Deconvolution x stride and y stride
  m.AddInit(m.state(RUBIK_D_DECONV_STRIDE_G0) == 0);
  m.AddInit(m.state(RUBIK_D_DECONV_STRIDE_G1) == 0);

  // Enable/Disable performance counting
  m.AddInit(m.state(RUBIK_D_PERF_ENABLE_G0) == 0);
  m.AddInit(m.state(RUBIK_D_PERF_ENABLE_G1) == 0);

  // RD_STALL Count stall cycles of read DMA for one layer
  m.AddInit(m.state(RUBIK_D_PERF_READ_STALL_G0) == 0);
  m.AddInit(m.state(RUBIK_D_PERF_READ_STALL_G1) == 0);

  // WR_STALL Count stall cycles of write DMA for one layer
  m.AddInit(m.state(RUBIK_D_PERF_WRITE_STALL_G0) == 0);
  m.AddInit(m.state(RUBIK_D_PERF_WRITE_STALL_G1) == 0);

  return;
}

}; // namespace ilang
