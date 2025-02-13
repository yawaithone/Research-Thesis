#include <SPI.h>
#include <nRF24L01.h> 
#include <RF24.h> 

RF24 radio(7, 8);
const uint64_t rAddress[] = {0x7878787878LL, 0xB3B4B5B6F1LL, 0xB3B4B5B6CDLL};

void setup() {
   randomSeed(analogRead(0));
   Serial.begin(115200);
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
    
    byte pipeNum = 0;
    byte gotByte= 0;
    
    while(radio.available(&pipeNum)){ //Check if received data
     radio.read( &gotByte, 1 ); //read one byte of data and store it in gotByte variable
     Serial.print("Received data from car: "); 
     Serial.println(pipeNum + 1);
     Serial.print("The number is: ");
     Serial.println(gotByte);
    
    }
delay(100);
      
}
