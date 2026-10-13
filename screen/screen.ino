
#include <SoftwareSerial.h>
SoftwareSerial myserial( 2 , 8 );
#include "MyLibrary.h"
#include "LCD.h"
#include "SPI.h"
boolean Data;
char username[20] = "esl";
char password[20] = "msl";
char user[20];
char pass[20];
char car_id[20];
char id[3][20]  = {"2654" , "7857 ", "4965 "};
char color[3][20]  ={"Gray", "White" ,"Black"};
char model[3][20] = {"Tucson","audi","Toyota"};
char node[3][20] = {"node_1","node_2","node_3"};
char lat[3][20]  = {"31.24632","31.50328","31.26728"};
char lon[3][20]  = {"32.31421","31.82995","32.22332"};
int passflag = 0;
void setup() {

  Serial.begin(115200);
  myserial.begin(115200);
  delay(2000);
  GO_PAGE(0);
}
void loop() {
 // Serial.println("222");
  Data = ReadData();
  if (readflag == 1) {
    if (VP == ENTER) {
      if (strcmp(username, user) == 0 && strcmp(password, pass) == 0) {
        GO_PAGE(2);
      } else {
        GO_PAGE(3);
      }
    }
    else if (VP == USER) {
      for (char j = 0; j < 6; j++) {
        user[j] = buff[j + 7];
      }
    } 
    else if (VP == PASS) {
      for (char m = 0; m < 6; m++) {
        pass[m] = buff[m + 7];
      }
    }
     else if (VP == CAR_ID) {
      for (char s = 0; s < 6; s++) {
        car_id[s] = buff[s + 7];
      }
    }
    else if (VP == SEND) {
      delay(4000);
      if( strcmp(car_id,"2654")==0){
        GO_PAGE(5);
        delay(3000);
        GO_PAGE(12);
        delay(2000);
        WriteData(ID,id[0]);
        delay(200);
        WriteData(COLOR,color[0]);
        delay(200);
        WriteData(MODEL,model[0]);
        delay(200);
        WriteData(NODE,node[0]);
        delay(200);
        WriteData(LAT,lat[0]);
        delay(200);
        WriteData(LONG,lon[0]);
      }
      else if (strcmp(car_id,"7857")==0){
        GO_PAGE(4);
        delay(3000);
        GO_PAGE(12);
        delay(2000);
        WriteData(ID,id[1]);
        delay(200);
        WriteData(COLOR,color[1]);
        delay(200);
        WriteData(MODEL,model[1]);
        delay(200);
        WriteData(NODE,node[1]);
        delay(200);
        WriteData(LAT,lat[1]);
        delay(200);
        WriteData(LONG,lon[1]);
      }
      else if (strcmp(car_id, "4965")==0){
        GO_PAGE(6);
        delay(3000);
        GO_PAGE(12);
        delay(2000);
        WriteData(ID,id[2]);
        delay(200);
        WriteData(COLOR,color[2]);
        delay(200);
        WriteData(MODEL,model[2]);
        delay(200);
        WriteData(NODE,node[2]);
        delay(200);
        WriteData(LAT,lat[2]);
        delay(200);
        WriteData(LONG,lon[2]);
      }
      else {
        GO_PAGE(7);
      }
    }

    readflag = 0;
  }  
  delay(20);
}