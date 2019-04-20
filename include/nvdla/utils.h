// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: utils.h

#ifndef NVDLA_ILA_UTILS_H__
#define NVDLA_ILA_UTILS_H__

#include <ilang/ilang++.h>

namespace ilang {

// Return a Boolean/bit-vector value based on the input
ExprRef BoolVal(const int& val);

// Return an expr that compares the value to true/1
ExprRef IsTrue(const ExprRef& e);

// Return an expr that compares the value to false/0
ExprRef IsFalse(const ExprRef& e);

// Create new input variable in the ILA
ExprRef NewInput(Ila& m, const std::string& name, const int& wid = 1);

// Create new state variable in the ILA
ExprRef NewState(Ila& m, const std::string& name, const int& wid = 1);

}; // namespace ilang

#endif // NVDLA_ILA_UTILS_H__

