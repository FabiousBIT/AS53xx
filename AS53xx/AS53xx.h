#ifndef AS53xx_H
#define AS53xx_H

#include <Arduino.h>

class AS53 {
public:
//get sensor type (type: 1 - 5304, 0 - 5306 / Analog, A, B, Index pins )
		 AS53(byte typ, byte As, byte Bs, byte Is, byte A0s);
	
//Attach interrupt on that function in global code to make this thing work (like in example)
	void interruptOnMe();

//reset counter
	void resetCounter();

//return counted steps
	int  curstep();

//return counted micrometers
	float curmcm();

private:
	
    void actions();
	
	bool stringAbsence;
	bool startState;
	bool lastState;
	bool index;

	int encCounter;
	float mcm;
	float _multiplier = 0;
	byte _A;
	byte _An;
	byte _B;
	byte _I;

};
#endif