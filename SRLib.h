#pragma once
#include <Arduino.h>

class shiftRegisters{
	public:
	shiftRegisters(byte registerCount = 1,byte latchPin = 9,byte clockPin = 10,byte dataPin = 8);
	void setPin(int num,byte type);
	void setClear();
	void begin();
	private:
	byte _registerCount;
	byte _latchPin;
	byte _clockPin;
	byte _dataPin;
	unsigned long inp = 0;
};

shiftRegisters::shiftRegisters(byte registerCount = 1,byte latchPin = 9,byte clockPin = 10,byte dataPin = 8){
	_registerCount = registerCount;
	_latchPin = latchPin;
	_clockPin = clockPin;
	_dataPin = dataPin;
}

void shiftRegisters::setPin(int num,byte type){
	if (type == 1)
		inp = inp | (long)1<<num;
	else if (type == 0)
		inp = inp & (~((long)1<<num));
	
	digitalWrite(_latchPin, LOW);
	for(int i = _registerCount;i >= 0;i--)
		shiftOut(_dataPin, _clockPin, MSBFIRST, (byte)(inp>>8*i));
	digitalWrite(_latchPin, HIGH);
	}
	
void shiftRegisters::setClear(){
	inp = 0;
	
	digitalWrite(_latchPin, LOW);
	for(int i = 0;i < _registerCount;i++)
		shiftOut(_dataPin, _clockPin, MSBFIRST, (byte)(inp>>8*i));
	digitalWrite(_latchPin, HIGH);
}

void shiftRegisters::begin(){
	pinMode(_latchPin, OUTPUT);
	pinMode(_clockPin, OUTPUT);
	pinMode(_dataPin, OUTPUT);
	digitalWrite(_latchPin, LOW);
}