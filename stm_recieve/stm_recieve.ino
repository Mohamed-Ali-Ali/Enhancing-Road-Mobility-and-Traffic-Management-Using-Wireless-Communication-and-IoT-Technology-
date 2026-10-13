
#include <SoftwareSerial.h>
SoftwareSerial mySerial (A1,A0);
String test;
String car[5];

// String car_id="";
// String color="";
// String model="";
// String node="";
// String location="";


String id ="1234";
void setup() {
  Serial.begin(9600);
  Serial2.begin(9600);
  mySerial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

if(mySerial.available()) {
 
  mySerial.println(String(id));
  delay(100);
  test= readStringFromSerial(mySerial);
  Serial.println( String(test));
  delay(100);
  // if(test == "Ack")
  // {
    for(int i=0;i<5;i++)
      {
        delay(100);
        car[i] = readStringFromSerial(mySerial);
        Serial.println( "Recived: " + String( car[i]) );
     
      }
  // }
}
delay(1000);
}
String readStringFromSerial(SoftwareSerial &nserial) {
  String result = "";
  while (nserial.available()) {
    char c = nserial.read();
    
    if (c == '\n') {
      break; // End of line
    }
    result += c;
    
  }
  return result;
}