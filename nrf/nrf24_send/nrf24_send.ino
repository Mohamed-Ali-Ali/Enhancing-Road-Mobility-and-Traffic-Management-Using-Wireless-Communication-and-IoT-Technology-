#include <SPI.h>
#include <RF24.h>

#define CE_PIN    22
#define CSN_PIN   21

RF24 radio(CE_PIN, CSN_PIN);

const byte address[6] = "00001";

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {
  const char text [4][32] =  { "car id : 1234" , "type : taxi" , " model: toyota" , "color : white" };
 for (int i =0 ; i<4 ; i++ )
 {
      radio.write(&text[i], sizeof(text[i]));
      delay(1000);
 }
   
}