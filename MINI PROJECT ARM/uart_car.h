#include <LPC21XX.H>

#define M1 1<<16 //MOTOR LEFT
#define M2 1<<17 //MOTOR RIGHT
#define M3 1<<18 //MOTOR FORWARD
#define M4 1<<19 //MOTOR FORWARD 

void UART0_CONFIG(void); //UART SETUP CONFIGURATION DECLARATION
void UART0_STR(unsigned char *s);
void UART0_TX(unsigned char); //UART DATA TRANSMITTING FUNCTION DECLARATION
unsigned char UART0_RX(void); //UART DATA RECIEVING FUNCTION DECLARATION

void UART0_CONFIG(void) //UART SETUP CONFIGURATION DECLARATION
{
	PINSEL0 = 0X05;
	IODIR1 = M1 | M2 | M3 | M4 ; //OUTPUT DIRECTION FOR MOTORS
	U0LCR = 0X83;
	U0DLL = 97;
	U0DLM = 0X00;
	U0LCR = 0X03;
}
void UART0_TX(unsigned char data) //DATA TRANSMITTING
{
	while(((U0LSR>>5)&1)==0);
	U0THR = data; 
}
unsigned char UART0_RX(void) //DATA RECIEVING
{
	while((U0LSR&1)==0);
	
	return U0RBR;
}
void UART0_STR(unsigned char *s)
{
	while(*s)
	{
		UART0_TX(*s++);
	}
}
