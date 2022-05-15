#include <RussianRomanizer.h>

String sampleStrings[4] = {
  "Расцветали яблони и груши,",
  "Поплыли туманы над рекой;",
  "Выходила на берег Катюша,",
  "На высокий берег, на крутой."
};


void setup(){
  Serial.begin(9600);
  for (int i = 0; i < 4; i++){
    String rusText = sampleStrings[i];
    Serial.println(rusText);
    Serial.println(rtor(rusText));
  }
}

void loop(){
  if(Serial.available()){
    String myString = Serial.readString();
    Serial.println(myString);
    Serial.println(rtor(myString));
  }
}
