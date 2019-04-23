// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: state_define_bdma.cc

#include <ilang/ilang++.h>
#include <nvdla/configs/state_info.h>
#include <nvdla/utils.h>

// namespace ilang
namespace ilang {

void StateDefine_bdma(Ila& m) {
  // Lower 32bits of source address
  NewState(m, BDMA_CFG_SRC_ADDR_LOW, BDMA_CFG_SRC_ADDR_LOW_BWID);

  // Higher 32bits of source address when axi araddr is 64bits
  NewState(m, BDMA_CFG_SRC_ADDR_HIGH, BDMA_CFG_SRC_ADDR_HIGH_BWID);

  // Lower 32bits of dest address
  NewState(m, BDMA_CFG_DST_ADDR_LOW, BDMA_CFG_DST_ADDR_LOW_BWID);

  // Higher 32bits of dest address when axi awaddr is 64bits
  NewState(m, BDMA_CFG_DST_ADDR_HIGH, BDMA_CFG_DST_ADDR_HIGH_BWID);

  // Size of one line
  NewState(m, BDMA_CFG_LINE, BDMA_CFG_LINE_BWID);

  // Ram type of source and destination
  NewState(m, BDMA_CFG_CMD, BDMA_CFG_CMD_BWID);

  // Number of lines to be moved in one surface
  NewState(m, BDMA_CFG_LINE_REPEAT, BDMA_CFG_LINE_REPEAT_BWID);

  // Source line stride
  NewState(m, BDMA_CFG_SRC_LINE, BDMA_CFG_SRC_LINE_BWID);

  // Destination line stride
  NewState(m, BDMA_CFG_DST_LINE, BDMA_CFG_DST_LINE_BWID);

  // Number of surfaces to be moved in one operation
  NewState(m, BDMA_CFG_SURF_REPEAT, BDMA_CFG_SURF_REPEAT_BWID);

  // Source surface stride
  NewState(m, BDMA_CFG_SRC_SURF, BDMA_CFG_SRC_SURF_BWID);

  // Destination surface stride
  NewState(m, BDMA_CFG_DST_SURF, BDMA_CFG_DST_SURF_BWID);

  // This register is not used in NVDLA 1.0
  NewState(m, BDMA_CFG_OP, BDMA_CFG_OP_BWID);

  // Set it to 1 to kick off operations in group0
  NewState(m, BDMA_CFG_LAUNCH0, BDMA_CFG_LAUNCH0_BWID);

  // Set it to 1 to kick off operations in group1
  NewState(m, BDMA_CFG_LAUNCH1, BDMA_CFG_LAUNCH1_BWID);

  // Enable/Disable of counting stalls
  NewState(m, BDMA_CFG_STATUS, BDMA_CFG_STATUS_BWID);

  // Status register: idle status of bdma, group0 and group1
  NewState(m, BDMA_STATUS, BDMA_STATUS_BWID);

  // Counting register of group0 read stall
  NewState(m, BDMA_STAUS_GRP0_READ_STALL, BDMA_STAUS_GRP0_READ_STALL_BWID);

  // Counting register of group0 write stall
  NewState(m, BDMA_STATUS_GRP0_WRITE_STALL, BDMA_STATUS_GRP0_WRITE_STALL_BWID);

  // Counting register of group1 read stall
  NewState(m, BDMA_STAUS_GRP1_READ_STALL, BDMA_STAUS_GRP1_READ_STALL_BWID);

  // Counting register of group1 write stall
  NewState(m, BDMA_STATUS_GRP1_WRITE_STALL, BDMA_STATUS_GRP1_WRITE_STALL_BWID);

  return;
}

}; // namespace ilang
