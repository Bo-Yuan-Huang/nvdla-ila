#!/usr/bin/bash

CONVERT_PY=scripts/parse_addr_space.py
SRC_DIR=data
DST_DIR=include/nvdla/configs

F () {
  python3 $CONVERT_PY $SRC_DIR/addr_$1.txt $DST_DIR/addr_$1.h --prefix $1 
  clang-format -i $DST_DIR/addr_$1.h
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
