const int led1 = 0;
const int led2 = 1;
const int led3 = 2;
const int led4 = 3;
const int led5 = 4;
const int led6 = 5;
const int led7 = 6;
const int led8 = 7;

void setup()
{
  // put your setup code here, to run once:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  led(0, 781, 515);
  led(1, 2014, 1348);
  led(2, 343, 573);
  led(3, 678, 1839);
  led(4, 342, 534);
  led(5, 1478, 326);
  led(6, 1859, 351);
  led(7, 777, 888); 
}

void led(int pin, int on, int off)
{
  digitalWrite(pin, HIGH);
  delay(on);
  digitalWrite(pin,LOW);
  delay(off);
}
