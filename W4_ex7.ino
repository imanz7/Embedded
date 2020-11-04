#define led0 8
#define led1 9

void setup()
{
  // put your setup code here, to run once:
  pinMode(led0,OUTPUT);
  pinMode(led1,OUTPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:
  while(1)
  {
    Refresh0();
    Refresh1();
  }
}

void Refresh0()
{
  digitalWrite(led0,HIGH);
  delay(750);
  digitalWrite(led0,LOW);
  delay(350);
}

void Refresh1()
{
  digitalWrite(led1,HIGH);
  delay(400);
  digitalWrite(led1,LOW);
  delay(600);
}
