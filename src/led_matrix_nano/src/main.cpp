#include <Arduino.h>

#include "board.h"
#include "snake.h"

#define BUTTON_UP A0
#define BUTTON_DOWN A1
#define BUTTON_LEFT A2
#define BUTTON_RIGHT A3


#define SCHLANGE 1
#define WAND 2
#define ESSEN 3
#define OFF 0

#define WELCOME 0
#define OP 1
#define WIN 2
#define GAMEOVER 3
#define END 4
#define INIT 5



/*
int dimx;
int dimy;
short STATE;
int s_length;
int points;
int item_amount;
char startHeading;
int startposx;
int startposy;
*/

  int dimx = 8;
  int dimy = 8;
  short STATE = 0;
  int s_length = 3;
  int points = 0;
  int item_amount = 12;
  char startHeading = 's';
  int startposx = round((dimx/2));
  int startposy = round((dimy/2));
  int counter=0;
  int snake_speed = 50;

board board1;
snake* snake1 = new snake(s_length,startposx, startposy, startHeading);


void update(int mode) { // MUSS EVTL NOCH UMBESCHRIEBEN WERDEN
    switch(mode) {
        case(0):
            //board1.draw(0);
            break;
        case(1):
            board1.draw();
            break;
    }
}

void create_item_pattern(){
    bool re = false;
    int x; 
    int y;
    
    while(re){}
    x = random(1,dimx-1);
    y = random(1,dimy-1);
    for (int i = 0; i<(snake1->getlength()); i++){
        if (x==(snake1->getposx(i))){
            re=true;
        }
        if (y==(snake1->getposy(i))){
            re=true;
        }
    }

     board1.setvalue(ESSEN,x,y);
}
    
void eat() {
    create_item_pattern();
    snake1->grow();
    points+=100;
    if (points%200 == 0){
    }
    if (points==item_amount*100){STATE=WIN;}
    
}

bool check_collision() {
    bool ret = false;
    switch(snake1->getheading()) {
        case 'w':
            if ((board1.getvalue(snake1->getposx(0),snake1->getposy(0)-1)==WAND) || (board1.getvalue(snake1->getposx(0),snake1->getposy(0)-1)==SCHLANGE)) {
            STATE = GAMEOVER;
            ret = true;
            } else if ((board1.getvalue(snake1->getposx(0),snake1->getposy(0)-1)==ESSEN)){
                eat();
            }

            break;
        case 'a':
            if ((board1.getvalue(snake1->getposx(0)-1,snake1->getposy(0))==WAND) || (board1.getvalue(snake1->getposx(0)-1,snake1->getposy(0))==SCHLANGE)) {
            STATE = GAMEOVER;
            ret = true;
            } else if ((board1.getvalue(snake1->getposx(0)-1,snake1->getposy(0))==ESSEN)){
                eat();
            }
            break;
        case 's':
            if ((board1.getvalue(snake1->getposx(0),snake1->getposy(0)+1)==WAND) || (board1.getvalue(snake1->getposx(0),snake1->getposy(0)+1)==SCHLANGE)) {
            STATE = GAMEOVER;
            ret = true;
            } else if ((board1.getvalue(snake1->getposx(0),snake1->getposy(0)+1)==ESSEN)){
                eat();
            }
            break;
        case 'd':
            if ((board1.getvalue(snake1->getposx(0)+1,snake1->getposy(0))==WAND) || (board1.getvalue(snake1->getposx(0)+1,snake1->getposy(0))==SCHLANGE)) {
            STATE = GAMEOVER;
            ret = true;
            } else if ((board1.getvalue(snake1->getposx(0)+1,snake1->getposy(0))==ESSEN)){
                eat();
            }
            break;
    }

    return ret;

}


void snake_move() {

    if (!check_collision()) {
        board1.setvalue(OFF, snake1->getposx(snake1->getlength()-1), snake1->getposy(snake1->getlength()-1));
        snake1->move();
    }

}


void update_snake_pos() {

    for (int i=0; i<snake1->getlength(); i++) {
       
        board1.setvalue(SCHLANGE, snake1->getposx(i), snake1->getposy(i));

    }
   

}

void go() {

    snake_move();
    update_snake_pos();
    //update(1);

}

char read_key(){
    char output;
    if (digitalRead(BUTTON_UP)==HIGH){  
        output='w';
    }
    if (digitalRead(BUTTON_DOWN)==HIGH){
        output='s';
    }
    if (digitalRead(BUTTON_LEFT)==HIGH){
        output='a';
    }
    if (digitalRead(BUTTON_RIGHT)==HIGH){
        output='d';
    }

    return output;

}







void setup(){
  Serial.begin(9600);
  create_item_pattern();
    
  pinMode(BUTTON_UP, INPUT);
  pinMode(BUTTON_DOWN, INPUT);
  pinMode(BUTTON_LEFT, INPUT);
  pinMode(BUTTON_RIGHT, INPUT);


    /*
  dimx = 40+2;
  dimy = 20+2;
  Serial.print("-");
  STATE = 0;
  s_length = 4;
  points = 0;
  item_amount = 12;
  startHeading = 's';
  Serial.print("-");
  startposx = round((dimx/2));
  startposy = round((dimy/2));
  Serial.print("-");
    */
}


void loop(){
        if (STATE == WELCOME){
          STATE = INIT;
        } else if (STATE == INIT) {
            //create_items(create_item_pattern(dimx,dimy,item_amount));
            update_snake_pos();
            //update(0);

            STATE = OP;
        } else if (STATE == OP) {
            char input = read_key();
            
            if (input == 'w' || input == 'a' || input == 's' || input == 'd') { 
                if (!(((input == 'w') && (snake1->getheading() == 's')) || 
                      ((input == 's') && (snake1->getheading() == 'w')) || 
                      ((input == 'a') && (snake1->getheading() == 'd')) || 
                      ((input == 'd') && (snake1->getheading() == 'a')))) {

                    snake1->setheading(input); 
                }
                
            }
            
           if (counter==snake_speed){
            go();
            counter=0;
           } else {
               counter++;
           }
           board1.draw();
            
            //board1.draw();
            

        } else if (STATE == GAMEOVER) {
          //CODE HERE
          board1.fill(1);
          board1.draw();
        } else if (STATE == WIN) {
          //CODE HERE
        } else if (STATE == END) {
          //CODE HERE
        }
    }




