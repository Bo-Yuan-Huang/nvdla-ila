// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: ppsm_sdp_rdma.cc

#include <ilang/ilang++.h>
#include <nvdla/configs/modeling_config.h>
#include <nvdla/configs/state_info.h>
#include <nvdla/utils.h>

// namespace ilang
namespace ilang {

// SDP_RDMA_D_OP_ENABLE
void CsbWrPpsm_SDP_RDMA_D_OP_ENABLE(Ila& m) {
  auto instr = m.NewInstr("CsbWr_SDP_RDMA_D_OP_ENABLE");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == SDP_RDMA_D_OP_ENABLE_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer =
      Extract(m.state(SDP_RDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
              ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(SDP_RDMA_D_OP_ENABLE_G0);
  auto var_g1 = m.state(SDP_RDMA_D_OP_ENABLE_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// SDP_RDMA_D_DATA_CUBE_WIDTH
void CsbWrPpsm_SDP_RDMA_D_DATA_CUBE_WIDTH(Ila& m) {
  auto instr = m.NewInstr("CsbWr_SDP_RDMA_D_DATA_CUBE_WIDTH");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == SDP_RDMA_D_DATA_CUBE_WIDTH_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer =
      Extract(m.state(SDP_RDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
              ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(SDP_RDMA_D_DATA_CUBE_WIDTH_G0);
  auto var_g1 = m.state(SDP_RDMA_D_DATA_CUBE_WIDTH_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// SDP_RDMA_D_DATA_CUBE_HEIGHT
void CsbWrPpsm_SDP_RDMA_D_DATA_CUBE_HEIGHT(Ila& m) {
  auto instr = m.NewInstr("CsbWr_SDP_RDMA_D_DATA_CUBE_HEIGHT");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == SDP_RDMA_D_DATA_CUBE_HEIGHT_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer =
      Extract(m.state(SDP_RDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
              ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(SDP_RDMA_D_DATA_CUBE_HEIGHT_G0);
  auto var_g1 = m.state(SDP_RDMA_D_DATA_CUBE_HEIGHT_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// SDP_RDMA_D_DATA_CUBE_CHANNEL
void CsbWrPpsm_SDP_RDMA_D_DATA_CUBE_CHANNEL(Ila& m) {
  auto instr = m.NewInstr("CsbWr_SDP_RDMA_D_DATA_CUBE_CHANNEL");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == SDP_RDMA_D_DATA_CUBE_CHANNEL_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer =
      Extract(m.state(SDP_RDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
              ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(SDP_RDMA_D_DATA_CUBE_CHANNEL_G0);
  auto var_g1 = m.state(SDP_RDMA_D_DATA_CUBE_CHANNEL_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// SDP_RDMA_D_SRC_BASE_ADDR_LOW
void CsbWrPpsm_SDP_RDMA_D_SRC_BASE_ADDR_LOW(Ila& m) {
  auto instr = m.NewInstr("CsbWr_SDP_RDMA_D_SRC_BASE_ADDR_LOW");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == SDP_RDMA_D_SRC_BASE_ADDR_LOW_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer =
      Extract(m.state(SDP_RDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
              ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(SDP_RDMA_D_SRC_BASE_ADDR_LOW_G0);
  auto var_g1 = m.state(SDP_RDMA_D_SRC_BASE_ADDR_LOW_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// SDP_RDMA_D_SRC_BASE_ADDR_HIGH
void CsbWrPpsm_SDP_RDMA_D_SRC_BASE_ADDR_HIGH(Ila& m) {
  auto instr = m.NewInstr("CsbWr_SDP_RDMA_D_SRC_BASE_ADDR_HIGH");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == SDP_RDMA_D_SRC_BASE_ADDR_HIGH_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer =
      Extract(m.state(SDP_RDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
              ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(SDP_RDMA_D_SRC_BASE_ADDR_HIGH_G0);
  auto var_g1 = m.state(SDP_RDMA_D_SRC_BASE_ADDR_HIGH_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// SDP_RDMA_D_SRC_LINE_STRIDE
void CsbWrPpsm_SDP_RDMA_D_SRC_LINE_STRIDE(Ila& m) {
  auto instr = m.NewInstr("CsbWr_SDP_RDMA_D_SRC_LINE_STRIDE");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == SDP_RDMA_D_SRC_LINE_STRIDE_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer =
      Extract(m.state(SDP_RDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
              ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(SDP_RDMA_D_SRC_LINE_STRIDE_G0);
  auto var_g1 = m.state(SDP_RDMA_D_SRC_LINE_STRIDE_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// SDP_RDMA_D_SRC_SURFACE_STRIDE
void CsbWrPpsm_SDP_RDMA_D_SRC_SURFACE_STRIDE(Ila& m) {
  auto instr = m.NewInstr("CsbWr_SDP_RDMA_D_SRC_SURFACE_STRIDE");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == SDP_RDMA_D_SRC_SURFACE_STRIDE_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer =
      Extract(m.state(SDP_RDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
              ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(SDP_RDMA_D_SRC_SURFACE_STRIDE_G0);
  auto var_g1 = m.state(SDP_RDMA_D_SRC_SURFACE_STRIDE_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// SDP_RDMA_D_BRDMA_CFG
void CsbWrPpsm_SDP_RDMA_D_BRDMA_CFG(Ila& m) {
  auto instr = m.NewInstr("CsbWr_SDP_RDMA_D_BRDMA_CFG");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == SDP_RDMA_D_BRDMA_CFG_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer =
      Extract(m.state(SDP_RDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
              ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(SDP_RDMA_D_BRDMA_CFG_G0);
  auto var_g1 = m.state(SDP_RDMA_D_BRDMA_CFG_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// SDP_RDMA_D_BS_BASE_ADDR_LOW
void CsbWrPpsm_SDP_RDMA_D_BS_BASE_ADDR_LOW(Ila& m) {
  auto instr = m.NewInstr("CsbWr_SDP_RDMA_D_BS_BASE_ADDR_LOW");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == SDP_RDMA_D_BS_BASE_ADDR_LOW_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer =
      Extract(m.state(SDP_RDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
              ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(SDP_RDMA_D_BS_BASE_ADDR_LOW_G0);
  auto var_g1 = m.state(SDP_RDMA_D_BS_BASE_ADDR_LOW_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// SDP_RDMA_D_BS_BASE_ADDR_HIGH
void CsbWrPpsm_SDP_RDMA_D_BS_BASE_ADDR_HIGH(Ila& m) {
  auto instr = m.NewInstr("CsbWr_SDP_RDMA_D_BS_BASE_ADDR_HIGH");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == SDP_RDMA_D_BS_BASE_ADDR_HIGH_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer =
      Extract(m.state(SDP_RDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
              ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(SDP_RDMA_D_BS_BASE_ADDR_HIGH_G0);
  auto var_g1 = m.state(SDP_RDMA_D_BS_BASE_ADDR_HIGH_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// SDP_RDMA_D_BS_LINE_STRIDE
void CsbWrPpsm_SDP_RDMA_D_BS_LINE_STRIDE(Ila& m) {
  auto instr = m.NewInstr("CsbWr_SDP_RDMA_D_BS_LINE_STRIDE");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == SDP_RDMA_D_BS_LINE_STRIDE_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer =
      Extract(m.state(SDP_RDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
              ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(SDP_RDMA_D_BS_LINE_STRIDE_G0);
  auto var_g1 = m.state(SDP_RDMA_D_BS_LINE_STRIDE_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// SDP_RDMA_D_BS_SURFACE_STRIDE
void CsbWrPpsm_SDP_RDMA_D_BS_SURFACE_STRIDE(Ila& m) {
  auto instr = m.NewInstr("CsbWr_SDP_RDMA_D_BS_SURFACE_STRIDE");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == SDP_RDMA_D_BS_SURFACE_STRIDE_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer =
      Extract(m.state(SDP_RDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
              ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(SDP_RDMA_D_BS_SURFACE_STRIDE_G0);
  auto var_g1 = m.state(SDP_RDMA_D_BS_SURFACE_STRIDE_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// SDP_RDMA_D_BS_BATCH_STRIDE
void CsbWrPpsm_SDP_RDMA_D_BS_BATCH_STRIDE(Ila& m) {
  auto instr = m.NewInstr("CsbWr_SDP_RDMA_D_BS_BATCH_STRIDE");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == SDP_RDMA_D_BS_BATCH_STRIDE_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer =
      Extract(m.state(SDP_RDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
              ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(SDP_RDMA_D_BS_BATCH_STRIDE_G0);
  auto var_g1 = m.state(SDP_RDMA_D_BS_BATCH_STRIDE_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// SDP_RDMA_D_NRDMA_CFG
void CsbWrPpsm_SDP_RDMA_D_NRDMA_CFG(Ila& m) {
  auto instr = m.NewInstr("CsbWr_SDP_RDMA_D_NRDMA_CFG");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == SDP_RDMA_D_NRDMA_CFG_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer =
      Extract(m.state(SDP_RDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
              ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(SDP_RDMA_D_NRDMA_CFG_G0);
  auto var_g1 = m.state(SDP_RDMA_D_NRDMA_CFG_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// SDP_RDMA_D_BN_BASE_ADDR_LOW
void CsbWrPpsm_SDP_RDMA_D_BN_BASE_ADDR_LOW(Ila& m) {
  auto instr = m.NewInstr("CsbWr_SDP_RDMA_D_BN_BASE_ADDR_LOW");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == SDP_RDMA_D_BN_BASE_ADDR_LOW_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer =
      Extract(m.state(SDP_RDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
              ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(SDP_RDMA_D_BN_BASE_ADDR_LOW_G0);
  auto var_g1 = m.state(SDP_RDMA_D_BN_BASE_ADDR_LOW_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// SDP_RDMA_D_BN_BASE_ADDR_HIGH
void CsbWrPpsm_SDP_RDMA_D_BN_BASE_ADDR_HIGH(Ila& m) {
  auto instr = m.NewInstr("CsbWr_SDP_RDMA_D_BN_BASE_ADDR_HIGH");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == SDP_RDMA_D_BN_BASE_ADDR_HIGH_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer =
      Extract(m.state(SDP_RDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
              ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(SDP_RDMA_D_BN_BASE_ADDR_HIGH_G0);
  auto var_g1 = m.state(SDP_RDMA_D_BN_BASE_ADDR_HIGH_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// SDP_RDMA_D_BN_LINE_STRIDE
void CsbWrPpsm_SDP_RDMA_D_BN_LINE_STRIDE(Ila& m) {
  auto instr = m.NewInstr("CsbWr_SDP_RDMA_D_BN_LINE_STRIDE");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == SDP_RDMA_D_BN_LINE_STRIDE_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer =
      Extract(m.state(SDP_RDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
              ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(SDP_RDMA_D_BN_LINE_STRIDE_G0);
  auto var_g1 = m.state(SDP_RDMA_D_BN_LINE_STRIDE_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// SDP_RDMA_D_BN_SURFACE_STRIDE
void CsbWrPpsm_SDP_RDMA_D_BN_SURFACE_STRIDE(Ila& m) {
  auto instr = m.NewInstr("CsbWr_SDP_RDMA_D_BN_SURFACE_STRIDE");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == SDP_RDMA_D_BN_SURFACE_STRIDE_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer =
      Extract(m.state(SDP_RDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
              ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(SDP_RDMA_D_BN_SURFACE_STRIDE_G0);
  auto var_g1 = m.state(SDP_RDMA_D_BN_SURFACE_STRIDE_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// SDP_RDMA_D_BN_BATCH_STRIDE
void CsbWrPpsm_SDP_RDMA_D_BN_BATCH_STRIDE(Ila& m) {
  auto instr = m.NewInstr("CsbWr_SDP_RDMA_D_BN_BATCH_STRIDE");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == SDP_RDMA_D_BN_BATCH_STRIDE_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer =
      Extract(m.state(SDP_RDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
              ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(SDP_RDMA_D_BN_BATCH_STRIDE_G0);
  auto var_g1 = m.state(SDP_RDMA_D_BN_BATCH_STRIDE_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// SDP_RDMA_D_ERDMA_CFG
void CsbWrPpsm_SDP_RDMA_D_ERDMA_CFG(Ila& m) {
  auto instr = m.NewInstr("CsbWr_SDP_RDMA_D_ERDMA_CFG");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == SDP_RDMA_D_ERDMA_CFG_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer =
      Extract(m.state(SDP_RDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
              ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(SDP_RDMA_D_ERDMA_CFG_G0);
  auto var_g1 = m.state(SDP_RDMA_D_ERDMA_CFG_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// SDP_RDMA_D_EW_BASE_ADDR_LOW
void CsbWrPpsm_SDP_RDMA_D_EW_BASE_ADDR_LOW(Ila& m) {
  auto instr = m.NewInstr("CsbWr_SDP_RDMA_D_EW_BASE_ADDR_LOW");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == SDP_RDMA_D_EW_BASE_ADDR_LOW_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer =
      Extract(m.state(SDP_RDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
              ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(SDP_RDMA_D_EW_BASE_ADDR_LOW_G0);
  auto var_g1 = m.state(SDP_RDMA_D_EW_BASE_ADDR_LOW_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// SDP_RDMA_D_EW_BASE_ADDR_HIGH
void CsbWrPpsm_SDP_RDMA_D_EW_BASE_ADDR_HIGH(Ila& m) {
  auto instr = m.NewInstr("CsbWr_SDP_RDMA_D_EW_BASE_ADDR_HIGH");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == SDP_RDMA_D_EW_BASE_ADDR_HIGH_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer =
      Extract(m.state(SDP_RDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
              ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(SDP_RDMA_D_EW_BASE_ADDR_HIGH_G0);
  auto var_g1 = m.state(SDP_RDMA_D_EW_BASE_ADDR_HIGH_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// SDP_RDMA_D_EW_LINE_STRIDE
void CsbWrPpsm_SDP_RDMA_D_EW_LINE_STRIDE(Ila& m) {
  auto instr = m.NewInstr("CsbWr_SDP_RDMA_D_EW_LINE_STRIDE");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == SDP_RDMA_D_EW_LINE_STRIDE_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer =
      Extract(m.state(SDP_RDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
              ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(SDP_RDMA_D_EW_LINE_STRIDE_G0);
  auto var_g1 = m.state(SDP_RDMA_D_EW_LINE_STRIDE_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// SDP_RDMA_D_EW_SURFACE_STRIDE
void CsbWrPpsm_SDP_RDMA_D_EW_SURFACE_STRIDE(Ila& m) {
  auto instr = m.NewInstr("CsbWr_SDP_RDMA_D_EW_SURFACE_STRIDE");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == SDP_RDMA_D_EW_SURFACE_STRIDE_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer =
      Extract(m.state(SDP_RDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
              ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(SDP_RDMA_D_EW_SURFACE_STRIDE_G0);
  auto var_g1 = m.state(SDP_RDMA_D_EW_SURFACE_STRIDE_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// SDP_RDMA_D_EW_BATCH_STRIDE
void CsbWrPpsm_SDP_RDMA_D_EW_BATCH_STRIDE(Ila& m) {
  auto instr = m.NewInstr("CsbWr_SDP_RDMA_D_EW_BATCH_STRIDE");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == SDP_RDMA_D_EW_BATCH_STRIDE_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer =
      Extract(m.state(SDP_RDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
              ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(SDP_RDMA_D_EW_BATCH_STRIDE_G0);
  auto var_g1 = m.state(SDP_RDMA_D_EW_BATCH_STRIDE_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// SDP_RDMA_D_FEATURE_MODE_CFG
void CsbWrPpsm_SDP_RDMA_D_FEATURE_MODE_CFG(Ila& m) {
  auto instr = m.NewInstr("CsbWr_SDP_RDMA_D_FEATURE_MODE_CFG");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == SDP_RDMA_D_FEATURE_MODE_CFG_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer =
      Extract(m.state(SDP_RDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
              ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(SDP_RDMA_D_FEATURE_MODE_CFG_G0);
  auto var_g1 = m.state(SDP_RDMA_D_FEATURE_MODE_CFG_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// SDP_RDMA_D_SRC_DMA_CFG
void CsbWrPpsm_SDP_RDMA_D_SRC_DMA_CFG(Ila& m) {
  auto instr = m.NewInstr("CsbWr_SDP_RDMA_D_SRC_DMA_CFG");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == SDP_RDMA_D_SRC_DMA_CFG_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer =
      Extract(m.state(SDP_RDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
              ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(SDP_RDMA_D_SRC_DMA_CFG_G0);
  auto var_g1 = m.state(SDP_RDMA_D_SRC_DMA_CFG_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// SDP_RDMA_D_STATUS_NAN_INPUT_NUM
void CsbWrPpsm_SDP_RDMA_D_STATUS_NAN_INPUT_NUM(Ila& m) {
  auto instr = m.NewInstr("CsbWr_SDP_RDMA_D_STATUS_NAN_INPUT_NUM");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == SDP_RDMA_D_STATUS_NAN_INPUT_NUM_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer =
      Extract(m.state(SDP_RDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
              ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(SDP_RDMA_D_STATUS_NAN_INPUT_NUM_G0);
  auto var_g1 = m.state(SDP_RDMA_D_STATUS_NAN_INPUT_NUM_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// SDP_RDMA_D_STATUS_INF_INPUT_NUM
void CsbWrPpsm_SDP_RDMA_D_STATUS_INF_INPUT_NUM(Ila& m) {
  auto instr = m.NewInstr("CsbWr_SDP_RDMA_D_STATUS_INF_INPUT_NUM");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == SDP_RDMA_D_STATUS_INF_INPUT_NUM_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer =
      Extract(m.state(SDP_RDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
              ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(SDP_RDMA_D_STATUS_INF_INPUT_NUM_G0);
  auto var_g1 = m.state(SDP_RDMA_D_STATUS_INF_INPUT_NUM_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// SDP_RDMA_D_PERF_ENABLE
void CsbWrPpsm_SDP_RDMA_D_PERF_ENABLE(Ila& m) {
  auto instr = m.NewInstr("CsbWr_SDP_RDMA_D_PERF_ENABLE");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == SDP_RDMA_D_PERF_ENABLE_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer =
      Extract(m.state(SDP_RDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
              ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(SDP_RDMA_D_PERF_ENABLE_G0);
  auto var_g1 = m.state(SDP_RDMA_D_PERF_ENABLE_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// SDP_RDMA_D_PERF_MRDMA_READ_STALL
void CsbWrPpsm_SDP_RDMA_D_PERF_MRDMA_READ_STALL(Ila& m) {
  auto instr = m.NewInstr("CsbWr_SDP_RDMA_D_PERF_MRDMA_READ_STALL");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) ==
                         SDP_RDMA_D_PERF_MRDMA_READ_STALL_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer =
      Extract(m.state(SDP_RDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
              ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(SDP_RDMA_D_PERF_MRDMA_READ_STALL_G0);
  auto var_g1 = m.state(SDP_RDMA_D_PERF_MRDMA_READ_STALL_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// SDP_RDMA_D_PERF_BRDMA_READ_STALL
void CsbWrPpsm_SDP_RDMA_D_PERF_BRDMA_READ_STALL(Ila& m) {
  auto instr = m.NewInstr("CsbWr_SDP_RDMA_D_PERF_BRDMA_READ_STALL");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) ==
                         SDP_RDMA_D_PERF_BRDMA_READ_STALL_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer =
      Extract(m.state(SDP_RDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
              ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(SDP_RDMA_D_PERF_BRDMA_READ_STALL_G0);
  auto var_g1 = m.state(SDP_RDMA_D_PERF_BRDMA_READ_STALL_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// SDP_RDMA_D_PERF_NRDMA_READ_STALL
void CsbWrPpsm_SDP_RDMA_D_PERF_NRDMA_READ_STALL(Ila& m) {
  auto instr = m.NewInstr("CsbWr_SDP_RDMA_D_PERF_NRDMA_READ_STALL");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) ==
                         SDP_RDMA_D_PERF_NRDMA_READ_STALL_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer =
      Extract(m.state(SDP_RDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
              ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(SDP_RDMA_D_PERF_NRDMA_READ_STALL_G0);
  auto var_g1 = m.state(SDP_RDMA_D_PERF_NRDMA_READ_STALL_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// SDP_RDMA_D_PERF_ERDMA_READ_STALL
void CsbWrPpsm_SDP_RDMA_D_PERF_ERDMA_READ_STALL(Ila& m) {
  auto instr = m.NewInstr("CsbWr_SDP_RDMA_D_PERF_ERDMA_READ_STALL");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) ==
                         SDP_RDMA_D_PERF_ERDMA_READ_STALL_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer =
      Extract(m.state(SDP_RDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
              ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(SDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(SDP_RDMA_D_PERF_ERDMA_READ_STALL_G0);
  auto var_g1 = m.state(SDP_RDMA_D_PERF_ERDMA_READ_STALL_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

}; // namespace ilang
