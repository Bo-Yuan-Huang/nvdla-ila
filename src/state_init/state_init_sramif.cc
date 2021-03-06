// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: state_init_sramif.cc

#include <ilang/ilang++.h>
#include <nvdla/configs/state_info.h>
#include <nvdla/utils.h>

// namespace ilang
namespace ilang {

// FIXME this is auto-generated placeholder

void StateInitSramif(Ila& m) {
  // Register0 to control the read weight of clients in MCIF
  m.AddInit(m.state(SRAMIF_CFG_RD_WEIGHT_0) == 0);

  // Register1 to control the read weight of clients in MCIF
  m.AddInit(m.state(SRAMIF_CFG_RD_WEIGHT_1) == 0);

  // Register2 to control the read weight of clients in MCIF
  m.AddInit(m.state(SRAMIF_CFG_RD_WEIGHT_2) == 0);

  // Register0 to control the write weight of clients in MCIF
  m.AddInit(m.state(SRAMIF_CFG_WR_WEIGHT_0) == 0);

  // Register1 to control the write weight of clients in MCIF
  m.AddInit(m.state(SRAMIF_CFG_WR_WEIGHT_1) == 0);

  // Outstanding AXI transactions in unit of 64Byte
  m.AddInit(m.state(SRAMIF_CFG_OUTSTANDING_CNT) == 0);

  // Idle status of SRAMIF
  m.AddInit(m.state(SRAMIF_STATUS) == 0);

  return;
}

}; // namespace ilang
