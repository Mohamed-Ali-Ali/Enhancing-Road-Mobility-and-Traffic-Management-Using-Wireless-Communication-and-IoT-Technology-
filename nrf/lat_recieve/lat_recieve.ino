#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(22, 21); // CE, CSN

const byte address[6] = "00001";
char payload[32]="";

unsigned long sendTime;
unsigned long recieveTime;
 unsigned long roundTripTime ;

unsigned long before_recieve;
unsigned long after_recieve;

int flag =1;
void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}
void loop() {

if ( radio.available()) {
    if(flag){
    before_recieve = micros();
    flag=0;
    } 
    radio.read( &payload, sizeof(payload));
    if(  strcmp( payload ,"100000" ) == 0 ){
    
    after_recieve= micros();
    recieveTime = after_recieve - before_recieve - 1000000;
    Serial.print("recieve time: ");
    Serial.print(recieveTime);
    Serial.println(" us");
    flag=1;
    }

    else{
    
    sendTime = atol(payload);
    Serial.print("send time: ");
    Serial.print(sendTime);
    Serial.println(" us");
    
    roundTripTime = recieveTime - sendTime ;
    
    Serial.print("latency: ");
    Serial.print(roundTripTime);
    Serial.println(" us");
    }
  }
}
