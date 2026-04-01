#define RCC_APB2ENR (*(volatile unsigned int*)0x40021018)
#define GPIOA_CRL   (*(volatile unsigned int*)0x40010800)
#define GPIOA_ODR   (*(volatile unsigned int*)0x4001080C)

#define GPIOA_IDR   (*(volatile unsigned int*)0x40010808)

#define GPIOB_CRL   (*(volatile unsigned int*)0x40010c00)
#define GPIOB_ODR   (*(volatile unsigned int*)0x40010c0C)

#define GPIOB_IDR   (*(volatile unsigned int*)0x40010c08)

void set_mode_led(int n) {
    GPIOA_CRL &= ~(0xF << n);
    GPIOA_CRL |=  (0x2 << n);
}

void delay() {
    for (int i = 0; i < 500000; i++) {
            // Delay
    }
}

void mode1() {
    GPIOA_ODR &= ~(1 << 0);
    delay();
    GPIOA_ODR &= ~(1 << 1);
    delay();
    GPIOA_ODR &= ~(1 << 2);
    delay();
    GPIOA_ODR &= ~(1 << 3);
    delay(); 
}

void mode2() {
    GPIOA_ODR ^= (1 << 3);
    delay();
    GPIOA_ODR ^= (1 << 2);
    delay();
    GPIOA_ODR ^= (1 << 1);
    delay();
    GPIOA_ODR ^= (1 << 0);
    delay(); 
}

void turn_all_off() {
    GPIOA_ODR |= (0 << 0);
    GPIOA_ODR |= (0 << 1);
    GPIOA_ODR |= (0 << 2);
    GPIOA_ODR |= (0 << 3);
}

void test() {
    GPIOA_ODR ^= (1 << 0);
    delay();
}

int main(void)
{
    // Enable clock
    RCC_APB2ENR |= (1 << 2);
    RCC_APB2ENR |= (1 << 3); 

    set_mode_led(0);
    set_mode_led(4);
    set_mode_led(8);
    set_mode_led(12);

    GPIOB_CRL &= ~(0xF << 0);
    GPIOB_CRL |=  (0x8 << 0);
    GPIOB_ODR |= (1 << 0);

    volatile int mode = 1;

    while(1)
    {    
        if (!GPIOB_IDR & (1 << 0)){
            if (mode == 0) {
                mode = 1;
            } else {
                mode = 0;
            }
        }

        test();

        if (mode == 1) {
            test();
        } else {
            turn_all_off();
        }
    }
}
