#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(22, 21); // CE, CSN
const byte address[6] = "00001";
unsigned long packetCount = 0;
unsigned long interval = 1000; // Interval between packets in milliseconds

void setup() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_HIGH);
  radio.powerUp();
  radio.stopListening();
}

void loop() {
  const char text[] = "Hello World";
  radio.write(&text, sizeof(text));
  packetCount++;
  delay(interval);
}