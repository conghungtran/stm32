#define RCC_APB2ENR (*(volatile unsigned int*)0x40021018)

#define GPIOA_CRL   (*(volatile unsigned int*)0x40010800)
#define GPIOA_ODR   (*(volatile unsigned int*)0x4001080C)


int main(void)
{
    // Enable clock
    RCC_APB2ENR |= (1 << 2);

    GPIOA_CRL &= ~(0xF << 0);
    GPIOA_CRL |=  (0x2 << 0);


    GPIOA_ODR |= (1 << 0);

    while(1)
    {
        // GPIOA_ODR ^= (1 << 0);   // đảo trạng thái LED
        //
        // for(int i=0;i<500000;i++); // delay
    }
}
