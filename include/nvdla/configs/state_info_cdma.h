// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: state_info_cdma.h

#ifndef STATE_INFO_CDMA_H__
#define STATE_INFO_CDMA_H__

#include <nvdla/configs/modeling_config.h>

// namespace ilang
namespace ilang {

// Idle status of two register groups
#define CDMA_S_STATUS "cdma_s_status"
#define CDMA_S_STATUS_ADDR 0x5000
#define CDMA_S_STATUS_BWID ICFG_CSB_DATA_BWID

// Pointer for CSB master and data path to access groups
#define CDMA_S_POINTER "cdma_s_pointer"
#define CDMA_S_POINTER_ADDR 0x5004
#define CDMA_S_POINTER_BWID ICFG_CSB_DATA_BWID

// WMB and Weight share same port to access external memory. This register
// controls the weight factor in the arbiter.
#define CDMA_S_ARBITER "cdma_s_arbiter"
#define CDMA_S_ARBITER_ADDR 0x5008
#define CDMA_S_ARBITER_BWID ICFG_CSB_DATA_BWID

// Indicates whether CBUF flush is finished after reset.
#define CDMA_S_CBUF_FLUSH_STATUS "cdma_s_cbuf_flush_status"
#define CDMA_S_CBUF_FLUSH_STATUS_ADDR 0x500c
#define CDMA_S_CBUF_FLUSH_STATUS_BWID ICFG_CSB_DATA_BWID

// Set it to 1 to kick off operation for current register group
#define CDMA_D_OP_ENABLE_G0 "cdma_d_op_enable_g0"
#define CDMA_D_OP_ENABLE_G1 "cdma_d_op_enable_g1"
#define CDMA_D_OP_ENABLE_ADDR 0x5010
#define CDMA_D_OP_ENABLE_BWID ICFG_CSB_DATA_BWID

// Configuration of operation: convolution mode, precision, weight reuse, data
// reuse.
#define CDMA_D_MISC_CFG_G0 "cdma_d_misc_cfg_g0"
#define CDMA_D_MISC_CFG_G1 "cdma_d_misc_cfg_g1"
#define CDMA_D_MISC_CFG_ADDR 0x5014
#define CDMA_D_MISC_CFG_BWID ICFG_CSB_DATA_BWID

// Input data format and pixel format
#define CDMA_D_DATAIN_FORMAT_G0 "cdma_d_datain_format_g0"
#define CDMA_D_DATAIN_FORMAT_G1 "cdma_d_datain_format_g1"
#define CDMA_D_DATAIN_FORMAT_ADDR 0x5018
#define CDMA_D_DATAIN_FORMAT_BWID ICFG_CSB_DATA_BWID

// Input cube’s width and height
#define CDMA_D_DATAIN_SIZE_0_G0 "cdma_d_datain_size_0_g0"
#define CDMA_D_DATAIN_SIZE_0_G1 "cdma_d_datain_size_0_g1"
#define CDMA_D_DATAIN_SIZE_0_ADDR 0x501c
#define CDMA_D_DATAIN_SIZE_0_BWID ICFG_CSB_DATA_BWID

// Input cube’s channel
#define CDMA_D_DATAIN_SIZE_1_G0 "cdma_d_datain_size_1_g0"
#define CDMA_D_DATAIN_SIZE_1_G1 "cdma_d_datain_size_1_g1"
#define CDMA_D_DATAIN_SIZE_1_ADDR 0x5020
#define CDMA_D_DATAIN_SIZE_1_BWID ICFG_CSB_DATA_BWID

// Input cube’s width and height after extension
#define CDMA_D_DATAIN_SIZE_EXT_0_G0 "cdma_d_datain_size_ext_0_g0"
#define CDMA_D_DATAIN_SIZE_EXT_0_G1 "cdma_d_datain_size_ext_0_g1"
#define CDMA_D_DATAIN_SIZE_EXT_0_ADDR 0x5024
#define CDMA_D_DATAIN_SIZE_EXT_0_BWID ICFG_CSB_DATA_BWID

// For image-in mode, horizontal offset and vertical offset of the 1 st pixel.
#define CDMA_D_PIXEL_OFFSET_G0 "cdma_d_pixel_offset_g0"
#define CDMA_D_PIXEL_OFFSET_G1 "cdma_d_pixel_offset_g1"
#define CDMA_D_PIXEL_OFFSET_ADDR 0x5028
#define CDMA_D_PIXEL_OFFSET_BWID ICFG_CSB_DATA_BWID

// Ram type of input RAM
#define CDMA_D_DAIN_RAM_TYPE_G0 "cdma_d_dain_ram_type_g0"
#define CDMA_D_DAIN_RAM_TYPE_G1 "cdma_d_dain_ram_type_g1"
#define CDMA_D_DAIN_RAM_TYPE_ADDR 0x502c
#define CDMA_D_DAIN_RAM_TYPE_BWID ICFG_CSB_DATA_BWID

// Higher 32bits of input data address when axi araddr is 64bits
#define CDMA_D_DAIN_ADDR_HIGH_0_G0 "cdma_d_dain_addr_high_0_g0"
#define CDMA_D_DAIN_ADDR_HIGH_0_G1 "cdma_d_dain_addr_high_0_g1"
#define CDMA_D_DAIN_ADDR_HIGH_0_ADDR 0x5030
#define CDMA_D_DAIN_ADDR_HIGH_0_BWID ICFG_CSB_DATA_BWID

// Lower 32bits of input data address
#define CDMA_D_DAIN_ADDR_LOW_0_G0 "cdma_d_dain_addr_low_0_g0"
#define CDMA_D_DAIN_ADDR_LOW_0_G1 "cdma_d_dain_addr_low_0_g1"
#define CDMA_D_DAIN_ADDR_LOW_0_ADDR 0x5034
#define CDMA_D_DAIN_ADDR_LOW_0_BWID ICFG_CSB_DATA_BWID

// Higher 32bits of input data address of UV plane when axi araddr is 64bits
#define CDMA_D_DAIN_ADDR_HIGH_1_G0 "cdma_d_dain_addr_high_1_g0"
#define CDMA_D_DAIN_ADDR_HIGH_1_G1 "cdma_d_dain_addr_high_1_g1"
#define CDMA_D_DAIN_ADDR_HIGH_1_ADDR 0x5038
#define CDMA_D_DAIN_ADDR_HIGH_1_BWID ICFG_CSB_DATA_BWID

// Lower 32bits of input data address of UV plane
#define CDMA_D_DAIN_ADDR_LOW_1_G0 "cdma_d_dain_addr_low_1_g0"
#define CDMA_D_DAIN_ADDR_LOW_1_G1 "cdma_d_dain_addr_low_1_g1"
#define CDMA_D_DAIN_ADDR_LOW_1_ADDR 0x503c
#define CDMA_D_DAIN_ADDR_LOW_1_BWID ICFG_CSB_DATA_BWID

// Line stride of input cube
#define CDMA_D_LINE_STRIDE_G0 "cdma_d_line_stride_g0"
#define CDMA_D_LINE_STRIDE_G1 "cdma_d_line_stride_g1"
#define CDMA_D_LINE_STRIDE_ADDR 0x5040
#define CDMA_D_LINE_STRIDE_BWID ICFG_CSB_DATA_BWID

// Line stride of input cube’s UV plane
#define CDMA_D_LINE_UV_STRIDE_G0 "cdma_d_line_uv_stride_g0"
#define CDMA_D_LINE_UV_STRIDE_G1 "cdma_d_line_uv_stride_g1"
#define CDMA_D_LINE_UV_STRIDE_ADDR 0x5044
#define CDMA_D_LINE_UV_STRIDE_BWID ICFG_CSB_DATA_BWID

// Surface stride of input cube
#define CDMA_D_SURF_STRIDE_G0 "cdma_d_surf_stride_g0"
#define CDMA_D_SURF_STRIDE_G1 "cdma_d_surf_stride_g1"
#define CDMA_D_SURF_STRIDE_ADDR 0x5048
#define CDMA_D_SURF_STRIDE_BWID ICFG_CSB_DATA_BWID

// Whether input cube is line packed or surface packed
#define CDMA_D_DAIN_MAP_G0 "cdma_d_dain_map_g0"
#define CDMA_D_DAIN_MAP_G1 "cdma_d_dain_map_g1"
#define CDMA_D_DAIN_MAP_ADDR 0x504c
#define CDMA_D_DAIN_MAP_BWID ICFG_CSB_DATA_BWID

// This address is reserved
#define CDMA_RESERVED "cdma_reserved"
#define CDMA_RESERVED_ADDR 0x5050
#define CDMA_RESERVED_BWID ICFG_CSB_DATA_BWID

// Number of batches
#define CDMA_D_BATCH_NUMBER_G0 "cdma_d_batch_number_g0"
#define CDMA_D_BATCH_NUMBER_G1 "cdma_d_batch_number_g1"
#define CDMA_D_BATCH_NUMBER_ADDR 0x5058
#define CDMA_D_BATCH_NUMBER_BWID ICFG_CSB_DATA_BWID

// The stride of input data cubes when batches > 1
#define CDMA_D_BATCH_STRIDE_G0 "cdma_d_batch_stride_g0"
#define CDMA_D_BATCH_STRIDE_G1 "cdma_d_batch_stride_g1"
#define CDMA_D_BATCH_STRIDE_ADDR 0x505c
#define CDMA_D_BATCH_STRIDE_BWID ICFG_CSB_DATA_BWID

// Number of CBUF entries used for one input slice
#define CDMA_D_ENTRY_PER_SLICE_G0 "cdma_d_entry_per_slice_g0"
#define CDMA_D_ENTRY_PER_SLICE_G1 "cdma_d_entry_per_slice_g1"
#define CDMA_D_ENTRY_PER_SLICE_ADDR 0x5060
#define CDMA_D_ENTRY_PER_SLICE_BWID ICFG_CSB_DATA_BWID

// Number of slices to be fetched before sending update information to CSC
#define CDMA_D_FETCH_GRAIN_G0 "cdma_d_fetch_grain_g0"
#define CDMA_D_FETCH_GRAIN_G1 "cdma_d_fetch_grain_g1"
#define CDMA_D_FETCH_GRAIN_ADDR 0x5064
#define CDMA_D_FETCH_GRAIN_BWID ICFG_CSB_DATA_BWID

// Whether weight is compressed or not
#define CDMA_D_WEIGHT_FORMAT_G0 "cdma_d_weight_format_g0"
#define CDMA_D_WEIGHT_FORMAT_G1 "cdma_d_weight_format_g1"
#define CDMA_D_WEIGHT_FORMAT_ADDR 0x5068
#define CDMA_D_WEIGHT_FORMAT_BWID ICFG_CSB_DATA_BWID

// The size of one kernel in bytes
#define CDMA_D_WEIGHT_SIZE_0_G0 "cdma_d_weight_size_0_g0"
#define CDMA_D_WEIGHT_SIZE_0_G1 "cdma_d_weight_size_0_g1"
#define CDMA_D_WEIGHT_SIZE_0_ADDR 0x506c
#define CDMA_D_WEIGHT_SIZE_0_BWID ICFG_CSB_DATA_BWID

// Number of kernels
#define CDMA_D_WEIGHT_SIZE_1_G0 "cdma_d_weight_size_1_g0"
#define CDMA_D_WEIGHT_SIZE_1_G1 "cdma_d_weight_size_1_g1"
#define CDMA_D_WEIGHT_SIZE_1_ADDR 0x5070
#define CDMA_D_WEIGHT_SIZE_1_BWID ICFG_CSB_DATA_BWID

// Ram type of weight
#define CDMA_D_WEIGHT_RAM_TYPE_G0 "cdma_d_weight_ram_type_g0"
#define CDMA_D_WEIGHT_RAM_TYPE_G1 "cdma_d_weight_ram_type_g1"
#define CDMA_D_WEIGHT_RAM_TYPE_ADDR 0x5074
#define CDMA_D_WEIGHT_RAM_TYPE_BWID ICFG_CSB_DATA_BWID

// Higher 32bits of weight address when axi araddr is 64bits
#define CDMA_D_WEIGHT_ADDR_HIGH_G0 "cdma_d_weight_addr_high_g0"
#define CDMA_D_WEIGHT_ADDR_HIGH_G1 "cdma_d_weight_addr_high_g1"
#define CDMA_D_WEIGHT_ADDR_HIGH_ADDR 0x5078
#define CDMA_D_WEIGHT_ADDR_HIGH_BWID ICFG_CSB_DATA_BWID

// Lower 32bits of weight address
#define CDMA_D_WEIGHT_ADDR_LOW_G0 "cdma_d_weight_addr_low_g0"
#define CDMA_D_WEIGHT_ADDR_LOW_G1 "cdma_d_weight_addr_low_g1"
#define CDMA_D_WEIGHT_ADDR_LOW_ADDR 0x507c
#define CDMA_D_WEIGHT_ADDR_LOW_BWID ICFG_CSB_DATA_BWID

// Total bytes of Weight
#define CDMA_D_WEIGHT_BYTES_G0 "cdma_d_weight_bytes_g0"
#define CDMA_D_WEIGHT_BYTES_G1 "cdma_d_weight_bytes_g1"
#define CDMA_D_WEIGHT_BYTES_ADDR 0x5080
#define CDMA_D_WEIGHT_BYTES_BWID ICFG_CSB_DATA_BWID

// Higher 32bits of wgs address when axi araddr is 64bits
#define CDMA_D_WGS_ADDR_HIGH_G0 "cdma_d_wgs_addr_high_g0"
#define CDMA_D_WGS_ADDR_HIGH_G1 "cdma_d_wgs_addr_high_g1"
#define CDMA_D_WGS_ADDR_HIGH_ADDR 0x5084
#define CDMA_D_WGS_ADDR_HIGH_BWID ICFG_CSB_DATA_BWID

// Lower 32bits of wgs address
#define CDMA_D_WGS_ADDR_LOW_G0 "cdma_d_wgs_addr_low_g0"
#define CDMA_D_WGS_ADDR_LOW_G1 "cdma_d_wgs_addr_low_g1"
#define CDMA_D_WGS_ADDR_LOW_ADDR 0x5088
#define CDMA_D_WGS_ADDR_LOW_BWID ICFG_CSB_DATA_BWID

// Higher 32bits of wmb address when axi araddr is 64bits
#define CDMA_D_WMB_ADDR_HIGH_G0 "cdma_d_wmb_addr_high_g0"
#define CDMA_D_WMB_ADDR_HIGH_G1 "cdma_d_wmb_addr_high_g1"
#define CDMA_D_WMB_ADDR_HIGH_ADDR 0x508c
#define CDMA_D_WMB_ADDR_HIGH_BWID ICFG_CSB_DATA_BWID

// Lower 32bits of wmb address
#define CDMA_D_WMB_ADDR_LOW_G0 "cdma_d_wmb_addr_low_g0"
#define CDMA_D_WMB_ADDR_LOW_G1 "cdma_d_wmb_addr_low_g1"
#define CDMA_D_WMB_ADDR_LOW_ADDR 0x5090
#define CDMA_D_WMB_ADDR_LOW_BWID ICFG_CSB_DATA_BWID

// Total bytes of WMB
#define CDMA_D_WMB_BYTES_G0 "cdma_d_wmb_bytes_g0"
#define CDMA_D_WMB_BYTES_G1 "cdma_d_wmb_bytes_g1"
#define CDMA_D_WMB_BYTES_ADDR 0x5094
#define CDMA_D_WMB_BYTES_BWID ICFG_CSB_DATA_BWID

// Whether mean registers are used or not
#define CDMA_D_MEAN_FORMAT_G0 "cdma_d_mean_format_g0"
#define CDMA_D_MEAN_FORMAT_G1 "cdma_d_mean_format_g1"
#define CDMA_D_MEAN_FORMAT_ADDR 0x5098
#define CDMA_D_MEAN_FORMAT_BWID ICFG_CSB_DATA_BWID

// Global mean value for red in RGB or Y in YUV. Global mean value for green in
// RGB or U in YUV
#define CDMA_D_MEAN_GLOBAL_0_G0 "cdma_d_mean_global_0_g0"
#define CDMA_D_MEAN_GLOBAL_0_G1 "cdma_d_mean_global_0_g1"
#define CDMA_D_MEAN_GLOBAL_0_ADDR 0x509c
#define CDMA_D_MEAN_GLOBAL_0_BWID ICFG_CSB_DATA_BWID

// Global mean value for blue in RGB or V in YUV. Global mean value for alpha in
// ARGB/AYUV or X in XRGB
#define CDMA_D_MEAN_GLOBAL_1_G0 "cdma_d_mean_global_1_g0"
#define CDMA_D_MEAN_GLOBAL_1_G1 "cdma_d_mean_global_1_g1"
#define CDMA_D_MEAN_GLOBAL_1_ADDR 0x50a0
#define CDMA_D_MEAN_GLOBAL_1_BWID ICFG_CSB_DATA_BWID

// Enable/disable input data converter in CDMA and number of bits to be
// truncated in the input data converter
#define CDMA_D_CVT_CFG_G0 "cdma_d_cvt_cfg_g0"
#define CDMA_D_CVT_CFG_G1 "cdma_d_cvt_cfg_g1"
#define CDMA_D_CVT_CFG_ADDR 0x50a4
#define CDMA_D_CVT_CFG_BWID ICFG_CSB_DATA_BWID

// Offset of input data convertor
#define CDMA_D_CVT_OFFSET_G0 "cdma_d_cvt_offset_g0"
#define CDMA_D_CVT_OFFSET_G1 "cdma_d_cvt_offset_g1"
#define CDMA_D_CVT_OFFSET_ADDR 0x50a8
#define CDMA_D_CVT_OFFSET_BWID ICFG_CSB_DATA_BWID

// Scale of input data convertor
#define CDMA_D_CVT_SCALE_G0 "cdma_d_cvt_scale_g0"
#define CDMA_D_CVT_SCALE_G1 "cdma_d_cvt_scale_g1"
#define CDMA_D_CVT_SCALE_ADDR 0x50ac
#define CDMA_D_CVT_SCALE_BWID ICFG_CSB_DATA_BWID

// Convolution x stride and convolution y stride
#define CDMA_D_CONV_STRIDE_G0 "cdma_d_conv_stride_g0"
#define CDMA_D_CONV_STRIDE_G1 "cdma_d_conv_stride_g1"
#define CDMA_D_CONV_STRIDE_ADDR 0x50b0
#define CDMA_D_CONV_STRIDE_BWID ICFG_CSB_DATA_BWID

// Left/right/top/bottom padding size
#define CDMA_D_ZERO_PADDING_G0 "cdma_d_zero_padding_g0"
#define CDMA_D_ZERO_PADDING_G1 "cdma_d_zero_padding_g1"
#define CDMA_D_ZERO_PADDING_ADDR 0x50b4
#define CDMA_D_ZERO_PADDING_BWID ICFG_CSB_DATA_BWID

// Padding value
#define CDMA_D_ZERO_PADDING_VALUE_G0 "cdma_d_zero_padding_value_g0"
#define CDMA_D_ZERO_PADDING_VALUE_G1 "cdma_d_zero_padding_value_g1"
#define CDMA_D_ZERO_PADDING_VALUE_ADDR 0x50b8
#define CDMA_D_ZERO_PADDING_VALUE_BWID ICFG_CSB_DATA_BWID

// Number of data banks and weight banks in CBUF
#define CDMA_D_BANK_G0 "cdma_d_bank_g0"
#define CDMA_D_BANK_G1 "cdma_d_bank_g1"
#define CDMA_D_BANK_ADDR 0x50bc
#define CDMA_D_BANK_BWID ICFG_CSB_DATA_BWID

// Enable/Disable flushing input NaN to zero
#define CDMA_D_NAN_FLUSH_TO_ZERO_G0 "cdma_d_nan_flush_to_zero_g0"
#define CDMA_D_NAN_FLUSH_TO_ZERO_G1 "cdma_d_nan_flush_to_zero_g1"
#define CDMA_D_NAN_FLUSH_TO_ZERO_ADDR 0x50c0
#define CDMA_D_NAN_FLUSH_TO_ZERO_BWID ICFG_CSB_DATA_BWID

// Count NaN number in input data cube, update per layer
#define CDMA_D_NAN_INPUT_DATA_NUM_G0 "cdma_d_nan_input_data_num_g0"
#define CDMA_D_NAN_INPUT_DATA_NUM_G1 "cdma_d_nan_input_data_num_g1"
#define CDMA_D_NAN_INPUT_DATA_NUM_ADDR 0x50c4
#define CDMA_D_NAN_INPUT_DATA_NUM_BWID ICFG_CSB_DATA_BWID

// Count NaN number in weight kernels, update per layer
#define CDMA_D_NAN_INPUT_WEIGHT_NUM_G0 "cdma_d_nan_input_weight_num_g0"
#define CDMA_D_NAN_INPUT_WEIGHT_NUM_G1 "cdma_d_nan_input_weight_num_g1"
#define CDMA_D_NAN_INPUT_WEIGHT_NUM_ADDR 0x50c8
#define CDMA_D_NAN_INPUT_WEIGHT_NUM_BWID ICFG_CSB_DATA_BWID

// Count infinity number in input data cube, update per layer
#define CDMA_D_INF_INPUT_DATA_NUM_G0 "cdma_d_inf_input_data_num_g0"
#define CDMA_D_INF_INPUT_DATA_NUM_G1 "cdma_d_inf_input_data_num_g1"
#define CDMA_D_INF_INPUT_DATA_NUM_ADDR 0x50cc
#define CDMA_D_INF_INPUT_DATA_NUM_BWID ICFG_CSB_DATA_BWID

// Count infinity number in weight kernels, update per layer
#define CDMA_D_INF_INPUT_WEIGHT_NUM_G0 "cdma_d_inf_input_weight_num_g0"
#define CDMA_D_INF_INPUT_WEIGHT_NUM_G1 "cdma_d_inf_input_weight_num_g1"
#define CDMA_D_INF_INPUT_WEIGHT_NUM_ADDR 0x50d0
#define CDMA_D_INF_INPUT_WEIGHT_NUM_BWID ICFG_CSB_DATA_BWID

// Enable/disable performance counter
#define CDMA_D_PERF_ENABLE_G0 "cdma_d_perf_enable_g0"
#define CDMA_D_PERF_ENABLE_G1 "cdma_d_perf_enable_g1"
#define CDMA_D_PERF_ENABLE_ADDR 0x50d4
#define CDMA_D_PERF_ENABLE_BWID ICFG_CSB_DATA_BWID

// Count blocking cycles of read request of input data, update per layer
#define CDMA_D_PERF_DAT_READ_STALL_G0 "cdma_d_perf_dat_read_stall_g0"
#define CDMA_D_PERF_DAT_READ_STALL_G1 "cdma_d_perf_dat_read_stall_g1"
#define CDMA_D_PERF_DAT_READ_STALL_ADDR 0x50d8
#define CDMA_D_PERF_DAT_READ_STALL_BWID ICFG_CSB_DATA_BWID

// Count blocking cycles of read request of weight data, update per layer
#define CDMA_D_PERF_WT_READ_STALL_G0 "cdma_d_perf_wt_read_stall_g0"
#define CDMA_D_PERF_WT_READ_STALL_G1 "cdma_d_perf_wt_read_stall_g1"
#define CDMA_D_PERF_WT_READ_STALL_ADDR 0x50dc
#define CDMA_D_PERF_WT_READ_STALL_BWID ICFG_CSB_DATA_BWID

// Count total latency cycles of read response of input data, update per layer
#define CDMA_D_PERF_DAT_READ_LATENCY_G0 "cdma_d_perf_dat_read_latency_g0"
#define CDMA_D_PERF_DAT_READ_LATENCY_G1 "cdma_d_perf_dat_read_latency_g1"
#define CDMA_D_PERF_DAT_READ_LATENCY_ADDR 0x50e0
#define CDMA_D_PERF_DAT_READ_LATENCY_BWID ICFG_CSB_DATA_BWID

// Count total latency cycles of read request of weight data, update per layer
#define CDMA_D_PERF_WT_READ_LATENCY_G0 "cdma_d_perf_wt_read_latency_g0"
#define CDMA_D_PERF_WT_READ_LATENCY_G1 "cdma_d_perf_wt_read_latency_g1"
#define CDMA_D_PERF_WT_READ_LATENCY_ADDR 0x50e4
#define CDMA_D_PERF_WT_READ_LATENCY_BWID ICFG_CSB_DATA_BWID

}; // namespace ilang

#endif // STATE_INFO_CDMA_H__
