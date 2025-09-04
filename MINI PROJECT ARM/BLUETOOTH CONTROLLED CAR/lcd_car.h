#include <lpc21xx.h>

#define LCD_D 0XFF<<6
#define RS 1<<14
#define E 1<<15

	void LCD_INIT(void); //LCD INITITATION FUNCTION DECLARATION
	void LCD_COMMAND(unsigned char cmd);
	void LCD_DATA(unsigned char d);
	void LCD_STR(unsigned char*); //STRING FUNCTION DECLARATION
	void delay_millisecond(unsigned int MS); //DELAY PROGRAM DECLARATION

void delay_millisecond(unsigned int MS) //DELAY FUNCTION CALL
{
	T0PR = 15000-1;
	T0TCR = 0X01;
	while(T0TC<MS);
	T0TCR = 0X03;
	T0TCR = 0X00;
}
void LCD_INIT(void) //LCD INITITATION FUNCTION CALL
{
	IODIR0 |= LCD_D|RS|E;
	LCD_COMMAND(0X01);
	LCD_COMMAND(0X02);
	LCD_COMMAND(0X0C);
	LCD_COMMAND(0X38);
}
void LCD_COMMAND(unsigned char cmd)
{
	IOPIN0 = cmd<<6;
	IOCLR0 = RS;
	IOSET0 = E;
	delay_millisecond(2);
	IOCLR0 = E;
}
void LCD_DATA(unsigned char d)
{
	IOPIN0 = d<<6;
	IOSET0 = RS;
	IOSET0 = E;
	delay_millisecond(2);
	IOCLR0 = E;
}
void LCD_STR(unsigned char *s) //LCD STRING FUNCTION CALL
{
	while(*s)
		LCD_DATA(*s++);
}
