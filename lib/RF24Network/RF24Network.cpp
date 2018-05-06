#include "RF24Network.h"

RF24Network::RF24Network(uint16_t cePin, uint16_t csPin, String nodeAddress, char separator) : RF24(cePin, csPin)
{
    this->nodeAddress = nodeAddress;
    this->separator = separator;
}

bool RF24Network::sendMessage(String message)
{
    String dataToSend = nodeAddress + String(separator) + message;
    dataToSend.toCharArray(buf, 128);
    return this->write(&buf, strlen(buf));
}

void RF24Network::setNodeAddress(String nodeAddress)
{
    this->nodeAddress = nodeAddress;
}
