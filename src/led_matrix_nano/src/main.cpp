#include <Arduino.h>

// I/O DEFINITIONS

//Shift-Register I/O for red input of LEDs
#define SHIFT_REG_R_DS 7
#define SHIFT_REG_R_SHCP 8
#define SHIFT_REG_R_STCP 9

//Shift-Register I/O for green input of LEDs
#define SHIFT_REG_G_DS 3
#define SHIFT_REG_G_SHCP 4
#define SHIFT_REG_G_STCP 5

// Shift-Register I/O for iransistor IC
#define SHIFT_REG_T_DS 11
#define SHIFT_REG_T_SHCP 12
#define SHIFT_REG_T_STCP 13


// MEMORY ALLOCATION

const short rows = 8; // 2 bits
const short columns = 8; // 2 bits

short Register[rows][columns]; // [0 - OFF], [1 - Red],  [2 - Green] // 8*8*2 = 128 bits
short transistor[rows]; //8*2= 16 bits

bool RG_SHIFT_REG_STCP; // 1 bit
bool RG_SHIFT_REG_SHCP; // 1 bit
bool T_SHIFT_REG_STCP; // 1 bit
bool T_SHIFT_REG_SHCP; // 1 bit

// total size: 152 bits (of memory needed during runtime)

// FUNCTION DEFINITIONS

void registerWrite(short x, short y, short value) {  // Value: [0 - OFF], [1 - Red],  [2 - Green]
  Register[x][y]=value;
} // + 6 bits needed during execution

void transistorWrite(short x, short value) {  // Value: [0 - OFF], [1 - ON]
  transistor[x]=value;
} // + 4 bits needed during execution

void makeRed(){

/*
  for (int i=0; i<rows;i++){
    for (int j=0; j<columns; j++) {
        registerWrite(i,j,1);
    } }
*/

  digitalWrite(SHIFT_REG_T_SHCP,LOW);
  bool a[] = {1,0,0,0,0,0};
  for (int i=0; i<8; i++){
    digitalWrite(SHIFT_REG_T_STCP,LOW);
    digitalWrite(SHIFT_REG_T_DS,a[i]);
    digitalWrite(SHIFT_REG_T_STCP,HIGH);
  }
  digitalWrite(SHIFT_REG_T_SHCP,HIGH);

  /*

  digitalWrite(SHIFT_REG_R_SHCP,LOW);
  for (int i=0; i<8;i++){
    digitalWrite(SHIFT_REG_R_STCP,LOW);
    digitalWrite(SHIFT_REG_R_DS,1);
    digitalWrite(SHIFT_REG_R_STCP,HIGH);
  }
  digitalWrite(SHIFT_REG_R_SHCP,HIGH);
  */


}

void init() {

RG_SHIFT_REG_STCP = 0;
RG_SHIFT_REG_SHCP = 0;
T_SHIFT_REG_STCP = 0;
T_SHIFT_REG_SHCP = 0;

  for (int i=0; i<rows;i++){
      transistorWrite(i,0);
    for (int j=0; j<columns; j++) {
        registerWrite(i,j,0);
    }
  }

  digitalWrite(SHIFT_REG_R_DS,0);
  digitalWrite(SHIFT_REG_R_STCP,0);
  digitalWrite(SHIFT_REG_R_SHCP,0);

  digitalWrite(SHIFT_REG_G_DS,0);
  digitalWrite(SHIFT_REG_G_STCP,0);
  digitalWrite(SHIFT_REG_G_SHCP,0);

  digitalWrite(SHIFT_REG_T_DS,0);
  digitalWrite(SHIFT_REG_T_STCP,0);
  digitalWrite(SHIFT_REG_T_SHCP,0);


}

void update()  {

}


////////////////////////////////////////////////////////////////////////////////////////////////


void setup() {

  // Declaring outputs for Register inputs
  pinMode(SHIFT_REG_R_DS,OUTPUT);
  pinMode(SHIFT_REG_R_STCP,OUTPUT);
  pinMode(SHIFT_REG_R_SHCP,OUTPUT);

  pinMode(SHIFT_REG_G_DS,OUTPUT);
  pinMode(SHIFT_REG_G_STCP,OUTPUT);
  pinMode(SHIFT_REG_G_SHCP,OUTPUT);

  pinMode(SHIFT_REG_T_DS,OUTPUT);
  pinMode(SHIFT_REG_T_STCP,OUTPUT);
  pinMode(SHIFT_REG_T_SHCP,OUTPUT);


  // init();
  makeRed();
}



void loop() {
  
}