#include <LPC21XX.H>
#include "can2.h"
#include "Delay.h"
#include "LCD8Bit.h"
#include "uart.h"


int main()
{	
	CAN2_MSG m1;
	VPBDIV=1; 

	LCD_INIT(); //LCD INITITATION FUNCTION CALL
	uart0_init(115200);
	can2_init();

	LCD_COMMAND(0X86); //LCD FIRST LINE DISPLAY COMMAND
	LCDPrintString("V24CE9M2"); 
	LCD_COMMAND(0XC4); //LCD SECOND LINE DISPLAY COMMAND
	LCDPrintString("CAR DASHBOARD");
	uart0_tx_string("Dashboard\r\n");
	delay(7);
	
	LCD_COMMAND(0x01);
	LCD_COMMAND(0x80);	       
	LCDPrintString("CAR DASHBOARD");
	
	LCD_COMMAND(0xC0);
	LCDPrintString("ultrasonic : ");
	
	LCD_COMMAND(0x94);
	LCDPrintString("temperature: ");
	
	LCD_COMMAND(0xD4);
	LCDPrintString("headlight  : ");
	
	
	while(1)
		{					       
		can2_rx(&m1);
		
		if(m1.rtr==0)
			{
				if(m1.id == 1)
				{	LCD_COMMAND(0xC0);
					LCDPrintString("distance  ");
					LCD_COMMAND(0xC0 + 13);
					LCDPrintFloat(m1.byteA);
					uart0_tx_string("ultrasonic: ");
					uart0_tx_integer(m1.byteA);
					uart0_tx_string("\r\n");
				}
				if(m1.id == 2)
				{
					LCD_COMMAND(0x94);
					LCDPrintString("temperature: ");
					LCD_COMMAND(0x94 + 13);
					LCDPrintInt(m1.byteA);
					uart0_tx_string("temperature: ");
					uart0_tx_integer(m1.byteA);
					uart0_tx_string("\r\n");
				}
				if(m1.id == 3)
				{
					LCD_COMMAND(0xD4);
					LCDPrintString("headlights : ");
					LCD_COMMAND(0xD4 + 13);
					if(m1.byteA == 1)
					{
					   LCDPrintString("ON");
					}
					else
					LCDPrintString("OFF");
					uart0_tx_string("HeadLights: ");
					uart0_tx_integer(m1.byteA);
					uart0_tx_string("\r\n");
				}
			}
	 }
}
