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
#include <string>
#include <vector>

/// \namespace ilang
namespace ilang {

class NvDla {
public:
  NvDla();
  ~NvDla();

  static Ila New(const std::string& name = "nvdla_top");
  static std::vector<ExprRef> Assumptions(Ila& m);
  static std::vector<ExprRef> Invariants(Ila& m);

protected:
  /* internal state info
   * name of the child ILA
   * name of the trigger signal
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
  static void DefineInterface(Ila& m);
  static void DefineInternal(Ila& m);
  static void DefineChild(Ila& m);
  static void DefineInstr(Ila& m);

}; // class NvDla

}; // namespace ilang

#endif // ILA_NVDLA_TOP_H__

