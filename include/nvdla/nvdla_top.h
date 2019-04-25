// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: nvdla_top.h

#ifndef ILA_NVDLA_TOP_H__
#define ILA_NVDLA_TOP_H__

#include <ilang/ilang++.h>

// namespace ilang
namespace ilang {

// Top level model of NVDLA
class NvDla {
public:
  // vector of expr
  typedef std::vector<ExprRef> ExprVec;

  // default constructor
  NvDla();
  // default destructor
  ~NvDla();

  // return a new ILA with the given name
  static Ila New(const std::string& name = "nvdla_top");

  // return all input assumptions
  static void GetInputAssumption(const Ila& top, ExprVec& assm);
  // return all invariants over state variables
  static void GetStateInvariant(const Ila& top, ExprVec& invr);

protected:
  /* internal state info
   * - name of the child ILA
   * - name of the trigger signal
   */

  // convolution pipeline (CDMA, CBUF, CSC, CMAC, and CACC)
  static const std::string k_name_conv_pipe;
  static const std::string k_trig_conv_pipe;

  // single data processor pipeline (SDP and SDP-RDMA)
  static const std::string k_name_sdp_pipe;
  static const std::string k_trig_sdp_pipe;

  // planar data processor pipeline (PDP and PDP-RDMA)
  static const std::string k_name_pdp_pipe;
  static const std::string k_trig_pdp_pipe;

  // channel data processor pipeline (CDP and CDP-RDMA)
  static const std::string k_name_cdp_pipe;
  static const std::string k_trig_cdp_pipe;

  // bridge DMA (BDMA)
  static const std::string k_name_bdma;
  static const std::string k_trig_bdma;

  // reshape engine (RUBIK)
  static const std::string k_name_rubik;
  static const std::string k_trig_rubik;

private:
  // set architectural state variable (spec./doc.)
  static void SetArchStateVar(Ila& m);
  // set implementation state variable (internal)
  static void SetImplStateVar(Ila& m);
  // set child ila
  static void SetChild(Ila& m);
  // set instruction
  static void SetInstr(Ila& m);

  // input assumptions (no hierarchy)
  static void InputAssume(const Ila& m, ExprVec& assm);
  // state invariant (no hierarchy)
  static void StateInvariant(const Ila& m, ExprVec& invr);

}; // class NvDla

}; // namespace ilang

#endif // ILA_NVDLA_TOP_H__
