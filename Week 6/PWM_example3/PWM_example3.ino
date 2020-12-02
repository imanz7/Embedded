/*
Write a program to produce a PWM signal with 50% duty cycle on
Channel B of timer0. Use Fast PWM mode and pre-scaler value of 1, top value of 5.
Determine the theoretical frequency of the generated PWM signal.
List all the PWM duty cycles that can be generated using the above settings.
*/

void setup()
{
    unsigned char* ddrd = (unsigned char*) 0x2A;
    unsigned char* ocr0a = (unsigned char*) 0x47;
    unsigned char* ocr0b = (unsigned char*) 0x48;
    unsigned char* tccr0a = (unsigned char*) 0x44;
    unsigned char* tccr0b = (unsigned char*) 0x45;
    
    *ddrd = 1 << 5;           //set pin 5 as output
    *ocr0a = 5;               //set ocr0a 5 (always HIGH)
    *ocr0b = 2;               //50% of duty cycle (2.5) 
    *tccr0a = 0b00100011;     //normal output, fast PWM
    *tccr0b = 0b00001001;     //pre-scaler value of 1

}

void loop()
{
  // put your main code here, to run repeatedly:

}
