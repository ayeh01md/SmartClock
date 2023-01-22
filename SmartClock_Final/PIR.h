#include "pinNum.h"


void PIRDetection()
{
  if(Awake == false){
    //Still on bed
    if(pirStat2 == LOW){
      //Check if Alarm for the next minute is set
      if(NextAlarm == false){
        Serial.println("Not Awake");
        //Work on changing to next minute
        AlarmHour = hours;
        AlarmMinute = minutes+1;
        if(AlarmMinute == 60){
          AlarmMinute = 0;
          AlarmHour = hours+1;
          
        }
        NextAlarm = true;
        Serial.println("Alarm set");       
      } 
    }
    else{
      Awake = true;
    }
 
  }
  
  //Person has left bed (detect if he returns)
  else{
    if(pirStat1 == HIGH){
      Awake = false;
      Serial.println("Back to sleep"); 
    }
  }
  
}



/*

Case 1: PIR1 true PIR2 false

Case 2: PIR1 false PIR2 true

PIR 1 Priority over PIR 2

 AlarmMinute = minutes+1;
  AlarmHour = hour+1;
 */
