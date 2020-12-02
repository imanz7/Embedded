/*
Write a program to produce a PWM signal with 50% duty cycle on
Channel B of timer0. Use Fast PWM mode and pre-scaler value of 1.
Determine the theoretical frequency of the generated PWM signal.
*/

void setup()
{
  // put your setup code here, to run once:
    unsigned char* ddrd = (unsigned char*) 0x2A;
    unsigned char* ocr0b = (unsigned char*) 0x48;
    unsigned char* tccr0a = (unsigned char*) 0x44;
    unsigned char* tccr0b = (unsigned char*) 0x45;
    *ddrd = 1 << 5;           //set pin 5 as output
    *ocr0b = 127;             //set duty cycle 50% of 255 - lower duty cycle, dimmer the LED
    *tccr0a = 0b00100011;     //normal output, fast PWM
    *tccr0b = 0b00000001;     //pre-scaler value of 1
}

void loop()
{
  // put your main code here, to run repeatedly:

}
