#include <virtuabotixRTC.h>
#include <TM1637Display.h>
#include "PinNum.h"
#include "ClockDisplay.h"
#include "Buzzer.h"
#include "LCD.h"
#include "PIR.h"


void setup() {
  // put your setup code here, to run once:
  
  clock.setBrightness(3);
  pinMode(buzzer, OUTPUT);

  pinMode(pirPin1, INPUT);
  pinMode(pirPin2, INPUT);    
  
  // LCD
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);   // 與電腦序列埠連線
  //Serial.println("BT is ready!");
  BT.begin(9600);   // 藍牙透傳模式的預設連線速率。
  
  //Comment the function after setting the time so that the time does not reset after feach upload
  //Format of time: (Second, Minute, Hour, Day of the Week, Day, Month, Year)
  //myRTC.setDS1302Time(45, 29, 8, 3, 8 , 06, 2022);
}

void loop() {
  // put your main code here, to run repeatedly:

  pirStat1 = digitalRead(pirPin1);
  pirStat2 = digitalRead(pirPin2); 
  myRTC.updateTime();
  displayTime();


  if(AlarmActivated == true){
    PIRDetection();
  }
  //PIR Movement Detection
  
  if(Awake == false && AlarmActivated == true){
    if(NextAlarm == true){
        NextAlarm = true;
        if(hours == AlarmHour && minutes == AlarmMinute){
          BuzzerSound();
          if(AlarmCount >=5)
          {
            AlarmCount = 0;
            NextAlarm =false;
          }
        }
    }
    
  }
  
  //Alarm 8:30 (Sound 5 times)
  if(hours == 8 && minutes == 30 && AlarmActivated == false)
  {
    BuzzerSound();
    if(AlarmCount >=5)
    {
      AlarmActivated = true;
      AlarmCount = 0;
    }
    Serial.println("Beep!");
  }
  
  if(data[6] == 1){
    RainSong();
    
  }
  BuzzerNoSound();  

  //LCD
  LCDDisplay();

  
  //Debugging
  Serial.print("Current Date / Time: ");
  Serial.print(myRTC.dayofmonth);
  Serial.print("/");
  Serial.print(myRTC.month);
  Serial.print("/");
  Serial.print(myRTC.year);
  Serial.print("  ");
  Serial.print(myRTC.hours);
  Serial.print(":");
  Serial.print(myRTC.minutes);
  Serial.print(":");
  Serial.println(myRTC.seconds);

  delay(1000);  
    
}
