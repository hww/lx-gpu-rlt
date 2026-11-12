#!/usr/bin/env bash
set -e
TOP="${1:-tb_regfile}"
mkdir -p build
verilator --binary --timing -j 1 -Wno-fatal -Wno-TIMESCALEMOD \
    --top-module "$TOP" \
    -Mdir build/"$TOP" \
    rtl/*.sv tb/"$TOP".sv
./build/"$TOP"/V"$TOP"