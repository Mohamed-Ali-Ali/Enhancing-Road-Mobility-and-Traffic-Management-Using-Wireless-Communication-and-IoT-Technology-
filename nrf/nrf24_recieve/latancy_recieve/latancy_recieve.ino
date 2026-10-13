#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(22, 21); // CE, CSN
const byte address[6] = "00001";
char payload[32];

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}

void loop() {
  while ( radio.available()) {
    radio.read(&payload, sizeof(payload));
    Serial.print("Received: ");
    Serial.println(payload);
    
    // Send acknowledgment with the received timestamp
    radio.stopListening();
    delay(20);
    radio.write(&payload, sizeof(payload));
    Serial.print("Sent ACK: ");
    Serial.println(payload);
    radio.startListening();
    delay(20);
  }
  delay(100); // Small delay to prevent overwhelming the receiver
}