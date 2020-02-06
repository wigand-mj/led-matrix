#include <Arduino.h>


/*
// I/O DEFINITIONS

//Shift-Register I/O for  input of LEDs 1-4
#define SHIFT_REG_1_DS 3
#define SHIFT_REG_1_STCP 4
#define SHIFT_REG_1_SHCP 5


//Shift-Register I/O for input of LEDs 4-8
#define SHIFT_REG_2_DS 7
#define SHIFT_REG_2_STCP 8
#define SHIFT_REG_2_SHCP 9


// Shift-Register I/O for transistor IC
#define SHIFT_REG_T_DS 11
#define SHIFT_REG_T_STCP 12
#define SHIFT_REG_T_SHCP 13



// MEMORY ALLOCATION

const short rows = 8; // 2 bits
const short columns = 8; // 2 bits

short Register[rows][columns]; // [0 - OFF], [1 - Red],  [2 - Green] // 8*8*2 = 128 bits
short transistor[rows]; //8*2= 16 bits


// total size: 158 bits (of memory needed during runtime)

// FUNCTION DEFINITIONS

void registerWrite(short x, short y, short value) {  // Value: [0 - OFF], [1 - Red],  [2 - Green]
  Register[x][y]=value;
} // + 6 bits needed during execution

void transistorWrite(short x, short value) {  // Value: [0 - OFF], [1 - ON]
  transistor[x]=value;
} // + 4 bits needed during execution

void registerClear(){
   for (int i=0; i<rows;i++){
    for (int j=0; j<columns; j++) {
        registerWrite(i,j,0);
    }
  }
}

void transistorClear(){
   for (int i=0; i<rows;i++){
      transistorWrite(i,0);
  }
}

void transistorShift() {

  for (int i=0; i<rows; i++){
    if ((i==(rows-1)) && (transistor[i]==1)){
      transistor[0]=1;
      transistor[i]=0;
    } else if (transistor[i]==1){
      transistor[i]=0;
      transistor[i+1]=1;
      i+=1;
    }
  }

  digitalWrite(SHIFT_REG_T_STCP,LOW);
  for (int j=rows; j>0; j--){
      digitalWrite(SHIFT_REG_T_SHCP,LOW);
      digitalWrite(SHIFT_REG_T_DS,transistor[j]);
      digitalWrite(SHIFT_REG_T_SHCP,HIGH);
    }
  digitalWrite(SHIFT_REG_T_STCP,HIGH);
}

void clearAll(){
  transistorClear();
  registerClear();
}

void fillBlank(char color){
  if(color=='r'){
    for (int i=0; i<rows;i++){
      for (int j=0; j<columns; j++) {
          registerWrite(i,j,1);
      }
  }
  } else if (color=='g'){
    for (int i=0; i<rows;i++){
      for (int j=0; j<columns; j++) {
          registerWrite(i,j,1);
      }
  }
  }
}

void draw(){

  short SR1[rows/2][columns];
  short SR2[rows/2][columns];

  for (int i = 0; i<rows; i++){
    for (int j = 0; j<columns; j++){
      if (Register[i][j]>4){ // First SHIFT_REG
        if (Register[i][j]==3){
          SR1[i+1][j]==1;
        } else {
          SR1[i][j]==Register[i][j];
        }
      }else if (Register[i][j]<=4){ // Second SHIFT_REG
        if (Register[i][j]==3){
          SR2[i-(columns/2)+1][j]==1;
        } else{
          SR2[i=(columns/2)][j]==Register[i][j];
        }
      }
    }
  }

  for(int i=rows; i>0; i--){

    digitalWrite(SHIFT_REG_1_STCP,LOW);
    digitalWrite(SHIFT_REG_2_STCP,LOW);
    for (int j=columns; j>0; j--){
      digitalWrite(SHIFT_REG_1_SHCP,LOW);
      digitalWrite(SHIFT_REG_1_DS,SR1[i][j]);
      digitalWrite(SHIFT_REG_1_SHCP,HIGH);

      digitalWrite(SHIFT_REG_2_SHCP,LOW);
      digitalWrite(SHIFT_REG_2_DS,SR2[i][j]);
      digitalWrite(SHIFT_REG_2_SHCP,HIGH);
    }
    digitalWrite(SHIFT_REG_1_STCP,HIGH);
    digitalWrite(SHIFT_REG_2_STCP,HIGH);
    transistorShift();
  }
}

void update()  {
  draw();
}

void init() {

  clearAll();

  // Declaring outputs for Register inputs
  pinMode(SHIFT_REG_1_DS,OUTPUT);
  pinMode(SHIFT_REG_1_STCP,OUTPUT);
  pinMode(SHIFT_REG_1_SHCP,OUTPUT);

  pinMode(SHIFT_REG_2_DS,OUTPUT);
  pinMode(SHIFT_REG_2_STCP,OUTPUT);
  pinMode(SHIFT_REG_2_SHCP,OUTPUT);

  pinMode(SHIFT_REG_T_DS,OUTPUT);
  pinMode(SHIFT_REG_T_STCP,OUTPUT);
  pinMode(SHIFT_REG_T_SHCP,OUTPUT);

  digitalWrite(SHIFT_REG_1_DS,0);
  digitalWrite(SHIFT_REG_1_STCP,0);
  digitalWrite(SHIFT_REG_1_SHCP,0);

  digitalWrite(SHIFT_REG_2_DS,0);
  digitalWrite(SHIFT_REG_2_STCP,0);
  digitalWrite(SHIFT_REG_2_SHCP,0);

  digitalWrite(SHIFT_REG_T_DS,0);
  digitalWrite(SHIFT_REG_T_STCP,0);
  digitalWrite(SHIFT_REG_T_SHCP,0);

  draw();

  //fillBlank('r');
  //update();

}


////////////////////////////////////////////////////////////////////////////////////////////////


void setup() {
  init();
}



void loop() {

}

/*
int getByte(int length){
  char* c[length];
  char outputC[length+2];
  char t;
  for (int i=0; i<length; i++){
    *c[i] = (int)Register[i];
    strcpy(outputC,c[i]);
  } t=*outputC;

  int output = t - '0';

}
*/

