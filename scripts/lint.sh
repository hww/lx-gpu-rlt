#!/usr/bin/env bash
set -e
FILES="${@:-rtl/*.sv tb/*.sv}"
verilator --lint-only -Wall --top-module "$(basename "${1:-tb_top}" .sv)" $FILES