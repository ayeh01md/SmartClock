// 引用程式庫
#include <SoftwareSerial.h>   
#include "DHT.h"
#define DHTPIN 13
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

// 定義連接藍牙模組的序列埠
SoftwareSerial BT(8, 9); // 接收腳, 傳送腳

int started;
int isItRainy(int);

void setup() {
  BT.begin(9600);
  pinMode(A5, INPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600);
  dht.begin();
  started = 0;
}

void loop() {
  delay(2000);
  
  int rain = 1023 - analogRead(A0);
  //Serial.print("rain : ");
  //Serial.println(rain);
  int rainy = isItRainy(rain);
  Serial.print("rainy : ");
  Serial.println(rainy);
  
  int UV = analogRead(A5);
  //Serial.print("UV : ");
  //Serial.println(UV);
  int UV_value = UV / 100;
  Serial.print("UV : ");
  Serial.println(UV_value);

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  int data_h, data_t, data_hic;
  data_h = int(h);
  data_t = int(t);
  data_hic = int(hic);
  
  Serial.print(F("Humidity: "));
  Serial.print(data_h);
  Serial.print(F("%  Temperature: "));
  Serial.print(data_t);
  Serial.print(F("°C "));
  Serial.print(F(" Heat index: "));
  Serial.print(data_hic);
  Serial.println(F("°C "));

  started++;
  if(started > 10) {
    started--;
    // 若收到藍牙模組的資料，則送到「序列埠監控視窗」
    BT.println('a');
    BT.println(data_h);
    BT.println(data_t);
    BT.println(data_hic);
    BT.println(rainy);
    BT.println(UV_value);
  }
}

int isItRainy(int rain) {
  if(rain > 0) {
    return 1;
  }else if(rain == 0) {
    return 0;
  }
}
