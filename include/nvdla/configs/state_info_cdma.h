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

// Pointer for CSB master and data path to access groups
#define CDMA_S_POINTER_NAME "cdma_s_pointer"

// WMB and Weight share same port to access external memory. This register
// controls the weight factor in the arbiter.
#define CDMA_S_ARBITER_NAME "cdma_s_arbiter"

// Indicates whether CBUF flush is finished after reset.
#define CDMA_S_CBUF_FLUSH_STATUS_NAME "cdma_s_cbuf_flush_status"

// Set it to 1 to kick off operation for current register group
#define CDMA_D_OP_ENABLE_NAME "cdma_d_op_enable"

// Configuration of operation: convolution mode, precision, weight reuse, data
// reuse.
#define CDMA_D_MISC_CFG_NAME "cdma_d_misc_cfg"

// Input data format and pixel format
#define CDMA_D_DATAIN_FORMAT_NAME "cdma_d_datain_format"

// Input cube’s width and height
#define CDMA_D_DATAIN_SIZE_0_NAME "cdma_d_datain_size_0"

// Input cube’s channel
#define CDMA_D_DATAIN_SIZE_1_NAME "cdma_d_datain_size_1"

// Input cube’s width and height after extension
#define CDMA_D_DATAIN_SIZE_EXT_0_NAME "cdma_d_datain_size_ext_0"

// For image-in mode, horizontal offset and vertical offset of the 1 st pixel.
#define CDMA_D_PIXEL_OFFSET_NAME "cdma_d_pixel_offset"

// Ram type of input RAM
#define CDMA_D_DAIN_RAM_TYPE_NAME "cdma_d_dain_ram_type"

// Higher 32bits of input data address when axi araddr is 64bits
#define CDMA_D_DAIN_ADDR_HIGH_0_NAME "cdma_d_dain_addr_high_0"

// Lower 32bits of input data address
#define CDMA_D_DAIN_ADDR_LOW_0_NAME "cdma_d_dain_addr_low_0"

// Higher 32bits of input data address of UV plane when axi araddr is 64bits
#define CDMA_D_DAIN_ADDR_HIGH_1_NAME "cdma_d_dain_addr_high_1"

// Lower 32bits of input data address of UV plane
#define CDMA_D_DAIN_ADDR_LOW_1_NAME "cdma_d_dain_addr_low_1"

// Line stride of input cube
#define CDMA_D_LINE_STRIDE_NAME "cdma_d_line_stride"

// Line stride of input cube’s UV plane
#define CDMA_D_LINE_UV_STRIDE_NAME "cdma_d_line_uv_stride"

// Surface stride of input cube
#define CDMA_D_SURF_STRIDE_NAME "cdma_d_surf_stride"

// Whether input cube is line packed or surface packed
#define CDMA_D_DAIN_MAP_NAME "cdma_d_dain_map"

// This address is reserved
#define CDMA_RESERVED_NAME "cdma_reserved"

// This address is reserved
#define CDMA_RESERVED_NAME "cdma_reserved"

// Number of batches
#define CDMA_D_BATCH_NUMBER_NAME "cdma_d_batch_number"

// The stride of input data cubes when batches > 1
#define CDMA_D_BATCH_STRIDE_NAME "cdma_d_batch_stride"

// Number of CBUF entries used for one input slice
#define CDMA_D_ENTRY_PER_SLICE_NAME "cdma_d_entry_per_slice"

// Number of slices to be fetched before sending update information to CSC
#define CDMA_D_FETCH_GRAIN_NAME "cdma_d_fetch_grain"

// Whether weight is compressed or not
#define CDMA_D_WEIGHT_FORMAT_NAME "cdma_d_weight_format"

// The size of one kernel in bytes
#define CDMA_D_WEIGHT_SIZE_0_NAME "cdma_d_weight_size_0"

// Number of kernels
#define CDMA_D_WEIGHT_SIZE_1_NAME "cdma_d_weight_size_1"

// Ram type of weight
#define CDMA_D_WEIGHT_RAM_TYPE_NAME "cdma_d_weight_ram_type"

// Higher 32bits of weight address when axi araddr is 64bits
#define CDMA_D_WEIGHT_ADDR_HIGH_NAME "cdma_d_weight_addr_high"

