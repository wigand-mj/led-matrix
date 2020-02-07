#include <Arduino.h>
#include "board.h"

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

//Max:
short trow [9] = {0,1,2,4,8,16,32,64,128};
short grow [9] = {0,128,32,8,1,64,32,8,2};
short rrow [9] = {0,64,16,4,2,128,16,4,1};
short yrow [9] = {0,192,48,12,3,192,48,12,3};

//Maik:
 /*
short trow [9] = {0,1,2,4,8,16,32,64,128};
short grow [9] = {0,64,16,4,1,64,16,4,1};
short rrow [9] = {0,128,32,16,2,128,32,16,2};
short yrow [9] = {0,192,48,12,3,192,48,12,3};
*/



void board::init() {
  pinMode (REG_1_DS, OUTPUT);
  pinMode (REG_1_SHCP, OUTPUT);
  pinMode (REG_1_STCP, OUTPUT);
  pinMode (REG_2_DS, OUTPUT);
  pinMode (REG_2_SHCP, OUTPUT);
  pinMode (REG_2_STCP, OUTPUT);
  pinMode (REG_T_DS, OUTPUT);
  pinMode (REG_T_SHCP, OUTPUT);
  pinMode (REG_T_STCP, OUTPUT);

  
     set_default();
  
}

// sets a pixel on 8x8 Matrix with color rg. 0= pixel off, 1=green ,2=red , 3=yellow

