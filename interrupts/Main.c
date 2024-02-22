#include<reg51.h>

sbit ex_int0 = P3^2;
sbit LED = P1^0;
void main()
{
	   LED = 0;
	   ex_int0 = 1;
	   IT0 =1;
	   EX0 = 1;
	   EA = 1;
	
	while(1)
	{
		  LED = 0;
	}
	   
}

 void External_interrupt0()  interrupt 0
 {
	   LED = 1;
 }