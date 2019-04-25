// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: main.cc

#include <iostream>
#include <nvdla/nvdla_top.h>

using namespace ilang;

int main() {

  LogToErr(true);

  auto nvdla = NvDla::New();
  ExportIlaPortable(nvdla, "nvdla.json");

  auto assm = std::vector<ilang::ExprRef>();
  NvDla::GetInputAssumption(nvdla, assm);

  auto invr = std::vector<ilang::ExprRef>();
  NvDla::GetStateInvariant(nvdla, invr);

  return 0;
}
