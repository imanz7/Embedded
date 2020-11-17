void setup()
{
  // put your setup code here, to run once:
  DDRB = 32;    //set PB5 as input
  PORTB = 48;    //enable internal pull up resistor
  PINB = 0;     //set PB4 as input
}

void loop()
{
  // put your main code here, to run repeatedly:
  if(PINB == 16)    //check if input is HIGH
  {
    PORTB = 32;     //light up LED
  }
  else
  {
    PORTB = 0;    //light off LED
  }
}
