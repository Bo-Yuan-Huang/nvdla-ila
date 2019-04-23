// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: state_info_rubik.h

#ifndef STATE_INFO_RUBIK_H__
#define STATE_INFO_RUBIK_H__

// namespace ilang
namespace ilang {

// Idle status of two register groups
#define RUBIK_S_STATUS "rubik_s_status"
#define RUBIK_S_STATUS_ADDR 0x10000
#define RUBIK_S_STATUS_BWID 32

// Pointer for CSB master and data path to access groups
#define RUBIK_S_POINTER "rubik_s_pointer"
#define RUBIK_S_POINTER_ADDR 0x10004
#define RUBIK_S_POINTER_BWID 32

// Set it to 1 to kick off operation for current register group
#define RUBIK_D_OP_ENABLE "rubik_d_op_enable"
#define RUBIK_D_OP_ENABLE_ADDR 0x10008
#define RUBIK_D_OP_ENABLE_BWID 32

// Operation mode and precision
#define RUBIK_D_MISC_CFG "rubik_d_misc_cfg"
#define RUBIK_D_MISC_CFG_ADDR 0x1000c
#define RUBIK_D_MISC_CFG_BWID 32

// RAM type of input cube
#define RUBIK_D_DAIN_RAM_TYPE "rubik_d_dain_ram_type"
#define RUBIK_D_DAIN_RAM_TYPE_ADDR 0x10010
#define RUBIK_D_DAIN_RAM_TYPE_BWID 32

// Input data cube’s width and height
#define RUBIK_D_DATAIN_SIZE_0 "rubik_d_datain_size_0"
#define RUBIK_D_DATAIN_SIZE_0_ADDR 0x10014
#define RUBIK_D_DATAIN_SIZE_0_BWID 32

// Input data cube’s channel
#define RUBIK_D_DATAIN_SIZE_1 "rubik_d_datain_size_1"
#define RUBIK_D_DATAIN_SIZE_1_ADDR 0x10018
#define RUBIK_D_DATAIN_SIZE_1_BWID 32

// Higher 32bits of input data address when axi araddr is 64bits
#define RUBIK_D_DAIN_ADDR_HIGH "rubik_d_dain_addr_high"
#define RUBIK_D_DAIN_ADDR_HIGH_ADDR 0x1001c
#define RUBIK_D_DAIN_ADDR_HIGH_BWID 32

// Lower 32bits of input data address
#define RUBIK_D_DAIN_ADDR_LOW "rubik_d_dain_addr_low"
#define RUBIK_D_DAIN_ADDR_LOW_ADDR 0x10020
#define RUBIK_D_DAIN_ADDR_LOW_BWID 32

// Line stride of input data cube
#define RUBIK_D_DAIN_LINE_STRIDE "rubik_d_dain_line_stride"
#define RUBIK_D_DAIN_LINE_STRIDE_ADDR 0x10024
#define RUBIK_D_DAIN_LINE_STRIDE_BWID 32

// Surface stride of input data cube
#define RUBIK_D_DAIN_SURF_STRIDE "rubik_d_dain_surf_stride"
#define RUBIK_D_DAIN_SURF_STRIDE_ADDR 0x10028
#define RUBIK_D_DAIN_SURF_STRIDE_BWID 32

// Input data planar stride, for merge mode only
#define RUBIK_D_DAIN_PLANAR_STRIDE "rubik_d_dain_planar_stride"
#define RUBIK_D_DAIN_PLANAR_STRIDE_ADDR 0x1002c
#define RUBIK_D_DAIN_PLANAR_STRIDE_BWID 32

// RAM type of output cube
#define RUBIK_D_DAOUT_RAM_TYPE "rubik_d_daout_ram_type"
#define RUBIK_D_DAOUT_RAM_TYPE_ADDR 0x10030
#define RUBIK_D_DAOUT_RAM_TYPE_BWID 32

// Output data cube’s channel
#define RUBIK_D_DATAOUT_SIZE_1 "rubik_d_dataout_size_1"
#define RUBIK_D_DATAOUT_SIZE_1_ADDR 0x10034
#define RUBIK_D_DATAOUT_SIZE_1_BWID 32

// Higher 32bits of output data address when axi awaddr is 64bits
#define RUBIK_D_DAOUT_ADDR_HIGH "rubik_d_daout_addr_high"
#define RUBIK_D_DAOUT_ADDR_HIGH_ADDR 0x10038
#define RUBIK_D_DAOUT_ADDR_HIGH_BWID 32

// Lower 32bits of output data address
#define RUBIK_D_DAOUT_ADDR_LOW "rubik_d_daout_addr_low"
#define RUBIK_D_DAOUT_ADDR_LOW_ADDR 0x1003c
#define RUBIK_D_DAOUT_ADDR_LOW_BWID 32

// Line stride of output data cube
#define RUBIK_D_DAOUT_LINE_STRIDE "rubik_d_daout_line_stride"
#define RUBIK_D_DAOUT_LINE_STRIDE_ADDR 0x10040
#define RUBIK_D_DAOUT_LINE_STRIDE_BWID 32

// Input stride for each X step. Equals to (DATAOUT_CHANNEL+1) * BPE / 32 *
// DAIN_SURF_STRIDE. (BPE = (IN_PRECISION == INT8) ? 1 : 2;)
#define RUBIK_D_CONTRACT_STRIDE_0 "rubik_d_contract_stride_0"
#define RUBIK_D_CONTRACT_STRIDE_0_ADDR 0x10044
#define RUBIK_D_CONTRACT_STRIDE_0_BWID 32

// Output stride corresponding to each line in input cube. equals to
// (DECONV_Y_STRIDE+1) * DAOUT_LINE_STRIDE
#define RUBIK_D_CONTRACT_STRIDE_1 "rubik_d_contract_stride_1"
#define RUBIK_D_CONTRACT_STRIDE_1_ADDR 0x10048
#define RUBIK_D_CONTRACT_STRIDE_1_BWID 32

// Surface stride of output data cube
#define RUBIK_D_DAOUT_SURF_STRIDE "rubik_d_daout_surf_stride"
#define RUBIK_D_DAOUT_SURF_STRIDE_ADDR 0x1004c
#define RUBIK_D_DAOUT_SURF_STRIDE_BWID 32

// Output data planar stride, for split mode only
#define RUBIK_D_DAOUT_PLANAR_STRIDE "rubik_d_daout_planar_stride"
#define RUBIK_D_DAOUT_PLANAR_STRIDE_ADDR 0x10050
#define RUBIK_D_DAOUT_PLANAR_STRIDE_BWID 32

// Deconvolution x stride and y stride
#define RUBIK_D_DECONV_STRIDE "rubik_d_deconv_stride"
#define RUBIK_D_DECONV_STRIDE_ADDR 0x10054
#define RUBIK_D_DECONV_STRIDE_BWID 32

// Enable/Disable performance counting
#define RUBIK_D_PERF_ENABLE "rubik_d_perf_enable"
#define RUBIK_D_PERF_ENABLE_ADDR 0x10058
#define RUBIK_D_PERF_ENABLE_BWID 32

// RD_STALL Count stall cycles of read DMA for one layer
#define RUBIK_D_PERF_READ_STALL "rubik_d_perf_read_stall"
#define RUBIK_D_PERF_READ_STALL_ADDR 0x1005c
#define RUBIK_D_PERF_READ_STALL_BWID 32

// WR_STALL Count stall cycles of write DMA for one layer
#define RUBIK_D_PERF_WRITE_STALL "rubik_d_perf_write_stall"
#define RUBIK_D_PERF_WRITE_STALL_ADDR 0x10060
#define RUBIK_D_PERF_WRITE_STALL_BWID 32

}; // namespace ilang

#endif // STATE_INFO_RUBIK_H__
