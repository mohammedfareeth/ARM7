/*
IN1    	IN2	    Spinning Direction
Low(0)	Low(0)	Motor OFF
High(1)	Low(0)	Forward
Low(0)	High(1)	Backward
High(1)	High(1)	Motor OFF
*/

#include <LPC21XX.H>
#include "lcd_car.h"
#include "uart_car.h"

#define SEL0 0X05 //PINSOL0 MACRO
#define SEL1 0x00
int main ()
{
	UART0_CONFIG(); //UART SETUP CONFIGURATION DECLARATION
	LCD_INIT(); //LCD INITITATION FUNCTION CALL
	LCD_COMMAND(0X84); //LCD FIRST LINE DISPLAY COMMAND
	LCD_STR("V24CE9M2"); 
	LCD_COMMAND(0XC2); //LCD SECOND LINE DISPLAY COMMAND
	LCD_STR("BLUETOOTH CAR");

	while(1)
	{
		unsigned char op;
		op = UART0_RX(); //UART TRANSMITING DATA AND RECIEVING DATA
		
	if(op=='R') //CAR NEED TO TURN RIGHT
	{
		UART0_STR("Moving Right");
		LCD_COMMAND(0X01);
		LCD_COMMAND(0X80);
		LCD_STR("MOVING RIGHT");
		IOCLR1 = M1;
		IOSET1 = M2;
		IOSET1 |= M3;
		IOCLR1 |= M4;
	}
	else if(op=='F') //CAR NEED TO MOVE FORWARD
	{
		UART0_STR("Moving Forward ");
		LCD_COMMAND(0X01);
		LCD_COMMAND(0X80);
		LCD_STR("MOVING FORWARD");
		IOCLR1 = M1;
		IOSET1 = M2;
		IOCLR1 |= M3;
		IOSET1 |= M4;
	}
	else if(op=='S') //CAR NEED TO STOP
	{
		UART0_STR("Break");
		LCD_COMMAND(0X01);
		LCD_COMMAND(0X80);
		LCD_STR("BREAK");
		IOCLR1 |= M1 | M2 | M3 | M4;
	}
	else if(op=='B') //CAR NEED TO REVERSE
	{
		UART0_STR("Reverse");
		LCD_COMMAND(0X01);
		LCD_COMMAND(0X80);
		LCD_STR("REVERSE");
		IOCLR1 = M2;
		IOSET1 = M1;
		IOCLR1 |= M4;
		IOSET1 |= M3;
	}
	else if(op=='L') //CAR NEED TO TURN LEFT
	{
		UART0_STR("Moving Left");
		LCD_COMMAND(0X01);
		LCD_COMMAND(0X80);
		LCD_STR("MOVING LEFT");
		IOCLR1 = M3;
		IOSET1 = M4;
		IOSET1 |= M1;
		IOCLR1 |= M2;
	}
	UART0_TX('\n');
}
}
