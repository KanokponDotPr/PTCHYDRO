/*Libary Import*/
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
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
#define PWM0 D5
#define LED D4
#define Y0 D6
#define Y1 D7
#define A0 A0


/* Variable */
//WIFI
const char* ssid = STASSID;
const char* password = STAPSK;


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


}


