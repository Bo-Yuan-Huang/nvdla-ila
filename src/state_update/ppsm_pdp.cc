// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: ppsm_pdp.cc

#include <ilang/ilang++.h>
#include <nvdla/configs/modeling_config.h>
#include <nvdla/configs/state_info.h>
#include <nvdla/utils.h>

// namespace ilang
namespace ilang {

// PDP_D_OP_ENABLE
void CsbWrPpsm_PDP_D_OP_ENABLE(Ila& m) {
  auto instr = m.NewInstr("CsbWr_PDP_D_OP_ENABLE");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == PDP_D_OP_ENABLE_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(PDP_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(PDP_D_OP_ENABLE_G0);
  auto var_g1 = m.state(PDP_D_OP_ENABLE_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// PDP_D_DATA_CUBE_IN_WIDTH
void CsbWrPpsm_PDP_D_DATA_CUBE_IN_WIDTH(Ila& m) {
  auto instr = m.NewInstr("CsbWr_PDP_D_DATA_CUBE_IN_WIDTH");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == PDP_D_DATA_CUBE_IN_WIDTH_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(PDP_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(PDP_D_DATA_CUBE_IN_WIDTH_G0);
  auto var_g1 = m.state(PDP_D_DATA_CUBE_IN_WIDTH_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// PDP_D_DATA_CUBE_IN_HEIGHT
void CsbWrPpsm_PDP_D_DATA_CUBE_IN_HEIGHT(Ila& m) {
  auto instr = m.NewInstr("CsbWr_PDP_D_DATA_CUBE_IN_HEIGHT");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == PDP_D_DATA_CUBE_IN_HEIGHT_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(PDP_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(PDP_D_DATA_CUBE_IN_HEIGHT_G0);
  auto var_g1 = m.state(PDP_D_DATA_CUBE_IN_HEIGHT_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// PDP_D_DATA_CUBE_IN_CHANNEL
void CsbWrPpsm_PDP_D_DATA_CUBE_IN_CHANNEL(Ila& m) {
  auto instr = m.NewInstr("CsbWr_PDP_D_DATA_CUBE_IN_CHANNEL");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == PDP_D_DATA_CUBE_IN_CHANNEL_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(PDP_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(PDP_D_DATA_CUBE_IN_CHANNEL_G0);
  auto var_g1 = m.state(PDP_D_DATA_CUBE_IN_CHANNEL_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// PDP_D_DATA_CUBE_OUT_WIDTH
void CsbWrPpsm_PDP_D_DATA_CUBE_OUT_WIDTH(Ila& m) {
  auto instr = m.NewInstr("CsbWr_PDP_D_DATA_CUBE_OUT_WIDTH");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == PDP_D_DATA_CUBE_OUT_WIDTH_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(PDP_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(PDP_D_DATA_CUBE_OUT_WIDTH_G0);
  auto var_g1 = m.state(PDP_D_DATA_CUBE_OUT_WIDTH_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// PDP_D_DATA_CUBE_OUT_HEIGHT
void CsbWrPpsm_PDP_D_DATA_CUBE_OUT_HEIGHT(Ila& m) {
  auto instr = m.NewInstr("CsbWr_PDP_D_DATA_CUBE_OUT_HEIGHT");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == PDP_D_DATA_CUBE_OUT_HEIGHT_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(PDP_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(PDP_D_DATA_CUBE_OUT_HEIGHT_G0);
  auto var_g1 = m.state(PDP_D_DATA_CUBE_OUT_HEIGHT_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// PDP_D_DATA_CUBE_OUT_CHANNEL
void CsbWrPpsm_PDP_D_DATA_CUBE_OUT_CHANNEL(Ila& m) {
  auto instr = m.NewInstr("CsbWr_PDP_D_DATA_CUBE_OUT_CHANNEL");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == PDP_D_DATA_CUBE_OUT_CHANNEL_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(PDP_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(PDP_D_DATA_CUBE_OUT_CHANNEL_G0);
  auto var_g1 = m.state(PDP_D_DATA_CUBE_OUT_CHANNEL_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// PDP_D_OPERATION_MODE_CFG
void CsbWrPpsm_PDP_D_OPERATION_MODE_CFG(Ila& m) {
  auto instr = m.NewInstr("CsbWr_PDP_D_OPERATION_MODE_CFG");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == PDP_D_OPERATION_MODE_CFG_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(PDP_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(PDP_D_OPERATION_MODE_CFG_G0);
  auto var_g1 = m.state(PDP_D_OPERATION_MODE_CFG_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// PDP_D_NAN_FLUSH_TO_ZERO
void CsbWrPpsm_PDP_D_NAN_FLUSH_TO_ZERO(Ila& m) {
  auto instr = m.NewInstr("CsbWr_PDP_D_NAN_FLUSH_TO_ZERO");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == PDP_D_NAN_FLUSH_TO_ZERO_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(PDP_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(PDP_D_NAN_FLUSH_TO_ZERO_G0);
  auto var_g1 = m.state(PDP_D_NAN_FLUSH_TO_ZERO_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// PDP_D_PARTIAL_WIDTH_IN
void CsbWrPpsm_PDP_D_PARTIAL_WIDTH_IN(Ila& m) {
  auto instr = m.NewInstr("CsbWr_PDP_D_PARTIAL_WIDTH_IN");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == PDP_D_PARTIAL_WIDTH_IN_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(PDP_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(PDP_D_PARTIAL_WIDTH_IN_G0);
  auto var_g1 = m.state(PDP_D_PARTIAL_WIDTH_IN_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// PDP_D_PARTIAL_WIDTH_OUT
void CsbWrPpsm_PDP_D_PARTIAL_WIDTH_OUT(Ila& m) {
  auto instr = m.NewInstr("CsbWr_PDP_D_PARTIAL_WIDTH_OUT");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == PDP_D_PARTIAL_WIDTH_OUT_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(PDP_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(PDP_D_PARTIAL_WIDTH_OUT_G0);
  auto var_g1 = m.state(PDP_D_PARTIAL_WIDTH_OUT_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// PDP_D_POOLING_KERNEL_CFG
void CsbWrPpsm_PDP_D_POOLING_KERNEL_CFG(Ila& m) {
  auto instr = m.NewInstr("CsbWr_PDP_D_POOLING_KERNEL_CFG");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == PDP_D_POOLING_KERNEL_CFG_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(PDP_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(PDP_D_POOLING_KERNEL_CFG_G0);
  auto var_g1 = m.state(PDP_D_POOLING_KERNEL_CFG_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// PDP_D_RECIP_KERNEL_WIDTH
void CsbWrPpsm_PDP_D_RECIP_KERNEL_WIDTH(Ila& m) {
  auto instr = m.NewInstr("CsbWr_PDP_D_RECIP_KERNEL_WIDTH");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == PDP_D_RECIP_KERNEL_WIDTH_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(PDP_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(PDP_D_RECIP_KERNEL_WIDTH_G0);
  auto var_g1 = m.state(PDP_D_RECIP_KERNEL_WIDTH_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// PDP_D_RECIP_KERNEL_HEIGHT
void CsbWrPpsm_PDP_D_RECIP_KERNEL_HEIGHT(Ila& m) {
  auto instr = m.NewInstr("CsbWr_PDP_D_RECIP_KERNEL_HEIGHT");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == PDP_D_RECIP_KERNEL_HEIGHT_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(PDP_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(PDP_D_RECIP_KERNEL_HEIGHT_G0);
  auto var_g1 = m.state(PDP_D_RECIP_KERNEL_HEIGHT_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// PDP_D_POOLING_PADDING_CFG
void CsbWrPpsm_PDP_D_POOLING_PADDING_CFG(Ila& m) {
  auto instr = m.NewInstr("CsbWr_PDP_D_POOLING_PADDING_CFG");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == PDP_D_POOLING_PADDING_CFG_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(PDP_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(PDP_D_POOLING_PADDING_CFG_G0);
  auto var_g1 = m.state(PDP_D_POOLING_PADDING_CFG_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// PDP_D_POOLING_PADDING_VALUE_1_CFG
void CsbWrPpsm_PDP_D_POOLING_PADDING_VALUE_1_CFG(Ila& m) {
  auto instr = m.NewInstr("CsbWr_PDP_D_POOLING_PADDING_VALUE_1_CFG");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) ==
                         PDP_D_POOLING_PADDING_VALUE_1_CFG_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(PDP_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(PDP_D_POOLING_PADDING_VALUE_1_CFG_G0);
  auto var_g1 = m.state(PDP_D_POOLING_PADDING_VALUE_1_CFG_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// PDP_D_POOLING_PADDING_VALUE_2_CFG
void CsbWrPpsm_PDP_D_POOLING_PADDING_VALUE_2_CFG(Ila& m) {
  auto instr = m.NewInstr("CsbWr_PDP_D_POOLING_PADDING_VALUE_2_CFG");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) ==
                         PDP_D_POOLING_PADDING_VALUE_2_CFG_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(PDP_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(PDP_D_POOLING_PADDING_VALUE_2_CFG_G0);
  auto var_g1 = m.state(PDP_D_POOLING_PADDING_VALUE_2_CFG_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// PDP_D_POOLING_PADDING_VALUE_3_CFG
void CsbWrPpsm_PDP_D_POOLING_PADDING_VALUE_3_CFG(Ila& m) {
  auto instr = m.NewInstr("CsbWr_PDP_D_POOLING_PADDING_VALUE_3_CFG");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) ==
                         PDP_D_POOLING_PADDING_VALUE_3_CFG_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(PDP_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(PDP_D_POOLING_PADDING_VALUE_3_CFG_G0);
  auto var_g1 = m.state(PDP_D_POOLING_PADDING_VALUE_3_CFG_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// PDP_D_POOLING_PADDING_VALUE_4_CFG
void CsbWrPpsm_PDP_D_POOLING_PADDING_VALUE_4_CFG(Ila& m) {
  auto instr = m.NewInstr("CsbWr_PDP_D_POOLING_PADDING_VALUE_4_CFG");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) ==
                         PDP_D_POOLING_PADDING_VALUE_4_CFG_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(PDP_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(PDP_D_POOLING_PADDING_VALUE_4_CFG_G0);
  auto var_g1 = m.state(PDP_D_POOLING_PADDING_VALUE_4_CFG_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// PDP_D_POOLING_PADDING_VALUE_5_CFG
void CsbWrPpsm_PDP_D_POOLING_PADDING_VALUE_5_CFG(Ila& m) {
  auto instr = m.NewInstr("CsbWr_PDP_D_POOLING_PADDING_VALUE_5_CFG");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) ==
                         PDP_D_POOLING_PADDING_VALUE_5_CFG_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(PDP_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(PDP_D_POOLING_PADDING_VALUE_5_CFG_G0);
  auto var_g1 = m.state(PDP_D_POOLING_PADDING_VALUE_5_CFG_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// PDP_D_POOLING_PADDING_VALUE_6_CFG
void CsbWrPpsm_PDP_D_POOLING_PADDING_VALUE_6_CFG(Ila& m) {
  auto instr = m.NewInstr("CsbWr_PDP_D_POOLING_PADDING_VALUE_6_CFG");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) ==
                         PDP_D_POOLING_PADDING_VALUE_6_CFG_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(PDP_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(PDP_D_POOLING_PADDING_VALUE_6_CFG_G0);
  auto var_g1 = m.state(PDP_D_POOLING_PADDING_VALUE_6_CFG_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// PDP_D_POOLING_PADDING_VALUE_7_CFG
void CsbWrPpsm_PDP_D_POOLING_PADDING_VALUE_7_CFG(Ila& m) {
  auto instr = m.NewInstr("CsbWr_PDP_D_POOLING_PADDING_VALUE_7_CFG");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) ==
                         PDP_D_POOLING_PADDING_VALUE_7_CFG_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(PDP_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(PDP_D_POOLING_PADDING_VALUE_7_CFG_G0);
  auto var_g1 = m.state(PDP_D_POOLING_PADDING_VALUE_7_CFG_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// PDP_D_SRC_BASE_ADDR_LOW
void CsbWrPpsm_PDP_D_SRC_BASE_ADDR_LOW(Ila& m) {
  auto instr = m.NewInstr("CsbWr_PDP_D_SRC_BASE_ADDR_LOW");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == PDP_D_SRC_BASE_ADDR_LOW_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(PDP_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(PDP_D_SRC_BASE_ADDR_LOW_G0);
  auto var_g1 = m.state(PDP_D_SRC_BASE_ADDR_LOW_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// PDP_D_SRC_BASE_ADDR_HIGH
void CsbWrPpsm_PDP_D_SRC_BASE_ADDR_HIGH(Ila& m) {
  auto instr = m.NewInstr("CsbWr_PDP_D_SRC_BASE_ADDR_HIGH");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == PDP_D_SRC_BASE_ADDR_HIGH_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(PDP_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(PDP_D_SRC_BASE_ADDR_HIGH_G0);
  auto var_g1 = m.state(PDP_D_SRC_BASE_ADDR_HIGH_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// PDP_D_SRC_LINE_STRIDE
void CsbWrPpsm_PDP_D_SRC_LINE_STRIDE(Ila& m) {
  auto instr = m.NewInstr("CsbWr_PDP_D_SRC_LINE_STRIDE");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == PDP_D_SRC_LINE_STRIDE_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(PDP_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(PDP_D_SRC_LINE_STRIDE_G0);
  auto var_g1 = m.state(PDP_D_SRC_LINE_STRIDE_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// PDP_D_SRC_SURFACE_STRIDE
void CsbWrPpsm_PDP_D_SRC_SURFACE_STRIDE(Ila& m) {
  auto instr = m.NewInstr("CsbWr_PDP_D_SRC_SURFACE_STRIDE");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == PDP_D_SRC_SURFACE_STRIDE_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(PDP_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(PDP_D_SRC_SURFACE_STRIDE_G0);
  auto var_g1 = m.state(PDP_D_SRC_SURFACE_STRIDE_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// PDP_D_DST_BASE_ADDR_LOW
void CsbWrPpsm_PDP_D_DST_BASE_ADDR_LOW(Ila& m) {
  auto instr = m.NewInstr("CsbWr_PDP_D_DST_BASE_ADDR_LOW");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == PDP_D_DST_BASE_ADDR_LOW_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(PDP_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(PDP_D_DST_BASE_ADDR_LOW_G0);
  auto var_g1 = m.state(PDP_D_DST_BASE_ADDR_LOW_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// PDP_D_DST_BASE_ADDR_HIGH
void CsbWrPpsm_PDP_D_DST_BASE_ADDR_HIGH(Ila& m) {
  auto instr = m.NewInstr("CsbWr_PDP_D_DST_BASE_ADDR_HIGH");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == PDP_D_DST_BASE_ADDR_HIGH_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(PDP_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(PDP_D_DST_BASE_ADDR_HIGH_G0);
  auto var_g1 = m.state(PDP_D_DST_BASE_ADDR_HIGH_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// PDP_D_DST_LINE_STRIDE
void CsbWrPpsm_PDP_D_DST_LINE_STRIDE(Ila& m) {
  auto instr = m.NewInstr("CsbWr_PDP_D_DST_LINE_STRIDE");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == PDP_D_DST_LINE_STRIDE_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(PDP_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(PDP_D_DST_LINE_STRIDE_G0);
  auto var_g1 = m.state(PDP_D_DST_LINE_STRIDE_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// PDP_D_DST_SURFACE_STRIDE
void CsbWrPpsm_PDP_D_DST_SURFACE_STRIDE(Ila& m) {
  auto instr = m.NewInstr("CsbWr_PDP_D_DST_SURFACE_STRIDE");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == PDP_D_DST_SURFACE_STRIDE_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(PDP_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(PDP_D_DST_SURFACE_STRIDE_G0);
  auto var_g1 = m.state(PDP_D_DST_SURFACE_STRIDE_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// PDP_D_DST_RAM_CFG
void CsbWrPpsm_PDP_D_DST_RAM_CFG(Ila& m) {
  auto instr = m.NewInstr("CsbWr_PDP_D_DST_RAM_CFG");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == PDP_D_DST_RAM_CFG_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(PDP_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(PDP_D_DST_RAM_CFG_G0);
  auto var_g1 = m.state(PDP_D_DST_RAM_CFG_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// PDP_D_DATA_FORMAT
void CsbWrPpsm_PDP_D_DATA_FORMAT(Ila& m) {
  auto instr = m.NewInstr("CsbWr_PDP_D_DATA_FORMAT");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == PDP_D_DATA_FORMAT_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(PDP_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(PDP_D_DATA_FORMAT_G0);
  auto var_g1 = m.state(PDP_D_DATA_FORMAT_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// PDP_D_INF_INPUT_NUM
void CsbWrPpsm_PDP_D_INF_INPUT_NUM(Ila& m) {
  auto instr = m.NewInstr("CsbWr_PDP_D_INF_INPUT_NUM");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == PDP_D_INF_INPUT_NUM_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(PDP_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(PDP_D_INF_INPUT_NUM_G0);
  auto var_g1 = m.state(PDP_D_INF_INPUT_NUM_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// PDP_D_NAN_INPUT_NUM
void CsbWrPpsm_PDP_D_NAN_INPUT_NUM(Ila& m) {
  auto instr = m.NewInstr("CsbWr_PDP_D_NAN_INPUT_NUM");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == PDP_D_NAN_INPUT_NUM_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(PDP_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(PDP_D_NAN_INPUT_NUM_G0);
  auto var_g1 = m.state(PDP_D_NAN_INPUT_NUM_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// PDP_D_NAN_OUTPUT_NUM
void CsbWrPpsm_PDP_D_NAN_OUTPUT_NUM(Ila& m) {
  auto instr = m.NewInstr("CsbWr_PDP_D_NAN_OUTPUT_NUM");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == PDP_D_NAN_OUTPUT_NUM_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(PDP_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(PDP_D_NAN_OUTPUT_NUM_G0);
  auto var_g1 = m.state(PDP_D_NAN_OUTPUT_NUM_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// PDP_D_PERF_ENABLE
void CsbWrPpsm_PDP_D_PERF_ENABLE(Ila& m) {
  auto instr = m.NewInstr("CsbWr_PDP_D_PERF_ENABLE");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == PDP_D_PERF_ENABLE_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(PDP_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(PDP_D_PERF_ENABLE_G0);
  auto var_g1 = m.state(PDP_D_PERF_ENABLE_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// PDP_D_PERF_WRITE_STALL
void CsbWrPpsm_PDP_D_PERF_WRITE_STALL(Ila& m) {
  auto instr = m.NewInstr("CsbWr_PDP_D_PERF_WRITE_STALL");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == PDP_D_PERF_WRITE_STALL_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(PDP_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(PDP_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(PDP_D_PERF_WRITE_STALL_G0);
  auto var_g1 = m.state(PDP_D_PERF_WRITE_STALL_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

}; // namespace ilang
