/*
A tactile button is connected to PD2 (INT0) of ATmega328p via an external pull-down resistor
and an LED is connected to PB5 (pin 13). When the button is pressed, the LED should be ON and
when the button is not pressed, the LED should be OFF.

 */

unsigned char* pind = (unsigned char*) 0x29;
unsigned char* ddrb = (unsigned char*) 0x24;
unsigned char* portb = (unsigned char*) 0x25;
unsigned char* sreg = (unsigned char*) 0x5F;
unsigned char* eimsk = (unsigned char*) 0x3D;
unsigned char* eicra = (unsigned char*) 0x69;

void setup()
{
  // put your setup code here, to run once:
  *ddrb = 1 << 5;         //Set PB5 as output
  *sreg |= (1 << 7);      //Enable interrupts in general
  *eimsk = 1;             //Enable INT0
  *eicra = 1;             //Set interrupt mode to "any logic change"
}

ISR(INT0_vect)
{
    bool pin_status = ((*pind) & 4);      //AND pind with 4 (check status pd2)
    *portb = pin_status << 5; //Same as digitalWrite(13, digitalRead(2));
}

void loop()
{
  // put your main code here, to run repeatedly:

}
