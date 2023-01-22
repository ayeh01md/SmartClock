#ifndef PIN_NUM
#define PIN_NUM

//Define PIN
int CLK = 2;
int DIO=3;
int buzzer =4;

int pirPin1 = 6;
int pirPin2 = 5;

virtuabotixRTC myRTC(A1, A2, A3);
TM1637Display clock(CLK,DIO);  

//Clock Variable
int minutes;
int hours;

//PIR 1 and 2 Status
int pirStat1= 0;
int pirStat2= 0;

//How many alarms have sounded
int AlarmCount = 0;

//Alarm Variable
int AlarmMinute;
int AlarmHour;

//If the person is up and out of bed
bool Awake = false;

//8:30 Alarm
bool AlarmActivated = false;

//Repeat Alarm
bool NextAlarm = false;;

int PIR1Count=0;
bool SoundAlarm = false;
int AwakeCount;
#endif
