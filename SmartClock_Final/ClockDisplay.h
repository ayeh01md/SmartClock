#include "PinNum.h"


void displayTime() {
  
  /*
    if (Alarm_in_progress) {
    digitalWrite(Buzer, HIGH);
    delay(1000);
    digitalWrite(Buzer, LOW);
    delay(1000);
    }
  */
  
  if (myRTC.minutes != minutes) {

    clock.showNumberDecEx((int)myRTC.hours / 10 * 1000 + (myRTC.hours - ((int)myRTC.hours / 10) * 10) * 100 + (int)myRTC.minutes / 10 * 10 + myRTC.minutes - ((int)myRTC.minutes / 10) * 10, (0x80 >> 1), true);
    minutes = myRTC.minutes;
    hours = myRTC.hours;
  }

    

  
}
