#include <LPC21XX.H>
#include "lcd_rcount.h"
#include "uart_rcount.h"
#include "led_rcount.h"

#define SW1 16
#define SW2 17

unsigned int count=0;
int main ()
{
	MAIN_CONFIG();
	LED_INIT();
	LCD_INIT();
	LCD_COMMAND(0X84);
	LCD_STR("V24CE9M2");
	LCD_COMMAND(0XC0);
	LCD_STR("ROOM ENTRY COUNT ");
	delay_millisecond(700);
	LCD_INIT();
	
	while(1)
	{
		LCD_COMMAND(0X80);
    LCD_STR("TOTAL COUNT:");
		delay_millisecond(0);
		if(((IOPIN1>>SW1)&1)==0)
		{
			IOSET1 = LED1;
			LCD_COMMAND(0X01);
			++count;
			LCD_COMMAND(0X80);
			LCD_STR("PERSON ENTERED");
			LCD_COMMAND(0XC0);
			LCD_STR("TOTAL COUNT:");
			LCD_INT(count);
			delay_millisecond(1000);
			LCD_COMMAND(0X01);
			IOCLR1 = LED1;
		}
		else if(((IOPIN1>>SW2)&1)==0)
		{
			IOSET1 = LED2;
			LCD_COMMAND(0X01);
			--count;
			LCD_COMMAND(0X80);
			LCD_STR("PERSON EXITED");
			LCD_COMMAND(0XC0);
			LCD_STR("TOTAL COUNT:");
			LCD_INT(count);
			delay_millisecond(1000);
			LCD_COMMAND(0X01);
			IOCLR1 = LED2;
		}
	LCD_COMMAND(0X80);
  LCD_STR("TOTAL COUNT:");
	LCD_INT(count);
	}
}
