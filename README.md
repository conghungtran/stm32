# STM32F103C6T6 Bare-Metal LED Blink

A minimal bare-metal project for the STM32F103C6T6 (Blue Pill) that blinks an LED on **PA0** — no HAL, no CMSIS, no external libraries.

## Features

- Direct register manipulation (no HAL)
- Custom startup file and linker script
- Flash via ST-Link using `st-flash`

## Project Structure

```
stm32/
├── main.c        # Main application (GPIO + LED logic)
├── startup.s     # Minimal startup assembly (vector table + reset handler)
├── linker.ld     # Linker script for STM32F103C6T6
└── Makefile      # Build system
```

## Hardware

| Item        | Value            |
|-------------|------------------|
| MCU         | STM32F103C6T6    |
| Core        | ARM Cortex-M3    |
| LED Pin     | PA0              |
| Programmer  | ST-Link v2       |

## Prerequisites

- `arm-none-eabi-gcc` toolchain
- `st-flash` (from [stlink](https://github.com/stlink-org/stlink))

```bash
# Debian/Ubuntu
sudo apt install gcc-arm-none-eabi binutils-arm-none-eabi stlink-tools
```

## Build & Flash

```bash
# Build
make

# Flash to MCU
make flash

# Erase flash
make erase

# Clean build artifacts
make clean
```

## Memory Map (STM32F103C6T6)

| Region | Start        | Size  |
|--------|--------------|-------|
| Flash  | `0x08000000` | 32 KB |
| SRAM   | `0x20000000` | 10 KB |
