// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: state_info_csb.h

#ifndef STATE_INFO_CSB_H__
#define STATE_INFO_CSB_H__

namespace ilang {

// Indicates that a request is valid
#define CSB2NVDLA_VALID "csb2nvdla_valid"
#define CSB2NVDLA_VALID_BWID 1

// Indicates that the receiver is ready to take a request
#define CSB2NVDLA_READY "csb2nvdla_ready"
#define CSB2NVDLA_READY_BWID 1

// Address. Aligned to word boundary.
#define CSB2NVDLA_ADDR "csb2nvdla_addr"
#define CSB2NVDLA_ADDR_BWID 16

// Write data
#define CSB2NVDLA_WDAT "csb2nvdla_wdat"
#define CSB2NVDLA_WDAT_BWID 32

// Write flag.
// 1'b0: Request is a read request.
// 1'b1: Request is a write request.
#define CSB2NVDLA_WRITE "csb2nvdla_write"
#define CSB2NVDLA_WRITE_BWID 1
#define CSB2NVDLA_WRITE_READ 0
#define CSB2NVDLA_WRITE_WRITE 1

// Non-posted write transaction indicator.
// 1'b0: Request is a posted write request.
// 1'b1: Indicates a non-posted write request.
#define CSB2NVDLA_NPOSTED "csb2nvdla_nposted"
#define CSB2NVDLA_NPOSTED_BWID 1
#define CSB2NVDLA_NPOSTED_POSTED 0
#define CSB2NVDLA_NPOSTED_NPOSTED 1

// Indicates that read data is valid.
#define NVDLA2CSB_VALID "nvdla2csb_valid"
#define NVDLA2CSB_VALID_BWID 1

// Data corresponding to a read request, or zero in the event of an error.
#define NVDLA2CSB_DATA "nvdla2csb_data"
#define NVDLA2CSB_DATA_BWID 32

// Indicates that a CSB write has completed.
#define NVDLA2CSB_WR_COMPLETE "nvdla2csb_wr_complete"
#define NVDLA2CSB_WR_COMPLETE_BWID 1

// Active high while an interrupt is pending from NVDLA.
#define NVDLA2CORE_INTERRUPT "nvdla2core_interrupt"
#define NVDLA2CORE_INTERRUPT_BWID 1

}; // namespace ilang

#endif // STATE_INFO_CSB_H__

