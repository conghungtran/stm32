Lập trình **STM32F103** theo kiểu **bare-metal** (không dùng HAL/RTOS, thao tác trực tiếp thanh ghi) là cách rất tốt để hiểu sâu vi điều khiển. Dưới đây là **lộ trình bài tập từ dễ → khó**, phù hợp cho người mới đến mức khá.

---

# 1️⃣ Mức cơ bản – Làm quen thanh ghi

Mục tiêu: hiểu **GPIO, clock, thanh ghi**.

### Bài 1: Blink LED

* Bật/tắt LED tại 1 chân GPIO.
* Không dùng thư viện.
* Tự cấu hình:

  * RCC enable clock GPIO
  * Cấu hình GPIO Output
  * Toggle pin

Nâng cấp:

* Nháy LED với delay khác nhau.

---

### Bài 2: Nút nhấn điều khiển LED

* 1 button → bật/tắt LED.
* Cấu hình:

  * GPIO input
  * Pull-up / pull-down

Nâng cấp:

* Chống dội nút (debounce bằng delay).

---

### Bài 3: Chạy LED kiểu hiệu ứng

Ví dụ:

```
LED1 -> LED2 -> LED3 -> LED4
```

Hoặc:

```
1010
0101
```

Mục tiêu:

* làm quen nhiều GPIO.

---

# 2️⃣ Mức trung bình – Timer & Interrupt

Mục tiêu: hiểu **timer + interrupt**

---

### Bài 4: Delay bằng Timer

Không dùng vòng for.

* cấu hình **TIM2**
* tạo delay 1ms.

Nâng cấp:

* viết hàm:

```
delay_ms(1000);
```

---

### Bài 5: Blink LED bằng Interrupt

* Timer interrupt mỗi 500ms.
* LED toggle trong ISR.

Hiểu:

* NVIC
* Interrupt handler.

---

### Bài 6: Button interrupt

* Button nhấn → LED đổi trạng thái.
* dùng EXTI interrupt.

Hiểu:

* **EXTI**

---

# 3️⃣ Mức khá – Peripheral

Mục tiêu: giao tiếp ngoại vi.

---

### Bài 7: UART cơ bản

Dùng **USART1**

* gửi chuỗi:

```
Hello STM32
```

hiển thị trên Serial Terminal.

Nâng cấp:

* gửi giá trị số.

---

### Bài 8: UART echo

* PC gửi ký tự
* MCU trả lại ký tự đó.

Hiểu:

* RX
* TX
* polling.

---

### Bài 9: UART interrupt

* nhận dữ liệu bằng interrupt.
* lưu vào buffer.

---

# 4️⃣ Mức nâng cao – Analog & PWM

---

### Bài 10: Đọc ADC

Dùng **ADC1**

* đọc biến trở
* gửi giá trị qua UART.

---

### Bài 11: PWM điều khiển LED

* dùng **TIM3**
* thay đổi độ sáng LED.

Nâng cấp:

* fade LED.

---

### Bài 12: PWM điều khiển Servo

* tạo PWM 50Hz.
* thay đổi góc servo.

---

# 5️⃣ Mức khó – Communication

---

### Bài 13: I2C đọc cảm biến

Dùng **I2C1**

ví dụ cảm biến:

* **MPU6050**

đọc:

* gia tốc
* gyro.

---

### Bài 14: SPI đọc module

Dùng **SPI1**

ví dụ:

* **W25Q64**

---

# 6️⃣ Mức rất khó – System level

---

### Bài 15: Viết driver delay chuẩn SysTick

Sử dụng **SysTick**

Tạo:

```
millis()
micros()
delay_ms()
```

---

### Bài 16: Ring buffer UART

Tạo driver UART với:

```
uart_write()
uart_read()
```

sử dụng:

* interrupt
* circular buffer.

---

### Bài 17: Mini scheduler

Tự viết task scheduler:

```
task1 10ms
task2 100ms
task3 1s
```

Không dùng RTOS.

---

# 📈 Nếu luyện hết các bài này bạn sẽ hiểu sâu

* GPIO
* Clock system
* Interrupt
* Timer
* UART
* ADC
* PWM
* I2C
* SPI
* Driver architecture

→ Đây chính là nền tảng để viết **driver hoặc RTOS cho STM32**.

---

✅ Nếu bạn muốn, tôi có thể:

* thiết kế **30 bài tập STM32F103 bare-metal chuẩn như khóa học Embedded**
* hoặc tạo **roadmap 60 ngày luyện STM32 cực nhanh từ beginner → embedded engineer**.

