// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: conv_pipe.h

#ifndef ILA_CONV_PIPE_H__
#define ILA_CONV_PIPE_H__

#include <nvdla/nvdla_top.h>

// namespace ilang
namespace ilang {

// convolution pipeline
class ConvPipe : protected NvDla {

public:
  // default constructor
  ConvPipe();
  // default destructor
  ~ConvPipe();

  // return a new ILA with the given name
  static Ila New(Ila& parent, const std::string& name = "conv_pipe");

  // return all input assumptions
  static void GetInputAssumption(const Ila& top, ExprVec& assm);
  // return all state invariant
  static void GetStateInvariant(const Ila& top, ExprVec& invr);

  // return the name of the i-th CBUF bank
  static std::string CbufBankName(const int& i);

protected:
  //

private:
  // set architectural state variable (spec./doc.)
  static void SetArchStateVar(Ila& m);
  // set implementation state variable (internal)
  static void SetImplStateVar(Ila& m);
  // set child ilas
  static void SetChild(Ila& m);
  // set instructions
  static void SetInstr(Ila& m);

  // define instruction of writing a csb register (no side-effect)
  static void DefineCsbWrInstr(Ila& m, const std::string& state_name,
                               const int& mmio_addr);

}; // class ConvPipe

}; // namespace ilang

#endif // ILA_CONV_PIPE_H__
