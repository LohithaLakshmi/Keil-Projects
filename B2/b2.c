#include<reg51.h>

int k;
sbit LED  = P0^0;
sbit LED1 = P1^1;

void main()
{
	
	LED = 0;
	LED1 = 0;
	while(1)
	
	{
		 for(k=0;k<1000;k++);
			{
				LED = ~LED;
				LED1 = ~LED1;
			}

	}
}