#!/usr/bin/bash

GEN_PY=scripts/gen_state_info.py
SRC_DIR=data
DST_DIR=include/nvdla/configs

F () {
  more $SRC_DIR/license_header.h.in > $DST_DIR/state_info_$1.h
  python3 $GEN_PY $SRC_DIR/spec_$1.txt $DST_DIR/state_info_$1.h $1 --append True
  clang-format-6.0 -i $DST_DIR/state_info_$1.h
}

F bdma
F cacc
F cdma
F cdp
F cdp_rdma
F cmac_a
F cmac_b
F csc
F glb
F mcif
F pdp
F pdp_rdma
F rubik
F sdp
F sdp_rdma
F sramif
