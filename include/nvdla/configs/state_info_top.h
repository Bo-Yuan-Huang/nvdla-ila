// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: state_info_top.h

#ifndef STATE_INFO_TOP_H__
#define STATE_INFO_TOP_H__

namespace ilang {

/* Configuration space bus */

#define CSB_REQ_ADDR_BWID 16
#define CSB_REQ_DATA_BWID 32

#define CSB2NVDLA_VALID "csb2nvdla_valid"
#define CSB2NVDLA_VALID_BWID 1

#define CSB2NVDLA_READY "csb2nvdla_ready"
#define CSB2NVDLA_READY_BWID 1

#define CSB2NVDLA_ADDR "csb2nvdla_addr"
#define CSB2NVDLA_ADDR_BWID 16

#define CSB2NVDLA_WDAT "csb2nvdla_wdat"
#define CSB2NVDLA_WDAT_BWID 32

#define CSB2NVDLA_WRITE "csb2nvdla_write"
#define CSB2NVDLA_WRITE_BWID 1
#define CSB2NVDLA_WRITE_READ 0
#define CSB2NVDLA_WRITE_WRITE 1

#define CSB2NVDLA_NPOSTED "csb2nvdla_nposted"
#define CSB2NVDLA_NPOSTED_BWID 1
#define CSB2NVDLA_NPOSTED_POSTED 0
#define CSB2NVDLA_NPOSTED_NPOSTED 1

#define NVDLA2CSB_VALID "nvdla2csb_valid"
#define NVDLA2CSB_VALID_BWID 1

#define NVDLA2CSB_DATA "nvdla2csb_data"
#define NVDLA2CSB_DATA_BWID 32

#define NVDLA2CSB_WR_COMPLETE "nvdla2csb_wr_complete"
#define NVDLA2CSB_WR_COMPLETE_BWID 1

#define NVDLA2CORE_INTERRUPT "nvdla2core_interrupt"
#define NVDLA2CORE_INTERRUPT_BWID 1

/* System interconnect: DBBIF */
// TODO

/* On-chip SRAM interface: SRAMIF */
// TODO

}; // namespace ilang

#endif // STATE_INFO_TOP_H__

