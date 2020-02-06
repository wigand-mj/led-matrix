#include <Arduino.h>

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

// int transistorValues[9] = {0,1,2,4,8,16,32,64,128}; // 8 Rows + All off
int transistorValues[9] = {128,64,32,16,8,4,2,1,0};

// total size: 158 bits (of memory needed during runtime)

// FUNCTION DEFINITIONS

int decToBin(long n) {
    int dec = 0, i = 0, rem;
    while (n != 0) {
        rem = n % 10;
        n /= 10;
        dec += rem * pow(2, i);
        ++i;
    }
    return dec;
}

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


    for (int i = 0; i<rows; i++){
        for (int j=0; j<columns; j++){
            Register[j][i]=1;
    }



  Serial.println(2);
  short SR1[rows][columns];
  short SR2[rows][columns];

  for (int r = 0; r<rows; r++){
    for (int c=0; c<columns; c++){

      if (c<=3){
        if(Register[c][r]==0){
            if (c==0){
              SR1[c][r]=0;
              SR1[c+1][r]=0;
            } else {
            SR1[c+c][r]=0;
            SR1[c+c+1][r]=0;
            }
        } else if (Register[c][r]==1){
            if (c==0){
              SR1[c][r]=1;
              SR1[c+1][r]=0;
            } else {
            SR1[c+c][r]=1;
            SR1[c+c+1][r]=0;
            }
        } else if (Register[c][r]==2){
            if (c==0){
              SR1[c][r]=0;
              SR1[c+1][r]=1;
            } else {
            SR1[c+c][r]=0;
            SR1[c+c+1][r]=1;
            }
        }
      }

        if(c>=4){
          int b = c-4;
          if(Register[c][r]==0){
            if (c==0){
              SR2[b][r]=0;
              SR2[b+1][r]=0;
            } else {
            SR2[b+b][r]=0;
            SR2[b+b+1][r]=0;
            }
        } else if (Register[c][r]==1){
            if (c==0){
              SR2[b][r]=1;
              SR2[b+1][r]=0;
            } else {
            SR2[b+b][r]=1;
            SR2[b+b+1][r]=0;
            }
        } else if (Register[c][r]==2){
            if (c==0){
              SR2[b][r]=0;
              SR2[b+1][r]=1;
            } else {
            SR2[b+b][r]=0;
            SR2[b+b+1][r]=1;
            }
        }
        }
    }
  }






Serial.println(3);
Serial.print("-------"); 
for(int i=0; i<8; i++) {
    Serial.print(SR1[0][i]); 
    Serial.print(SR1[1][i]); 
    Serial.print(SR1[2][i]); 
    Serial.print(SR1[3][i]); 
    Serial.print(SR1[4][i]); 
    Serial.print(SR1[5][i]); 
    Serial.print(SR1[6][i]); 
    Serial.print(SR1[7][i]);
    Serial.print(" ");
    Serial.print(SR2[0][i]);
    Serial.print(SR2[1][i]);
    Serial.print(SR2[2][i]);
    Serial.print(SR2[3][i]);
    Serial.print(SR2[4][i]);
    Serial.print(SR2[5][i]);
    Serial.print(SR2[6][i]);
    Serial.print(SR2[7][i]);
    Serial.println("");
}
Serial.print("-------"); 
  
  
//   int x=128;
//   for(int i=rows; i>0; i--){

//     digitalWrite(SHIFT_REG_1_STCP,LOW);
//     digitalWrite(SHIFT_REG_2_STCP,LOW);
//     digitalWrite(SHIFT_REG_T_STCP,LOW);
//     for (int j=columns; j>0; j--){
//       digitalWrite(SHIFT_REG_1_SHCP,LOW);
//       digitalWrite(SHIFT_REG_1_DS,SR1[i][j]);
//       digitalWrite(SHIFT_REG_1_SHCP,HIGH);

//       digitalWrite(SHIFT_REG_2_SHCP,LOW);
//       digitalWrite(SHIFT_REG_2_DS,SR2[i][j]);
//       digitalWrite(SHIFT_REG_2_SHCP,HIGH);
//     }
//     digitalWrite(SHIFT_REG_1_STCP,HIGH);
//     digitalWrite(SHIFT_REG_2_STCP,HIGH);
//     shiftOut(SHIFT_REG_T_DS, SHIFT_REG_T_SHCP, LSBFIRST, x);
//     digitalWrite(SHIFT_REG_T_STCP, HIGH);
//     x = x >> 1;
  // }
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

  digitalWrite(SHIFT_REG_1_DS,LOW);
  digitalWrite(SHIFT_REG_1_STCP,LOW);
  digitalWrite(SHIFT_REG_1_SHCP,LOW);

  digitalWrite(SHIFT_REG_2_DS,LOW);
  digitalWrite(SHIFT_REG_2_STCP,LOW);
  digitalWrite(SHIFT_REG_2_SHCP,LOW);

  digitalWrite(SHIFT_REG_T_DS,LOW);
  digitalWrite(SHIFT_REG_T_STCP,LOW);
  digitalWrite(SHIFT_REG_T_SHCP,LOW);
}


////////////////////////////////////////////////////////////////////////////////////////////////


void setup() {
  Serial.begin(9600);
  init();
}



void loop() {
  Serial.println(1);
  draw();
  Serial.println(999);


//  int x=128;
//  for (int i=0; i<(rows); i++){
//    digitalWrite(SHIFT_REG_T_STCP, LOW);
//    shiftOut(SHIFT_REG_T_DS, SHIFT_REG_T_SHCP, LSBFIRST, x);
//    digitalWrite(SHIFT_REG_T_STCP, HIGH);
//    x = x >> 1;
//  }



}


