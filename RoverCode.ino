// Motor A connections
int enA = 9;
int in1 = 8;
int in2 = 7;
// Motor B connections
int enB = 3;
int in3 = 5;
int in4 = 4;

//Bluetooth Input
char btInput;

float timeNeeded = 0;
float distance = 0;
void setup() {
  // Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  // Turn off motors - Initial state
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  //Test using the onboard LED
  pinMode(13, OUTPUT);

  Serial.begin(9600);
}

void loop() 
{
    if(Serial.available() > 0)
    {
      btInput = Serial.read();
      switch(btInput)
      {
        case 'F':
          analogWrite(enA, 255);
          analogWrite(enB, 255);
          digitalWrite(in1, LOW);
          digitalWrite(in2, HIGH);
          digitalWrite(in3, HIGH);
          digitalWrite(in4, LOW);
   
          break;
        case 'B':
            analogWrite(enA, 255);
            analogWrite(enB, 255);
            digitalWrite(in1, HIGH);
            digitalWrite(in2, LOW);
            digitalWrite(in3, LOW);
            digitalWrite(in4,HIGH);
          
            break;
        case 'L':
          analogWrite(enA, 255);
          analogWrite(enB, 255);
          digitalWrite(in1, LOW);
          digitalWrite(in2, LOW);
          digitalWrite(in3, HIGH);
          digitalWrite(in4, LOW);
  
          break;
        case 'R':
          analogWrite(enA, 255);
          analogWrite(enB, 255);
          digitalWrite(in1, LOW);
          digitalWrite(in2, HIGH);
          digitalWrite(in3, LOW);
          digitalWrite(in4, LOW);
 
          break;
        default:
          digitalWrite(in1, LOW);
          digitalWrite(in2, LOW);
          digitalWrite(in3, LOW);
          digitalWrite(in4, LOW);

          break;
      }
    }
}
