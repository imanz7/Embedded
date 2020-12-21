unsigned char* pind = (unsigned char*) 0x29;
unsigned char* ddrb = (unsigned char*)0x24;
unsigned char* portb = (unsigned char*) 0x25;
unsigned char* ddrc = (unsigned char*)0x27;
unsigned char* ddrd = (unsigned char*)0x2A;
unsigned char* adcsra = (unsigned char*)0x7A;
unsigned char* acsr = (unsigned char*)0x50;
unsigned char* sreg = (unsigned char*) 0x5F;
unsigned char* eimsk = (unsigned char*) 0x3D;
unsigned char* eicra = (unsigned char*) 0x69;
unsigned char* smcr = (unsigned char*)0x53;
unsigned volatile char* mcucr = (unsigned char*) 0x55;

bool red_pressed;
bool green_pressed;

void setup()
{ 
  DisableADCandComparator();
  EnableExternalInterrupts();
  //*ddrd = 0b11110011;

  for(;;)
  {
      DeepSleep();
  }
}


ISR(INT0_vect)
{
  red_pressed = ((*pind) & 0b00000100);   //check status PD2
  *portb = red_pressed << 3;     //light up red led (PB3)
}


ISR(INT1_vect)
{
  green_pressed = ((*pind) & 0b00001000); //check status PD3
  *portb = green_pressed << 4;   //light up red led (PB4)
}


void DisableADCandComparator()
{
  *ddrb = 0b11111111;
  *ddrc = 0b11111111;
  *ddrd = 0b11110011;       //set PD2 PD3 as input
  *adcsra = 0;              //disable ADC
  *acsr = 1 << 7;           //disable comparator
}

void EnableExternalInterrupts()
{
  *sreg |= (1 << 7);                      //Enable interrupts
  *eimsk = 0b00000011;                    //Enable INT0 and INT1
  *eicra = 15;     //                       //Set trigger mode to LOW TO HIGH
}

void DeepSleep()
{
  *smcr = 5;                              //Sleep mode = POWER DOWN, Sleep Enable = True
  *mcucr = 0b01100000;                    //Set Both BODS and BODSE
  *mcucr = 0b01000000;                    //Set BODS and clear BODSE
  asm("sleep");                           //Invoke in line assembler to sleep
}

void loop()
{

}
