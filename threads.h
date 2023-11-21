#include "threads.h"

void row_thread() {
  while (1) {
    BSP_LCD_Clear(LCD_COLOR_BLACK);
    BSP_LCD_SetFont(&LCD_DEFAULT_FONT);
    BSP_LCD_SetBackColor(LCD_COLOR_WHITE);

    BSP_LCD_DisplayStringAt(0, 1, (uint8_t *)"VITEJ", CENTER_MODE);
    HAL_Delay(2000);
  }
}

void lcd_thread(DigitalOut *led) {
  while (1) {
    *led = !*led;
    ThisThread::sleep_for(500ms);
  }
}
void button_press(InterruptIn *btn) {
  while (1) {
    if (btn->read()) {
      BSP_LCD_Clear(LCD_COLOR_BLACK);
      BSP_LCD_SetFont(&LCD_DEFAULT_FONT);
      BSP_LCD_SetBackColor(LCD_COLOR_WHITE);

      BSP_LCD_DisplayStringAt(0, 1, (uint8_t *)"NEMACKEJ MNE", CENTER_MODE);
    }
  }
}
