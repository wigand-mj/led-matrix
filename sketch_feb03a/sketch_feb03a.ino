#include <Arduino.h>

//Shift-Register I/O for  input of LEDs 1-4
#define REG_2_DS 7
#define REG_2_STCP 8
#define REG_2_SHCP 9

//Shift-Register I/O for input of LEDs 4-8
#define REG_1_DS 3
#define REG_1_STCP 4
#define REG_1_SHCP 5

// Shift-Register I/O for transistor IC
#define REG_T_DS 11
#define REG_T_SHCP 13
#define REG_T_STCP 12

// Row-Adresses for IC SN74HC595N
int trow [9] = {0,1,2,4,8,16,32,64,128};
int grow [9] = {0,128,32,8,2,128,32,8,2};
int rrow [9] = {0,64,16,4,1,64,16,4,1};

int mat[8][8];


void setup() {
  pinMode (REG_1_DS, OUTPUT);
  pinMode (REG_1_SHCP, OUTPUT);
  pinMode (REG_1_STCP, OUTPUT);
  pinMode (REG_2_DS, OUTPUT);
  pinMode (REG_2_SHCP, OUTPUT);
  pinMode (REG_2_STCP, OUTPUT);
  pinMode (REG_T_DS, OUTPUT);
  pinMode (REG_T_SHCP, OUTPUT);
  pinMode (REG_T_STCP, OUTPUT);

  
}