// Lower 32bits of weight address
#define CDMA_D_WEIGHT_ADDR_LOW_NAME "cdma_d_weight_addr_low"

// Total bytes of Weight
#define CDMA_D_WEIGHT_BYTES_NAME "cdma_d_weight_bytes"

// Higher 32bits of wgs address when axi araddr is 64bits
#define CDMA_D_WGS_ADDR_HIGH_NAME "cdma_d_wgs_addr_high"

// Lower 32bits of wgs address
#define CDMA_D_WGS_ADDR_LOW_NAME "cdma_d_wgs_addr_low"

// Higher 32bits of wmb address when axi araddr is 64bits
#define CDMA_D_WMB_ADDR_HIGH_NAME "cdma_d_wmb_addr_high"

// Lower 32bits of wmb address
#define CDMA_D_WMB_ADDR_LOW_NAME "cdma_d_wmb_addr_low"

// Total bytes of WMB
#define CDMA_D_WMB_BYTES_NAME "cdma_d_wmb_bytes"

// Whether mean registers are used or not
#define CDMA_D_MEAN_FORMAT_NAME "cdma_d_mean_format"

// Global mean value for red in RGB or Y in YUV. Global mean value for green in
// RGB or U in YUV
#define CDMA_D_MEAN_GLOBAL_0_NAME "cdma_d_mean_global_0"

// Global mean value for blue in RGB or V in YUV. Global mean value for alpha in
// ARGB/AYUV or X in XRGB
#define CDMA_D_MEAN_GLOBAL_1_NAME "cdma_d_mean_global_1"

// Enable/disable input data converter in CDMA and number of bits to be
// truncated in the input data converter
#define CDMA_D_CVT_CFG_NAME "cdma_d_cvt_cfg"

// Offset of input data convertor
#define CDMA_D_CVT_OFFSET_NAME "cdma_d_cvt_offset"

// Scale of input data convertor
#define CDMA_D_CVT_SCALE_NAME "cdma_d_cvt_scale"

// Convolution x stride and convolution y stride
#define CDMA_D_CONV_STRIDE_NAME "cdma_d_conv_stride"

// Left/right/top/bottom padding size
#define CDMA_D_ZERO_PADDING_NAME "cdma_d_zero_padding"

// Padding value
#define CDMA_D_ZERO_PADDING_VALUE_NAME "cdma_d_zero_padding_value"

// Number of data banks and weight banks in CBUF
#define CDMA_D_BANK_NAME "cdma_d_bank"

// Enable/Disable flushing input NaN to zero
#define CDMA_D_NAN_FLUSH_TO_ZERO_NAME "cdma_d_nan_flush_to_zero"

// Count NaN number in input data cube, update per layer
#define CDMA_D_NAN_INPUT_DATA_NUM_NAME "cdma_d_nan_input_data_num"

// Count NaN number in weight kernels, update per layer
#define CDMA_D_NAN_INPUT_WEIGHT_NUM_NAME "cdma_d_nan_input_weight_num"

// Count infinity number in input data cube, update per layer
#define CDMA_D_INF_INPUT_DATA_NUM_NAME "cdma_d_inf_input_data_num"

// Count infinity number in weight kernels, update per layer
#define CDMA_D_INF_INPUT_WEIGHT_NUM_NAME "cdma_d_inf_input_weight_num"

// Enable/disable performance counter
#define CDMA_D_PERF_ENABLE_NAME "cdma_d_perf_enable"

// Count blocking cycles of read request of input data, update per layer
#define CDMA_D_PERF_DAT_READ_STALL_NAME "cdma_d_perf_dat_read_stall"

// Count blocking cycles of read request of weight data, update per layer
#define CDMA_D_PERF_WT_READ_STALL_NAME "cdma_d_perf_wt_read_stall"

// Count total latency cycles of read response of input data, update per layer
#define CDMA_D_PERF_DAT_READ_LATENCY_NAME "cdma_d_perf_dat_read_latency"

// Count total latency cycles of read request of weight data, update per layer
#define CDMA_D_PERF_WT_READ_LATENCY_NAME "cdma_d_perf_wt_read_latency"

}; // namespace ilang

#endif // STATE_INFO_CDMA_H__
