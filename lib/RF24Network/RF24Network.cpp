#include "RF24Network.h"

bool RF24Network::sendMessage(String message)
{
    char buf[50];
    String dataToSend = nodeAdress + "|" + message;
    dataToSend.toCharArray(buf, 50);
    return this->write(&buf, strlen(buf));
}

void RF24Network::setNodeAdress(String nodeAdress)
{
    this->nodeAdress = nodeAdress;
}

