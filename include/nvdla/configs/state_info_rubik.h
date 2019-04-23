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

/// \namespace ilang
namespace ilang {

// Idle status of two register groups
#define RUBIK_S_STATUS_NAME "rubik_s_status"

// Pointer for CSB master and data path to access groups
#define RUBIK_S_POINTER_NAME "rubik_s_pointer"

// Set it to 1 to kick off operation for current register group
#define RUBIK_D_OP_ENABLE_NAME "rubik_d_op_enable"

// Operation mode and precision
#define RUBIK_D_MISC_CFG_NAME "rubik_d_misc_cfg"

// RAM type of input cube
#define RUBIK_D_DAIN_RAM_TYPE_NAME "rubik_d_dain_ram_type"

// Input data cube’s width and height
#define RUBIK_D_DATAIN_SIZE_0_NAME "rubik_d_datain_size_0"

// Input data cube’s channel
#define RUBIK_D_DATAIN_SIZE_1_NAME "rubik_d_datain_size_1"

// Higher 32bits of input data address when axi araddr is 64bits
#define RUBIK_D_DAIN_ADDR_HIGH_NAME "rubik_d_dain_addr_high"

// Lower 32bits of input data address
#define RUBIK_D_DAIN_ADDR_LOW_NAME "rubik_d_dain_addr_low"

// Line stride of input data cube
#define RUBIK_D_DAIN_LINE_STRIDE_NAME "rubik_d_dain_line_stride"

// Surface stride of input data cube
#define RUBIK_D_DAIN_SURF_STRIDE_NAME "rubik_d_dain_surf_stride"

// Input data planar stride, for merge mode only
#define RUBIK_D_DAIN_PLANAR_STRIDE_NAME "rubik_d_dain_planar_stride"

// RAM type of output cube
#define RUBIK_D_DAOUT_RAM_TYPE_NAME "rubik_d_daout_ram_type"

// Output data cube’s channel
#define RUBIK_D_DATAOUT_SIZE_1_NAME "rubik_d_dataout_size_1"

// Higher 32bits of output data address when axi awaddr is 64bits
#define RUBIK_D_DAOUT_ADDR_HIGH_NAME "rubik_d_daout_addr_high"

// Lower 32bits of output data address
#define RUBIK_D_DAOUT_ADDR_LOW_NAME "rubik_d_daout_addr_low"

// Line stride of output data cube
#define RUBIK_D_DAOUT_LINE_STRIDE_NAME "rubik_d_daout_line_stride"

// Input stride for each X step. Equals to (DATAOUT_CHANNEL+1) * BPE / 32 *
// DAIN_SURF_STRIDE. (BPE = (IN_PRECISION == INT8) ? 1 : 2;)
#define RUBIK_D_CONTRACT_STRIDE_0_NAME "rubik_d_contract_stride_0"

// Output stride corresponding to each line in input cube. equals to
// (DECONV_Y_STRIDE+1) * DAOUT_LINE_STRIDE
#define RUBIK_D_CONTRACT_STRIDE_1_NAME "rubik_d_contract_stride_1"

// Surface stride of output data cube
#define RUBIK_D_DAOUT_SURF_STRIDE_NAME "rubik_d_daout_surf_stride"

// Output data planar stride, for split mode only
#define RUBIK_D_DAOUT_PLANAR_STRIDE_NAME "rubik_d_daout_planar_stride"

// Deconvolution x stride and y stride
#define RUBIK_D_DECONV_STRIDE_NAME "rubik_d_deconv_stride"

// Enable/Disable performance counting
#define RUBIK_D_PERF_ENABLE_NAME "rubik_d_perf_enable"

// RD_STALL Count stall cycles of read DMA for one layer
#define RUBIK_D_PERF_READ_STALL_NAME "rubik_d_perf_read_stall"

// WR_STALL Count stall cycles of write DMA for one layer
#define RUBIK_D_PERF_WRITE_STALL_NAME "rubik_d_perf_write_stall"

}; // namespace ilang

#endif // STATE_INFO_RUBIK_H__
