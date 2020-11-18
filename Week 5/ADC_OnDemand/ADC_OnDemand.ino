/*
 * a program that continuously prints out the analog value of PC3 (A3)
 * through the serial port. Assume the followings:
      - The clock speed of the microcontroller is 16MHz
      - The desired clock speed of ADC is 125 kHz.
      - Use AVCC as analog reference.
      - On-demand mode
 */

void setup()
{
    Serial.begin(9600);
    ADMUX = 67;       //(1<<REFS0, 1<<MUX1, 1<<MUX0) - use PC3 as analog input
    ADCSRA = 199;     //(1<<ADEN, 1<<ADSC, 1<<ADPS2, 1<<ADPS1, 1<<ADPS0)
}

void loop()
{     
      ADCSRA |= 0b01000000;
      while(((ADCSRA) & 0b01000000))
      {
          //wait while start conversion
      }
      int lowbyte = ADCL;
      int highbyte = ADCH;
      int value = (highbyte<<8)|lowbyte;
      Serial.println (value);
      Serial.println(".....");
  }
