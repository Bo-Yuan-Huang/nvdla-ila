// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: state_define_csb.cc

#include <ilang/ilang++.h>
#include <nvdla/configs/state_info.h>
#include <nvdla/utils.h>

// namespace ilang
namespace ilang {

void StateDefineCsb(Ila& m) {
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
  NewInput(m, CSB2NVDLA_VALID, CSB2NVDLA_VALID_BWID);

  // Indicates that the receiver is ready to take a request
  NewState(m, CSB2NVDLA_READY, CSB2NVDLA_READY_BWID);

  // Address. Aligned to word boundary.
  NewInput(m, CSB2NVDLA_ADDR, CSB2NVDLA_ADDR_BWID);

  // Write data
  NewInput(m, CSB2NVDLA_WDAT, CSB2NVDLA_WDAT_BWID);

  // Write flag.
  // 1'b0: Request is a read request.
  // 1'b1: Request is a write request.
  NewInput(m, CSB2NVDLA_WRITE, CSB2NVDLA_WRITE_BWID);

  // Non-posted write transaction indicator.
  // 1'b0: Request is a posted write request.
  // 1'b1: Indicates a non-posted write request.
  NewInput(m, CSB2NVDLA_NPOSTED, CSB2NVDLA_NPOSTED_BWID);

  /* Read data channel
   * NVDLA returns read-response data to the host in strict request order; that
   * is to say, each request packet (above) for which “write” is set to 0 will
   * have exactly one response, and that response cannot jump forward or
   * backwards relative to other reads. The read data channel follows a
   * valid-only protocol; as such, the host cannot apply back-pressure to the
   * NVDLA on this interface.
   */

  // Indicates that read data is valid.
  NewState(m, NVDLA2CSB_VALID, NVDLA2CSB_VALID_BWID);

  // Data corresponding to a read request, or zero in the event of an error.
  NewState(m, NVDLA2CSB_DATA, NVDLA2CSB_DATA_BWID);

  /* Write response channel
   * NVDLA will return write completion to the host in request order for every
   * non-posted write. The write completion channel also follows a valid-only
   * protocol, and as such, the host cannot back-pressure NVDLA on this
   * interface.
   */

  // Indicates that a CSB write has completed.
  NewState(m, NVDLA2CSB_WR_COMPLETE, NVDLA2CSB_WR_COMPLETE_BWID);

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
  NewState(m, NVDLA2CORE_INTERRUPT, NVDLA2CORE_INTERRUPT_BWID);

  return;
}

}; // namespace ilang
