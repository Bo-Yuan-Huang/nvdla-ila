// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: ppsm_csc.cc

#include <ilang/ilang++.h>
#include <nvdla/configs/modeling_config.h>
#include <nvdla/configs/state_info.h>
#include <nvdla/utils.h>

// namespace ilang
namespace ilang {

// CSC_D_OP_ENABLE
void CsbWrPpsm_CSC_D_OP_ENABLE(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CSC_D_OP_ENABLE");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CSC_D_OP_ENABLE_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CSC_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CSC_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CSC_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CSC_D_OP_ENABLE_G0);
  auto var_g1 = m.state(CSC_D_OP_ENABLE_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CSC_D_MISC_CFG
void CsbWrPpsm_CSC_D_MISC_CFG(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CSC_D_MISC_CFG");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CSC_D_MISC_CFG_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CSC_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CSC_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CSC_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CSC_D_MISC_CFG_G0);
  auto var_g1 = m.state(CSC_D_MISC_CFG_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CSC_D_DATAIN_FORMAT
void CsbWrPpsm_CSC_D_DATAIN_FORMAT(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CSC_D_DATAIN_FORMAT");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CSC_D_DATAIN_FORMAT_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CSC_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CSC_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CSC_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CSC_D_DATAIN_FORMAT_G0);
  auto var_g1 = m.state(CSC_D_DATAIN_FORMAT_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CSC_D_DATAIN_SIZE_EXT_0
void CsbWrPpsm_CSC_D_DATAIN_SIZE_EXT_0(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CSC_D_DATAIN_SIZE_EXT_0");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == CSC_D_DATAIN_SIZE_EXT_0_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CSC_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CSC_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CSC_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CSC_D_DATAIN_SIZE_EXT_0_G0);
  auto var_g1 = m.state(CSC_D_DATAIN_SIZE_EXT_0_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CSC_D_DATAIN_SIZE_EXT_1
void CsbWrPpsm_CSC_D_DATAIN_SIZE_EXT_1(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CSC_D_DATAIN_SIZE_EXT_1");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == CSC_D_DATAIN_SIZE_EXT_1_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CSC_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CSC_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CSC_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CSC_D_DATAIN_SIZE_EXT_1_G0);
  auto var_g1 = m.state(CSC_D_DATAIN_SIZE_EXT_1_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CSC_D_BATCH_NUMBER
void CsbWrPpsm_CSC_D_BATCH_NUMBER(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CSC_D_BATCH_NUMBER");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CSC_D_BATCH_NUMBER_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CSC_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CSC_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CSC_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CSC_D_BATCH_NUMBER_G0);
  auto var_g1 = m.state(CSC_D_BATCH_NUMBER_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CSC_D_POST_Y_EXTENSION
void CsbWrPpsm_CSC_D_POST_Y_EXTENSION(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CSC_D_POST_Y_EXTENSION");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == CSC_D_POST_Y_EXTENSION_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CSC_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CSC_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CSC_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CSC_D_POST_Y_EXTENSION_G0);
  auto var_g1 = m.state(CSC_D_POST_Y_EXTENSION_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CSC_D_ENTRY_PER_SLICE
void CsbWrPpsm_CSC_D_ENTRY_PER_SLICE(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CSC_D_ENTRY_PER_SLICE");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CSC_D_ENTRY_PER_SLICE_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CSC_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CSC_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CSC_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CSC_D_ENTRY_PER_SLICE_G0);
  auto var_g1 = m.state(CSC_D_ENTRY_PER_SLICE_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CSC_D_WEIGHT_FORMAT
void CsbWrPpsm_CSC_D_WEIGHT_FORMAT(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CSC_D_WEIGHT_FORMAT");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CSC_D_WEIGHT_FORMAT_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CSC_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CSC_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CSC_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CSC_D_WEIGHT_FORMAT_G0);
  auto var_g1 = m.state(CSC_D_WEIGHT_FORMAT_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CSC_D_WEIGHT_SIZE_EXT_0
void CsbWrPpsm_CSC_D_WEIGHT_SIZE_EXT_0(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CSC_D_WEIGHT_SIZE_EXT_0");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == CSC_D_WEIGHT_SIZE_EXT_0_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CSC_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CSC_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CSC_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CSC_D_WEIGHT_SIZE_EXT_0_G0);
  auto var_g1 = m.state(CSC_D_WEIGHT_SIZE_EXT_0_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CSC_D_WEIGHT_SIZE_EXT_1
void CsbWrPpsm_CSC_D_WEIGHT_SIZE_EXT_1(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CSC_D_WEIGHT_SIZE_EXT_1");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == CSC_D_WEIGHT_SIZE_EXT_1_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CSC_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CSC_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CSC_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CSC_D_WEIGHT_SIZE_EXT_1_G0);
  auto var_g1 = m.state(CSC_D_WEIGHT_SIZE_EXT_1_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CSC_D_WEIGHT_BYTES
void CsbWrPpsm_CSC_D_WEIGHT_BYTES(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CSC_D_WEIGHT_BYTES");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CSC_D_WEIGHT_BYTES_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CSC_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CSC_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CSC_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CSC_D_WEIGHT_BYTES_G0);
  auto var_g1 = m.state(CSC_D_WEIGHT_BYTES_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CSC_D_WMB_BYTES
void CsbWrPpsm_CSC_D_WMB_BYTES(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CSC_D_WMB_BYTES");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CSC_D_WMB_BYTES_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CSC_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CSC_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CSC_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CSC_D_WMB_BYTES_G0);
  auto var_g1 = m.state(CSC_D_WMB_BYTES_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CSC_D_DATAOUT_SIZE_0
void CsbWrPpsm_CSC_D_DATAOUT_SIZE_0(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CSC_D_DATAOUT_SIZE_0");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CSC_D_DATAOUT_SIZE_0_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CSC_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CSC_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CSC_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CSC_D_DATAOUT_SIZE_0_G0);
  auto var_g1 = m.state(CSC_D_DATAOUT_SIZE_0_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CSC_D_DATAOUT_SIZE_1
void CsbWrPpsm_CSC_D_DATAOUT_SIZE_1(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CSC_D_DATAOUT_SIZE_1");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CSC_D_DATAOUT_SIZE_1_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CSC_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CSC_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CSC_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CSC_D_DATAOUT_SIZE_1_G0);
  auto var_g1 = m.state(CSC_D_DATAOUT_SIZE_1_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CSC_D_ATOMICS
void CsbWrPpsm_CSC_D_ATOMICS(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CSC_D_ATOMICS");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CSC_D_ATOMICS_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CSC_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CSC_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CSC_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CSC_D_ATOMICS_G0);
  auto var_g1 = m.state(CSC_D_ATOMICS_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CSC_D_RELEASE
void CsbWrPpsm_CSC_D_RELEASE(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CSC_D_RELEASE");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CSC_D_RELEASE_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CSC_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CSC_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CSC_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CSC_D_RELEASE_G0);
  auto var_g1 = m.state(CSC_D_RELEASE_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CSC_D_CONV_STRIDE_EXT
void CsbWrPpsm_CSC_D_CONV_STRIDE_EXT(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CSC_D_CONV_STRIDE_EXT");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CSC_D_CONV_STRIDE_EXT_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CSC_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CSC_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CSC_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CSC_D_CONV_STRIDE_EXT_G0);
  auto var_g1 = m.state(CSC_D_CONV_STRIDE_EXT_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CSC_D_DILATION_EXT
void CsbWrPpsm_CSC_D_DILATION_EXT(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CSC_D_DILATION_EXT");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CSC_D_DILATION_EXT_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CSC_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CSC_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CSC_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CSC_D_DILATION_EXT_G0);
  auto var_g1 = m.state(CSC_D_DILATION_EXT_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CSC_D_ZERO_PADDING
void CsbWrPpsm_CSC_D_ZERO_PADDING(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CSC_D_ZERO_PADDING");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CSC_D_ZERO_PADDING_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CSC_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CSC_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CSC_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CSC_D_ZERO_PADDING_G0);
  auto var_g1 = m.state(CSC_D_ZERO_PADDING_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CSC_D_ZERO_PADDING_VALUE
void CsbWrPpsm_CSC_D_ZERO_PADDING_VALUE(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CSC_D_ZERO_PADDING_VALUE");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == CSC_D_ZERO_PADDING_VALUE_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CSC_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CSC_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CSC_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CSC_D_ZERO_PADDING_VALUE_G0);
  auto var_g1 = m.state(CSC_D_ZERO_PADDING_VALUE_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CSC_D_BANK
void CsbWrPpsm_CSC_D_BANK(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CSC_D_BANK");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CSC_D_BANK_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CSC_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CSC_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CSC_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CSC_D_BANK_G0);
  auto var_g1 = m.state(CSC_D_BANK_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CSC_D_PRA_CFG
void CsbWrPpsm_CSC_D_PRA_CFG(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CSC_D_PRA_CFG");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CSC_D_PRA_CFG_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer = Extract(m.state(CSC_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
                          ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CSC_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CSC_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CSC_D_PRA_CFG_G0);
  auto var_g1 = m.state(CSC_D_PRA_CFG_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

}; // namespace ilang
