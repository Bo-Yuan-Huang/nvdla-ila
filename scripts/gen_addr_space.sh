#!/usr/bin/bash

GEN_PY=scripts/gen_addr_space.py
SRC_DIR=data
DST_DIR=include/nvdla/configs

F () {
  python3 $GEN_PY $SRC_DIR/addr_$1.txt $DST_DIR/addr_$1.h $1 
  clang-format-6.0 -i $DST_DIR/addr_$1.h
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
