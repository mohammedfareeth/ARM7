#include <lpc21xx.h>

#define LCD_D 0XFF << 0
#define RS 1 << 8
#define E 1 << 9

	void LCD_INIT(void);
	void LCD_COMMAND(unsigned char cmd);
	void LCD_DATA(unsigned char d);
	void LCD_STR(unsigned char*);
	void delay_millisecond(unsigned int MS);
	void LCD_SCROLL(unsigned char *S);
	
void LCD_SCROLL(unsigned char *S)
	{
		unsigned char *S1;
		unsigned int i = 0;
		*S1 = i[0];
		{
			LCD_DATA(*S1+i);
		}
		i++;
		delay_millisecond(50);
	}	
	
int main ()
{
	LCD_INIT();
	LCD_SCROLL("Vector India");
}

void delay_millisecond(unsigned int MS)
{
	T0PR = 15000-1;
	T0TCR = 0X01;
	while(T0TC<MS);
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
	delay_millisecond(200);
	IOCLR0 = E;
}
void LCD_DATA(unsigned char d)
{
	IOCLR0 = LCD_D;
	IOSET0 = d;
	IOSET0 = RS;
	IOSET0 = E;
	delay_millisecond(200);
	IOCLR0 = E;
}
	
void LCD_STR(unsigned char *S)
{
	while(*S)
		LCD_DATA(*S++);
	
}
