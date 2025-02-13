#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 8); 
#define WHICH_NODE 2
const uint64_t wAddress[] = {0x7878787878LL, 0xB3B4B5B6F1LL, 0xB3B4B5B6CDLL};
const uint64_t PTXpipe = wAddress[ WHICH_NODE - 1 ]; 
long randNumber;
void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
  radio.begin();
  radio.setPALevel(RF24_PA_LOW);
  radio.setChannel(108);
  radio.openWritingPipe(PTXpipe);
  radio.stopListening();
}
void loop() {
  randNumber = random(0,255);
  radio.write( &randNumber, sizeof(randNumber) );
  delay(1000);
}
