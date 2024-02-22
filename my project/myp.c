#include<reg51.h>
#define LCD = P1; //LCD display
#define ADC = P2; //temperature sensor
sbit rs = P3^2;  //RS pin 
sbit rw = P3^3;  // RW pin 
sbit e =  P3^4;  //E pin 
sbit pwm = P3^0;//PWM
//temp
sbit ADC_DATA = P1;
sbit read = P3^5;
sbit write= P3^6;
sbit intr = P3^7;
sbit cs = P3^1;
unsigned char value;

//temp
void conv()
{

cs = 0;
write = 0;
write = 1;
cs = 1;
while(intr);
}

void send()
{
cs=0;
read = 1;
read = 0;
value = ADC_DATA;
cs = 1;
}
//temp


//LCD
void delay(unsigned int time)  
{
    unsigned i,j ;
    for(i=0;i<time;i++)    
    for(j=0;j<1275;j++);
}
void lcd_cmd(unsigned char command)  
{
    display_port = command;
    rs= 0;
    rw=0;
    e=1;
    delay(1);
    e=0;
}

void lcd_data(unsigned char disp_data) 
{
    display_port = disp_data;
    rs= 1;
    rw=0;
    e=1;
    delay(1);
    e=0;
}

 void lcd_init()    
{
    lcd_cmd(0x38);  // for using 2 lines and 5X7 matrix of LCD
    msdelay(10);
    lcd_cmd(0x0F);  //  display ON, cursor blinking
    delay(10);
    lcd_cmd(0x01);  //clear screen
    delay(10);
    lcd_cmd(0x81);  // bring cursor to position 1 of line 1
    delay(10);
}

//LCD

//pwm
void pwm_default()
{
pwm = 0;
TH0 = 0xFF;
TL0 = 0x47;
TR0 = 1;
while(!TF0)
{
TF0=0;
TR0 = 0; 

}

}

//pwm







void main()
{ 

read = 1;
write = 1;
intr = 0;

while(1)
{
{
conv();
send();
SBUF = ADC_DATA;
}

    unsigned char a[15]= "TEMP:", ADC_DATA;  
  
    int l=0;

    lcd_init();

    while(a[l] != '\0') // searching the null terminator in the sentence
    
    {
        lcd_data(a[l]);
        l++;
        msdelay(50);
    }




//PWM

if(temp<20)
{
pwm = 1;
TH0 = 0xDC;
TL0 = 0x00;

}
else if(20<temp<25)
{
pwm = 1;
TH0 = 0xCA;
TL0 = 0x00;
void pwm_default();

}
else if(25<temp<30)
{
pwm = 1;
TH0 = 0xB8;
TL0 = 0x00;
void pwm_default();
}

else if(30<temp<35)
{
pwm = 1;
TH0 = 0xA6;
TL0 = 0x00;
void pwm_default();
}

else if(35<temp<40)
{
pwm = 1;
TH0 = 0x94;
TL0 = 0x00;
void pwm_default();
}
else if(temp>40)
{
pwm = 1;
TH0 = 0x82;
TL0 = 0x00;
void pwm_default();
}



}







}