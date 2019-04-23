// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: addr_space.h

#ifndef NVDLA_ILA_ADDR_SPACE_H__
#define NVDLA_ILA_ADDR_SPACE_H__

/// \namespace ilang
namespace ilang {

// NVDLA address space range of each sub-unit
#define GLB_ADDR_SPACE_START 0x00000000
#define GLB_ADDR_SPACE_END 0x00000FFF
#define MCIF_ADDR_SPACE_START 0x00002000
#define MCIF_ADDR_SPACE_END 0x00002FFF
#define SRAMIF_ADDR_SPACE_START 0x00003000
#define SRAMIF_ADDR_SPACE_END 0x00003FFF
#define BDMA_ADDR_SPACE_START 0x00004000
#define BDMA_ADDR_SPACE_END 0x00004FFF
#define CDMA_ADDR_SPACE_START 0x00005000
#define CDMA_ADDR_SPACE_END 0x00005FFF
#define CSC_ADDR_SPACE_START 0x00006000
#define CSC_ADDR_SPACE_END 0x00006FFF
#define CMAC_A_ADDR_SPACE_START 0x00007000
#define CMAC_A_ADDR_SPACE_END 0x00007FFF
#define CMAC_B_ADDR_SPACE_START 0x00008000
#define CMAC_B_ADDR_SPACE_END 0x00008FFF
#define CACC_ADDR_SPACE_START 0x00009000
#define CACC_ADDR_SPACE_END 0x00009FFF
#define SDP_RDMA_ADDR_SPACE_START 0x0000A000
#define SDP_RDMA_ADDR_SPACE_END 0x0000AFFF
#define SDP_ADDR_SPACE_START 0x0000B000
#define SDP_ADDR_SPACE_END 0x0000BFFF
#define PDP_RDMA_ADDR_SPACE_START 0x0000C000
#define PDP_RDMA_ADDR_SPACE_END 0x0000CFFF
#define PDP_ADDR_SPACE_START 0x0000D000
#define PDP_ADDR_SPACE_END 0x0000DFFF
#define CDP_RDMA_ADDR_SPACE_START 0x0000E000
#define CDP_RDMA_ADDR_SPACE_END 0x0000EFFF
#define CDP_ADDR_SPACE_START 0x0000F000
#define CDP_ADDR_SPACE_END 0x0000FFFF
#define RUBIK_ADDR_SPACE_START 0x00010000
#define RUBIK_ADDR_SPACE_END 0x00010FFF

}; // namespace ilang

#endif // NVDLA_ILA_ADDR_SPACE_H__

