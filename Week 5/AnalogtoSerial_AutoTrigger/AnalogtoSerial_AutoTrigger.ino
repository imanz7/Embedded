/*
 * a program that continuously prints out the analog value of PC3 (A3)
 * through the serial port. Assume the followings:
      - The clock speed of the microcontroller is 16MHz
      - The desired clock speed of ADC is 125 kHz.
      - Use AVCC as analog reference.
      - Auto trigger mode
 */
volatile unsigned char *admux = 0x7C;
volatile unsigned char *adcsra = 0x7A;
volatile unsigned char *adcsrb = 0x7B;
volatile unsigned char *adch = 0x79;
volatile unsigned char *adcl = 0x78;

void setup()
{
    Serial.begin(9600);
    pinMode(A3,INPUT);
    char *admux = (1<<REFS0, 1<<MUX1, 1<<MUX0);    //analog ref refs01, analog source mux 0011
    char *adcsra = (1<<ADEN, 1<<ADSC, 1<<ADATE, 1<<ADPS2, 1<<ADPS1, 1<<ADPS0);
    //char *adcsrb = 0;
}

void loop()
{     *adcsra |= 0b01000000;
      while(((*adcsra) & 0b01000000))
      {
          //wait while start conversion
      }
          int lowbyte = *adcl;
          int highbyte = *adch;
          int value = (highbyte<<8)+lowbyte;
          Serial.println (value);
          Serial.println(".....");
  }
