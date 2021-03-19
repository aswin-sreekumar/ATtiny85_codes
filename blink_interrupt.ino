// ATtiny85 embedded program
// Blink using TIMER0 with timer interrupt
// Output LED at PIN 0


#include<avr/io.h>
#include<avr/interrupt.h>

bool i=0;

ISR(TIMER0_OVF_vect)
{
  i^=1;
  if(i==1)
  PORTB^=0x01;
}

int main()
{
  DDRB|=0b00000001;
  PORTB|=0b00000001;
  TCCR0B|=(1<<CS00)|(1<<CS02);
  TIMSK|=(1<<TOIE0);
  sei();
  while(1);
}
