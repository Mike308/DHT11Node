#include <Arduino.h>
#include <DHT.h>
#include <printf.h>
#include "RF24Network.h"

uint64_t pipeAddress = 0xF0F0F0F0F101;
uint64_t receivingPipeAddress = 0xF0F0F0F0E101;
char rxBuf[128];

RF24Network node(9, 10, "dhtNode");
DHT sensor(3, DHT11);

void setup()
{
    Serial.begin(9600);
    printf_begin();
    node.begin();
    node.openWritingPipe(pipeAddress);
    node.openReadingPipe(1, receivingPipeAddress);
    node.startListening();
   // node.printDetails();
    sensor.begin();
}

void loop()
{

    if (node.receiveMessage(rxBuf))
    {
        char *atCommand = strtok(rxBuf, "?");
        if (strcmp(atCommand, "AT+DHT11") == 0)
        {
            float humidity = sensor.readHumidity();
            float temperature = sensor.readTemperature();
            String atCommand = "AT+DHT11=";
            String strValues = String(humidity) + "," + String(temperature);
            atCommand += strValues;
            node.sendMessage(atCommand);
        }
    }
}