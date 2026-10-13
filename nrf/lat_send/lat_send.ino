#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(22, 21); // CE, CSN
const byte address[6] = "00001";
char stime[32]= "";
unsigned long sendTime;

unsigned long before_send;
unsigned long after_send;

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {
  // put your main code here, to run repeatedly:
  before_send=millis();
  char payload[32]= "100000" ;
  radio.write(&payload, sizeof(payload));
  after_send = millis();
  sendTime = after_send - before_send;
  snprintf(stime, sizeof(stime), "%lu", sendTime);
  Serial.println("send time: " + (String)stime);
  delay(1000);
  radio.write( &stime, sizeof(stime) );
  delay(1000);
}
