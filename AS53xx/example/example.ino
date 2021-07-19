#include <AS53xx.h>

#define MULTIPLIER 1
#define AS         2
#define BS         4
#define IS         7
#define A0S        A1

AS53 ASk (MULTIPLIER, AS, BS, IS, A0S);

void doJob() { //trigger-function needs to be asked by attachInterrupt
  ASk.interruptOnMe();
  Serial.print(ASk.curstep()); Serial.print(" is "); Serial.print(ASk.curmcm()); Serial.println(" in micrometers.");
}

void setup() {
attachInterrupt(digitalPinToInterrupt(AS), doJob, CHANGE); // interrupt needs to ask function containing trigger

Serial.begin(115200);

}

void loop() {
delay(1);
}

