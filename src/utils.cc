// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: utils.cc

#include <nvdla/configs/modeling_config.h>
#include <nvdla/utils.h>

namespace ilang {

void NewInput(Ila& m, const std::string& name, const int& wid) {
#ifdef MODEL_BOOL_AS_BV
  m.NewBvInput(name, wid);

#else // MODEL_BOOL_AS_BV
  if (wid == 1) {
    m.NewBoolInput(name);
  } else {
    m.NewBvInput(name, wid);
  }

#endif // MODEL_BOOL_AS_BV
}

void NewState(Ila& m, const std::string& name, const int& wid) {
#ifdef MODEL_BOOL_AS_BV
  m.NewBvState(name, wid);

#else // MODEL_BOOL_AS_BV
  m.NewBvInput(name, wid);
  if (wid == 1) {
    m.NewBoolState(name);
  } else {
    m.NewBvState(name, wid);
  }

#endif // MODEL_BOOL_AS_BV
}

}; // namespace ilang

