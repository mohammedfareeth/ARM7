#include <LPC21XX.H>
#define LCD_D 0XFF << 0
#define RS 1 << 8
#define E 1 << 9

void delay_ms(unsigned int);
void LCD_INIT(void);
void LCD_COMMAND(unsigned int);
void LCD_DATA(unsigned char);
void LCD_STRING(const char* s);
void CGRAM_WRITE(unsigned char);

unsigned char cgram[] = {0x00,0x00,0x0A,0X15,0X15,0X0A,0X04,0X00};

void CGRAM_WRITE(unsigned char nBytes)
{
	unsigned char i;
	LCD_COMMAND(0X40);
	for(i=0;i<nBytes;i++)
	LCD_DATA(cgram[i]);
	delay_ms(5);
}

int main ()
{
	LCD_INIT();
	CGRAM_WRITE(8);
	LCD_COMMAND(0X80);
	LCD_DATA(0);
}

void delay_ms(unsigned int ms)
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
	//LCD_COMMAND(0X06);
	LCD_COMMAND(0X38);

}

void LCD_COMMAND(unsigned int cmd)
{
	IOCLR0 = LCD_D;
	IOSET0 = cmd;
	IOCLR0 = RS;
	IOSET0 = E;
	delay_ms(1);
	IOCLR0 = E;
}

void LCD_DATA(unsigned char d)
{
	IOCLR0 = LCD_D;
	IOSET0 = d;
	IOSET0 = RS;
	IOSET0 = E;
	delay_ms(1);
	IOCLR0 = E;
}

void LCD_STRING(const char* s)
{
	unsigned char i;
	for(i = 0 ; s[i] ; i++)
	LCD_DATA(s[i]);
}
