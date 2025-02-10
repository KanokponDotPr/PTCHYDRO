void loop() {
  if (!mqttClient.connected()) 
  {
    reconnect();
    ArduinoOTA.handle();
  }
  mqttClient.loop();
  ArduinoOTA.handle();


  X0State = mqttClient.subscribe("sf/X0State");
  Serial.println(X0State);
  if(X0State == '1') { digitalWrite(LED,0); } 
  if(X0State == '0') { digitalWrite(LED,1); } 

  // mqttClient.publish("sf/LEDState", "OFF");
  // delay(5000);
  // mqttClient.publish("sf/LEDState", "OFF");
  // delay(5000);
  // mqttClient.publish("sf/LEDState", "ON");
   delay(100);
    
}