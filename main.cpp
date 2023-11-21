#include "threads.h"

void init();
void exit();

InterruptIn btn1(BUTTON1);
DigitalOut led(LED1);

Thread thread1;
Thread thread2;
Thread thread3;

int main()
{
    init();

    thread1.start(lcd_thread);
    thread2.start(callback(led_thread, &led));
    thread3.start(callback(button_check, &btn1));

    exit();
}

void init(){
    BSP_LCD_Init();
    BSP_LCD_LayerDefaultInit(LTDC_ACTIVE_LAYER, LCD_FB_START_ADDRESS);
    BSP_LCD_SelectLayer(LTDC_ACTIVE_LAYER);
}
void exit(){}
