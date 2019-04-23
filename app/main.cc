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

  auto assumptions = NvDla::Assumptions(nvdla);
  auto invariants = NvDla::Invariants(nvdla);

  return 0;
}
