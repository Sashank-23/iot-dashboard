#include <WiFi.h>
#include <Wire.h>

#include <Adafruit_BME280.h>
#include <Adafruit_INA219.h>

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include <Firebase_ESP_Client.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH,SCREEN_HEIGHT,&Wire,-1);

Adafruit_BME280 bme;
Adafruit_INA219 ina219;

#define TRIG 5
#define ECHO 18

#define WIFI_SSID "YOUR_WIFI"
#define WIFI_PASSWORD "YOUR_PASS"

#define DATABASE_URL "https://iotproject-cb5d4-default-rtdb.firebaseio.com/"
#define DATABASE_SECRET "riYCQJvXDNY15SR2WVaD4OtAWmaYc3lzkJ6qWkhI"

FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

float temperature;
float humidity;
float pressure;

float voltage;
float current;
float power;

float distance;

float readDistance()
{

digitalWrite(TRIG,LOW);
delayMicroseconds(2);

digitalWrite(TRIG,HIGH);
delayMicroseconds(10);

digitalWrite(TRIG,LOW);

long duration=pulseIn(ECHO,HIGH);

float dist=duration*0.034/2;

return dist;

}

void readSensors()
{

temperature=bme.readTemperature();

humidity=bme.readHumidity();

pressure=bme.readPressure()/100.0F;

voltage=ina219.getBusVoltage_V();

current=ina219.getCurrent_mA();

power=ina219.getPower_mW();

distance=readDistance();

}

void setup()
{

Serial.begin(115200);

Wire.begin(21,22);

bme.begin(0x76);

ina219.begin();

display.begin(SSD1306_SWITCHCAPVCC,0x3C);

display.clearDisplay();

display.setTextSize(1);

display.setTextColor(SSD1306_WHITE);

pinMode(TRIG,OUTPUT);

pinMode(ECHO,INPUT);

WiFi.begin(WIFI_SSID,WIFI_PASSWORD);

while(WiFi.status()!=WL_CONNECTED)
{
delay(500);
Serial.print(".");
}

Serial.println("WiFi Connected");

config.database_url=DATABASE_URL;
config.signer.tokens.legacy_token=DATABASE_SECRET;

Firebase.begin(&config,&auth);

Firebase.reconnectWiFi(true);

}

void loop()
{

readSensors();

display.clearDisplay();

display.setCursor(0,0);

display.print("Temp:");
display.println(temperature);

display.print("Hum:");
display.println(humidity);

display.print("Volt:");
display.println(voltage);

display.print("Curr:");
display.println(current);

display.print("Dist:");
display.println(distance);

display.display();

Firebase.RTDB.setFloat(&fbdo,"sensor/temperature",temperature);

Firebase.RTDB.setFloat(&fbdo,"sensor/humidity",humidity);

Firebase.RTDB.setFloat(&fbdo,"sensor/pressure",pressure);

Firebase.RTDB.setFloat(&fbdo,"sensor/voltage",voltage);

Firebase.RTDB.setFloat(&fbdo,"sensor/current",current);

Firebase.RTDB.setFloat(&fbdo,"sensor/power",power);

Firebase.RTDB.setFloat(&fbdo,"sensor/distance",distance);

delay(3000);

}