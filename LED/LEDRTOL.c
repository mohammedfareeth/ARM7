#include <lpc21xx.h>
void delay(unsigned long val) 
{
    while (val > 0)
		{
        val--;
    }
}

int main() 
{
	  int i,j;
    IODIR0 = 0XFF; 
    for(i=0;i<10;i++)
			{ 
				for(j=7;j>=0;j--)
				{
				IOSET0 = (1 << j);
				delay(1000000);
        IOCLR0 = (1 << j);				
				}	
    } 
}
