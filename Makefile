CC      = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy

MCU     = cortex-m3

CFLAGS  = -mcpu=$(MCU) -mthumb -O0 -g -Wall
LDFLAGS = -T linker.ld -nostdlib -mcpu=$(MCU) -mthumb

TARGET  = main

C_SRCS  = main.c
ASM_SRCS = startup.s

C_OBJS   = $(C_SRCS:.c=.o)
ASM_OBJS = $(ASM_SRCS:.s=.o)
OBJS     = $(C_OBJS) $(ASM_OBJS)

all: $(TARGET).bin

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.s
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET).elf: $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@

$(TARGET).bin: $(TARGET).elf
	$(OBJCOPY) -O binary $< $@

flash: $(TARGET).bin
	st-flash write $(TARGET).bin 0x08000000

erase:
	st-flash erase

clean:
	rm -f *.o *.elf *.bin

.PHONY: all flash erase clean
