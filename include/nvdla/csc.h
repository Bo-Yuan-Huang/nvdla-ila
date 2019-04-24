// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: csc.h

#ifndef ILA_CSC_H__
#define ILA_CSC_H__

#include <nvdla/conv_pipe.h>

// namespace ilang
namespace ilang {

class Csc : protected ConvPipe {
public:
  Csc();
  ~Csc();

  static Ila New(Ila& parent, const std::string& name = "csc");

protected:
  //

private:
  static void DefineInterface(Ila& m);
  static void DefineInternal(Ila& m);
  static void DefineChild(Ila& m);
  static void DefineInstr(Ila& m);

}; // class Csc

}; // namespace ilang

#endif // ILA_CSC_H__

