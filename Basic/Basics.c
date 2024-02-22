#include<reg51.h>
sbit sout = P0^0;                          // serial out on P0.0
sbit D0 = P1^0;                            // parallal input from P1 (D0-D7)
sbit D1 = P1^1;
sbit D2 = P1^2;
sbit D3 = P1^3;
sbit D4 = P1^4;
sbit D5 = P1^5;
sbit D6 = P1^6;
sbit D7 = P1^7;
int i;
int k;
void delay(void);                         //  1 ms delay
 
main()
  {
    for(i=0;i<8;i++)                   // rotate loop for 8 times
      {
        sout = D0;                       // first bit out
        D0 = D1;                         // shift all bits in sequence 
        D1 = D2;
        D2 = D3;
        D3 = D4;	
        D4 = D5;
        D5 = D6;
        D6 = D7;
        delay();                           // generate 1 ms delay after each bit shifted
      }
   }
void delay()
  {
    for(k=0;k<1000;k++);
  }