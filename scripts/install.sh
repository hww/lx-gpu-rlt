#!/usr/bin/env bash
set -e

echo "=== LX-GPU RTL toolchain install (Ubuntu) ==="

sudo apt-get update
sudo apt-get install -y \
    verilator \
    yosys \
    gtkwave \
    build-essential \
    git

echo
echo "=== versions ==="
verilator --version
yosys -V
gtkwave --version 2>/dev/null | head -1 || true

echo
echo "=== done ==="