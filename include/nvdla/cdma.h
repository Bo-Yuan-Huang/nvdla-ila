// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: cdma.h

#ifndef ILA_CDMA_H__
#define ILA_CDMA_H__

#include <nvdla/conv_pipe.h>

/// \namespace ilang
namespace ilang {

class Cdma : protected ConvPipe {
public:
  Cdma();
  ~Cdma();

  static Ila New(Ila& parent, const std::string& name = "cdma");

protected:
  //

private:
  static void DefineInterface(Ila& m);
  static void DefineInternal(Ila& m);
  static void DefineChild(Ila& m);
  static void DefineInstr(Ila& m);

}; // class Cdma

}; // namespace ilang

#endif // ILA_CDMA_H__

