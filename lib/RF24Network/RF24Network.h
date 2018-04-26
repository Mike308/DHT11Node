#include <RF24.h>

class RF24Network : public RF24
{

  public:
    RF24Network(uint16_t cePin, uint16_t csPin) : RF24(cePin, csPin){}
    void setNodeAdress(String nodeAdress);
    bool sendMessage(String message);

  private:
    String nodeAdress;

};