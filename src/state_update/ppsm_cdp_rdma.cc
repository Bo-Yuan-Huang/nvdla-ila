// ============================================================================
// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)
//
// This ILA description is derived based on the NVDLA specification and design,
// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".
// Check "LICENSE" which comes with this distribution for more information.
// ============================================================================

// File Name: ppsm_cdp_rdma.cc

#include <ilang/ilang++.h>
#include <nvdla/configs/modeling_config.h>
#include <nvdla/configs/state_info.h>
#include <nvdla/utils.h>

// namespace ilang
namespace ilang {

// CDP_RDMA_D_OP_ENABLE
void CsbWrPpsm_CDP_RDMA_D_OP_ENABLE(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDP_RDMA_D_OP_ENABLE");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode = is_wr & (m.input(CSB2NVDLA_ADDR) == CDP_RDMA_D_OP_ENABLE_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer =
      Extract(m.state(CDP_RDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
              ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDP_RDMA_D_OP_ENABLE_G0);
  auto var_g1 = m.state(CDP_RDMA_D_OP_ENABLE_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDP_RDMA_D_DATA_CUBE_WIDTH
void CsbWrPpsm_CDP_RDMA_D_DATA_CUBE_WIDTH(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDP_RDMA_D_DATA_CUBE_WIDTH");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == CDP_RDMA_D_DATA_CUBE_WIDTH_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer =
      Extract(m.state(CDP_RDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
              ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDP_RDMA_D_DATA_CUBE_WIDTH_G0);
  auto var_g1 = m.state(CDP_RDMA_D_DATA_CUBE_WIDTH_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDP_RDMA_D_DATA_CUBE_HEIGHT
void CsbWrPpsm_CDP_RDMA_D_DATA_CUBE_HEIGHT(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDP_RDMA_D_DATA_CUBE_HEIGHT");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == CDP_RDMA_D_DATA_CUBE_HEIGHT_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer =
      Extract(m.state(CDP_RDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
              ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDP_RDMA_D_DATA_CUBE_HEIGHT_G0);
  auto var_g1 = m.state(CDP_RDMA_D_DATA_CUBE_HEIGHT_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDP_RDMA_D_DATA_CUBE_CHANNEL
void CsbWrPpsm_CDP_RDMA_D_DATA_CUBE_CHANNEL(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDP_RDMA_D_DATA_CUBE_CHANNEL");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == CDP_RDMA_D_DATA_CUBE_CHANNEL_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer =
      Extract(m.state(CDP_RDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
              ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDP_RDMA_D_DATA_CUBE_CHANNEL_G0);
  auto var_g1 = m.state(CDP_RDMA_D_DATA_CUBE_CHANNEL_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDP_RDMA_D_SRC_BASE_ADDR_LOW
void CsbWrPpsm_CDP_RDMA_D_SRC_BASE_ADDR_LOW(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDP_RDMA_D_SRC_BASE_ADDR_LOW");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == CDP_RDMA_D_SRC_BASE_ADDR_LOW_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer =
      Extract(m.state(CDP_RDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
              ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDP_RDMA_D_SRC_BASE_ADDR_LOW_G0);
  auto var_g1 = m.state(CDP_RDMA_D_SRC_BASE_ADDR_LOW_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDP_RDMA_D_SRC_BASE_ADDR_HIGH
void CsbWrPpsm_CDP_RDMA_D_SRC_BASE_ADDR_HIGH(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDP_RDMA_D_SRC_BASE_ADDR_HIGH");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == CDP_RDMA_D_SRC_BASE_ADDR_HIGH_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer =
      Extract(m.state(CDP_RDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
              ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDP_RDMA_D_SRC_BASE_ADDR_HIGH_G0);
  auto var_g1 = m.state(CDP_RDMA_D_SRC_BASE_ADDR_HIGH_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDP_RDMA_D_SRC_LINE_STRIDE
void CsbWrPpsm_CDP_RDMA_D_SRC_LINE_STRIDE(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDP_RDMA_D_SRC_LINE_STRIDE");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == CDP_RDMA_D_SRC_LINE_STRIDE_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer =
      Extract(m.state(CDP_RDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
              ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDP_RDMA_D_SRC_LINE_STRIDE_G0);
  auto var_g1 = m.state(CDP_RDMA_D_SRC_LINE_STRIDE_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDP_RDMA_D_SRC_SURFACE_STRIDE
void CsbWrPpsm_CDP_RDMA_D_SRC_SURFACE_STRIDE(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDP_RDMA_D_SRC_SURFACE_STRIDE");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == CDP_RDMA_D_SRC_SURFACE_STRIDE_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer =
      Extract(m.state(CDP_RDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
              ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDP_RDMA_D_SRC_SURFACE_STRIDE_G0);
  auto var_g1 = m.state(CDP_RDMA_D_SRC_SURFACE_STRIDE_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDP_RDMA_D_SRC_DMA_CFG
void CsbWrPpsm_CDP_RDMA_D_SRC_DMA_CFG(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDP_RDMA_D_SRC_DMA_CFG");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == CDP_RDMA_D_SRC_DMA_CFG_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer =
      Extract(m.state(CDP_RDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
              ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDP_RDMA_D_SRC_DMA_CFG_G0);
  auto var_g1 = m.state(CDP_RDMA_D_SRC_DMA_CFG_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDP_RDMA_D_SRC_COMPRESSION_EN
void CsbWrPpsm_CDP_RDMA_D_SRC_COMPRESSION_EN(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDP_RDMA_D_SRC_COMPRESSION_EN");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == CDP_RDMA_D_SRC_COMPRESSION_EN_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer =
      Extract(m.state(CDP_RDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
              ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDP_RDMA_D_SRC_COMPRESSION_EN_G0);
  auto var_g1 = m.state(CDP_RDMA_D_SRC_COMPRESSION_EN_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDP_RDMA_D_OPERATION_MODE
void CsbWrPpsm_CDP_RDMA_D_OPERATION_MODE(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDP_RDMA_D_OPERATION_MODE");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == CDP_RDMA_D_OPERATION_MODE_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer =
      Extract(m.state(CDP_RDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
              ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDP_RDMA_D_OPERATION_MODE_G0);
  auto var_g1 = m.state(CDP_RDMA_D_OPERATION_MODE_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDP_RDMA_D_DATA_FORMAT
void CsbWrPpsm_CDP_RDMA_D_DATA_FORMAT(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDP_RDMA_D_DATA_FORMAT");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == CDP_RDMA_D_DATA_FORMAT_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer =
      Extract(m.state(CDP_RDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
              ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDP_RDMA_D_DATA_FORMAT_G0);
  auto var_g1 = m.state(CDP_RDMA_D_DATA_FORMAT_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDP_RDMA_D_PERF_ENABLE
void CsbWrPpsm_CDP_RDMA_D_PERF_ENABLE(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDP_RDMA_D_PERF_ENABLE");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == CDP_RDMA_D_PERF_ENABLE_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer =
      Extract(m.state(CDP_RDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
              ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDP_RDMA_D_PERF_ENABLE_G0);
  auto var_g1 = m.state(CDP_RDMA_D_PERF_ENABLE_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

// CDP_RDMA_D_PERF_READ_STALL
void CsbWrPpsm_CDP_RDMA_D_PERF_READ_STALL(Ila& m) {
  auto instr = m.NewInstr("CsbWr_CDP_RDMA_D_PERF_READ_STALL");

  // decode
  auto is_wr = m.input(CSB2NVDLA_WRITE) == BoolVal(CSB2NVDLA_WRITE_WRITE);
  auto decode =
      is_wr & (m.input(CSB2NVDLA_ADDR) == CDP_RDMA_D_PERF_READ_STALL_ADDR);
  instr.SetDecode(decode);

  // updates
  auto producer =
      Extract(m.state(CDP_RDMA_S_POINTER), ICFG_PPSM_PTR_PRODUCER_END,
              ICFG_PPSM_PTR_PRODUCER_BEGIN);

  auto g0_is_idle = Extract(m.state(CDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G0_END,
                            ICFG_PPSM_STATUS_G0_BEGIN);
  auto g1_is_idle = Extract(m.state(CDP_RDMA_S_STATUS), ICFG_PPSM_STATUS_G1_END,
                            ICFG_PPSM_STATUS_G1_BEGIN);

  auto write_to_g0 = (producer == 0) & (g0_is_idle == ICFG_PPSM_STATUS_IDLE);
  auto write_to_g1 = (producer == 1) & (g1_is_idle == ICFG_PPSM_STATUS_IDLE);

  auto var_g0 = m.state(CDP_RDMA_D_PERF_READ_STALL_G0);
  auto var_g1 = m.state(CDP_RDMA_D_PERF_READ_STALL_G1);

  auto g0_next = Ite(write_to_g0, m.input(CSB2NVDLA_WDAT), var_g0);
  auto g1_next = Ite(write_to_g1, m.input(CSB2NVDLA_WDAT), var_g1);

  instr.SetUpdate(var_g0, g0_next);
  instr.SetUpdate(var_g1, g1_next);

  return;
}

}; // namespace ilang
