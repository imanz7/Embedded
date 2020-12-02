/*
Write a program to produce a PWM signal with 25% duty cycle on
Channel A of timer1. Use 10-bit Phase Correct PWM-mode and pre-scaler value of 8.
Determine the theoretical frequency of the generated PWM signal.
List all the PWM duty cycles that can be generated using the above settings.
*/

void setup()
{
    unsigned char* ddrb = (unsigned char*) 0x24;
    unsigned char* ocr1al = (unsigned char*) 0x88;
    unsigned char* tccr1a = (unsigned char*) 0x80;
    unsigned char* tccr1b = (unsigned char*) 0x81;
    
    *ddrb = 2;                  //set pin 1 (PB1) as output
    *ocr1al = 255;             //compare 1A low byte (set all)
    *tccr1a = 0b10000011;     //normal output (Channel A), 10-bit Phase Correct PWM
    *tccr1b = 0b00000010;     //pre-scaler value of 8

}

void loop()
{
  // put your main code here, to run repeatedly:

}