void board::setpixel(short rg, short x, short y){
      
      if (rg ==0){
        return;
      }
       
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
      
      if (rg == 1){
       switch (x) {
         case 1 :{
      digitalWrite(REG_1_STCP, LOW);
      shiftOut(REG_1_DS, REG_1_SHCP, LSBFIRST, grow[1]);
      digitalWrite(REG_1_STCP, HIGH);
      
      digitalWrite(REG_2_STCP, LOW);
      shiftOut(REG_2_DS, REG_2_SHCP, LSBFIRST, 0);
      digitalWrite(REG_2_STCP, HIGH);
      
      break;
        }
          case 2 :{
      digitalWrite(REG_1_STCP, LOW);
      shiftOut(REG_1_DS, REG_1_SHCP, LSBFIRST, grow[2]);
      digitalWrite(REG_1_STCP, HIGH);
       
      digitalWrite(REG_2_STCP, LOW);
      shiftOut(REG_2_DS, REG_2_SHCP, LSBFIRST, 0);
      digitalWrite(REG_2_STCP, HIGH);
      
      break;
        }
          case 3 :{
      digitalWrite(REG_1_STCP, LOW);
      shiftOut(REG_1_DS, REG_1_SHCP, LSBFIRST, grow[3]);
      digitalWrite(REG_1_STCP, HIGH);

       
      digitalWrite(REG_2_STCP, LOW);
      shiftOut(REG_2_DS, REG_2_SHCP, LSBFIRST, 0);
      digitalWrite(REG_2_STCP, HIGH);
      
      break;
        }
          case 4 :{
      digitalWrite(REG_1_STCP, LOW);
      shiftOut(REG_1_DS, REG_1_SHCP, LSBFIRST, grow[4]);
      digitalWrite(REG_1_STCP, HIGH);

       
      digitalWrite(REG_2_STCP, LOW);
      shiftOut(REG_2_DS, REG_2_SHCP, LSBFIRST, 0);
      digitalWrite(REG_2_STCP, HIGH);
      
      break;
        }
          case 5 :{
      digitalWrite(REG_2_STCP, LOW);
      shiftOut(REG_2_DS, REG_2_SHCP, LSBFIRST, grow[5]);
      digitalWrite(REG_2_STCP, HIGH);
 
      digitalWrite(REG_1_STCP, LOW);
      shiftOut(REG_1_DS, REG_1_SHCP, LSBFIRST, 0);
      digitalWrite(REG_1_STCP, HIGH);
      
      break;
        }
          case 6 :{
      digitalWrite(REG_2_STCP, LOW);
      shiftOut(REG_2_DS, REG_2_SHCP, LSBFIRST, grow[6]);
      digitalWrite(REG_2_STCP, HIGH);

       
      digitalWrite(REG_1_STCP, LOW);
      shiftOut(REG_1_DS, REG_1_SHCP, LSBFIRST, 0);
      digitalWrite(REG_1_STCP, HIGH);
      
      break;
        }
          case 7 :{
      digitalWrite(REG_2_STCP, LOW);
      shiftOut(REG_2_DS, REG_2_SHCP, LSBFIRST, grow[7]);
      digitalWrite(REG_2_STCP, HIGH);
       
      digitalWrite(REG_1_STCP, LOW);
      shiftOut(REG_1_DS, REG_1_SHCP, LSBFIRST, 0);
      digitalWrite(REG_1_STCP, HIGH);
      
      break;
        }
          case 8 :{
      digitalWrite(REG_2_STCP, LOW);
      shiftOut(REG_2_DS, REG_2_SHCP, LSBFIRST, grow[8]);
      digitalWrite(REG_2_STCP, HIGH);

      
      digitalWrite(REG_1_STCP, LOW);
      shiftOut(REG_1_DS, REG_1_SHCP, LSBFIRST, 0);
      digitalWrite(REG_1_STCP, HIGH);
      
      break;
        } 
      }
      }

            if (rg == 2){
       switch (x) {
         case 1 :{
      digitalWrite(REG_1_STCP, LOW);
      shiftOut(REG_1_DS, REG_1_SHCP, LSBFIRST, rrow[1]);
      digitalWrite(REG_1_STCP, HIGH);
           
      digitalWrite(REG_2_STCP, LOW);
      shiftOut(REG_2_DS, REG_2_SHCP, LSBFIRST, 0);
      digitalWrite(REG_2_STCP, HIGH);
      
      break;
        }
          case 2 :{
      digitalWrite(REG_1_STCP, LOW);
      shiftOut(REG_1_DS, REG_1_SHCP, LSBFIRST, rrow[2]);
      digitalWrite(REG_1_STCP, HIGH);
     
      digitalWrite(REG_2_STCP, LOW);
      shiftOut(REG_2_DS, REG_2_SHCP, LSBFIRST, 0);
      digitalWrite(REG_2_STCP, HIGH);
      
      break;
        }
          case 3 :{
      digitalWrite(REG_1_STCP, LOW);
      shiftOut(REG_1_DS, REG_1_SHCP, LSBFIRST, rrow[3]);
      digitalWrite(REG_1_STCP, HIGH);
           
      digitalWrite(REG_2_STCP, LOW);
      shiftOut(REG_2_DS, REG_2_SHCP, LSBFIRST, 0);
      digitalWrite(REG_2_STCP, HIGH);
      
      break;
        }
          case 4 :{
      digitalWrite(REG_1_STCP, LOW);
      shiftOut(REG_1_DS, REG_1_SHCP, LSBFIRST, rrow[4]);
      digitalWrite(REG_1_STCP, HIGH);
           
      digitalWrite(REG_2_STCP, LOW);
      shiftOut(REG_2_DS, REG_2_SHCP, LSBFIRST, 0);
      digitalWrite(REG_2_STCP, HIGH);
      
      break;
        }
          case 5 :{
      digitalWrite(REG_2_STCP, LOW);
      shiftOut(REG_2_DS, REG_2_SHCP, LSBFIRST, rrow[5]);
      digitalWrite(REG_2_STCP, HIGH);
           
      digitalWrite(REG_1_STCP, LOW);
      shiftOut(REG_1_DS, REG_1_SHCP, LSBFIRST, 0);
      digitalWrite(REG_1_STCP, HIGH);
      
      break;
        }
          case 6 :{
      digitalWrite(REG_2_STCP, LOW);
      shiftOut(REG_2_DS, REG_2_SHCP, LSBFIRST, rrow[6]);
      digitalWrite(REG_2_STCP, HIGH);
      
      digitalWrite(REG_1_STCP, LOW);
      shiftOut(REG_1_DS, REG_1_SHCP, LSBFIRST, 0);
      digitalWrite(REG_1_STCP, HIGH);
      break;
        }
          case 7 :{
      digitalWrite(REG_2_STCP, LOW);
      shiftOut(REG_2_DS, REG_2_SHCP, LSBFIRST, rrow[7]);
      digitalWrite(REG_2_STCP, HIGH);

      digitalWrite(REG_1_STCP, LOW);
      shiftOut(REG_1_DS, REG_1_SHCP, LSBFIRST, 0);
      digitalWrite(REG_1_STCP, HIGH);
      break;
        }
          case 8 :{
      digitalWrite(REG_2_STCP, LOW);
      shiftOut(REG_2_DS, REG_2_SHCP, LSBFIRST, rrow[8]);
      digitalWrite(REG_2_STCP, HIGH);

      digitalWrite(REG_1_STCP, LOW);
      shiftOut(REG_1_DS, REG_1_SHCP, LSBFIRST, 0);
      digitalWrite(REG_1_STCP, HIGH);
      break;
        } 
      }
     }
                 if (rg == 3){
       switch (x) {
         case 1 :{
      digitalWrite(REG_1_STCP, LOW);
      shiftOut(REG_1_DS, REG_1_SHCP, LSBFIRST, yrow[1]);
      digitalWrite(REG_1_STCP, HIGH);
           
      digitalWrite(REG_2_STCP, LOW);
      shiftOut(REG_2_DS, REG_2_SHCP, LSBFIRST, 0);
      digitalWrite(REG_2_STCP, HIGH);
      
      break;
        }
          case 2 :{
      digitalWrite(REG_1_STCP, LOW);
      shiftOut(REG_1_DS, REG_1_SHCP, LSBFIRST, yrow[2]);
      digitalWrite(REG_1_STCP, HIGH);
     
      digitalWrite(REG_2_STCP, LOW);
      shiftOut(REG_2_DS, REG_2_SHCP, LSBFIRST, 0);
      digitalWrite(REG_2_STCP, HIGH);
      
      break;
        }
          case 3 :{
      digitalWrite(REG_1_STCP, LOW);
      shiftOut(REG_1_DS, REG_1_SHCP, LSBFIRST, yrow[3]);
      digitalWrite(REG_1_STCP, HIGH);
           
      digitalWrite(REG_2_STCP, LOW);
      shiftOut(REG_2_DS, REG_2_SHCP, LSBFIRST, 0);
      digitalWrite(REG_2_STCP, HIGH);
      
      break;
        }
          case 4 :{
      digitalWrite(REG_1_STCP, LOW);
      shiftOut(REG_1_DS, REG_1_SHCP, LSBFIRST, yrow[4]);
      digitalWrite(REG_1_STCP, HIGH);
           
      digitalWrite(REG_2_STCP, LOW);
      shiftOut(REG_2_DS, REG_2_SHCP, LSBFIRST, 0);
      digitalWrite(REG_2_STCP, HIGH);
      
      break;
        }
          case 5 :{
      digitalWrite(REG_2_STCP, LOW);
      shiftOut(REG_2_DS, REG_2_SHCP, LSBFIRST, yrow[5]);
      digitalWrite(REG_2_STCP, HIGH);
           
      digitalWrite(REG_1_STCP, LOW);
      shiftOut(REG_1_DS, REG_1_SHCP, LSBFIRST, 0);
      digitalWrite(REG_1_STCP, HIGH);
      
      break;
        }
          case 6 :{
      digitalWrite(REG_2_STCP, LOW);
      shiftOut(REG_2_DS, REG_2_SHCP, LSBFIRST, yrow[6]);
      digitalWrite(REG_2_STCP, HIGH);
      
      digitalWrite(REG_1_STCP, LOW);
      shiftOut(REG_1_DS, REG_1_SHCP, LSBFIRST, 0);
      digitalWrite(REG_1_STCP, HIGH);
      break;
        }
          case 7 :{
      digitalWrite(REG_2_STCP, LOW);
      shiftOut(REG_2_DS, REG_2_SHCP, LSBFIRST, yrow[7]);
      digitalWrite(REG_2_STCP, HIGH);

      digitalWrite(REG_1_STCP, LOW);
      shiftOut(REG_1_DS, REG_1_SHCP, LSBFIRST, 0);
      digitalWrite(REG_1_STCP, HIGH);
      break;
        }
          case 8 :{
      digitalWrite(REG_2_STCP, LOW);
      shiftOut(REG_2_DS, REG_2_SHCP, LSBFIRST, yrow[8]);
      digitalWrite(REG_2_STCP, HIGH);

      digitalWrite(REG_1_STCP, LOW);
      shiftOut(REG_1_DS, REG_1_SHCP, LSBFIRST, 0);
      digitalWrite(REG_1_STCP, HIGH);
      break;
        } 
      }
     }
   }

// Prints 8x8 short matrix on LED Screen

void board::draw(){
  for (short i=0; i<8; i++){
    for (short r=0; r<8; r++){
      setpixel(mat[i][r],i+1,r+1);
    }
   }
}

void board::setvalue(short value, short x, short y) {
    mat[x][y] = value;
}

short board::getvalue(short x, short y) {
        return mat[x][y];
}


void board::fill(short f){
  for (int i=0; i<8; i++){
        for (int j=0; j<8; j++){
          if ((j==0) || (j==7)){
            mat[i][j]=f;
          } else if ((i==0) || (i==7)){
            mat[i][j]=2;
          } else {
            mat[i][j]=f;
          }
    }

    }
}

void board::set_default(){

    for (int i=0; i<8; i++){
        for (int j=0; j<8; j++){
          if ((j==0) || (j==7)){
            mat[i][j]=2;
          } else if ((i==0) || (i==7)){
            mat[i][j]=2;
          } else {
            mat[i][j]=0;
          }
    }

    }
}

board::board(){
  init();
  }
board::~board(){}