// I/O DEFINITIONS

//Shift-Register I/O for  input of LEDs 1-4
#define SHIFT_REG_1_DS 3
#define SHIFT_REG_1_STCP 4
#define SHIFT_REG_1_SHCP 5


//Shift-Register I/O for input of LEDs 4-8
#define SHIFT_REG_2_DS 7
#define SHIFT_REG_2_STCP 8
#define SHIFT_REG_2_SHCP 9


// Shift-Register I/O for transistor IC
#define SHIFT_REG_T_DS 11
#define SHIFT_REG_T_STCP 12
#define SHIFT_REG_T_SHCP 13



// MEMORY ALLOCATION

const short rows = 8; // 2 bits
const short columns = 8; // 2 bits

short Register[rows][columns]; // [0 - OFF], [1 - Red],  [2 - Green] // 8*8*2 = 128 bits
short transistor[rows]; //8*2= 16 bits


// total size: 158 bits (of memory needed during runtime)

// FUNCTION DEFINITIONS

void registerWrite(short x, short y, short value) {  // Value: [0 - OFF], [1 - Red],  [2 - Green]
  Register[x][y]=value;
} // + 6 bits needed during execution

void transistorWrite(short x, short value) {  // Value: [0 - OFF], [1 - ON]
  transistor[x]=value;
} // + 4 bits needed during execution

void registerClear(){
   for (int i=0; i<rows;i++){
    for (int j=0; j<columns; j++) {
        registerWrite(i,j,0);
    }
  }
}

void transistorClear(){
   for (int i=0; i<rows;i++){
      transistorWrite(i,0);
  }
}

void transistorShift() {

  for (int i=0; i<rows; i++){
    if ((i==(rows-1)) && (transistor[i]==1)){
      transistor[0]=1;
      transistor[i]=0;
    } else if (transistor[i]==1){
      transistor[i]=0;
      transistor[i+1]=1;
      i+=1;
    }
  }

  digitalWrite(SHIFT_REG_T_STCP,LOW);
  for (int j=rows; j>0; j--){
      digitalWrite(SHIFT_REG_T_SHCP,LOW);
      digitalWrite(SHIFT_REG_T_DS,transistor[j]);
      digitalWrite(SHIFT_REG_T_SHCP,HIGH);
    }
  digitalWrite(SHIFT_REG_T_STCP,HIGH);
}

