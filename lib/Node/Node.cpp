#include "Node.h"

Node::Node(DHT *sensor, RF24Network *network) {
  this->network = network;
  this->sensor = sensor;
}

String Node::getATResponse() {
  float humidity = sensor->readHumidity();
  float temperature = sensor->readTemperature();
  String atResponse = "+H*T=" + String(humidity) + ";" + String(temperature);
  return atResponse;
}

void Node::start() {
  if (network->receiveMessage(rxBuff)) {
    char *atCommand = strtok(rxBuff, "?");
    if (strcmp(atCommand, "AT+DHT11") == 0) {
         String atResponse = getATResponse();
         network->sendMessage(atCommand);
    }
  }
}
