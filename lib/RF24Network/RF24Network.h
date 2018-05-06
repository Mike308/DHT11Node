#include <RF24.h>

class RF24Network : public RF24
{

  public:
    RF24Network(uint16_t cePin, uint16_t csPin) : RF24(cePin, csPin){}
    RF24Network(uint16_t cePin, uint16_t csPin, String nodeAddress, char separator = '|');
    void setNodeAddress(String nodeAddress);
    bool sendMessage(String message);

  private:
    String nodeAddress;
    char buf[128];
    char separator;

};