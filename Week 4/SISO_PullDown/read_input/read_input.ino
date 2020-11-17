void setup()
{
  // put your setup code here, to run once:
  DDRB = 32;
  PORTB = 0;
  PINB = 0;
}

void loop()
{
  // put your main code here, to run repeatedly:
  if(PINB == 16)
  {
    PORTB = 32;
  }
  else
  {
    PORTB = 0;
  }
}
