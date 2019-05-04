// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: ppsm_cdma.cc

#include <ilang/ilang++.h>
#include <nvdla/configs/modeling_config.h>
#include <nvdla/configs/state_info.h>
#include <nvdla/utils.h>

// namespace ilang
namespace ilang {

// CDMA_D_OP_ENABLE
void CsbWrPpsm_CDMA_D_OP_ENABLE(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDMA_D_OP_ENABLE");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CDMA_D_OP_ENABLE_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDMA_D_OP_ENABLE_G0);
  auto var_g1 = m.state(CDMA_D_OP_ENABLE_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDMA_D_MISC_CFG
void CsbWrPpsm_CDMA_D_MISC_CFG(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDMA_D_MISC_CFG");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CDMA_D_MISC_CFG_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDMA_D_MISC_CFG_G0);
  auto var_g1 = m.state(CDMA_D_MISC_CFG_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDMA_D_DATAIN_FORMAT
void CsbWrPpsm_CDMA_D_DATAIN_FORMAT(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDMA_D_DATAIN_FORMAT");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CDMA_D_DATAIN_FORMAT_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDMA_D_DATAIN_FORMAT_G0);
  auto var_g1 = m.state(CDMA_D_DATAIN_FORMAT_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDMA_D_DATAIN_SIZE_0
void CsbWrPpsm_CDMA_D_DATAIN_SIZE_0(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDMA_D_DATAIN_SIZE_0");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CDMA_D_DATAIN_SIZE_0_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDMA_D_DATAIN_SIZE_0_G0);
  auto var_g1 = m.state(CDMA_D_DATAIN_SIZE_0_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDMA_D_DATAIN_SIZE_1
void CsbWrPpsm_CDMA_D_DATAIN_SIZE_1(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDMA_D_DATAIN_SIZE_1");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CDMA_D_DATAIN_SIZE_1_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDMA_D_DATAIN_SIZE_1_G0);
  auto var_g1 = m.state(CDMA_D_DATAIN_SIZE_1_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDMA_D_DATAIN_SIZE_EXT_0
void CsbWrPpsm_CDMA_D_DATAIN_SIZE_EXT_0(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDMA_D_DATAIN_SIZE_EXT_0");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == CDMA_D_DATAIN_SIZE_EXT_0_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDMA_D_DATAIN_SIZE_EXT_0_G0);
  auto var_g1 = m.state(CDMA_D_DATAIN_SIZE_EXT_0_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDMA_D_PIXEL_OFFSET
void CsbWrPpsm_CDMA_D_PIXEL_OFFSET(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDMA_D_PIXEL_OFFSET");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CDMA_D_PIXEL_OFFSET_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDMA_D_PIXEL_OFFSET_G0);
  auto var_g1 = m.state(CDMA_D_PIXEL_OFFSET_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDMA_D_DAIN_RAM_TYPE
void CsbWrPpsm_CDMA_D_DAIN_RAM_TYPE(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDMA_D_DAIN_RAM_TYPE");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CDMA_D_DAIN_RAM_TYPE_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDMA_D_DAIN_RAM_TYPE_G0);
  auto var_g1 = m.state(CDMA_D_DAIN_RAM_TYPE_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDMA_D_DAIN_ADDR_HIGH_0
void CsbWrPpsm_CDMA_D_DAIN_ADDR_HIGH_0(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDMA_D_DAIN_ADDR_HIGH_0");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == CDMA_D_DAIN_ADDR_HIGH_0_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDMA_D_DAIN_ADDR_HIGH_0_G0);
  auto var_g1 = m.state(CDMA_D_DAIN_ADDR_HIGH_0_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDMA_D_DAIN_ADDR_LOW_0
void CsbWrPpsm_CDMA_D_DAIN_ADDR_LOW_0(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDMA_D_DAIN_ADDR_LOW_0");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == CDMA_D_DAIN_ADDR_LOW_0_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDMA_D_DAIN_ADDR_LOW_0_G0);
  auto var_g1 = m.state(CDMA_D_DAIN_ADDR_LOW_0_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDMA_D_DAIN_ADDR_HIGH_1
void CsbWrPpsm_CDMA_D_DAIN_ADDR_HIGH_1(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDMA_D_DAIN_ADDR_HIGH_1");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == CDMA_D_DAIN_ADDR_HIGH_1_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDMA_D_DAIN_ADDR_HIGH_1_G0);
  auto var_g1 = m.state(CDMA_D_DAIN_ADDR_HIGH_1_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDMA_D_DAIN_ADDR_LOW_1
void CsbWrPpsm_CDMA_D_DAIN_ADDR_LOW_1(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDMA_D_DAIN_ADDR_LOW_1");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == CDMA_D_DAIN_ADDR_LOW_1_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDMA_D_DAIN_ADDR_LOW_1_G0);
  auto var_g1 = m.state(CDMA_D_DAIN_ADDR_LOW_1_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDMA_D_LINE_STRIDE
void CsbWrPpsm_CDMA_D_LINE_STRIDE(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDMA_D_LINE_STRIDE");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CDMA_D_LINE_STRIDE_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDMA_D_LINE_STRIDE_G0);
  auto var_g1 = m.state(CDMA_D_LINE_STRIDE_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDMA_D_LINE_UV_STRIDE
void CsbWrPpsm_CDMA_D_LINE_UV_STRIDE(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDMA_D_LINE_UV_STRIDE");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CDMA_D_LINE_UV_STRIDE_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDMA_D_LINE_UV_STRIDE_G0);
  auto var_g1 = m.state(CDMA_D_LINE_UV_STRIDE_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDMA_D_SURF_STRIDE
void CsbWrPpsm_CDMA_D_SURF_STRIDE(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDMA_D_SURF_STRIDE");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CDMA_D_SURF_STRIDE_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDMA_D_SURF_STRIDE_G0);
  auto var_g1 = m.state(CDMA_D_SURF_STRIDE_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDMA_D_DAIN_MAP
void CsbWrPpsm_CDMA_D_DAIN_MAP(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDMA_D_DAIN_MAP");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CDMA_D_DAIN_MAP_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDMA_D_DAIN_MAP_G0);
  auto var_g1 = m.state(CDMA_D_DAIN_MAP_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDMA_D_BATCH_NUMBER
void CsbWrPpsm_CDMA_D_BATCH_NUMBER(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDMA_D_BATCH_NUMBER");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CDMA_D_BATCH_NUMBER_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDMA_D_BATCH_NUMBER_G0);
  auto var_g1 = m.state(CDMA_D_BATCH_NUMBER_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDMA_D_BATCH_STRIDE
void CsbWrPpsm_CDMA_D_BATCH_STRIDE(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDMA_D_BATCH_STRIDE");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CDMA_D_BATCH_STRIDE_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDMA_D_BATCH_STRIDE_G0);
  auto var_g1 = m.state(CDMA_D_BATCH_STRIDE_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDMA_D_ENTRY_PER_SLICE
void CsbWrPpsm_CDMA_D_ENTRY_PER_SLICE(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDMA_D_ENTRY_PER_SLICE");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == CDMA_D_ENTRY_PER_SLICE_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDMA_D_ENTRY_PER_SLICE_G0);
  auto var_g1 = m.state(CDMA_D_ENTRY_PER_SLICE_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDMA_D_FETCH_GRAIN
void CsbWrPpsm_CDMA_D_FETCH_GRAIN(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDMA_D_FETCH_GRAIN");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CDMA_D_FETCH_GRAIN_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDMA_D_FETCH_GRAIN_G0);
  auto var_g1 = m.state(CDMA_D_FETCH_GRAIN_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDMA_D_WEIGHT_FORMAT
void CsbWrPpsm_CDMA_D_WEIGHT_FORMAT(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDMA_D_WEIGHT_FORMAT");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CDMA_D_WEIGHT_FORMAT_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDMA_D_WEIGHT_FORMAT_G0);
  auto var_g1 = m.state(CDMA_D_WEIGHT_FORMAT_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDMA_D_WEIGHT_SIZE_0
void CsbWrPpsm_CDMA_D_WEIGHT_SIZE_0(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDMA_D_WEIGHT_SIZE_0");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CDMA_D_WEIGHT_SIZE_0_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDMA_D_WEIGHT_SIZE_0_G0);
  auto var_g1 = m.state(CDMA_D_WEIGHT_SIZE_0_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDMA_D_WEIGHT_SIZE_1
void CsbWrPpsm_CDMA_D_WEIGHT_SIZE_1(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDMA_D_WEIGHT_SIZE_1");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CDMA_D_WEIGHT_SIZE_1_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDMA_D_WEIGHT_SIZE_1_G0);
  auto var_g1 = m.state(CDMA_D_WEIGHT_SIZE_1_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDMA_D_WEIGHT_RAM_TYPE
void CsbWrPpsm_CDMA_D_WEIGHT_RAM_TYPE(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDMA_D_WEIGHT_RAM_TYPE");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == CDMA_D_WEIGHT_RAM_TYPE_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDMA_D_WEIGHT_RAM_TYPE_G0);
  auto var_g1 = m.state(CDMA_D_WEIGHT_RAM_TYPE_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDMA_D_WEIGHT_ADDR_HIGH
void CsbWrPpsm_CDMA_D_WEIGHT_ADDR_HIGH(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDMA_D_WEIGHT_ADDR_HIGH");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == CDMA_D_WEIGHT_ADDR_HIGH_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDMA_D_WEIGHT_ADDR_HIGH_G0);
  auto var_g1 = m.state(CDMA_D_WEIGHT_ADDR_HIGH_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDMA_D_WEIGHT_ADDR_LOW
void CsbWrPpsm_CDMA_D_WEIGHT_ADDR_LOW(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDMA_D_WEIGHT_ADDR_LOW");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == CDMA_D_WEIGHT_ADDR_LOW_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDMA_D_WEIGHT_ADDR_LOW_G0);
  auto var_g1 = m.state(CDMA_D_WEIGHT_ADDR_LOW_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDMA_D_WEIGHT_BYTES
void CsbWrPpsm_CDMA_D_WEIGHT_BYTES(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDMA_D_WEIGHT_BYTES");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CDMA_D_WEIGHT_BYTES_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDMA_D_WEIGHT_BYTES_G0);
  auto var_g1 = m.state(CDMA_D_WEIGHT_BYTES_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDMA_D_WGS_ADDR_HIGH
void CsbWrPpsm_CDMA_D_WGS_ADDR_HIGH(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDMA_D_WGS_ADDR_HIGH");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CDMA_D_WGS_ADDR_HIGH_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDMA_D_WGS_ADDR_HIGH_G0);
  auto var_g1 = m.state(CDMA_D_WGS_ADDR_HIGH_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDMA_D_WGS_ADDR_LOW
void CsbWrPpsm_CDMA_D_WGS_ADDR_LOW(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDMA_D_WGS_ADDR_LOW");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CDMA_D_WGS_ADDR_LOW_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDMA_D_WGS_ADDR_LOW_G0);
  auto var_g1 = m.state(CDMA_D_WGS_ADDR_LOW_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDMA_D_WMB_ADDR_HIGH
void CsbWrPpsm_CDMA_D_WMB_ADDR_HIGH(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDMA_D_WMB_ADDR_HIGH");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CDMA_D_WMB_ADDR_HIGH_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDMA_D_WMB_ADDR_HIGH_G0);
  auto var_g1 = m.state(CDMA_D_WMB_ADDR_HIGH_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDMA_D_WMB_ADDR_LOW
void CsbWrPpsm_CDMA_D_WMB_ADDR_LOW(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDMA_D_WMB_ADDR_LOW");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CDMA_D_WMB_ADDR_LOW_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDMA_D_WMB_ADDR_LOW_G0);
  auto var_g1 = m.state(CDMA_D_WMB_ADDR_LOW_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDMA_D_WMB_BYTES
void CsbWrPpsm_CDMA_D_WMB_BYTES(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDMA_D_WMB_BYTES");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CDMA_D_WMB_BYTES_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDMA_D_WMB_BYTES_G0);
  auto var_g1 = m.state(CDMA_D_WMB_BYTES_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDMA_D_MEAN_FORMAT
void CsbWrPpsm_CDMA_D_MEAN_FORMAT(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDMA_D_MEAN_FORMAT");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CDMA_D_MEAN_FORMAT_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDMA_D_MEAN_FORMAT_G0);
  auto var_g1 = m.state(CDMA_D_MEAN_FORMAT_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDMA_D_MEAN_GLOBAL_0
void CsbWrPpsm_CDMA_D_MEAN_GLOBAL_0(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDMA_D_MEAN_GLOBAL_0");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CDMA_D_MEAN_GLOBAL_0_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDMA_D_MEAN_GLOBAL_0_G0);
  auto var_g1 = m.state(CDMA_D_MEAN_GLOBAL_0_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDMA_D_MEAN_GLOBAL_1
void CsbWrPpsm_CDMA_D_MEAN_GLOBAL_1(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDMA_D_MEAN_GLOBAL_1");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CDMA_D_MEAN_GLOBAL_1_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDMA_D_MEAN_GLOBAL_1_G0);
  auto var_g1 = m.state(CDMA_D_MEAN_GLOBAL_1_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDMA_D_CVT_CFG
void CsbWrPpsm_CDMA_D_CVT_CFG(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDMA_D_CVT_CFG");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CDMA_D_CVT_CFG_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDMA_D_CVT_CFG_G0);
  auto var_g1 = m.state(CDMA_D_CVT_CFG_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDMA_D_CVT_OFFSET
void CsbWrPpsm_CDMA_D_CVT_OFFSET(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDMA_D_CVT_OFFSET");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CDMA_D_CVT_OFFSET_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDMA_D_CVT_OFFSET_G0);
  auto var_g1 = m.state(CDMA_D_CVT_OFFSET_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDMA_D_CVT_SCALE
void CsbWrPpsm_CDMA_D_CVT_SCALE(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDMA_D_CVT_SCALE");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CDMA_D_CVT_SCALE_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDMA_D_CVT_SCALE_G0);
  auto var_g1 = m.state(CDMA_D_CVT_SCALE_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDMA_D_CONV_STRIDE
void CsbWrPpsm_CDMA_D_CONV_STRIDE(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDMA_D_CONV_STRIDE");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CDMA_D_CONV_STRIDE_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDMA_D_CONV_STRIDE_G0);
  auto var_g1 = m.state(CDMA_D_CONV_STRIDE_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDMA_D_ZERO_PADDING
void CsbWrPpsm_CDMA_D_ZERO_PADDING(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDMA_D_ZERO_PADDING");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CDMA_D_ZERO_PADDING_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDMA_D_ZERO_PADDING_G0);
  auto var_g1 = m.state(CDMA_D_ZERO_PADDING_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDMA_D_ZERO_PADDING_VALUE
void CsbWrPpsm_CDMA_D_ZERO_PADDING_VALUE(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDMA_D_ZERO_PADDING_VALUE");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == CDMA_D_ZERO_PADDING_VALUE_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDMA_D_ZERO_PADDING_VALUE_G0);
  auto var_g1 = m.state(CDMA_D_ZERO_PADDING_VALUE_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDMA_D_BANK
void CsbWrPpsm_CDMA_D_BANK(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDMA_D_BANK");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CDMA_D_BANK_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDMA_D_BANK_G0);
  auto var_g1 = m.state(CDMA_D_BANK_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDMA_D_NAN_FLUSH_TO_ZERO
void CsbWrPpsm_CDMA_D_NAN_FLUSH_TO_ZERO(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDMA_D_NAN_FLUSH_TO_ZERO");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == CDMA_D_NAN_FLUSH_TO_ZERO_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDMA_D_NAN_FLUSH_TO_ZERO_G0);
  auto var_g1 = m.state(CDMA_D_NAN_FLUSH_TO_ZERO_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDMA_D_NAN_INPUT_DATA_NUM
void CsbWrPpsm_CDMA_D_NAN_INPUT_DATA_NUM(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDMA_D_NAN_INPUT_DATA_NUM");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == CDMA_D_NAN_INPUT_DATA_NUM_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDMA_D_NAN_INPUT_DATA_NUM_G0);
  auto var_g1 = m.state(CDMA_D_NAN_INPUT_DATA_NUM_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDMA_D_NAN_INPUT_WEIGHT_NUM
void CsbWrPpsm_CDMA_D_NAN_INPUT_WEIGHT_NUM(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDMA_D_NAN_INPUT_WEIGHT_NUM");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == CDMA_D_NAN_INPUT_WEIGHT_NUM_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDMA_D_NAN_INPUT_WEIGHT_NUM_G0);
  auto var_g1 = m.state(CDMA_D_NAN_INPUT_WEIGHT_NUM_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDMA_D_INF_INPUT_DATA_NUM
void CsbWrPpsm_CDMA_D_INF_INPUT_DATA_NUM(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDMA_D_INF_INPUT_DATA_NUM");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == CDMA_D_INF_INPUT_DATA_NUM_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDMA_D_INF_INPUT_DATA_NUM_G0);
  auto var_g1 = m.state(CDMA_D_INF_INPUT_DATA_NUM_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDMA_D_INF_INPUT_WEIGHT_NUM
void CsbWrPpsm_CDMA_D_INF_INPUT_WEIGHT_NUM(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDMA_D_INF_INPUT_WEIGHT_NUM");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == CDMA_D_INF_INPUT_WEIGHT_NUM_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDMA_D_INF_INPUT_WEIGHT_NUM_G0);
  auto var_g1 = m.state(CDMA_D_INF_INPUT_WEIGHT_NUM_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDMA_D_PERF_ENABLE
void CsbWrPpsm_CDMA_D_PERF_ENABLE(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDMA_D_PERF_ENABLE");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CDMA_D_PERF_ENABLE_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDMA_D_PERF_ENABLE_G0);
  auto var_g1 = m.state(CDMA_D_PERF_ENABLE_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDMA_D_PERF_DAT_READ_STALL
void CsbWrPpsm_CDMA_D_PERF_DAT_READ_STALL(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDMA_D_PERF_DAT_READ_STALL");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == CDMA_D_PERF_DAT_READ_STALL_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDMA_D_PERF_DAT_READ_STALL_G0);
  auto var_g1 = m.state(CDMA_D_PERF_DAT_READ_STALL_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDMA_D_PERF_WT_READ_STALL
void CsbWrPpsm_CDMA_D_PERF_WT_READ_STALL(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDMA_D_PERF_WT_READ_STALL");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == CDMA_D_PERF_WT_READ_STALL_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDMA_D_PERF_WT_READ_STALL_G0);
  auto var_g1 = m.state(CDMA_D_PERF_WT_READ_STALL_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDMA_D_PERF_DAT_READ_LATENCY
void CsbWrPpsm_CDMA_D_PERF_DAT_READ_LATENCY(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDMA_D_PERF_DAT_READ_LATENCY");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == CDMA_D_PERF_DAT_READ_LATENCY_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDMA_D_PERF_DAT_READ_LATENCY_G0);
  auto var_g1 = m.state(CDMA_D_PERF_DAT_READ_LATENCY_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDMA_D_PERF_WT_READ_LATENCY
void CsbWrPpsm_CDMA_D_PERF_WT_READ_LATENCY(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDMA_D_PERF_WT_READ_LATENCY");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == CDMA_D_PERF_WT_READ_LATENCY_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDMA_D_PERF_WT_READ_LATENCY_G0);
  auto var_g1 = m.state(CDMA_D_PERF_WT_READ_LATENCY_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

}; // namespace ilang
