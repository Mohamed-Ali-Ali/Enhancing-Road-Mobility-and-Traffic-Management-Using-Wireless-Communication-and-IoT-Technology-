#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(22, 21); // CE, CSN
const byte address[6] = "00001";
unsigned long receivedPackets = 0;
unsigned long lostPackets = 0;
unsigned long expectedPackets = 0;
unsigned long interval = 10; // Interval between packets in milliseconds
unsigned long startTime;
const unsigned long duration = 10000; // Test duration in milliseconds (e.g., 1 minute)

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_HIGH);
  radio.powerUp();
  radio.startListening();
  startTime = millis();
}

void loop() {
  if (millis() - startTime < duration) {
    if (radio.available()) {
      char text[32] = "";
      radio.read(&text, sizeof(text));
      receivedPackets++;
    } else {
      lostPackets++;
    }
    delay(interval);
  } else {
    // Calculate PER
    expectedPackets = receivedPackets + lostPackets;
    float PER = (float)lostPackets / expectedPackets * 100;

    // Print results
    Serial.print("Expected Packets: ");
    Serial.println(expectedPackets);
    Serial.print("Received Packets: ");
    Serial.println(receivedPackets);
    Serial.print("Lost Packets: ");
    Serial.println(lostPackets);
    Serial.print("PER: ");
    Serial.print(PER);
    Serial.println(" %");

    // Reset counters and timer for a new test cycle
    receivedPackets = 0;
    lostPackets = 0;
    startTime = millis();
  }
}