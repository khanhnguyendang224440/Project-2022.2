#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>            
LiquidCrystal_I2C lcd(0x3F,16,2);
const int DHTPIN = 4;      
const int DHTTYPE = DHT11;  
DHT dht(DHTPIN, DHTTYPE);
int button = 7;


void setup()
{
  Serial.begin(9600);//Mở cổng Serial ở mức 9600
  pinMode (2, INPUT);
  pinMode(A0, INPUT);
  pinMode(button, INPUT_PULLUP);
  lcd.init();                    
  lcd.backlight();
  dht.begin();
}
 
void loop()
{
  int state = digitalRead(button);
 
  if (state == 1) {
  int smv = analogRead(A0);     // Ta sẽ đọc giá trị hiệu điện thế của cảm biến
                                      // Giá trị được số hóa thành 1 số nguyên có giá trị
                                      // trong khoảng từ 0 đến 1023
  float t = dht.readTemperature();
  int fpercentage = map(smv, 0, 1023, 1, 100);
  int rpercentage = 100 - fpercentage;


  if (0 <= rpercentage && rpercentage  < 20) {
    Serial. print("Do am: ");  
  Serial. print(rpercentage); Serial. println("%"); Serial. print(" ");  Serial. print("~"); Serial. print(" "); Serial. print(" verydry, need a lot of water ");
  Serial.print("\nNhiet do: ");
  Serial.println(t);      
  delay(1000);
   
  }


  if (20 <= rpercentage && rpercentage <= 40) {
    Serial. print("Do am: ");  
  Serial. print(rpercentage); Serial. println("%"); Serial. print(" ");  Serial. print("~"); Serial. print(" "); Serial. print(" dry, need a lil bit of water ");
  Serial.print("\nNhiet do: ");
  Serial.println(t);      
  delay(1000);
   
  }
 
  if (40 < rpercentage && rpercentage <= 55) {
    Serial. print("Do am: ");  
  Serial. print(rpercentage); Serial. println("%"); Serial. print(" ");  Serial. print("~"); Serial. print(" "); Serial. print(" normal, optimized ");
  Serial.print("\nNhiet do: ");
  Serial.println(t);      
  delay(1000);
   
  }


  if (55 < rpercentage && rpercentage <= 70) {
    Serial. print("Do am: ");  
  Serial. print(rpercentage); Serial. println("%"); Serial. print(" ");  Serial. print("~"); Serial. print(" "); Serial. print(" wet, need less water ");
  Serial.print("\nNhiet do: ");
  Serial.println(t);    
  delay(1000);
  }


  if (70 < rpercentage && rpercentage <= 100) {
    Serial. print("Do am: ");  
  Serial. print(rpercentage); Serial. println("%"); Serial. print(" ");  Serial. print("~"); Serial. print(" "); Serial. print(" verywet, need less water ");
  Serial.print("\nNhiet do: ");
  Serial.println(t);    
  delay(1000);
  }


  lcd.setCursor(2,0);
  lcd. print("Do am: ");
  lcd. print(rpercentage); lcd. println("%");  
  lcd.setCursor(0,1);
  lcd.print("Nhiet do: ");
  lcd.println(t);      
 
  delay(500); }
 
 
  }
