// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: nvdla_top.cc

#include <nvdla/configs/addr_space.h>
#include <nvdla/configs/state_info_top.h>
#include <nvdla/nvdla_top.h>
#include <nvdla/utils.h>

namespace ilang {

const std::string NvDla::k_tag_glb = "tag_glb";
const std::string NvDla::k_tag_mcif = "tag_mcif";
const std::string NvDla::k_tag_bdma = "tag_bdma";
const std::string NvDla::k_tag_cbuf = "tag_cbuf";
const std::string NvDla::k_tag_cdma = "tag_cdma";
const std::string NvDla::k_tag_csc = "tag_csc";
const std::string NvDla::k_tag_cmac_a = "tag_cmac_a";
const std::string NvDla::k_tag_cmac_b = "tag_cmac_b";
const std::string NvDla::k_tag_cacc = "tag_cacc";
const std::string NvDla::k_tag_sdp_rdma = "tag_sdp_rdma";
const std::string NvDla::k_tag_sdp = "tag_sdp";
const std::string NvDla::k_tag_pdp_rdma = "tag_pdp_rdma";
const std::string NvDla::k_tag_pdp = "tag_pdp";
const std::string NvDla::k_tag_cdp_rdma = "tag_cdp_rdma";
const std::string NvDla::k_tag_cdp = "tag_cdp";
const std::string NvDla::k_tag_rubic = "tag_rubic";

const std::string NvDla::k_child_cdma = "cdma";
const std::string NvDla::k_child_cbuf = "cbuf";
const std::string NvDla::k_child_csc = "csc";
const std::string NvDla::k_child_cmac_a = "cmac_a";
const std::string NvDla::k_child_cmac_b = "cmac_b";
const std::string NvDla::k_child_cacc = "cacc";

NvDla::NvDla() {}

NvDla::~NvDla() {}

Ila NvDla::NewIla(const std::string& name) {
  auto m = Ila(name);

  DefineInterface(m);
  DefineInternal(m);
  DeclareChild(m);
  DefineInstr(m);

  // valid
  m.SetValid(BoolVal(1)); // FIXME

  // fetch
  m.SetFetch(BvConst(1, 1)); // FIXME

  return m;
}

void NvDla::DefineInterface(Ila& m) {
  /***** configuration space bus (CSB) *****/

  /* Request channel
   * The request channel follows a valid/ready protocol; a data transaction
   * occurs on the request channel when and only when the valid signal (from the
   * host) and the ready signal (from NVDLA) are both asserted in the same clock
   * cycle. Each request to CSB has a fixed request size of 32 bits of data, and
   * has a fixed 16bit address size. CSB does not support any form of burst
   * requests; each packet sent down the request channel is independent from any
   * other packet.
   */

  // Indicates that a request is valid
  NewInput(m, CSB2NVDLA_VALID, CSB2NVDLA_VALID_WID);

  // Indicates that the receiver is ready to take a request
  NewState(m, CSB2NVDLA_READY, CSB2NVDLA_READY_WID);

  // Address. Aligned to word boundary.
  NewInput(m, CSB2NVDLA_ADDR, CSB2NVDLA_ADDR_WID);

  // Write data
  NewInput(m, CSB2NVDLA_WDAT, CSB2NVDLA_WDAT_WID);

  // Write flag.
  // 1'b0: Request is a read request.
  // 1'b1: Request is a write request.
  NewInput(m, CSB2NVDLA_WRITE, CSB2NVDLA_WRITE_WID);

  // Non-posted write transaction indicator.
  // 1'b0: Request is a posted write request.
  // 1'b1: Indicates a non-posted write request.
  NewInput(m, CSB2NVDLA_NPOSTED, CSB2NVDLA_NPOSTED_WID);

  /* Read data channel
   * NVDLA returns read-response data to the host in strict request order; that
   * is to say, each request packet (above) for which “write” is set to 0 will
   * have exactly one response, and that response cannot jump forward or
   * backwards relative to other reads. The read data channel follows a
   * valid-only protocol; as such, the host cannot apply back-pressure to the
   * NVDLA on this interface.
   */

  // Indicates that read data is valid.
  NewState(m, NVDLA2CSB_VALID, NVDLA2CSB_VALID_WID);

  // Data corresponding to a read request, or zero in the event of an error.
  NewState(m, NVDLA2CSB_DATA, NVDLA2CSB_DATA_WID);

  /* Write response channel
   * NVDLA will return write completion to the host in request order for every
   * non-posted write. The write completion channel also follows a valid-only
   * protocol, and as such, the host cannot back-pressure NVDLA on this
   * interface.
   */

  // Indicates that a CSB write has completed.
  NewState(m, NVDLA2CSB_WR_COMPLETE, NVDLA2CSB_WR_COMPLETE_WID);

  /* Host interrupt
   * NVDLA provides an asynchronous (interrupt-driven) return channel to deliver
   * event notifications to the CPU. The interrupt signal is a level-driven
   * interrupt that is asserted high as long as the NVDLA core has interrupts
   * pending. Interrupts are pending if any bits are set in GLB’s INTR_STATUS
   * register that are also not masked out (i.e., set to zero) in the INTR_MASK
   * register. The NVDLA interrupt signal is on the same clock domain as the CSB
   * interface.
   */

  // Active high while an interrupt is pending from NVDLA.
  NewState(m, NVDLA2CORE_INTERRUPT, NVDLA2CORE_INTERRUPT_WID);

  /***** System interconnect: DBBIF *****/
  // TODO abstract AXI protocol

  /***** On-chip SRAM interface: SRAMIF *****/
  // TODO no SRAM in nv-small config
}

void NvDla::DefineInternal(Ila& m) {
  /* Trigger signals (tag of child-ILAs) */

  auto tag_glb = NewState(m, k_tag_glb);
  auto tag_mcif = NewState(m, k_tag_mcif);
  auto tag_bdma = NewState(m, k_tag_bdma);
  auto tag_cbuf = NewState(m, k_tag_cbuf);
  auto tag_cdma = NewState(m, k_tag_cdma);
  auto tag_csc = NewState(m, k_tag_csc);
  auto tag_cmac_a = NewState(m, k_tag_cmac_a);
  auto tag_cmac_b = NewState(m, k_tag_cmac_b);
  auto tag_cacc = NewState(m, k_tag_cacc);
  auto tag_sdp_rdma = NewState(m, k_tag_sdp_rdma);
  auto tag_sdp = NewState(m, k_tag_sdp);
  auto tag_pdp_rdma = NewState(m, k_tag_pdp_rdma);
  auto tag_pdp = NewState(m, k_tag_pdp);
  auto tag_cdp_rdma = NewState(m, k_tag_cdp_rdma);
  auto tag_cdp = NewState(m, k_tag_cdp);
  auto tag_rubic = NewState(m, k_tag_rubic);

  m.AddInit(IsFalse(tag_glb));
  m.AddInit(IsFalse(tag_mcif));
  m.AddInit(IsFalse(tag_bdma));
  m.AddInit(IsFalse(tag_cbuf));
  m.AddInit(IsFalse(tag_cdma));
  m.AddInit(IsFalse(tag_csc));
  m.AddInit(IsFalse(tag_cmac_a));
  m.AddInit(IsFalse(tag_cmac_b));
  m.AddInit(IsFalse(tag_cacc));
  m.AddInit(IsFalse(tag_sdp_rdma));
  m.AddInit(IsFalse(tag_sdp));
  m.AddInit(IsFalse(tag_pdp_rdma));
  m.AddInit(IsFalse(tag_pdp));
  m.AddInit(IsFalse(tag_cdp_rdma));
  m.AddInit(IsFalse(tag_cdp));
  m.AddInit(IsFalse(tag_rubic));
}

void NvDla::DeclareChild(Ila& m) {
  // CDMA
  auto cdma_ila = m.NewChild(k_child_cdma);
  cdma_ila.SetValid(IsTrue(m.state(k_tag_cdma)));

  // CBUF
  auto cbuf_ila = m.NewChild(k_child_cbuf); // XXX plain memory?
  cbuf_ila.SetValid(IsTrue(m.state(k_tag_cbuf)));

  // CSC
  auto csc_ila = m.NewChild(k_child_csc);
  csc_ila.SetValid(IsTrue(m.state(k_tag_csc)));

#ifdef NVDLA_RETIMING_ENABLE
  // CMAC
  auto cmac_ila = m.NewChild(k_child_cmac_b);
  cmac_ila.SetValid(IsTrue(m.state(k_tag_cmac_b)));

  // CACC
  auto cacc_ila = m.NewChild(k_child_cacc);
  cacc_ila.SetValid(IsTrue(m.state(k_tag_cacc)));
#endif
}

void NvDla::DefineInstr(Ila& m) {
  /***** configuration space bus (CSB) *****/

  // helper functions
  auto is_csb = m.state(CSB2NVDLA_READY) & m.input(CSB2NVDLA_VALID);
  auto csb_wr = (m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE));
  auto csb_rd = (m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_READ));
  auto raise_tag_val = BoolVal(1);

  { // Write to CDMA CSB registers
    auto instr = m.NewInstr("csb_wr_cdma");
    auto decode = is_csb & csb_wr &
                  (m.input(CSB2NVDLA_ADDR) >= CDMA_ADDR_SPACE_START) &
                  (m.input(CSB2NVDLA_ADDR) <= CDMA_ADDR_SPACE_END);
    instr.SetDecode(decode);

    instr.SetProgram(m.child(k_child_cdma));

    auto tag_update = raise_tag_val;
    instr.SetUpdate(m.state(k_tag_cdma), tag_update);
  }

  { // Read from CDMA CSB registers
    auto instr = m.NewInstr("csb_rd_cdma");
    auto decode = is_csb & csb_rd &
                  (m.input(CSB2NVDLA_ADDR) >= CDMA_ADDR_SPACE_START) &
                  (m.input(CSB2NVDLA_ADDR) <= CDMA_ADDR_SPACE_END);
    instr.SetDecode(decode);

    instr.SetProgram(m.child(k_child_cdma));

    auto tag_update = raise_tag_val;
    instr.SetUpdate(m.state(k_tag_cdma), tag_update);
  }

  { // Write to CSC CSB registers
    auto instr = m.NewInstr("csb_wr_csc");
    auto decode = is_csb & csb_wr &
                  (m.input(CSB2NVDLA_ADDR) >= CSC_ADDR_SPACE_START) &
                  (m.input(CSB2NVDLA_ADDR) <= CSC_ADDR_SPACE_END);

    instr.SetDecode(decode);

    instr.SetProgram(m.child(k_child_csc));

    auto tag_update = raise_tag_val;
    instr.SetUpdate(m.state(k_tag_csc), tag_update);
  }

  { // Read from CSC CSB registers
    auto instr = m.NewInstr("csb_rd_csc");
    auto decode = is_csb & csb_rd &
                  (m.input(CSB2NVDLA_ADDR) >= CSC_ADDR_SPACE_START) &
                  (m.input(CSB2NVDLA_ADDR) <= CSC_ADDR_SPACE_END);

    instr.SetDecode(decode);

    instr.SetProgram(m.child(k_child_csc));

    auto tag_update = raise_tag_val;
    instr.SetUpdate(m.state(k_tag_csc), tag_update);
  }
}

}; // namespace ilang
