// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: nvdla_top.h

#ifndef NVDLA_TOP_H__
#define NVDLA_TOP_H__

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
  // signal name of the child ILA trigger
  static const std::string k_tag_glb;
  static const std::string k_tag_mcif;
  static const std::string k_tag_bdma;
  static const std::string k_tag_cdma;
  static const std::string k_tag_cbuf;
  static const std::string k_tag_csc;
  static const std::string k_tag_cmac_a;
  static const std::string k_tag_cmac_b;
  static const std::string k_tag_cacc;
  static const std::string k_tag_sdp_rdma;
  static const std::string k_tag_sdp;
  static const std::string k_tag_pdp_rdma;
  static const std::string k_tag_pdp;
  static const std::string k_tag_cdp_rdma;
  static const std::string k_tag_cdp;
  static const std::string k_tag_rubic;

  static const std::string k_child_cdma;
  static const std::string k_child_cbuf;
  static const std::string k_child_csc;
  static const std::string k_child_cmac_a;
  static const std::string k_child_cmac_b;
  static const std::string k_child_cacc;

private:
  static void DefineInterface(Ila& m);
  static void DefineInternal(Ila& m);
  static void DefineChild(Ila& m);
  static void DefineInstr(Ila& m);

}; // class NvDla

}; // namespace ilang

#endif // NVDLA_TOP_H__

