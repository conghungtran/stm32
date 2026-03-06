.syntax unified
.cpu cortex-m3
.thumb

.global _start
.global main

.section .isr_vector
.word _estack
.word _start

.section .text
_start:
    bl main
loop:
    b loop
