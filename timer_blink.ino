// ATtiny85 embedded program
// Blink using TIMER0
// Output LED at PIN 0


#include<avr/io.h>

int i=0;

void delay_timer()
{
  TCNT0=0;
  TCCR0B=(1<<CS02)|(1<<CS00);
  while(!(TIFR&0x02));
  TCCR0B=0;
  TIFR=0x02;
}

int main()
{

  DDRB|=0b00000001;
  PORTB|=0b00000001;
  while(true)
  {
    for(i=0;i<3;i++)
    delay_timer();
    PORTB^=0b00000001;
  }
}
