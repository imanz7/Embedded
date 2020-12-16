/*
 * read contents of EEDR at specific memory location
 */

char* data_register = (char*) 0x40;                 //Points to EEDR
volatile char *control_register = (char*) 0x3F;     //Points to EECR
int* address_register = (int*) 0x41;                //Points to EEAR. Note that int is 16bit on ATmega328p
                                                    //This pointer points to both low byte and high byte of EEAR

char ReadByte(int address)
{            
      while (((*control_register) & 0b00000010))          //If the data is being written (EEPE is high)
      {
          //wait until writing operation is done
      }
      
      *address_register = address;                        //Stores the address in the EEAR
      *control_register = 0b00000001;                     //Set EERE (Initiate reading)
      return *data_register;                              //Return the contents of the data register (EEDR)
}

void setup()
{
    Serial.begin(9600);
    unsigned char a = ReadByte(115); //Read the value of the EEPROM at memory address 115
    Serial.println(a); //Prints the value of the EEPROM at memory address 115
}

void loop()
{
    //none
}
