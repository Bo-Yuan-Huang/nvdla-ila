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

/// \namespace ilang
namespace ilang {

// Idle status of two register groups
#define CDMA_S_STATUS_NAME "cdma_s_status"
#define CDMA_S_STATUS_BWID 32
// Pointer for CSB master and data path to access groups
#define CDMA_S_POINTER_NAME "cdma_s_pointer"
#define CDMA_S_POINTER_BWID 32
// WMB and Weight share same port to access external memory. This register
// controls the weight factor in the arbiter.
#define CDMA_S_ARBITER_NAME "cdma_s_arbiter"
#define CDMA_S_ARBITER_BWID 32
// Indicates whether CBUF flush is finished after reset.
#define CDMA_S_CBUF_FLUSH_STATUS_NAME "cdma_s_cbuf_flush_status"
#define CDMA_S_CBUF_FLUSH_STATUS_BWID 32
// Set it to 1 to kick off operation for current register group
#define CDMA_D_OP_ENABLE_NAME "cdma_d_op_enable"
#define CDMA_D_OP_ENABLE_BWID 32
// Configuration of operation: convolution mode, precision, weight reuse, data
// reuse.
#define CDMA_D_MISC_CFG_NAME "cdma_d_misc_cfg"
#define CDMA_D_MISC_CFG_BWID 32
// Input data format and pixel format
#define CDMA_D_DATAIN_FORMAT_NAME "cdma_d_datain_format"
#define CDMA_D_DATAIN_FORMAT_BWID 32
// Input cube’s width and height
#define CDMA_D_DATAIN_SIZE_0_NAME "cdma_d_datain_size_0"
#define CDMA_D_DATAIN_SIZE_0_BWID 32
// Input cube’s channel
#define CDMA_D_DATAIN_SIZE_1_NAME "cdma_d_datain_size_1"
#define CDMA_D_DATAIN_SIZE_1_BWID 32
// Input cube’s width and height after extension
#define CDMA_D_DATAIN_SIZE_EXT_0_NAME "cdma_d_datain_size_ext_0"
#define CDMA_D_DATAIN_SIZE_EXT_0_BWID 32
// For image-in mode, horizontal offset and vertical offset of the 1 st pixel.
#define CDMA_D_PIXEL_OFFSET_NAME "cdma_d_pixel_offset"
#define CDMA_D_PIXEL_OFFSET_BWID 32
// Ram type of input RAM
#define CDMA_D_DAIN_RAM_TYPE_NAME "cdma_d_dain_ram_type"
#define CDMA_D_DAIN_RAM_TYPE_BWID 32
// Higher 32bits of input data address when axi araddr is 64bits
#define CDMA_D_DAIN_ADDR_HIGH_0_NAME "cdma_d_dain_addr_high_0"
#define CDMA_D_DAIN_ADDR_HIGH_0_BWID 32
// Lower 32bits of input data address
#define CDMA_D_DAIN_ADDR_LOW_0_NAME "cdma_d_dain_addr_low_0"
#define CDMA_D_DAIN_ADDR_LOW_0_BWID 32
// Higher 32bits of input data address of UV plane when axi araddr is 64bits
#define CDMA_D_DAIN_ADDR_HIGH_1_NAME "cdma_d_dain_addr_high_1"
#define CDMA_D_DAIN_ADDR_HIGH_1_BWID 32
// Lower 32bits of input data address of UV plane
#define CDMA_D_DAIN_ADDR_LOW_1_NAME "cdma_d_dain_addr_low_1"
#define CDMA_D_DAIN_ADDR_LOW_1_BWID 32
// Line stride of input cube
#define CDMA_D_LINE_STRIDE_NAME "cdma_d_line_stride"
#define CDMA_D_LINE_STRIDE_BWID 32
// Line stride of input cube’s UV plane
#define CDMA_D_LINE_UV_STRIDE_NAME "cdma_d_line_uv_stride"
#define CDMA_D_LINE_UV_STRIDE_BWID 32
// Surface stride of input cube
#define CDMA_D_SURF_STRIDE_NAME "cdma_d_surf_stride"
#define CDMA_D_SURF_STRIDE_BWID 32
// Whether input cube is line packed or surface packed
#define CDMA_D_DAIN_MAP_NAME "cdma_d_dain_map"
#define CDMA_D_DAIN_MAP_BWID 32
// This address is reserved
#define CDMA_RESERVED_NAME "cdma_reserved"
#define CDMA_RESERVED_BWID 32
// This address is reserved
#define CDMA_RESERVED_NAME "cdma_reserved"
#define CDMA_RESERVED_BWID 32
// Number of batches
#define CDMA_D_BATCH_NUMBER_NAME "cdma_d_batch_number"
#define CDMA_D_BATCH_NUMBER_BWID 32
// The stride of input data cubes when batches > 1
#define CDMA_D_BATCH_STRIDE_NAME "cdma_d_batch_stride"
#define CDMA_D_BATCH_STRIDE_BWID 32
// Number of CBUF entries used for one input slice
#define CDMA_D_ENTRY_PER_SLICE_NAME "cdma_d_entry_per_slice"
#define CDMA_D_ENTRY_PER_SLICE_BWID 32
// Number of slices to be fetched before sending update information to CSC
#define CDMA_D_FETCH_GRAIN_NAME "cdma_d_fetch_grain"
#define CDMA_D_FETCH_GRAIN_BWID 32
// Whether weight is compressed or not
#define CDMA_D_WEIGHT_FORMAT_NAME "cdma_d_weight_format"
#define CDMA_D_WEIGHT_FORMAT_BWID 32
// The size of one kernel in bytes
#define CDMA_D_WEIGHT_SIZE_0_NAME "cdma_d_weight_size_0"
#define CDMA_D_WEIGHT_SIZE_0_BWID 32
// Number of kernels
#define CDMA_D_WEIGHT_SIZE_1_NAME "cdma_d_weight_size_1"
#define CDMA_D_WEIGHT_SIZE_1_BWID 32
// Ram type of weight
#define CDMA_D_WEIGHT_RAM_TYPE_NAME "cdma_d_weight_ram_type"
#define CDMA_D_WEIGHT_RAM_TYPE_BWID 32
// Higher 32bits of weight address when axi araddr is 64bits
#define CDMA_D_WEIGHT_ADDR_HIGH_NAME "cdma_d_weight_addr_high"
#define CDMA_D_WEIGHT_ADDR_HIGH_BWID 32
// Lower 32bits of weight address
#define CDMA_D_WEIGHT_ADDR_LOW_NAME "cdma_d_weight_addr_low"
#define CDMA_D_WEIGHT_ADDR_LOW_BWID 32
// Total bytes of Weight
#define CDMA_D_WEIGHT_BYTES_NAME "cdma_d_weight_bytes"
#define CDMA_D_WEIGHT_BYTES_BWID 32
// Higher 32bits of wgs address when axi araddr is 64bits
#define CDMA_D_WGS_ADDR_HIGH_NAME "cdma_d_wgs_addr_high"
#define CDMA_D_WGS_ADDR_HIGH_BWID 32
// Lower 32bits of wgs address
#define CDMA_D_WGS_ADDR_LOW_NAME "cdma_d_wgs_addr_low"
#define CDMA_D_WGS_ADDR_LOW_BWID 32
// Higher 32bits of wmb address when axi araddr is 64bits
#define CDMA_D_WMB_ADDR_HIGH_NAME "cdma_d_wmb_addr_high"
#define CDMA_D_WMB_ADDR_HIGH_BWID 32
// Lower 32bits of wmb address
#define CDMA_D_WMB_ADDR_LOW_NAME "cdma_d_wmb_addr_low"
#define CDMA_D_WMB_ADDR_LOW_BWID 32
// Total bytes of WMB
#define CDMA_D_WMB_BYTES_NAME "cdma_d_wmb_bytes"
#define CDMA_D_WMB_BYTES_BWID 32
// Whether mean registers are used or not
#define CDMA_D_MEAN_FORMAT_NAME "cdma_d_mean_format"
#define CDMA_D_MEAN_FORMAT_BWID 32
// Global mean value for red in RGB or Y in YUV. Global mean value for green in
// RGB or U in YUV
#define CDMA_D_MEAN_GLOBAL_0_NAME "cdma_d_mean_global_0"
#define CDMA_D_MEAN_GLOBAL_0_BWID 32
// Global mean value for blue in RGB or V in YUV. Global mean value for alpha in
// ARGB/AYUV or X in XRGB
#define CDMA_D_MEAN_GLOBAL_1_NAME "cdma_d_mean_global_1"
#define CDMA_D_MEAN_GLOBAL_1_BWID 32
// Enable/disable input data converter in CDMA and number of bits to be
// truncated in the input data converter
#define CDMA_D_CVT_CFG_NAME "cdma_d_cvt_cfg"
#define CDMA_D_CVT_CFG_BWID 32
// Offset of input data convertor
#define CDMA_D_CVT_OFFSET_NAME "cdma_d_cvt_offset"
#define CDMA_D_CVT_OFFSET_BWID 32
// Scale of input data convertor
#define CDMA_D_CVT_SCALE_NAME "cdma_d_cvt_scale"
#define CDMA_D_CVT_SCALE_BWID 32
// Convolution x stride and convolution y stride
#define CDMA_D_CONV_STRIDE_NAME "cdma_d_conv_stride"
#define CDMA_D_CONV_STRIDE_BWID 32
// Left/right/top/bottom padding size
#define CDMA_D_ZERO_PADDING_NAME "cdma_d_zero_padding"
#define CDMA_D_ZERO_PADDING_BWID 32
// Padding value
#define CDMA_D_ZERO_PADDING_VALUE_NAME "cdma_d_zero_padding_value"
#define CDMA_D_ZERO_PADDING_VALUE_BWID 32
// Number of data banks and weight banks in CBUF
#define CDMA_D_BANK_NAME "cdma_d_bank"
#define CDMA_D_BANK_BWID 32
// Enable/Disable flushing input NaN to zero
#define CDMA_D_NAN_FLUSH_TO_ZERO_NAME "cdma_d_nan_flush_to_zero"
#define CDMA_D_NAN_FLUSH_TO_ZERO_BWID 32
// Count NaN number in input data cube, update per layer
#define CDMA_D_NAN_INPUT_DATA_NUM_NAME "cdma_d_nan_input_data_num"
#define CDMA_D_NAN_INPUT_DATA_NUM_BWID 32
// Count NaN number in weight kernels, update per layer
#define CDMA_D_NAN_INPUT_WEIGHT_NUM_NAME "cdma_d_nan_input_weight_num"
#define CDMA_D_NAN_INPUT_WEIGHT_NUM_BWID 32
// Count infinity number in input data cube, update per layer
#define CDMA_D_INF_INPUT_DATA_NUM_NAME "cdma_d_inf_input_data_num"
#define CDMA_D_INF_INPUT_DATA_NUM_BWID 32
// Count infinity number in weight kernels, update per layer
#define CDMA_D_INF_INPUT_WEIGHT_NUM_NAME "cdma_d_inf_input_weight_num"
#define CDMA_D_INF_INPUT_WEIGHT_NUM_BWID 32
// Enable/disable performance counter
#define CDMA_D_PERF_ENABLE_NAME "cdma_d_perf_enable"
#define CDMA_D_PERF_ENABLE_BWID 32
// Count blocking cycles of read request of input data, update per layer
#define CDMA_D_PERF_DAT_READ_STALL_NAME "cdma_d_perf_dat_read_stall"
#define CDMA_D_PERF_DAT_READ_STALL_BWID 32
// Count blocking cycles of read request of weight data, update per layer
#define CDMA_D_PERF_WT_READ_STALL_NAME "cdma_d_perf_wt_read_stall"
#define CDMA_D_PERF_WT_READ_STALL_BWID 32
// Count total latency cycles of read response of input data, update per layer
#define CDMA_D_PERF_DAT_READ_LATENCY_NAME "cdma_d_perf_dat_read_latency"
#define CDMA_D_PERF_DAT_READ_LATENCY_BWID 32
// Count total latency cycles of read request of weight data, update per layer
#define CDMA_D_PERF_WT_READ_LATENCY_NAME "cdma_d_perf_wt_read_latency"
#define CDMA_D_PERF_WT_READ_LATENCY_BWID 32

}; // namespace ilang

#endif // STATE_INFO_CDMA_H__
