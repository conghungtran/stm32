.syntax unified
.cpu cortex-m3
.thumb

.global _start
.global main

.section .isr_vector
.word _estack
.word _start  /* + 1 THUMB bit required for Cortex-M3 reset vector */

.section .text
_start:
    bl main
loop:
    b loop
