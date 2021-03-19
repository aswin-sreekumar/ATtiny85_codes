// Attiny85 embedded code
// ADC input
// Analog input at IC PIN 3 : PB4
// Digital LED output at PIN 0

#include <avr/io.h>

unsigned int data;

void initialise()
{
  DDRB=0x01;
  ADCSRA|=(1<<ADEN)|(1<<ADPS2)|(1<<ADPS1);
  ADMUX|=(1<<MUX1)|(1<<MUX0);
}

void ADC_convert()
{
  data=0;
  ADCSRA|=(1<<ADSC);
  while(!(ADCSRA&(1<<ADIF)));
  data=int(ADCL);
  data+=(int(ADCH)*256);
}

int main()
{
  initialise();
  while(1)
  {
      ADC_convert();
      if(data>=512)
        PORTB|=(1<<0);
      if(data<512)  
        PORTB&=~(1<<0);
  }
}
