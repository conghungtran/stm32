#define RCC_APB2ENR (*(volatile unsigned int*)0x40021018)

#define GPIOA_CRL   (*(volatile unsigned int*)0x40010800)
#define GPIOA_ODR   (*(volatile unsigned int*)0x4001080C)

#define GPIOA_IDR   (*(volatile unsigned int*)0x40010808)
int main(void)
{
    // Enable clock
    RCC_APB2ENR |= (1 << 2);

    GPIOA_CRL &= ~(0xF << 0);
    GPIOA_CRL |=  (0x2 << 0);

    GPIOA_CRL &= ~(0xF << 8);
    GPIOA_CRL |=  (0x8 << 8);


    GPIOA_ODR |= (1 << 2);

    while(1)
    {
        if (GPIOA_IDR & (1 << 2)) {
            GPIOA_ODR |= (1 << 0);
        } else {
            GPIOA_ODR &= ~(1 << 0);
        }

    }
}
