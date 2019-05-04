// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: ppsm_cdp.cc

#include <ilang/ilang++.h>
#include <nvdla/configs/modeling_config.h>
#include <nvdla/configs/state_info.h>
#include <nvdla/utils.h>

// namespace ilang
namespace ilang {

// CDP_D_OP_ENABLE
void CsbWrPpsm_CDP_D_OP_ENABLE(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDP_D_OP_ENABLE");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CDP_D_OP_ENABLE_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDP_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDP_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDP_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDP_D_OP_ENABLE_G0);
  auto var_g1 = m.state(CDP_D_OP_ENABLE_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDP_D_FUNC_BYPASS
void CsbWrPpsm_CDP_D_FUNC_BYPASS(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDP_D_FUNC_BYPASS");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CDP_D_FUNC_BYPASS_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDP_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDP_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDP_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDP_D_FUNC_BYPASS_G0);
  auto var_g1 = m.state(CDP_D_FUNC_BYPASS_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDP_D_DST_BASE_ADDR_LOW
void CsbWrPpsm_CDP_D_DST_BASE_ADDR_LOW(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDP_D_DST_BASE_ADDR_LOW");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == CDP_D_DST_BASE_ADDR_LOW_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDP_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDP_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDP_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDP_D_DST_BASE_ADDR_LOW_G0);
  auto var_g1 = m.state(CDP_D_DST_BASE_ADDR_LOW_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDP_D_DST_BASE_ADDR_HIGH
void CsbWrPpsm_CDP_D_DST_BASE_ADDR_HIGH(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDP_D_DST_BASE_ADDR_HIGH");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == CDP_D_DST_BASE_ADDR_HIGH_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDP_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDP_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDP_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDP_D_DST_BASE_ADDR_HIGH_G0);
  auto var_g1 = m.state(CDP_D_DST_BASE_ADDR_HIGH_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDP_D_DST_LINE_STRIDE
void CsbWrPpsm_CDP_D_DST_LINE_STRIDE(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDP_D_DST_LINE_STRIDE");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CDP_D_DST_LINE_STRIDE_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDP_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDP_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDP_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDP_D_DST_LINE_STRIDE_G0);
  auto var_g1 = m.state(CDP_D_DST_LINE_STRIDE_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDP_D_DST_SURFACE_STRIDE
void CsbWrPpsm_CDP_D_DST_SURFACE_STRIDE(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDP_D_DST_SURFACE_STRIDE");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == CDP_D_DST_SURFACE_STRIDE_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDP_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDP_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDP_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDP_D_DST_SURFACE_STRIDE_G0);
  auto var_g1 = m.state(CDP_D_DST_SURFACE_STRIDE_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDP_D_DST_DMA_CFG
void CsbWrPpsm_CDP_D_DST_DMA_CFG(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDP_D_DST_DMA_CFG");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CDP_D_DST_DMA_CFG_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDP_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDP_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDP_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDP_D_DST_DMA_CFG_G0);
  auto var_g1 = m.state(CDP_D_DST_DMA_CFG_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDP_D_DST_COMPRESSION_EN
void CsbWrPpsm_CDP_D_DST_COMPRESSION_EN(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDP_D_DST_COMPRESSION_EN");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == CDP_D_DST_COMPRESSION_EN_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDP_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDP_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDP_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDP_D_DST_COMPRESSION_EN_G0);
  auto var_g1 = m.state(CDP_D_DST_COMPRESSION_EN_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDP_D_DATA_FORMAT
void CsbWrPpsm_CDP_D_DATA_FORMAT(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDP_D_DATA_FORMAT");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CDP_D_DATA_FORMAT_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDP_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDP_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDP_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDP_D_DATA_FORMAT_G0);
  auto var_g1 = m.state(CDP_D_DATA_FORMAT_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDP_D_NAN_FLUSH_TO_ZERO
void CsbWrPpsm_CDP_D_NAN_FLUSH_TO_ZERO(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDP_D_NAN_FLUSH_TO_ZERO");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == CDP_D_NAN_FLUSH_TO_ZERO_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDP_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDP_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDP_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDP_D_NAN_FLUSH_TO_ZERO_G0);
  auto var_g1 = m.state(CDP_D_NAN_FLUSH_TO_ZERO_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDP_D_LRN_CFG
void CsbWrPpsm_CDP_D_LRN_CFG(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDP_D_LRN_CFG");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CDP_D_LRN_CFG_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDP_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDP_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDP_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDP_D_LRN_CFG_G0);
  auto var_g1 = m.state(CDP_D_LRN_CFG_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDP_D_DATIN_OFFSET
void CsbWrPpsm_CDP_D_DATIN_OFFSET(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDP_D_DATIN_OFFSET");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CDP_D_DATIN_OFFSET_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDP_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDP_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDP_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDP_D_DATIN_OFFSET_G0);
  auto var_g1 = m.state(CDP_D_DATIN_OFFSET_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDP_D_DATIN_SCALE
void CsbWrPpsm_CDP_D_DATIN_SCALE(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDP_D_DATIN_SCALE");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CDP_D_DATIN_SCALE_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDP_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDP_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDP_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDP_D_DATIN_SCALE_G0);
  auto var_g1 = m.state(CDP_D_DATIN_SCALE_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDP_D_DATIN_SHIFTER
void CsbWrPpsm_CDP_D_DATIN_SHIFTER(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDP_D_DATIN_SHIFTER");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CDP_D_DATIN_SHIFTER_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDP_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDP_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDP_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDP_D_DATIN_SHIFTER_G0);
  auto var_g1 = m.state(CDP_D_DATIN_SHIFTER_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDP_D_DATOUT_OFFSET
void CsbWrPpsm_CDP_D_DATOUT_OFFSET(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDP_D_DATOUT_OFFSET");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CDP_D_DATOUT_OFFSET_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDP_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDP_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDP_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDP_D_DATOUT_OFFSET_G0);
  auto var_g1 = m.state(CDP_D_DATOUT_OFFSET_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDP_D_DATOUT_SCALE
void CsbWrPpsm_CDP_D_DATOUT_SCALE(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDP_D_DATOUT_SCALE");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CDP_D_DATOUT_SCALE_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDP_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDP_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDP_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDP_D_DATOUT_SCALE_G0);
  auto var_g1 = m.state(CDP_D_DATOUT_SCALE_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDP_D_DATOUT_SHIFTER
void CsbWrPpsm_CDP_D_DATOUT_SHIFTER(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDP_D_DATOUT_SHIFTER");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CDP_D_DATOUT_SHIFTER_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDP_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDP_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDP_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDP_D_DATOUT_SHIFTER_G0);
  auto var_g1 = m.state(CDP_D_DATOUT_SHIFTER_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDP_D_NAN_INPUT_NUM
void CsbWrPpsm_CDP_D_NAN_INPUT_NUM(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDP_D_NAN_INPUT_NUM");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CDP_D_NAN_INPUT_NUM_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDP_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDP_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDP_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDP_D_NAN_INPUT_NUM_G0);
  auto var_g1 = m.state(CDP_D_NAN_INPUT_NUM_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDP_D_INF_INPUT_NUM
void CsbWrPpsm_CDP_D_INF_INPUT_NUM(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDP_D_INF_INPUT_NUM");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CDP_D_INF_INPUT_NUM_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDP_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDP_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDP_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDP_D_INF_INPUT_NUM_G0);
  auto var_g1 = m.state(CDP_D_INF_INPUT_NUM_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDP_D_NAN_OUTPUT_NUM
void CsbWrPpsm_CDP_D_NAN_OUTPUT_NUM(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDP_D_NAN_OUTPUT_NUM");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CDP_D_NAN_OUTPUT_NUM_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDP_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDP_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDP_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDP_D_NAN_OUTPUT_NUM_G0);
  auto var_g1 = m.state(CDP_D_NAN_OUTPUT_NUM_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDP_D_OUT_SATURATION
void CsbWrPpsm_CDP_D_OUT_SATURATION(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDP_D_OUT_SATURATION");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CDP_D_OUT_SATURATION_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDP_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDP_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDP_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDP_D_OUT_SATURATION_G0);
  auto var_g1 = m.state(CDP_D_OUT_SATURATION_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDP_D_PERF_ENABLE
void CsbWrPpsm_CDP_D_PERF_ENABLE(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDP_D_PERF_ENABLE");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CDP_D_PERF_ENABLE_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDP_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDP_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDP_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDP_D_PERF_ENABLE_G0);
  auto var_g1 = m.state(CDP_D_PERF_ENABLE_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDP_D_PERF_WRITE_STALL
void CsbWrPpsm_CDP_D_PERF_WRITE_STALL(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDP_D_PERF_WRITE_STALL");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == CDP_D_PERF_WRITE_STALL_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDP_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDP_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDP_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDP_D_PERF_WRITE_STALL_G0);
  auto var_g1 = m.state(CDP_D_PERF_WRITE_STALL_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDP_D_PERF_LUT_UFLOW
void CsbWrPpsm_CDP_D_PERF_LUT_UFLOW(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDP_D_PERF_LUT_UFLOW");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CDP_D_PERF_LUT_UFLOW_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDP_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDP_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDP_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDP_D_PERF_LUT_UFLOW_G0);
  auto var_g1 = m.state(CDP_D_PERF_LUT_UFLOW_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDP_D_PERF_LUT_OFLOW
void CsbWrPpsm_CDP_D_PERF_LUT_OFLOW(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDP_D_PERF_LUT_OFLOW");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CDP_D_PERF_LUT_OFLOW_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDP_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDP_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDP_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDP_D_PERF_LUT_OFLOW_G0);
  auto var_g1 = m.state(CDP_D_PERF_LUT_OFLOW_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDP_D_PERF_LUT_HYBRID
void CsbWrPpsm_CDP_D_PERF_LUT_HYBRID(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDP_D_PERF_LUT_HYBRID");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CDP_D_PERF_LUT_HYBRID_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDP_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDP_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDP_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDP_D_PERF_LUT_HYBRID_G0);
  auto var_g1 = m.state(CDP_D_PERF_LUT_HYBRID_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDP_D_PERF_LUT_LE_HIT
void CsbWrPpsm_CDP_D_PERF_LUT_LE_HIT(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDP_D_PERF_LUT_LE_HIT");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CDP_D_PERF_LUT_LE_HIT_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDP_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDP_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDP_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDP_D_PERF_LUT_LE_HIT_G0);
  auto var_g1 = m.state(CDP_D_PERF_LUT_LE_HIT_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDP_D_PERF_LUT_LO_HIT
void CsbWrPpsm_CDP_D_PERF_LUT_LO_HIT(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDP_D_PERF_LUT_LO_HIT");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CDP_D_PERF_LUT_LO_HIT_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDP_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDP_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDP_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDP_D_PERF_LUT_LO_HIT_G0);
  auto var_g1 = m.state(CDP_D_PERF_LUT_LO_HIT_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

}; // namespace ilang
