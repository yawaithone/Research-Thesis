#include <SPI.h>
#include <nRF24L01.h> 
#include <RF24.h> 

RF24 radio(7, 8);
const uint64_t rAddress[] = {0x7878787878LL, 0xB3B4B5B6F1LL, 0xB3B4B5B6CDLL};
byte data1=0;
byte data2=0;
void setup() {
   randomSeed(analogRead(0));
   Serial.begin(9600);
   Serial.println("Date & Time, Car_1, Car_2");
   radio.begin(); 
   radio.setPALevel(RF24_PA_LOW);   
   radio.setChannel(108);

   radio.openReadingPipe(0,rAddress[0]);
   radio.openReadingPipe(1,rAddress[1]);
   radio.openReadingPipe(2,rAddress[2]);
   radio.startListening();                 // Start listening for messages
}

void loop()  
{   
    delay(1000);
    byte pipeNum = 0;
    byte gotByte= 0;
    
    while(radio.available(&pipeNum)){ //Check if received data
     radio.read( &gotByte, 1); //read one byte of data and store it in gotByte variable
     if (pipeNum==0){
      data1=gotByte;
     }
    else if (pipeNum==1){
      data2=gotByte;
    }
 }

   Serial.print(",");
   Serial.print(data1);
   Serial.print(",");
   Serial.println(data2);
      
}
