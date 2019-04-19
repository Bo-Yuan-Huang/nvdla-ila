// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: addr_rubik.h

#ifndef NVDLA_ADDR_RUBIK_H__
#define NVDLA_ADDR_RUBIK_H__

/// \namespace ilang
namespace ilang {

// Idle status of two register groups
#define RUBIK_S_STATUS 0x10000
// Pointer for CSB master and data path to access groups
#define RUBIK_S_POINTER 0x10004
// Set it to 1 to kick off operation for current register group
#define RUBIK_D_OP_ENABLE 0x10008
// Operation mode and precision
#define RUBIK_D_MISC_CFG 0x1000c
// RAM type of input cube
#define RUBIK_D_DAIN_RAM_TYPE 0x10010
// Input data cube’s width and height
#define RUBIK_D_DATAIN_SIZE_0 0x10014
// Input data cube’s channel
#define RUBIK_D_DATAIN_SIZE_1 0x10018
// Higher 32bits of input data address when axi araddr is 64bits
#define RUBIK_D_DAIN_ADDR_HIGH 0x1001c
// Lower 32bits of input data address
#define RUBIK_D_DAIN_ADDR_LOW 0x10020
// Line stride of input data cube
#define RUBIK_D_DAIN_LINE_STRIDE 0x10024
// Surface stride of input data cube
#define RUBIK_D_DAIN_SURF_STRIDE 0x10028
// Input data planar stride, for merge mode only
#define RUBIK_D_DAIN_PLANAR_STRIDE 0x1002c
// RAM type of output cube
#define RUBIK_D_DAOUT_RAM_TYPE 0x10030
// Output data cube’s channel
#define RUBIK_D_DATAOUT_SIZE_1 0x10034
// Higher 32bits of output data address when axi awaddr is 64bits
#define RUBIK_D_DAOUT_ADDR_HIGH 0x10038
// Lower 32bits of output data address
#define RUBIK_D_DAOUT_ADDR_LOW 0x1003c
// Line stride of output data cube
#define RUBIK_D_DAOUT_LINE_STRIDE 0x10040
// Input stride for each X step. Equals to (DATAOUT_CHANNEL+1) * BPE / 32 *
// DAIN_SURF_STRIDE. (BPE = (IN_PRECISION == INT8) ? 1 : 2;)
#define RUBIK_D_CONTRACT_STRIDE_0 0x10044
// Output stride corresponding to each line in input cube. equals to
// (DECONV_Y_STRIDE+1) * DAOUT_LINE_STRIDE
#define RUBIK_D_CONTRACT_STRIDE_1 0x10048
// Surface stride of output data cube
#define RUBIK_D_DAOUT_SURF_STRIDE 0x1004c
// Output data planar stride, for split mode only
#define RUBIK_D_DAOUT_PLANAR_STRIDE 0x10050
// Deconvolution x stride and y stride
#define RUBIK_D_DECONV_STRIDE 0x10054
// Enable/Disable performance counting
#define RUBIK_D_PERF_ENABLE 0x10058
// RD_STALL Count stall cycles of read DMA for one layer
#define RUBIK_D_PERF_READ_STALL 0x1005c
// WR_STALL Count stall cycles of write DMA for one layer
#define RUBIK_D_PERF_WRITE_STALL 0x10060

}; // namespace ilang

#endif // NVDLA_ADDR_RUBIK_H__
