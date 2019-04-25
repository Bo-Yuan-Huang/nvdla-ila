// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: state_init_bdma.cc

#include <ilang/ilang++.h>
#include <nvdla/configs/state_info.h>
#include <nvdla/utils.h>

// namespace ilang
namespace ilang {

// FIXME this is auto-generated placeholder

void StateInitBdma(Ila& m) {
  // Lower 32bits of source address
  m.AddInit(m.state(BDMA_CFG_SRC_ADDR_LOW) == 0);

  // Higher 32bits of source address when axi araddr is 64bits
  m.AddInit(m.state(BDMA_CFG_SRC_ADDR_HIGH) == 0);

  // Lower 32bits of dest address
  m.AddInit(m.state(BDMA_CFG_DST_ADDR_LOW) == 0);

  // Higher 32bits of dest address when axi awaddr is 64bits
  m.AddInit(m.state(BDMA_CFG_DST_ADDR_HIGH) == 0);

  // Size of one line
  m.AddInit(m.state(BDMA_CFG_LINE) == 0);

  // Ram type of source and destination
  m.AddInit(m.state(BDMA_CFG_CMD) == 0);

  // Number of lines to be moved in one surface
  m.AddInit(m.state(BDMA_CFG_LINE_REPEAT) == 0);

  // Source line stride
  m.AddInit(m.state(BDMA_CFG_SRC_LINE) == 0);

  // Destination line stride
  m.AddInit(m.state(BDMA_CFG_DST_LINE) == 0);

  // Number of surfaces to be moved in one operation
  m.AddInit(m.state(BDMA_CFG_SURF_REPEAT) == 0);

  // Source surface stride
  m.AddInit(m.state(BDMA_CFG_SRC_SURF) == 0);

  // Destination surface stride
  m.AddInit(m.state(BDMA_CFG_DST_SURF) == 0);

  // This register is not used in NVDLA 1.0
  m.AddInit(m.state(BDMA_CFG_OP) == 0);

  // Set it to 1 to kick off operations in group0
  m.AddInit(m.state(BDMA_CFG_LAUNCH0) == 0);

  // Set it to 1 to kick off operations in group1
  m.AddInit(m.state(BDMA_CFG_LAUNCH1) == 0);

  // Enable/Disable of counting stalls
  m.AddInit(m.state(BDMA_CFG_STATUS) == 0);

  // Status register: idle status of bdma, group0 and group1
  m.AddInit(m.state(BDMA_STATUS) == 0);

  // Counting register of group0 read stall
  m.AddInit(m.state(BDMA_STAUS_GRP0_READ_STALL) == 0);

  // Counting register of group0 write stall
  m.AddInit(m.state(BDMA_STATUS_GRP0_WRITE_STALL) == 0);

  // Counting register of group1 read stall
  m.AddInit(m.state(BDMA_STAUS_GRP1_READ_STALL) == 0);

  // Counting register of group1 write stall
  m.AddInit(m.state(BDMA_STATUS_GRP1_WRITE_STALL) == 0);

  return;
}

}; // namespace ilang
