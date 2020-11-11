/*A tactile button (push-to-make switch) is connected to PB4 of ATmega328p via a pull down
resistor. The microcontroller needs to keep track of how many times the button has been
pressed (LOW to HIGH). Whenever a button has been pressed, the microcontroller needs to
send out the number (of times the button has been pressed) through the serial port.
Program the microcontroller to accomplish this.*/

unsigned int count;
bool previous;
unsigned char *reader = (unsigned char*) 0x23;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(;;)
  {
      bool current = (((*reader) & 0b00010000)!=0);   //check PB4
      if(current && !previous)                        
      {
        count++;
        Serial.println(count);  
      }
      previous = current;
  }
}

void loop()
{
  // put your main code here, to run repeatedly:

}
