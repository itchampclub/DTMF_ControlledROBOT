int D3 = 8; //D3 //pins 8 to 11 are addressed to the 4 switches
int D2 = 9; //D2
int D1 = 10; //D1
int D0 = 11; //D0
int r1; //r1 to r4 are variables
int r2;
int r3;
int r4;
void setup()
{
  Serial.begin(9600);
  // Setup motors
  pinMode(2, OUTPUT); //Initializing the Digital Pin 2,3,4,5 as OUTPUT pins for the Motors
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

  pinMode(D3, INPUT); //Initializing as input ports from DTMF Module
  pinMode(D2, INPUT);
  pinMode(D1, INPUT);
  pinMode(D0, INPUT);
  r1 = 0;
  r2 = 0;
  r3 = 0;
  r4 = 0;
}

void loop()
{
  r1 = digitalRead(D3); //r1 to r4 get the values of D3 to D0 respectively
  r2 = digitalRead(D2);
  r3 = digitalRead(D1);
  r4 = digitalRead(D0);
  if (r1 == LOW && r2 == LOW && r3 == HIGH && r4 == LOW) // Binary 0010 ; Decimal 2
  { Serial.println("Moving Forward");
    moveforward();
  }
  else if (r1 == LOW && r2 == HIGH && r3 == LOW && r4 == LOW) // Binary 0100 ; Decimal 4
  { Serial.println("Moving Left");
    moveleft();
  }
  else if (r1 == LOW && r2 == HIGH && r3 == LOW && r4 == HIGH) // Binary 0101 ; Decimal 5
  { Serial.println("Not moving");
    nomove();
  }
  else if (r1 == LOW && r2 == HIGH && r3 == HIGH && r4 == LOW) // Binary 0110 ; Decimal 6
  { Serial.println("Moving Right");
    moveright();
  }
  else if (r1 == HIGH && r2 == LOW && r3 == LOW && r4 == LOW) // Binary 1000 ; Decimal 8
  { Serial.println("Moving Backward");
    movebackward();
  }
} //end of void loop
void moveforward()
{
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
}
void movebackward()
{
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
}
void moveleft()
{
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
}
void moveright()
{
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
}
void nomove()
{
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
}
