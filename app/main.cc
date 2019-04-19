// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" wich comes with this distribution for more information.
// ============================================================================

// File Name: main.cc

#include <iostream>
#include <nvdla/top.h>

int main() {
  std::cout << "Hello World from executable main." << std::endl;

  ilang::Foo();

  return 0;
}
