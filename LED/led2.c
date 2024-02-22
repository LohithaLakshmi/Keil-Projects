#include<reg52.h>           // special function register declarations
                            // for the intended 8051 derivative

sbit LED = P1^1;            // Defining LED pin

void Delay();           // Function prototype declaration

void main ()
{
	LED = 0;
    while(1)                // infinite loop
    {
        LED = 0;            // LED off
        Delay();
        LED = 1;            // LED On
        Delay();
    }
}
 
void Delay()
{
    int j;
    int i;
    for(i=0;i<20;i++)
    {
        for(j=0;j<10000;j++); 
    }
}