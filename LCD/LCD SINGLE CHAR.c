#include <LPC21XX.H>

#define LCD_D 0XFF << 0
#define RS 1 << 8
#define E 1 << 9

void delay_millisecond(unsigned int ms);
void LCD_INIT(void);
void LCD_COMMAND(unsigned char);
void LCD_DATA(unsigned char);

int main ()
{
	LCD_INIT();
	LCD_COMMAND(0X81);
	LCD_DATA('F');
}

void delay_milliseconds(unsigned int ms)
{
	T0PR = 15000-1;
	T0TCR = 0X01;
	while(T0TC<ms);
	T0TCR = 0X03;
	T0TCR = 0X00;
}

void LCD_INIT(void)
{
	IODIR0 = LCD_D|RS|E;
	LCD_COMMAND(0X01);
	LCD_COMMAND(0X02);
	LCD_COMMAND(0X0C);
	LCD_COMMAND(0X38);
}
void LCD_COMMAND(unsigned char cmd)
{
	IOCLR0 = LCD_D;
	IOSET0 = cmd;
	IOCLR0 = RS;
	IOSET0 = E;
	delay_milliseconds(2);
	IOCLR0 = E;
}

void LCD_DATA(unsigned char d)
{
	IOCLR0 = LCD_D;
	IOSET0 = d;
	IOSET0 = RS;
	IOSET0 = E;
	delay_milliseconds(2);
	IOCLR0 = E;
}

