#!/usr/bin/bash

GEN_PY=scripts/gen_state_init.py
SRC_DIR=data
DST_DIR=src/state_init

F () {
  TARGET=$DST_DIR/state_init_$1.cc
  more $SRC_DIR/license_header.h.in > $TARGET
  python3 $GEN_PY $1 $SRC_DIR/spec_$1.txt $DST_DIR --append True
  clang-format-6.0 -i $TARGET
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
