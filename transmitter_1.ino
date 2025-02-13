#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 8); // CE, CSN
#define WHICH_NODE 3
const uint64_t wAddress[] = {0x7878787878LL, 0xB3B4B5B6F1LL, 0xB3B4B5B6CDLL};
const uint64_t PTXpipe = wAddress[ WHICH_NODE - 1 ]; 
void setup() {
  Serial.begin(115200);
  radio.begin();
  radio.setPALevel(RF24_PA_LOW);
  radio.setChannel(108);
  radio.openWritingPipe(PTXpipe);
  radio.stopListening();
}
void loop() {
  const char text[] = "Hello World";
  radio.write(&text, sizeof(text));
  delay(2000);
}
