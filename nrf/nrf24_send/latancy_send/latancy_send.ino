
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(22, 21); // CE, CSN
const byte address[6] = "00001";
unsigned long sendTime;
char payload[32];

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {
  // Prepare payload with current time
  sendTime = millis();
  snprintf(payload, sizeof(payload), "%lu", sendTime);
  
  // Send payload
 bool x= radio.write(&payload, sizeof(payload));
  if (x) {
    Serial.print("Sent: ");
    Serial.println(payload);

    // Start listening for acknowledgment
    radio.startListening();
    unsigned long startTime = millis();
    while (millis() - startTime < 500) { // Timeout after 500 ms
      
      if (radio.available()) {
        radio.read(&payload, sizeof(payload));
        unsigned long ackTime = atol(payload);
        unsigned long roundTripTime = millis() - ackTime;
        Serial.print("Received ACK. Round-trip time: ");
        Serial.print(roundTripTime);
        Serial.println(" ms");
        Serial.print("One-way latency: ");
        Serial.print(roundTripTime / 2.0);
        Serial.println(" ms");
        break;
      }
    }
    radio.stopListening();
  } 
  else {
    Serial.println("Failed to send");
  }
  delay(1000); // Wait 1 second before sending the next packet
}