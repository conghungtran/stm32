#define RCC_APB2ENR (*(volatile unsigned int*)0x40021018)
#define GPIOA_CRL   (*(volatile unsigned int*)0x40010800)
#define GPIOA_ODR   (*(volatile unsigned int*)0x4001080C)
#define GPIOA_IDR   (*(volatile unsigned int*)0x40010808)

// SysTick registers (Cortex-M core peripheral, address is fixed on all Cortex-M MCUs)
#define SYSTICK_CTRL (*(volatile unsigned int*)0xE000E010)
#define SYSTICK_LOAD (*(volatile unsigned int*)0xE000E014)
#define SYSTICK_VAL  (*(volatile unsigned int*)0xE000E018)

// Assumes 8 MHz HSI/HSE with no PLL. Adjust SYSCLK_HZ if you configure the PLL.
#define SYSCLK_HZ    8000000UL

volatile unsigned int ms_ticks = 0;

// SysTick interrupt handler — name must match your vector table entry
void SysTick_Handler(void)
{
    ms_ticks++;
}

void systick_init(void)
{
    SYSTICK_LOAD = (SYSCLK_HZ / 1000) - 1;   // reload value for 1ms tick
    SYSTICK_VAL  = 0;                        // clear current value
    SYSTICK_CTRL = (1 << 2) | (1 << 1) | (1 << 0);
    // bit0 ENABLE, bit1 TICKINT (interrupt on countdown to 0), bit2 CLKSOURCE (processor clock)
}

void delay_ms(unsigned int ms)
{
    unsigned int start = ms_ticks;
    while ((ms_ticks - start) < ms)
    {
        __asm volatile ("wfi"); // sleep until next interrupt, saves power
    }
}

int main(void)
{
    RCC_APB2ENR |= (1 << 2);      // enable GPIOA clock
    GPIOA_CRL &= ~(0xF << 0);
    GPIOA_CRL |=  (0x2 << 0);     // PA0 as output, 2MHz push-pull
    GPIOA_ODR |= (1 << 0);

    systick_init();

    while(1)
    {
        GPIOA_ODR ^= (1 << 0);
        delay_ms(500);
    }
}
