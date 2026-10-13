
#include <SoftwareSerial.h>

SoftwareSerial mySerial(16, 17); // RX, TX
String id ="";
int flag=0;
String car[5]={"1234","red","audi","node1","1512"};
// String car_id="1234";
// String color="red";
// String model="audi";
// String node="node1";
// String location="1512";
void setup() {
  Serial.begin(9600);
  Serial2.begin(9600);    // Initialize hardware serial communication
  mySerial.begin(9600);  // Initialize software serial communication
}

void loop() {
 
   if(mySerial.available()) {
    id = readStringFromSerial(mySerial);
    delay(100);
    mySerial.println( "Ack");
    Serial.println( String(id));
    delay(100);
    // if ( flag==0  &&  id == car_id)
    //     {
          for(int i=0;i<5;i++)
          {
             delay(100);
             mySerial.println( String(car[i]));
          }
          flag++;
      //  }
  }

  delay(1000); // Wait for 1 second
}

String readStringFromSerial(SoftwareSerial &serial) {
  String result = "";
  while (serial.available()) {
    char c = serial.read();
    if (c == '\n') {
      break; // End of line
    }
    result += c;
  }
  return result;
}
