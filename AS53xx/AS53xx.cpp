#include "AS53xx.h"

AS53::AS53(byte typ, byte As, byte Bs, byte Is, byte A0s){
_multiplier = typ;
_A = As;
_B = Bs;
_I = Is;
_An = A0s;

pinMode(A0s,INPUT);
pinMode(As ,INPUT);
pinMode(Bs ,INPUT);
pinMode(Is ,INPUT);


}



void AS53::interruptOnMe( ){
  actions();
}

void AS53::resetCounter(){
	encCounter = 0;
}

float AS53::curmcm(){
	 mcm = encCounter*_multiplier;
   return mcm;
}

int AS53::curstep(){
	return encCounter;
}

void AS53::actions(){
	stringAbsence = (analogRead(_An) > 700) ? 0 : 1; //String check
    if (!stringAbsence) {
    return;
  }

  index = digitalRead(_I);

  startState = digitalRead(_A);                  //Decode
  if (startState != lastState) {
    encCounter += (digitalRead(_B) != lastState) ? -1 : 1;
    lastState = startState;

  }
}