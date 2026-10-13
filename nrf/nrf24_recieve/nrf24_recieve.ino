#include <SPI.h>
#include <RF24.h>

#define CE_PIN    22
#define CSN_PIN   21

RF24 radio(CE_PIN, CSN_PIN);

const byte address[6] = "00001";

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(1, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}

void loop() {
  if (radio.available()) {
  char text[4][32] = {"","","",""};
  for (int i =0 ; i<4 ; i++ )
  {
    radio.read(&text[i], sizeof(text[i]));
    Serial.println(text[i]);
  }
}
}