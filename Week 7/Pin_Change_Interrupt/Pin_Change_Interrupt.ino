/*
    An ATmega328p micrcontroller is embedded part of a home security system.
    8 motion sensors are connected to the port D of microcontroller
*/
 
volatile bool changed;
unsigned char* pinb = (unsigned char*) 0x23;
unsigned char* sreg = (unsigned char*) 0x5F;
unsigned char* pcicr = (unsigned char*) 0x68;
unsigned char* pcmsk0 = (unsigned char*) 0x6B;

void setup()
{
  // put your setup code here, to run once:
  *sreg |= (1 << 7);            //Enable interrupts in general
  *pcicr = 1;                   //Enable pin change interrupt 0
  *pcmsk0 = 255;                //Enable pin change interrupt on all the Port B pin
  Serial.begin(9600);
  
  while(1)
  {   changed = *pinb;
      if (changed)
      {
          Serial.println("Sensor values changed");    //Perform necessary investigation and subsequent operations
          changed = 0;
      }
      else
      {
          //Do other things or go back to sleep
          Sleep();                                    //There is no such function called ‘Sleep’. Just for demo.
      }
  }
}

void Sleep()
{
    Serial.println("sleeping");
}

ISR(PCINT0_vect)
{
    changed = 1;
}

void loop()
{
  // put your main code here, to run repeatedly:

}
