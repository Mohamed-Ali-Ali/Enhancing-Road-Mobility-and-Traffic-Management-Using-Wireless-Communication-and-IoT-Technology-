#include "Arduino.h"
char VP , readflag=0;
char use[20];
uint8_t  dat  ; // frame varibles
char buff [20] ;
void GO_PAGE(uint16_t PG ) {
  myserial.write((byte)0x5A);   
  myserial.write((byte)0xA5);
  myserial.write((byte)0x04);
  myserial.write((byte)0x80);
  myserial.write((byte)0x03); 
  myserial.write(PG >> 8);
  myserial.write(PG % 256);
}
void WriteData( uint16_t VP1 , String Str) {
  myserial.write((byte)0x5A);                 myserial.write((byte)0xA5);                
  myserial.write( sizeof(Str) + 5);           myserial.write((byte)0x82);
  myserial.write(VP1 >> 8);                   myserial.write(VP1 % 256);

  for(int m =0 ; m < sizeof(Str) ;m++)
  {
     myserial.write(Str[m]);
  }
  myserial.write(0xff);                     myserial.write(0xff);
}
boolean  ReadData() {
  char i=0;
  while( myserial.available() > 0) {
    buff[i] = myserial.read();
    Serial.print("data >>>   "); Serial.println(buff[i], HEX);
    if(i==5)
    {
       VP = buff[5];
    }
    i++;
    readflag=1;
  }
  i=0;
  return 0;
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

