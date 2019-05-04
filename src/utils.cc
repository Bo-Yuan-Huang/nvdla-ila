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

ExprRef BoolVal(const int& val) {
#ifdef ICFG_BOOL_AS_BV
  return BvConst(val, 1);
#else  // ICFG_BOOL_AS_BV
  return BoolConst(val == 1);
#endif // ICFG_BOOL_AS_BV
}

ExprRef IsTrue(const ExprRef& e) { return (e == BoolVal(1)); }

ExprRef IsFalse(const ExprRef& e) { return (e == BoolVal(0)); }

ExprRef NewInput(Ila& m, const std::string& name, const int& wid) {
#ifdef ICFG_BOOL_AS_BV
  return m.NewBvInput(name, wid);

#else // ICFG_BOOL_AS_BV
  if (wid == 1) {
    return m.NewBoolInput(name);
  } else {
    return m.NewBvInput(name, wid);
  }

#endif // ICFG_BOOL_AS_BV
}

ExprRef NewState(Ila& m, const std::string& name, const int& wid) {
#ifdef ICFG_BOOL_AS_BV
  return m.NewBvState(name, wid);

#else // ICFG_BOOL_AS_BV
  if (wid == 1) {
    return m.NewBoolState(name);
  } else {
    return m.NewBvState(name, wid);
  }

#endif // ICFG_BOOL_AS_BV
}

}; // namespace ilang

