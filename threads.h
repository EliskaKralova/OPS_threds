#include "mbed.h"
#include "stm32746g_discovery_lcd.h"

void led_thread(DigitalOut *led);
void button_check(InterruptIn *btn);
void lcd_thread();
