#include <LPC21XX.H>

#define LCD 0XFF<<6
#define RS 1<<14
#define E 1<<15

 void MAIN_CONFIG(void);
 void LCD_INIT(void);
 void LCD_COMMAND(unsigned char cmd);
 void LCD_DATA(unsigned char d);
 void LCD_STR(unsigned char*);
 void LCD_INT(int c);
 void delay_millisecond(unsigned int MS);
 
void MAIN_CONFIG(void)
{
	PINSEL1 = 0X0;
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
	 IODIR0 |= LCD|RS|E;
	 LCD_COMMAND(0X01);
	 LCD_COMMAND(0X02);
	 LCD_COMMAND(0X0C);
	 LCD_COMMAND(0X38);
}
void LCD_COMMAND(unsigned char  cmd)
{
	 IOCLR0 = LCD;
	 IOSET0 = cmd<<6;
	 IOCLR0 = RS;
	 IOSET0 = E;
	 delay_millisecond(70);
	 IOCLR0 = E;
}
void LCD_DATA(unsigned char d)
{
	 IOCLR0 = LCD;
	 IOSET0 = d<<6;
	 IOSET0 = RS;
	 IOSET0 = E;
	 delay_millisecond(70);
	 IOCLR0 = E;
}
void LCD_STR(unsigned char *s)
{
	 while(*s)
		 LCD_DATA(*s++);
}
void LCD_INT(int count)
{
	unsigned char arr[5];
	signed char i=0;
	if(count==0)
		LCD_DATA('0');
	else
	{
		if(count<0)
		{
			LCD_DATA('-');
			count=-count;
		}
		while(count>0)
		{
			arr[i++]=((count%10)+48);
			count=count/10;
		}
		for(--i;i>=0;i--)
		LCD_DATA(arr[i]);
	}
}
