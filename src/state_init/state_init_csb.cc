// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: state_init_csb.cc

#include <ilang/ilang++.h>
#include <nvdla/configs/state_info.h>
#include <nvdla/utils.h>

// namespace ilang
namespace ilang {

void StateInitCsb(Ila& m) {
  // FIXME this is temporary

  // Indicates that the receiver is ready to take a request
  m.AddInit(IsFalse(m.state(CSB2NVDLA_READY)));

  // Indicates that read data is valid.
  m.AddInit(IsFalse(m.state(NVDLA2CSB_VALID)));

  // Data corresponding to a read request, or zero in the event of an error.
  // NVDLA2CSB_DATA (don't care?)

  // Indicates that a CSB write has completed.
  m.AddInit(IsFalse(m.state(NVDLA2CSB_WR_COMPLETE)));

  // Active high while an interrupt is pending from NVDLA.
  m.AddInit(IsFalse(m.state(NVDLA2CORE_INTERRUPT)));

  return;
}

}; // namespace ilang
