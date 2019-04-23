// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: addr_bdma.h

#ifndef NVDLA_ADDR_BDMA_H__
#define NVDLA_ADDR_BDMA_H__

/// \namespace ilang
namespace ilang {

// Lower 32bits of source address
#define BDMA_CFG_SRC_ADDR_LOW_ADDR 0x4000
// Higher 32bits of source address when axi araddr is 64bits
#define BDMA_CFG_SRC_ADDR_HIGH_ADDR 0x4004
// Lower 32bits of dest address
#define BDMA_CFG_DST_ADDR_LOW_ADDR 0x4008
// Higher 32bits of dest address when axi awaddr is 64bits
#define BDMA_CFG_DST_ADDR_HIGH_ADDR 0x400c
// Size of one line
#define BDMA_CFG_LINE_ADDR 0x4010
// Ram type of source and destination
#define BDMA_CFG_CMD_ADDR 0x4014
// Number of lines to be moved in one surface
#define BDMA_CFG_LINE_REPEAT_ADDR 0x4018
// Source line stride
#define BDMA_CFG_SRC_LINE_ADDR 0x401c
// Destination line stride
#define BDMA_CFG_DST_LINE_ADDR 0x4020
// Number of surfaces to be moved in one operation
#define BDMA_CFG_SURF_REPEAT_ADDR 0x4024
// Source surface stride
#define BDMA_CFG_SRC_SURF_ADDR 0x4028
// Destination surface stride
#define BDMA_CFG_DST_SURF_ADDR 0x402c
// This register is not used in NVDLA 1.0
#define BDMA_CFG_OP_ADDR 0x4030
// Set it to 1 to kick off operations in group0
#define BDMA_CFG_LAUNCH0_ADDR 0x4034
// Set it to 1 to kick off operations in group1
#define BDMA_CFG_LAUNCH1_ADDR 0x4038
// Enable/Disable of counting stalls
#define BDMA_CFG_STATUS_ADDR 0x403c
// Status register: idle status of bdma, group0 and group1
#define BDMA_STATUS_ADDR 0x4040
// Counting register of group0 read stall
#define BDMA_STAUS_GRP0_READ_STALL_ADDR 0x4044
// Counting register of group0 write stall
#define BDMA_STATUS_GRP0_WRITE_STALL_ADDR 0x4048
// Counting register of group1 read stall
#define BDMA_STAUS_GRP1_READ_STALL_ADDR 0x404c
// Counting register of group1 write stall
#define BDMA_STATUS_GRP1_WRITE_STALL_ADDR 0x4050

}; // namespace ilang

#endif // NVDLA_ADDR_BDMA_H__