void setpixel(int rg, int x, int y){
  
      digitalWrite(REG_T_SHCP, LOW);
       
      switch (y) {
         case 1 :{
      digitalWrite(REG_T_STCP, LOW);
      shiftOut(REG_T_DS, REG_T_SHCP, LSBFIRST, trow[1]);
      digitalWrite(REG_T_STCP, HIGH);
      break;
        }
          case 2 :{
      digitalWrite(REG_T_STCP, LOW);
      shiftOut(REG_T_DS, REG_T_SHCP, LSBFIRST, trow[2]);
      digitalWrite(REG_T_STCP, HIGH);
      break;
        }
          case 3 :{
      digitalWrite(REG_T_STCP, LOW);
      shiftOut(REG_T_DS, REG_T_SHCP, LSBFIRST, trow[3]);
      digitalWrite(REG_T_STCP, HIGH);
      break;
        }
          case 4 :{
      digitalWrite(REG_T_STCP, LOW);
      shiftOut(REG_T_DS, REG_T_SHCP, LSBFIRST, trow[4]);
      digitalWrite(REG_T_STCP, HIGH);
      break;
        }
          case 5 :{
      digitalWrite(REG_T_STCP, LOW);
      shiftOut(REG_T_DS, REG_T_SHCP, LSBFIRST, trow[5]);
      digitalWrite(REG_T_STCP, HIGH);
      break;
        }
          case 6 :{
      digitalWrite(REG_T_STCP, LOW);
      shiftOut(REG_T_DS, REG_T_SHCP, LSBFIRST, trow[6]);
      digitalWrite(REG_T_STCP, HIGH);
      break;
        }
          case 7 :{
      digitalWrite(REG_T_STCP, LOW);
      shiftOut(REG_T_DS, REG_T_SHCP, LSBFIRST, trow[7]);
      digitalWrite(REG_T_STCP, HIGH);
      break;
        }
          case 8 :{
      digitalWrite(REG_T_STCP, LOW);
      shiftOut(REG_T_DS, REG_T_SHCP, LSBFIRST, trow[8]);
      digitalWrite(REG_T_STCP, HIGH);
      break;
        }
      }

      digitalWrite(REG_1_SHCP, LOW);
      digitalWrite(REG_2_SHCP, LOW);
      
      if (rg == 0){
       switch (x) {
         case 1 :{
      digitalWrite(REG_1_STCP, LOW);
      shiftOut(REG_1_DS, REG_1_SHCP, LSBFIRST, rrow[1]);
      digitalWrite(REG_1_STCP, HIGH);
      break;
        }
          case 2 :{
      digitalWrite(REG_1_STCP, LOW);
      shiftOut(REG_1_DS, REG_1_SHCP, LSBFIRST, rrow[2]);
      digitalWrite(REG_1_STCP, HIGH);
      break;
        }
          case 3 :{
      digitalWrite(REG_1_STCP, LOW);
      shiftOut(REG_1_DS, REG_1_SHCP, LSBFIRST, rrow[3]);
      digitalWrite(REG_1_STCP, HIGH);
      break;
        }
          case 4 :{
      digitalWrite(REG_1_STCP, LOW);
      shiftOut(REG_1_DS, REG_1_SHCP, LSBFIRST, rrow[4]);
      digitalWrite(REG_1_STCP, HIGH);
      break;
        }
          case 5 :{
      digitalWrite(REG_2_STCP, LOW);
      shiftOut(REG_2_DS, REG_2_SHCP, LSBFIRST, rrow[5]);
      digitalWrite(REG_2_STCP, HIGH);
      break;
        }
          case 6 :{
      digitalWrite(REG_2_STCP, LOW);
      shiftOut(REG_2_DS, REG_2_SHCP, LSBFIRST, rrow[6]);
      digitalWrite(REG_2_STCP, HIGH);
      break;
        }
          case 7 :{
      digitalWrite(REG_2_STCP, LOW);
      shiftOut(REG_2_DS, REG_2_SHCP, LSBFIRST, rrow[7]);
      digitalWrite(REG_2_STCP, HIGH);
      break;
        }
          case 8 :{
      digitalWrite(REG_2_STCP, LOW);
      shiftOut(REG_2_DS, REG_2_SHCP, LSBFIRST, rrow[8]);
      digitalWrite(REG_2_STCP, HIGH);
      break;
        } 
      }
      }

      digitalWrite(REG_1_SHCP, LOW);
      digitalWrite(REG_2_SHCP, LOW);

            if (rg == 1){
       switch (x) {
         case 1 :{
      digitalWrite(REG_1_STCP, LOW);
      shiftOut(REG_1_DS, REG_1_SHCP, LSBFIRST, grow[1]);
      digitalWrite(REG_1_STCP, HIGH);
      break;
        }
          case 2 :{
      digitalWrite(REG_1_STCP, LOW);
      shiftOut(REG_1_DS, REG_1_SHCP, LSBFIRST, grow[2]);
      digitalWrite(REG_1_STCP, HIGH);
      break;
        }
          case 3 :{
      digitalWrite(REG_1_STCP, LOW);
      shiftOut(REG_1_DS, REG_1_SHCP, LSBFIRST, grow[3]);
      digitalWrite(REG_1_STCP, HIGH);
      break;
        }
          case 4 :{
      digitalWrite(REG_1_STCP, LOW);
      shiftOut(REG_1_DS, REG_1_SHCP, LSBFIRST, grow[4]);
      digitalWrite(REG_1_STCP, HIGH);
      break;
        }
          case 5 :{
      digitalWrite(REG_2_STCP, LOW);
      shiftOut(REG_2_DS, REG_2_SHCP, LSBFIRST, grow[5]);
      digitalWrite(REG_2_STCP, HIGH);
      break;
        }
          case 6 :{
      digitalWrite(REG_2_STCP, LOW);
      shiftOut(REG_2_DS, REG_2_SHCP, LSBFIRST, grow[6]);
      digitalWrite(REG_2_STCP, HIGH);
      break;
        }
          case 7 :{
      digitalWrite(REG_2_STCP, LOW);
      shiftOut(REG_2_DS, REG_2_SHCP, LSBFIRST, grow[7]);
      digitalWrite(REG_2_STCP, HIGH);
      break;
        }
          case 8 :{
      digitalWrite(REG_2_STCP, LOW);
      shiftOut(REG_2_DS, REG_2_SHCP, LSBFIRST, grow[8]);
      digitalWrite(REG_2_STCP, HIGH);
      break;
        } 
      }
     }
   }
void draw(int rg, int** matrix){
  for (int i=0; i<8;i++){
    for (int r=0; r<8; r++){
      setpixel(rg, matrix[i][r],r);   
    }
  }
}

void loop() {
for (int i=0; i<8;i++){
    for (int r=0; r<8; r++){
      mat[i][r]=1;   
    }
  }
draw(1, mat); 
}
