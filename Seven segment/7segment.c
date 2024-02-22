#include<reg51.h> 
#define led P2
sbit sw1=P0^0;
sbit sw2=P0^1;
sbit sw3=P0^2;
sbit sw4=P0^3;
unsigned char ch[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
//void delay (int);
void display (unsigned long int);
void sdelay (char);

/*void delay (int d)
{
	unsigned char i;
	for(;d>0;d--)
	{
		for(i=250;i>0;i--);
		for(i=248;i>0;i--);
	}
}*/

void sdelay (char d)
{
	for(;d>0;d--);
}

void display (unsigned long int n)
{
	led=ch[n/1000];
	sw1=1;
	sdelay(30);
	sw1=0;
	
	led=ch[(n/100)%10];
	sw2=1;
	sdelay(30);
	sw2=0;
	
	led=ch[(n/10)%10];
	sw3=1;
	sdelay(30);
	sw3=0;
	
	led=ch[n%10];
	sw4=1;
	sdelay(30);
	sw4=0;
}

void main()
{
	unsigned long int i=1;
	
	while(1)
	{
		i=++i;
		display(i);
		if(i==9999)
			i=0;
	}
}
