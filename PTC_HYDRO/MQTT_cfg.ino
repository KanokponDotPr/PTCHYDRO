void callback(char* topic, byte* payload, unsigned int length)
{
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) 
  {
    Serial.print((char)payload[i]);
  }
  Serial.println();

  // Switch on the LED if an 1 was received as first character
  /*if ((char)payload[0] == '0') 
  {
    X0State = 0;
    LEDState = 0;
    mqttClient.publish("sf/X0State", "OFF");
    mqttClient.publish("sf/LEDState", "OFF");
    digitalWrite(LED, 1);
  } 

  else if ((char)payload[0] == '1')  {
    X0State = 1;
    mqttClient.publish("sf/X0State", "ON");
  } 

  else if ((char)payload[0] == '2')  {
    LEDState = 1;
    mqttClient.publish("sf/LEDState", "ON");
    digitalWrite(LED, 0);
  } 
  delay(3000);
  */
}

void reconnect()
{
  // Loop until we're reconnected
  while (!mqttClient.connected()) 
  {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (mqttClient.connect(clientId.c_str())) 
    {
      Serial.println("connected");
      // Once connected, publish an announcement...
      mqttClient.publish("sf/control", "hello world");
      // ... and resubscribe
      mqttClient.subscribe("sf/control");
    } 
    else 
    {
      Serial.print("failed, rc=");
      Serial.print(mqttClient.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}