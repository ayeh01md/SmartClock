#include "PinNum.h"


int numTones = 10;
int tones[] = {261, 277, 294, 311, 330, 349, 370, 392, 415, 440};
//            mid C  C#   D    D#   E    F    F#   G    G#   A

int melody[] = {261,261,392,392,440,440,392,392,349,349,330,330,294,294,261};


//Buzzer sound for 1 sec
void BuzzerSound() {
  //Advanced Sound 
  /*
  for (int i = 0; i < 15; i++)
  {
    tone(buzzer, melody[i]);
    delay(500);
  }
  noTone(buzzer);
  delay(1000);
  */
  
  /*
  for (int i = 0; i < numTones; i++)
  {
    tone(buzzer, tones[i]);
    delay(500);
  }
  noTone(buzzer);
  delay(1000);
  */
  if(AlarmCount < 5)
  {
    digitalWrite(buzzer,HIGH);
    delay(1000);
    AlarmCount++;
  }

}

//No Buzzer Sound for 1 sec
void BuzzerNoSound(){
  digitalWrite(buzzer,LOW);
  delay(1000);   
}

void RainSong(){
  for (int i = 0; i < 15; i++)
  {
    tone(buzzer, melody[i]);
    delay(500);
  }
  noTone(buzzer);
  delay(1000);
}
