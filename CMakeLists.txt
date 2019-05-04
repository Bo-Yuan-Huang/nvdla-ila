cmake_minimum_required(VERSION 3.8)

# ---------------------------------------------------------------------------- #
# PROJECT
# name version language
# ---------------------------------------------------------------------------- #
project(NvdlaIla VERSION 1.0 LANGUAGES CXX)

# ---------------------------------------------------------------------------- #
# VARIABLE
# alias and configurations
# ---------------------------------------------------------------------------- #
set(MyTarget ${PROJECT_NAME})

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

# ---------------------------------------------------------------------------- #
# External dependencies
# ---------------------------------------------------------------------------- #
##
## ilang
##
find_package(ilang REQUIRED)


# ---------------------------------------------------------------------------- #
# TARGET
# executable
# ---------------------------------------------------------------------------- #
add_executable(${MyTarget} 
  app/main.cc

  src/conv_pipe.cc
  src/nvdla_top.cc
  src/utils.cc

  src/state_define/state_define_bdma.cc
  src/state_define/state_define_cacc.cc
  src/state_define/state_define_cdma.cc
  src/state_define/state_define_cdp.cc
  src/state_define/state_define_cdp_rdma.cc
  src/state_define/state_define_cmac_a.cc
  src/state_define/state_define_cmac_b.cc
  src/state_define/state_define_csb.cc
  src/state_define/state_define_csc.cc
  src/state_define/state_define_glb.cc
  src/state_define/state_define_mcif.cc
  src/state_define/state_define_pdp.cc
  src/state_define/state_define_pdp_rdma.cc
  src/state_define/state_define_rubik.cc
  src/state_define/state_define_sdp.cc
  src/state_define/state_define_sdp_rdma.cc
  src/state_define/state_define_sramif.cc

  src/state_init/state_init_bdma.cc
  src/state_init/state_init_cacc.cc
  src/state_init/state_init_cdma.cc
  src/state_init/state_init_cdp.cc
  src/state_init/state_init_cdp_rdma.cc
  src/state_init/state_init_cmac_a.cc
  src/state_init/state_init_cmac_b.cc
  src/state_init/state_init_csb.cc
  src/state_init/state_init_csc.cc
  src/state_init/state_init_glb.cc
  src/state_init/state_init_mcif.cc
  src/state_init/state_init_pdp.cc
  src/state_init/state_init_pdp_rdma.cc
  src/state_init/state_init_rubik.cc
  src/state_init/state_init_sdp.cc
  src/state_init/state_init_sdp_rdma.cc
  src/state_init/state_init_sramif.cc

  src/state_update/ppsm_bdma.cc
  src/state_update/ppsm_cacc.cc
  src/state_update/ppsm_cdma.cc
  src/state_update/ppsm_cdp.cc
  src/state_update/ppsm_cdp_rdma.cc
  src/state_update/ppsm_cmac_a.cc
  src/state_update/ppsm_cmac_b.cc
  src/state_update/ppsm_csc.cc
  src/state_update/ppsm_glb.cc
  src/state_update/ppsm_mcif.cc
  src/state_update/ppsm_pdp.cc
  src/state_update/ppsm_pdp_rdma.cc
  src/state_update/ppsm_rubik.cc
  src/state_update/ppsm_sdp.cc
  src/state_update/ppsm_sdp_rdma.cc
  src/state_update/ppsm_sramif.cc

)

target_include_directories(${MyTarget} PRIVATE include)

target_link_libraries(${MyTarget} ilang::ilang)

