#include <LPC21XX.H>

#define LED1 1<<18
#define LED2 1<<19

void LED_INIT(void);
 
void LED_INIT(void)
{
	IODIR1 = LED1 | LED2 ;
}
