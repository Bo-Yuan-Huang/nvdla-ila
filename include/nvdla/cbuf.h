// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: cbuf.h

#ifndef CBUF_ILA_H__
#define CBUF_ILA_H__

#include <ilang/ilang++.h>
#include <nvdla/nvdla_top.h>

// namespace ilang
namespace ilang {

class Cbuf : protected NvDla {
public:
  Cbuf();
  ~Cbuf();

  static Ila New(Ila& parent, const std::string& name = "cbuf");

protected:
  //

private:
  static void DefineInterface(Ila& m);
  static void DefineInternal(Ila& m);
  static void DefineChild(Ila& m);
  static void DefineInstr(Ila& m);

}; // class Cbuf

}; // namespace ilang

#endif // CBUF_ILA_H__

