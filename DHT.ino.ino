#include <LiquidCrystal.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

int temperatura;
int humedad;
int sensor = 8;
int rele1 = 12;
int rele2 = 13;
DHT dht(sensor, DHT11);
LiquidCrystal lcd(7,6,5,4,3,2);

void ControlTemp(int) {
    if (temperatura < 21) {
        digitalWrite(rele1, HIGH);
    } else {
      (temperatura > 23);
        digitalWrite(rele1, LOW);        
    }
}

void ControlHumedad(int) {
    if (humedad < 45) {
        digitalWrite(rele2, HIGH);
    } else {
      (humedad > 55);
        digitalWrite(rele2, LOW);
    }
}

 
void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.begin(16,2);
}

void loop() {
  
  //Pantalla
  lcd.setCursor(0,0);
  lcd.print("Temperat:  ");
  lcd.print(temperatura);
  lcd.print("°C");
  lcd.setCursor(0,1);
  lcd.print("Humedad:   ");
  lcd.print(humedad);
  lcd.print("%");
  
  //Reles
  digitalWrite(rele1, LOW);
  digitalWrite(rele1, HIGH);
  digitalWrite(rele2, LOW);
  digitalWrite(rele2, HIGH);

  //Sensor DHT11
  temperatura = dht.readTemperature();
  humedad = dht.readHumidity();
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.print("Humedad: ");
  Serial.println(humedad);
  delay(500);
  
  //Controladores
  ControlTemp(temperatura);
  ControlHumedad(humedad);

}
