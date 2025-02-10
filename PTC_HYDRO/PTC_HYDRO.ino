/*Libary Import*/
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <PubSubClient.h>
#include <ESP8266WiFiMulti.h>
#include <ArduinoOTA.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#ifndef STASSID
#define STASSID "Progtech 3BB_2.4GHz"
#define STAPSK "progtech@"
#endif

/* Pin Mapping */

#define X0 D0
#define X1 D1
#define X2 D2
#define SS0 D5
#define LED D4
#define Y0 D6
#define Y1 D7
#define A0 A0




/* Variable */

//WIFI
const char* ssid = STASSID;
const char* password = STAPSK;



// MQTT Broker settings
WiFiClient espClientMqtt;
// WiFiClient espClientHttp;
ESP8266WiFiMulti wifiMulti;
const char* mqtt_server = "192.168.1.9";
PubSubClient mqttClient(espClientMqtt);
unsigned long lastMsg = 0;
#define MSG_BUFFER_SIZE	(50)
char msg[MSG_BUFFER_SIZE];
int value = 0;

//Temperature
float tempCelsius;    // temperature in Celsius
float tempFahrenheit; // temperature in Fahrenheit

//INPUT - OUTPUT STATE
bool X0State = 1,X1State = 1,X2State = 1;
bool SS0State = 1;
bool LEDState = 1,Y0State = 1, Y1State = 1;
bool A0Data = 0;



/* Library Config */

//Temperature
OneWire oneWire(SS0);         // setup a oneWire instance 
DallasTemperature tempSensor(&oneWire); // pass oneWire to DallasTemperature library


void setup() {

ini_wifi();

pinMode(X0,INPUT_PULLUP);
pinMode(X1,INPUT_PULLUP);
pinMode(X2,INPUT_PULLUP);
pinMode(A0,INPUT);
pinMode(Y0,OUTPUT);
pinMode(Y1,OUTPUT);
pinMode(LED,OUTPUT);

LED_OK_STATUS();

tempSensor.begin();    // initialize the sensor

mqttClient.setServer(mqtt_server, 1883);
mqttClient.setCallback(callback);

}


