#define Analog 1
#define A      2
#define B      8
#define In     7

boolean lastState;         // "A" state to save
boolean stateStart;        // "A" state to compare
int lastC;
int encCounter;


void setup() {
  pinMode(A, INPUT);
  pinMode(B, INPUT);

  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(A), act, CHANGE);
}

void loop() {
  
 if(encCounter != lastC){ Serial.print(encCounter); lastC = encCounter; Serial.print(" (height: "); Serial.print(analogRead(Analog)); Serial.println(" )");}

}

void act() {  
  stateStart = digitalRead(A);                  //Decode
  if (stateStart != lastState) {
    encCounter += (digitalRead(B) != lastState) ? -1 : 1;
    lastState = stateStart;
    
  }

}
