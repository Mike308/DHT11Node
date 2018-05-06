#include <Arduino.h>
#include <DHT.h>

#include "RF24Network.h"

uint64_t pipeAddress = 0xF0F0F0F0E102;

RF24Network node(9, 10, "dhtNode");
DHT sensor(3, DHT11);

void setup()
{
    // put your setup code here, to run once:
    Serial.begin(9600);
    node.begin();
    node.openWritingPipe(pipeAddress);
    sensor.begin();
}

void loop()
{
    // put your main code here, to run repeatedly:

    unsigned long currentMillis = millis();
    if ((currentMillis % 2000) == 0)
    {
        float humidity = sensor.readHumidity();
        float temperature = sensor.readTemperature();
        String atCommand = "AT+DHT11=";
        String strValues = String(humidity) + "," + String(temperature);
        atCommand += strValues;
        Serial.println("AT Command: " + atCommand);
        node.sendMessage(atCommand);
    }
}