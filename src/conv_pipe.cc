// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: conv_pipe.cc

#include <ilang/util/log.h>
#include <nvdla/configs/hw_param.h>
#include <nvdla/configs/modeling_config.h>
#include <nvdla/configs/state_info.h>
#include <nvdla/conv_pipe.h>
#include <nvdla/state_update/ppsm_cacc.h>
#include <nvdla/state_update/ppsm_cdma.h>
#include <nvdla/state_update/ppsm_cmac_a.h>
#include <nvdla/state_update/ppsm_cmac_b.h>
#include <nvdla/state_update/ppsm_csc.h>
#include <nvdla/utils.h>

// namespace ilang
namespace ilang {

// static data member

// extern member
void StateDefineCdma(Ila& m);
void StateDefineCsc(Ila& m);
void StateDefineCmac_B(Ila& m);
void StateDefineCacc(Ila& m);

void StateInitCdma(Ila& m);
void StateInitCsc(Ila& m);
void StateInitCmac_B(Ila& m);
void StateInitCacc(Ila& m);

Ila ConvPipe::New(Ila& parent, const std::string& name) {
  auto m = parent.NewChild(name);

  // state var
  SetArchStateVar(m);
  SetImplStateVar(m);

  // model hierarchy
  SetChild(m);

  // instructions
  SetInstr(m);

  // valid
  auto valid = IsTrue(m.state(k_trig_conv_pipe));
  m.SetValid(valid);

  // fetch
  auto fetch = m.input(CSB2NVDLA_ADDR);
  m.SetFetch(fetch);

  return m;
}

void ConvPipe::GetInputAssumption(const Ila& m, ExprVec& assm) {
  //
  return;
}

void ConvPipe::GetStateInvariant(const Ila& m, ExprVec& invr) {
  //
  return;
}

std::string ConvPipe::CbufBankName(const int& idx) {
  ILA_ASSERT((idx >= 0) && (idx < NVDLA_CBUF_BANK_NUMBER))
      << "Invalid cbuf idx " << idx;
  auto name = "cbuf_bank_" + std::to_string(idx);
  return name;
}

void ConvPipe::SetArchStateVar(Ila& m) {
  // CDMA
  StateDefineCdma(m);
  StateInitCdma(m);

  // CBUF
  // no MMIO addressible registers

  // CSC
  StateDefineCsc(m);
  StateInitCsc(m);

  // CMAC
  StateDefineCmac_B(m);
  StateInitCmac_B(m);

  // CACC
  StateDefineCacc(m);
  StateInitCacc(m);

  return;
}

void ConvPipe::SetImplStateVar(Ila& m) {
  // CBUF
  for (auto i = 0; i < NVDLA_CBUF_BANK_NUMBER; i++) {
    auto bank_i =
        m.NewMemState(CbufBankName(i), ICFG_PTR_BWID, NVDLA_CBUF_BANK_WIDTH);
    bank_i.SetEntryNum(NVDLA_CBUF_BANK_DEPTH);
  }

  return;
}

void ConvPipe::SetChild(Ila& m) {
  //
  return;
}

void ConvPipe::SetInstr(Ila& m) {
  // CSB write (no side effect)
  
  // CDMA
  CsbWrPpsm_CDMA_D_OP_ENABLE(m);
  CsbWrPpsm_CDMA_D_MISC_CFG(m);
  CsbWrPpsm_CDMA_D_DATAIN_FORMAT(m);
  CsbWrPpsm_CDMA_D_DATAIN_SIZE_0(m);
  CsbWrPpsm_CDMA_D_DATAIN_SIZE_1(m);
  CsbWrPpsm_CDMA_D_DATAIN_SIZE_EXT_0(m);
  CsbWrPpsm_CDMA_D_PIXEL_OFFSET(m);
  CsbWrPpsm_CDMA_D_DAIN_RAM_TYPE(m);
  CsbWrPpsm_CDMA_D_DAIN_ADDR_HIGH_0(m);
  CsbWrPpsm_CDMA_D_DAIN_ADDR_LOW_0(m);
  CsbWrPpsm_CDMA_D_DAIN_ADDR_HIGH_1(m);
  CsbWrPpsm_CDMA_D_DAIN_ADDR_LOW_1(m);
  CsbWrPpsm_CDMA_D_LINE_STRIDE(m);
  CsbWrPpsm_CDMA_D_LINE_UV_STRIDE(m);
  CsbWrPpsm_CDMA_D_SURF_STRIDE(m);
  CsbWrPpsm_CDMA_D_DAIN_MAP(m);
  CsbWrPpsm_CDMA_D_BATCH_NUMBER(m);
  CsbWrPpsm_CDMA_D_BATCH_STRIDE(m);
  CsbWrPpsm_CDMA_D_ENTRY_PER_SLICE(m);
  CsbWrPpsm_CDMA_D_FETCH_GRAIN(m);
  CsbWrPpsm_CDMA_D_WEIGHT_FORMAT(m);
  CsbWrPpsm_CDMA_D_WEIGHT_SIZE_0(m);
  CsbWrPpsm_CDMA_D_WEIGHT_SIZE_1(m);
  CsbWrPpsm_CDMA_D_WEIGHT_RAM_TYPE(m);
  CsbWrPpsm_CDMA_D_WEIGHT_ADDR_HIGH(m);
  CsbWrPpsm_CDMA_D_WEIGHT_ADDR_LOW(m);
  CsbWrPpsm_CDMA_D_WEIGHT_BYTES(m);
  CsbWrPpsm_CDMA_D_WGS_ADDR_HIGH(m);
  CsbWrPpsm_CDMA_D_WGS_ADDR_LOW(m);
  CsbWrPpsm_CDMA_D_WMB_ADDR_HIGH(m);
  CsbWrPpsm_CDMA_D_WMB_ADDR_LOW(m);
  CsbWrPpsm_CDMA_D_WMB_BYTES(m);
  CsbWrPpsm_CDMA_D_MEAN_FORMAT(m);
  CsbWrPpsm_CDMA_D_MEAN_GLOBAL_0(m);
  CsbWrPpsm_CDMA_D_MEAN_GLOBAL_1(m);
  CsbWrPpsm_CDMA_D_CVT_CFG(m);
  CsbWrPpsm_CDMA_D_CVT_OFFSET(m);
  CsbWrPpsm_CDMA_D_CVT_SCALE(m);
  CsbWrPpsm_CDMA_D_CONV_STRIDE(m);
  CsbWrPpsm_CDMA_D_ZERO_PADDING(m);
  CsbWrPpsm_CDMA_D_ZERO_PADDING_VALUE(m);
  CsbWrPpsm_CDMA_D_BANK(m);
  CsbWrPpsm_CDMA_D_NAN_FLUSH_TO_ZERO(m);
  CsbWrPpsm_CDMA_D_NAN_INPUT_DATA_NUM(m);
  CsbWrPpsm_CDMA_D_NAN_INPUT_WEIGHT_NUM(m);
  CsbWrPpsm_CDMA_D_INF_INPUT_DATA_NUM(m);
  CsbWrPpsm_CDMA_D_INF_INPUT_WEIGHT_NUM(m);
  CsbWrPpsm_CDMA_D_PERF_ENABLE(m);
  CsbWrPpsm_CDMA_D_PERF_DAT_READ_STALL(m);
  CsbWrPpsm_CDMA_D_PERF_WT_READ_STALL(m);
  CsbWrPpsm_CDMA_D_PERF_DAT_READ_LATENCY(m);
  CsbWrPpsm_CDMA_D_PERF_WT_READ_LATENCY(m);

  // CSC
  CsbWrPpsm_CSC_D_OP_ENABLE(m);
  CsbWrPpsm_CSC_D_MISC_CFG(m);
  CsbWrPpsm_CSC_D_DATAIN_FORMAT(m);
  CsbWrPpsm_CSC_D_DATAIN_SIZE_EXT_0(m);
  CsbWrPpsm_CSC_D_DATAIN_SIZE_EXT_1(m);
  CsbWrPpsm_CSC_D_BATCH_NUMBER(m);
  CsbWrPpsm_CSC_D_POST_Y_EXTENSION(m);
  CsbWrPpsm_CSC_D_ENTRY_PER_SLICE(m);
  CsbWrPpsm_CSC_D_WEIGHT_FORMAT(m);
  CsbWrPpsm_CSC_D_WEIGHT_SIZE_EXT_0(m);
  CsbWrPpsm_CSC_D_WEIGHT_SIZE_EXT_1(m);
  CsbWrPpsm_CSC_D_WEIGHT_BYTES(m);
  CsbWrPpsm_CSC_D_WMB_BYTES(m);
  CsbWrPpsm_CSC_D_DATAOUT_SIZE_0(m);
  CsbWrPpsm_CSC_D_DATAOUT_SIZE_1(m);
  CsbWrPpsm_CSC_D_ATOMICS(m);
  CsbWrPpsm_CSC_D_RELEASE(m);
  CsbWrPpsm_CSC_D_CONV_STRIDE_EXT(m);
  CsbWrPpsm_CSC_D_DILATION_EXT(m);
  CsbWrPpsm_CSC_D_ZERO_PADDING(m);
  CsbWrPpsm_CSC_D_ZERO_PADDING_VALUE(m);
  CsbWrPpsm_CSC_D_BANK(m);
  CsbWrPpsm_CSC_D_PRA_CFG(m);

  // CMAC
  CsbWrPpsm_CMAC_B_D_OP_ENABLE(m);
  CsbWrPpsm_CMAC_B_D_MISC_CFG(m);

  // CACC
  CsbWrPpsm_CACC_D_OP_ENABLE(m);
  CsbWrPpsm_CACC_D_MISC_CFG(m);
  CsbWrPpsm_CACC_D_DATAOUT_SIZE_0(m);
  CsbWrPpsm_CACC_D_DATAOUT_SIZE_1(m);
  CsbWrPpsm_CACC_D_DATAOUT_ADDR(m);
  CsbWrPpsm_CACC_D_BATCH_NUMBER(m);
  CsbWrPpsm_CACC_D_LINE_STRIDE(m);
  CsbWrPpsm_CACC_D_SURF_STRIDE(m);
  CsbWrPpsm_CACC_D_DATAOUT_MAP(m);
  CsbWrPpsm_CACC_D_CLIP_CFG(m);
  CsbWrPpsm_CACC_D_OUT_SATURATION(m);

  return;
}

}; // namespace ilang

