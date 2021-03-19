// ATtiny85 Embedded Program
// PWM fade of LED
// Analog input at IC PIN 3 : PB4
// Digital LED output at PIN 0

#include <avr/io.h>

unsigned int data;

void initialise()
{
  DDRB=0x01;

  TCCR0A|=(1<<WGM00)|(1<<WGM02)|(1<<COM0A0)|(1<<COM0A1);
  TCCR0B|=(1<<CS00);
  
  ADCSRA|=(1<<ADEN)|(1<<ADPS2)|(1<<ADPS1);
  ADMUX|=(1<<MUX1);
}

void ADC_convert()
{
  data=0;
  ADCSRA|=(1<<ADSC);
  while(!(ADCSRA&(1<<ADIF)));
  data=int(ADCL);
  data+=(int(ADCH)*256);
  data/=4;
}

int main()
{
  initialise();
  while(1)
  {
      ADC_convert();
      OCR0A=data;
  }
}
