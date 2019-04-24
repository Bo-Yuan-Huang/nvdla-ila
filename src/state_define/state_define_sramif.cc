// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: state_define_sramif.cc

#include <ilang/ilang++.h>
#include <nvdla/configs/state_info.h>
#include <nvdla/utils.h>

// namespace ilang
namespace ilang {

void StateDefineSramif(Ila& m) {
  // Register0 to control the read weight of clients in MCIF
  NewState(m, SRAMIF_CFG_RD_WEIGHT_0, SRAMIF_CFG_RD_WEIGHT_0_BWID);

  // Register1 to control the read weight of clients in MCIF
  NewState(m, SRAMIF_CFG_RD_WEIGHT_1, SRAMIF_CFG_RD_WEIGHT_1_BWID);

  // Register2 to control the read weight of clients in MCIF
  NewState(m, SRAMIF_CFG_RD_WEIGHT_2, SRAMIF_CFG_RD_WEIGHT_2_BWID);

  // Register0 to control the write weight of clients in MCIF
  NewState(m, SRAMIF_CFG_WR_WEIGHT_0, SRAMIF_CFG_WR_WEIGHT_0_BWID);

  // Register1 to control the write weight of clients in MCIF
  NewState(m, SRAMIF_CFG_WR_WEIGHT_1, SRAMIF_CFG_WR_WEIGHT_1_BWID);

  // Outstanding AXI transactions in unit of 64Byte
  NewState(m, SRAMIF_CFG_OUTSTANDING_CNT, SRAMIF_CFG_OUTSTANDING_CNT_BWID);

  // Idle status of SRAMIF
  NewState(m, SRAMIF_STATUS, SRAMIF_STATUS_BWID);

  return;
}

}; // namespace ilang
