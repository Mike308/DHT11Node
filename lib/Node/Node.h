#ifndef NODE_H
#define NODE_H
#include <DHT.h>
#include "RF24Network.h"
class Node {
public:
  Node(DHT *sensor, RF24Network *network);
  void start();
  String getATResponse();
private:
    RF24Network *network;
    DHT *sensor;
    char rxBuff[32];
};
#endif