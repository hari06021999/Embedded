#pragma config FOSC=HS//oscillator selection bits(hs oscillator)
#pragma config WDTE=ON//watchdog timer enable bit(WDT enable)
#pragma config PWRTE=OFF//power up timer enable bit(PWRT disable)
#pragma config BOREN=ON//brown out reset enable bit(BOR enabled)
#pragma config LVP=OFF//low voltage(single supply) in circuit serial programming enable bit
#pragma config CPD=OFF//data EEPROM memory code protection bit
#pragma config WRT=OFF//flash program memory write enable bit
#pragma config CP=OFF//Flash program memory code protect

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#define _XTAL_FREQ 20000000

int keypad();
void main()
{
    int a,b,c,d;
     unsigned char digit[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
     TRISB=0;
     PORTB=0;
     TRISD7=0;
   
     TRISD0=TRISD1=TRISD2=0;
     TRISD3=TRISD4=TRISD5=TRISD6=1;
     while(1)
     {
        a=keypad();
        PORTB=digit[a];
        b=keypad();
        PORTB=digit[b];
        c=keypad();
        PORTB=digit[c];
        d=keypad();
        PORTB=digit[d];
      if(a==1 && b==2 && c==3 && d==4)
      {
          RD7=1;
          __delay_ms(1000);
      }
      else
      {
          RD7=0;
      }
         
     }
}
int keypad()
{
    while(1)
    {
         RD0=1,RD1=RD2=0;
         
         if(RD3==1){   while(RD3==1); return 1;}
          if(RD4==1){   while(RD4==1); return 4;}
          if(RD5==1){   while(RD5==1); return 7;}
          if(RD6==1){   while(RD6==1); return *;}
          
         RD1=1;RD0=RD2=0;
         
          if(RD3==1){   while(RD3==1); return 2;}
          if(RD4==1){   while(RD4==1); return 5;}
          if(RD5==1){   while(RD5==1); return 8;}
          if(RD6==1){   while(RD6==1); return 0;}
         
         RD2=1;RD0=RD1=0;
         
          if(RD3==1){   while(RD3==1); return 3;}
          if(RD4==1){   while(RD4==1); return 6;}
          if(RD5==1){   while(RD5==1); return 9;}
          if(RD6==1){   while(RD6==1); return #;}
    }
}
