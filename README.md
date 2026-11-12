# lx-gpu-rtl

RTL implementation of the **LX-GPU** — a programmable 2D graphics coprocessor for the Z80.

This repository is the hardware side. The architecture is documented in the [XiAleste / Aleste LX documentation](https://hww.github.io/aleste-xi-doc/docs/gpu/docs/01_architecture.html). RTL follows that specification.

## What it is

A small, programmable 2D raster engine for MSX-class machines. The CPU says "draw at (x, y)"; the GPU handles address computation, pixel packing, and memory traffic.

**Architecture at a glance** (see the documentation for the full specification):

- **32-bit instruction**, four classes selected by `J`/`I` bits:
  - **reg-reg** (`J=0, I=0`): `d = d op s`, `SRC[5:0]` in bits [12:7]
  - **reg-imm12** (`J=1, I=1`): `d = d op imm12`, with sign/zero extend
  - **`LDI24`** (`J=0, I=1`): `R[DST] = imm24`, unconditional, flags untouched
  - **control** (`J=1, I=0`): `JMP`/`CALL`/`RET`/`JMPR`/`HALT`/`IRQ` with 12-bit `ADDR`
- **ARM-style conditions** (4 bits): `AL`, `EQ`, `NE`, `CS`, `CC`, `MI`, `PL`, `VS`, `VC`, `HI`, `LS`, `GE`, `LT`, `GT`, `LE`.
- **Flags** `Z N C V`, written only when `F=1` (`CMP`/`TST` always write).
- **ALU** (5 bits): `MOV`, `AND`, `OR`, `XOR`, `ANDN`, `ADD`, `SUB`, `CMP`, `TST`, `ROR`, `SHR`, `SAR`, `MUL`, `MULH` (the last two are DSP-backed, multi-cycle in RTL).
- **SHADOW** register — return address + flags. `CALL` writes it; `RET` uses only PC; `JMPR` for indirect return.
- **LOOP** register — `[23:12]` count, `[11:0]` target. The `L` bit drives it.
- **Three ports**: `SRC`, `DST`, `STM` (read-only stream). Each port exposes `.IDX`, `.PIX`, `.W16`, `.STEP`, `.MODE`, `.PAGE`. Source advances on read; destination on write.
- **Pixel formats**: 1, 4, 8, 16 bpp; pass-through `LO8`/`HI8`/`PASS16`. 1 bpp is source-only.
- **Loader**: packets with 16-bit headers `{kind[15:12], arg[11:0]}` — `END`, `ENDI`, `CODE`, `RUN`, `JUMP`.
- **No hardware scrolling, no page flip, no colour LUT, no combiner.** By design.

## Status

**Pre-alpha.** The behavioural C++ model validates the instruction set against 12 tests (fill, sprite copy, 8/1 bpp, affine, paging, pass-through, MMIO, ALU logic). RTL is being written against that model.

Target validation: a demo frame — **320×200 @ 4 bpp, 240 tiles of 16×16 + 64 sprites of 16×16 with colour-key transparency** — rendered within a 60 fps budget at 18 MHz. This is the success criterion before handing the design to the Z80 BIOS and RTL integration.

## Repository layout
