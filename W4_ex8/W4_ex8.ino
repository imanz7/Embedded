const int a = 8;
const int b = 9;
const int c = 10;
const int d = 11;
const int e = 12;

int count_A = 0;
int count_B = 0;
int count_C = 0;
int count_D = 0;
int count_E = 0;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(a, INPUT_PULLUP);
  pinMode(b, INPUT_PULLUP);
  pinMode(c, INPUT_PULLUP);
  pinMode(d, INPUT_PULLUP);
  pinMode(e, INPUT_PULLUP);
}

void loop()
{ 
  // put your main code here, to run repeatedly:
  checkA();
  checkB();
  checkC();
  checkD();
  checkE();
  delay(1000);
}

void checkA()
{ 
  int A_state = digitalRead(a);
  Serial.print("A = ");
  Serial.print(count_A);
  if(A_state == HIGH)
  {
    count_A++;
  }
  else
  {
   
  }
}

void checkB()
{ 
  int B_state = digitalRead(b);
  Serial.print(" B = ");
  Serial.print(count_B);
  if(B_state == HIGH)
  {
    count_B++;
  }
  else
  {
    
  }
}

void checkC()
{ 
  int C_state = digitalRead(c);
  Serial.print(" C = ");
  Serial.print(count_C);
  if(C_state == HIGH)
  {
    count_C++;
  }
  else
  {
    
  }
}

void checkD()
{ 
  int D_state = digitalRead(d);
  Serial.print(" D = ");
  Serial.print(count_D);
  if(D_state == HIGH)
  {
    count_D++;
  }
  else
  {
    
  }
}

void checkE()
{ 
  int E_state = digitalRead(e);
  Serial.print(" E = ");
  Serial.println(count_E); 
  if(E_state == HIGH)
  {
    count_E++;
  }
  else
  {
    
  }
}
