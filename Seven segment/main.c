#include<reg51.h>
sbit LED = P1^3;
void delay();

void main()
{
	TMOD = 0x00;
	TH0 = 0xFF;
	TL0 = 0x00;
	TR0 = 1;
	LED = 0;
	while(1)
	{
		LED = 1;
		delay();
		LED = 0;
		delay();
		
	
	}
}
void delay()
{

	
	while(TF0==1)
	{
		TR0 = 0;
		TF0 = 0;
	}



}