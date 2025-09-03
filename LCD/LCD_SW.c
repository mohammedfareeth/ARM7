#include <lpc21xx.h>

#define LCD_D 0XFF << 0
#define RS 1 << 8
#define E 1 << 9
#define SW1 16
#define SW2 17
#define SW3 18

	void LCD_INIT(void);
	void LCD_COMMAND(unsigned char cmd);
	void LCD_DATA(unsigned char d);
	void LCD_STR(unsigned char*);
	void delay_millisecond(unsigned int MS);
	
int main ()
{
	LCD_INIT();
	LCD_COMMAND(0X80);
		while(1)
	{
	if(((IOPIN0>>SW1)&1)==0)
	{
		IOCLR0 = SW1;
		delay_millisecond(50);
		LCD_STR("SW1 is pressed");
		while(((IOPIN0>>SW1)&1)==0);
	}
	else if(((IOPIN0>>SW2)&1)==0)
	{
		IOCLR0 = SW2;
		delay_millisecond(50);
	  LCD_STR("SW2");
		while(((IOPIN0>>SW2)&1)==0);
  }
	else if(((IOPIN0>>SW3)&1)==0)
	{
 		IOCLR0 = SW3;
		delay_millisecond(50);
	  LCD_STR("SW3");
		while(((IOPIN0>>SW3)&1)==0);
  }
	else
	{
		LCD_COMMAND(0X01);
	}
}
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
