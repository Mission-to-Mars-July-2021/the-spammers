int const FORWARD_RIGHT = 7;
int const REVERSE_RIGHT = 8;
int const ENABLE_RIGHT = 9;
int const ENABLE_LEFT = 10;
int const FORWARD_LEFT = 11;
int const REVERSE_LEFT = 12;
const int LEFT_FEEDBACK = 2; 
const int RIGHT_FEEDBACK = 3;
volatile int leftcounter = 0;
volatile int rightcounter = 0;

void setup()
{
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(LEFT_FEEDBACK), LeftMotorISR,RISING);
  attachInterrupt(digitalPinToInterrupt(RIGHT_FEEDBACK), RightMotorISR,RISING);
  pinMode(FORWARD_LEFT, OUTPUT);
  pinMode(REVERSE_LEFT, OUTPUT);
  pinMode(REVERSE_RIGHT, OUTPUT);
  pinMode(FORWARD_RIGHT, OUTPUT);
  pinMode(ENABLE_RIGHT, OUTPUT);
  pinMode(ENABLE_LEFT, OUTPUT);
}
void loop()
    {    
  
  if(millis() > 16000) {
  stop();
  delay(1500);
  exit(0);
  }
  
  forwards(155,155);
  delay(2000);
  turningleft();
  delay(2000);
  forwards(155,155);
  delay(2000);
  turningleft();  
  delay(2000);
  forwards(155,155);
  delay(2000);
  turningleft();  
  delay(2000);
  forwards(155,155);
  delay(2000);
  turningleft();  
  delay(2000);
    
    
  // You might want to put these next lines into a function below
  // They are not really needed for this task as the distance 
    // is small. - Robert
 
  
  
} // end of loop

void LeftMotorISR() 
    {
    leftcounter++;
     }

    void RightMotorISR() 
    {
    rightcounter++;
             } 
               
  void forwards(int leftspeed, int rightspeed)
  {
  analogWrite(ENABLE_RIGHT, rightspeed);
  analogWrite(ENABLE_LEFT, leftspeed);
  digitalWrite(FORWARD_RIGHT, HIGH);
  digitalWrite(FORWARD_LEFT, HIGH);
  digitalWrite(REVERSE_LEFT, LOW);
  digitalWrite(REVERSE_RIGHT, LOW);
             }


void turningleft() {
  analogWrite(ENABLE_RIGHT, 155);
  analogWrite(ENABLE_LEFT, 40);
  digitalWrite(FORWARD_RIGHT, HIGH);
  digitalWrite(FORWARD_LEFT, LOW);
  digitalWrite(REVERSE_LEFT, HIGH);
  digitalWrite(REVERSE_RIGHT, LOW);  
}
   
  void backwards() 
  {
  digitalWrite(ENABLE_RIGHT, HIGH);
  digitalWrite(ENABLE_LEFT, HIGH);
  digitalWrite(FORWARD_LEFT, LOW);
  digitalWrite(FORWARD_RIGHT, LOW);
  digitalWrite(REVERSE_LEFT, HIGH);
  digitalWrite(REVERSE_RIGHT, HIGH);
           }
  void stop() 
  {
  digitalWrite(ENABLE_RIGHT, LOW);
  digitalWrite(ENABLE_LEFT, LOW);
  digitalWrite(FORWARD_LEFT, LOW);
  digitalWrite(FORWARD_RIGHT, LOW);
  digitalWrite(REVERSE_LEFT, LOW);
  digitalWrite(REVERSE_RIGHT, LOW);  
}              
void controlleft() {
  if (rightcounter > leftcounter) 
  {
     forwards(165,155);
  }
 
}

void controlright() {
   if (leftcounter < rightcounter) {
    
    forwards(155,165);
  }
}
