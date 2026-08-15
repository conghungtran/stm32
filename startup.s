// startup.s
.syntax unified
.cpu cortex-m3
.thumb

.global _start
.global main

/* ---- Vector table ---- */
.section .isr_vector, "a"
.word _estack              /* 0: initial SP */
.word _start                /* 1: Reset handler (thumb bit added automatically for .thumb_func) */
.word Default_Handler       /* 2: NMI */
.word Default_Handler       /* 3: HardFault */
.word Default_Handler       /* 4: MemManage */
.word Default_Handler       /* 5: BusFault */
.word Default_Handler       /* 6: UsageFault */
.word 0                     /* 7: Reserved */
.word 0                     /* 8: Reserved */
.word 0                     /* 9: Reserved */
.word 0                     /* 10: Reserved */
.word Default_Handler       /* 11: SVC */
.word Default_Handler       /* 12: DebugMon */
.word 0                     /* 13: Reserved */
.word Default_Handler       /* 14: PendSV */
.word SysTick_Handler       /* 15: SysTick  <-- this is the one we need */

.section .text
.thumb_func
_start:
    /* Copy .data from FLASH to RAM */
    ldr r0, =_etext
    ldr r1, =_sdata
    ldr r2, =_edata
copy_data:
    cmp r1, r2
    bhs copy_data_done
    ldr r3, [r0], #4
    str r3, [r1], #4
    b copy_data
copy_data_done:

    /* Zero .bss */
    ldr r1, =_sbss
    ldr r2, =_ebss
    movs r3, #0
zero_bss:
    cmp r1, r2
    bhs zero_bss_done
    str r3, [r1], #4
    add r1, r1, #4
    b zero_bss
zero_bss_done:

    bl main
loop:
    b loop

.thumb_func
Default_Handler:
    b Default_Handler   /* trap here on any unhandled exception, easy to catch in debugger */
