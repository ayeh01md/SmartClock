#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>   

LiquidCrystal_I2C lcd(0x27, 16, 2);

// 定義連接藍牙模組的序列埠
SoftwareSerial BT(10, 11); // 接收腳, 傳送腳
// 儲存接收資料的變數
int display_data[5];
char val, data[8];


byte newChar[8] = {
        B00100,
        B01110,
        B01110,
        B11111,
        B11111,
        B11111,
        B11111,
        B01110
}; // create an image of rain

void LCDDisplay() {
  //Clear LCD
  lcd.clear();

  //Read Slave Arduino Data
  if (BT.available()) {
    val = BT.read();
  }
  while (val != 'a') {
     if (BT.available()) {
      val = BT.read();
    }
  }
  
  for(int i = 0; i < 8; i++) {
    // 若收到「序列埠監控視窗」的資料，則送到藍牙模組
    if (Serial.available()) {
      data[i] = Serial.read();
      BT.print(data[i]);
    }
    // 若收到藍牙模組的資料，則送到「序列埠監控視窗」
    if (BT.available()) {
      val = BT.read();
    }
    while (val < '0' || val > '9') {
      if (BT.available()) {
        val = BT.read();
      }
    }
    data[i] = val;
    //Serial.println(data[i]);
  }

  
  //Display Humidity
  lcd.print("HUM:");
  lcd.print(data[0]);
  lcd.print(data[1]);
  lcd.print("%");

  //Display UV
  lcd.setCursor(8,0);
  lcd.print("UV:");
  lcd.print(data[7]);

  //Display Rain Droplet
  if(data[6] == 1){
    lcd.createChar(0, newChar);
    lcd.setCursor(14,0);
    lcd.write(0);
  }

  
  //Display Temperature
  lcd.setCursor(0,1);
  lcd.print("TEMP:");
  lcd.print(data[2]);
  lcd.print(data[3]);
  lcd.print((char)223);
  lcd.print("C");

  //Bar line
  lcd.setCursor(10,1);
  lcd.print((char)124);

  //Display Heat index (Apparent Temperature)
  lcd.setCursor(12,1);
  lcd.print(data[4]);
  lcd.print(data[5]);
  lcd.print((char)223);
  lcd.print("C");
}
