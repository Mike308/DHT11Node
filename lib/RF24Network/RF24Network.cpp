#include "RF24Network.h"

RF24Network::RF24Network(uint16_t cePin, uint16_t csPin, String nodeAddress) : RF24(cePin, csPin)
{
    this->nodeAddress = nodeAddress;
}

bool RF24Network::sendMessage(String message)
{
    
    String dataToSend = nodeAddress + "|" + message;
    dataToSend.toCharArray(buf, 128);
    return this->write(&buf, strlen(buf));
}

void RF24Network::setNodeAddress(String nodeAddress)
{
    this->nodeAddress = nodeAddress;
}





