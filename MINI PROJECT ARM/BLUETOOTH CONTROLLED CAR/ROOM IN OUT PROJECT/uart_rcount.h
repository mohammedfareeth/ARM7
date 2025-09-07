#include <LPC21XX.H>

#define RE1 1<<17
#define RE2 1<<16

void UART_CONFIG(void);
void UART0_STR(unsigned char *s);
void UART0_TX(unsigned char);
unsigned char UART0_RX(void);

void UART_CONFIG(void)
{
	PINSEL0 = 0X05;
	IODIR1 = RE1 | RE2;
	U0LCR = 0X83;
	U0DLL = 97;
	U0DLM = 0X00;
	U0LCR = 0X03;
}
void UART0_TX(unsigned char data)
{
	while(((U0LSR>>5)&1)==0);
	U0THR = data;
}
unsigned char UART0_RX(void)
{
	while((U0LSR&1)==0);
	return U0RBR;
}
void UART_STR(unsigned char *s)
{
	while(*s)
		UART0_TX(*s++);
}
