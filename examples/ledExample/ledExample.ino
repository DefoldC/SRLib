#include <SRLib.h>

#define chipCount 3  // количество подключенных регистров (максимум 4)
#define latchPin 9  // ST_CP 
#define clockPin 10  // SH_CP 
#define dataPin 8   // DS 
#define delayMs 30 // задержка

shiftRegisters ledArray(chipCount,latchPin,clockPin,dataPin); // инициализация

void setup() {
  ledArray.begin();// тож инициалихация
  ledArray.setClear(); // тушим все светодиоды
}

void loop() {
    for (int i = 0 ; i < 24 ; i++) {
    ledArray.setPin(i, HIGH); // включение светодиода
    delay(delayMs);
  }
  for (int a = 24 ; a >= 0 ; a--) {
    ledArray.setPin(a, LOW);  // выключение светодиода
    delay(delayMs);
  }
}
