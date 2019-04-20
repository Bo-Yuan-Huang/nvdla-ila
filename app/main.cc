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

int main() {

  auto m = ilang::NvDla();
  auto nvdla = m.NewIla();
  ilang::ExportIlaPortable(nvdla, "nvdla.json");

  return 0;
}
