# lx-gpu-rtl

RTL implementation of the **LX-GPU** — a programmable stack-based 2D graphics coprocessor for the Z80.

This repository is the hardware side of the project. The behavioural model (C++ simulator) lives in [lx-gpu](../lx-gpu) and is the reference for the architecture. RTL follows the validated model, not the other way around.

## What it is

A small, programmable 2D raster engine intended for MSX-class machines. The CPU says "draw at (x, y)"; the GPU handles address arithmetic, pixel packing, and memory traffic.

- **Stack machine (A/B/C)** with push/pop, no separate accumulator/operand pair.
- **36-bit microcode** — one micro-word per cycle slot (fields: `REG_OP` 5, `ALU_OP` 5, `CTRL_OP` 3, `REG_ADDR` 5, `MASK` 3, `COND` 3, `IMM` 12).
- **Four logical pixel channels** — SOURCE, DEST, DATA, RSV — sharing one word-level pixel buffer.
- **Four pixel formats** — 1, 4, 8, 16 bpp (1 bpp is source-only in practice, but supported).
- **Address generator with embedded DSP** — `x`/`y` coordinates in, `addr24` + pixel position out. Multiplication lives here, not in the ALU.
- **No hardware scrolling, no page flip, no colour LUT, no combiner.** Those are software concerns by design.

The design goal is **simplicity over peak speed**. Memory is the bottleneck; the core is kept small.

## Status

**Pre-alpha.** The C++ behavioural model passes 12 tests (fill, sprite copy, 8 bpp, affine, paging, pass-through, 1 bpp, MMIO, ALU logic). The RTL is being written against that model.

Target validation (planned): a full demo frame — **320×200 @ 4 bpp, 240 tiles of 16×16 + 64 sprites of 16×16 with colour-key transparency** — rendered in **≤ 300 000 GPU cycles** at 18 MHz (60 fps).

## Repository layout