void clearAll(){
  transistorClear();
  registerClear();
}

void fillBlank(char color){
  if(color=='r'){
    for (int i=0; i<rows;i++){
      for (int j=0; j<columns; j++) {
          registerWrite(i,j,1);
      }
  }
  } else if (color=='g'){
    for (int i=0; i<rows;i++){
      for (int j=0; j<columns; j++) {
          registerWrite(i,j,1);
      }
  }
  }
}

void draw(){

  short SR1[rows/2][columns];
  short SR2[rows/2][columns];

  for (int i = 0; i<rows; i++){
    for (int j = 0; j<columns; j++){
      if (Register[i][j]>4){ // First SHIFT_REG
        if (Register[i][j]==3){
          SR1[i+1][j]==1;
        } else {
          SR1[i][j]==Register[i][j];
        }
      }else if (Register[i][j]<=4){ // Second SHIFT_REG
        if (Register[i][j]==3){
          SR2[i-(columns/2)+1][j]==1;
        } else{
          SR2[i=(columns/2)][j]==Register[i][j];
        }
      }
    }
  }

  for(int i=rows; i>0; i--){

    digitalWrite(SHIFT_REG_1_STCP,LOW);
    digitalWrite(SHIFT_REG_2_STCP,LOW);
    for (int j=columns; j>0; j--){
      digitalWrite(SHIFT_REG_1_SHCP,LOW);
      digitalWrite(SHIFT_REG_1_DS,SR1[i][j]);
      digitalWrite(SHIFT_REG_1_SHCP,HIGH);

      digitalWrite(SHIFT_REG_2_SHCP,LOW);
      digitalWrite(SHIFT_REG_2_DS,SR2[i][j]);
      digitalWrite(SHIFT_REG_2_SHCP,HIGH);
    }
    digitalWrite(SHIFT_REG_1_STCP,HIGH);
    digitalWrite(SHIFT_REG_2_STCP,HIGH);
  }
}

void update()  {
  draw();
}

void init() {

  clearAll();

  // Declaring outputs for Register inputs
  pinMode(SHIFT_REG_1_DS,OUTPUT);
  pinMode(SHIFT_REG_1_STCP,OUTPUT);
  pinMode(SHIFT_REG_1_SHCP,OUTPUT);

  pinMode(SHIFT_REG_2_DS,OUTPUT);
  pinMode(SHIFT_REG_2_STCP,OUTPUT);
  pinMode(SHIFT_REG_2_SHCP,OUTPUT);

  pinMode(SHIFT_REG_T_DS,OUTPUT);
  pinMode(SHIFT_REG_T_STCP,OUTPUT);
  pinMode(SHIFT_REG_T_SHCP,OUTPUT);

  digitalWrite(SHIFT_REG_1_DS,0);
  digitalWrite(SHIFT_REG_1_STCP,0);
  digitalWrite(SHIFT_REG_1_SHCP,0);

  digitalWrite(SHIFT_REG_2_DS,0);
  digitalWrite(SHIFT_REG_2_STCP,0);
  digitalWrite(SHIFT_REG_2_SHCP,0);

  digitalWrite(SHIFT_REG_T_DS,0);
  digitalWrite(SHIFT_REG_T_STCP,0);
  digitalWrite(SHIFT_REG_T_SHCP,0);

  //draw();

 digitalWrite(SHIFT_REG_T_STCP, LOW);
 shiftOut(SHIFT_REG_T_DS, SHIFT_REG_T_SHCP, LSBFIRST, 128);
 digitalWrite(SHIFT_REG_T_STCP, HIGH);

 

  


  //fillBlank('r');
  //update();

}


////////////////////////////////////////////////////////////////////////////////////////////////


void setup() {
  init();
}



void loop() {
}

/*
int getByte(int length){
  char* c[length];
  char outputC[length+2];
  char t;
  for (int i=0; i<length; i++){
    *c[i] = (int)Register[i];
    strcpy(outputC,c[i]);
  } t=*outputC;

  int output = t - '0';

}
*/

