#include"avr/io.h"
#include<util/delay.h>
void T0Delay();
void T1Delay();
void T2Delay();


void main()
{
 
 
 DDRB = 0xFF;
 PORTB=PORTB^(1<<PB4);
 T0Delay();

 while(1)
 {

 

 
 PORTB=PORTB^(1<<PB4);
 T1Delay();
 

 _delay_ms(200);

 PORTB=PORTB^(1<<PB4);
 T2Delay();
 
 
 
 }
 }
 void T0Delay()//for 1500 micro second
 {
  
  TCNT1H=(-15957)>>8;//0xC1;
  TCNT1L=(-15957);//0xAB;
  TCCR1A=0x00;
  TCCR1B=0x01;
   while((TIFR&(0x1<<TOV1))==0);
   TCCR1B=0;
   TIFR=0x1<<TOV1;
  
   }
void T1Delay()//for 8 micro second
 {
  TCNT1H=(-85)>>8;
  TCNT1L=(-85);
  TCCR1A=0x00;
  TCCR1B=0x01;
   while((TIFR&(0x1<<TOV1))==0);
   TCCR1B=0;
   TIFR=0x1<<TOV1;
   }
void T2Delay()//for 2200 micro second
 {
  TCNT1H=(-23404)>>8;//0xB1;
  TCNT1L=(-23404);
  TCCR1A=0x00;
  TCCR1B=0x01;
   while((TIFR&(0x1<<TOV1))==0);
   TCCR1B=0;
   TIFR=0x1<<TOV1;
   }
   void T3Delay()//FOR 8 MICRO SECOND
 {
 TCNT0=-88;
  TCCR0=0x01;
  while((TIFR&0x1)==0);
   TCCR0=0;
   TIFR=0x1;
   
 
   }
void T4Delay()//FOR 1900 MICRO SECOND
 {
  TCNT0=-65;
  TCCR0=0x04;
  while((TIFR&0x1)==0);
   TCCR0=0;
   TIFR=0x1;
   }

