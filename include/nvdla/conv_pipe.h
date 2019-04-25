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

class ConvPipe : protected NvDla {

public:
  ConvPipe();
  ~ConvPipe();

  static Ila New(Ila& parent, const std::string& name = "conv_pipe");

  static void GetInputAssumption(const Ila& top, ExprVec& assm);
  static void GetStateInvariant(const Ila& top, ExprVec& invr);

protected:
  /* internal state info
   * name of the child ila
   * name of the trigger signal
   */

  // CDMA
  static const std::string k_name_cdma;
  static const std::string k_trig_cdma;

  // CBUF
  static const std::string k_name_cbuf;
  static const std::string k_trig_cbuf;

  // CSC
  static const std::string k_name_csc;
  static const std::string k_trig_csc;

  // CMAC
  static const std::string k_name_cmac;
  static const std::string k_trig_cmac;

  // CACC
  static const std::string k_name_cacc;
  static const std::string k_trig_cacc;

private:
  static void SetArchStateVar(Ila& m);
  static void SetImplStateVar(Ila& m);
  static void SetChild(Ila& m);
  static void SetInstr(Ila& m);

}; // class ConvPipe

}; // namespace ilang

#endif // ILA_CONV_PIPE_H__

