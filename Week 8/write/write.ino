/*
 * write value at specific memory location then read
 */

char* data_register = (char*) 0x40;               //Points to EEDR
volatile char *control_register = (char*) 0x3F;   //Points to EECR
int* address_register = (int*) 0x41;              //Points to EEAR. Note that int is 16bit on ATmega328p
                                                  //This pointer points to both low byte and high byte of EEAR   

class EEPROM
{
    public:
    static void WriteByte(int address, char data)
    {
        //Code for Writing
        
        while (((*control_register) & 0b00000010))        //If the data is being written (EEPE is high)
        {
            //wait until writing operation is done
        }  
        
        *address_register = address;                      //Stores the address in the EEAR
        *data_register = data;                            //Stores the data in the EEDR
        *control_register = 0b00000100;                   //Enable Master Write (Set EEMPE), EEPM 00 (Erase and Write)
        *control_register |= 0b00000010;                  //Start writing (Set EEPE)
    }
    
    static char ReadByte(int address)
    {
        //Code for Reading
        
        while (((*control_register) & 0b00000010))      //If the data is being written (EEPE is high)
        {
            //wait until writing operation is done
        }
        
        *address_register = address;                        //Stores the address in the EEAR
        *control_register = 0b00000001;                     //Set EERE (Initiate reading)
        return *data_register;                              //Return the contents of the data register (EEDR)
    }
};

void setup()
{
    Serial.begin(9600);
    
    EEPROM::WriteByte(115, 168);                            //Write a value of 168 to the memory location 115
    unsigned char a = EEPROM::ReadByte(115);                //Read the value at memory location 115
    //Serial.print("Value at memory location 115:");
    Serial.println(a);                                      //Prints the value
}

void loop()
{
  //none
}
