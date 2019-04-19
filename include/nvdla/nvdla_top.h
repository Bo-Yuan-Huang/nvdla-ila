// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: nvdla_top.h

#ifndef NVDLA_TOP_H__
#define NVDLA_TOP_H__

#include <ilang/ilang++.h>

/// \namespace ilang
namespace ilang {

class NvDla {
public:
  NvDla();
  ~NvDla();

  static Ila NewIla(const std::string& name = "nvdla_top");

private:
  static void DefineArchState(Ila& m);
  static void DefineCsbInstr(Ila& m);

}; // class NvDla

}; // namespace ilang

#endif // NVDLA_TOP_H__

