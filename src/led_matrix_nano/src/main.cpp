#include <Arduino.h>

#include "board.h"
#include "snake.h"

// Taster
// #define BUTTON_UP A0
// #define BUTTON_DOWN A1
// #define BUTTON_LEFT A2
// #define BUTTON_RIGHT A3

// Analog Stick
#define BUTTON_UD A0
#define BUTTON_LR A1

// Defines color values for game objects
#define SCHLANGE 1
#define WAND 2
#define ESSEN 3
#define OFF 0

// Defines states for state machine
#define WELCOME 0
#define OP 1
#define WIN 2
#define GAMEOVER 3
#define END 4
#define INIT 5


int dimx = 8;
int dimy = 8;
short STATE = 0;
int s_length = 3; // initial length of snake
int points = 0;
int item_amount = 6;
char startHeading = 's'; // Snake directions are relative to hardware configuration
int startposx = round((dimx/2));
int startposy = round((dimy/2));
int counter=0; // counter to time snake updates
int snake_speed = 30; // smaller value = higher speed

board board1;
snake* snake1 = new snake(s_length,startposx, startposy, startHeading);

// Output to LED matrix
void update(int mode) { 
    switch(mode) {
        case(0):
            break;
        case(1):
            board1.draw();
            break;
    }
}

// saves next item position in board
void create_item_pattern(){
    bool re = false;
    int x; 
    int y;
    
    while(re){}
    x = random(2,dimx-1);
    y = random(2,dimy-1);
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
    
// upon item collision
void eat() {
    create_item_pattern(); // new item
    snake1->grow(); // increase snake size
    points+=100;
    if (points==item_amount*100){STATE=WIN;} // win condition
    
}

// Handles collision checks and behavior
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


// updates snake position within data structure
void snake_move() {

    if (!check_collision()) {
        board1.setvalue(OFF, snake1->getposx(snake1->getlength()-1), snake1->getposy(snake1->getlength()-1));
        snake1->move();
    }

}

// updates snake position within board
void update_snake_pos() {

    for (int i=0; i<snake1->getlength(); i++) {
       
        board1.setvalue(SCHLANGE, snake1->getposx(i), snake1->getposy(i));

    }
   

}

// update snake
void go() {
    snake_move();
    update_snake_pos();
}

// Input handling

// Taster
// char read_key(){
//     char output;
//     char output = 'g';
//     if (digitalRead(BUTTON_UP)==HIGH){  
//         output='w';
//     }
//     if (digitalRead(BUTTON_DOWN)==HIGH){
//         output='s';
//     }
//     if (digitalRead(BUTTON_LEFT)==HIGH){
//         output='a';
//     }
//     if (digitalRead(BUTTON_RIGHT)==HIGH){
//         output='d';
//     }

//     return output;

// }

// Analog Stick
char read_key(){
    char output = 'g';
    if (map(analogRead(BUTTON_UD),0,770,0,100)>93){
        output='d';
    }
    if (map(analogRead(BUTTON_UD),0,770,0,100)<60){
        output='a';
    }
    if (map(analogRead(BUTTON_LR),0,1021,0,100)<=15){
        output='s';
    }
    if (map(analogRead(BUTTON_LR),0,1021,0,100)>=70){
        output='w';
    }

    return output;

}









void setup(){
  Serial.begin(9600); // Serial output for debugging
  create_item_pattern(); // get first item

// Button initialization - only for digital buttons, not analog stick
// Taster
//   pinMode(BUTTON_UP, INPUT);
//   pinMode(BUTTON_DOWN, INPUT);
//   pinMode(BUTTON_LEFT, INPUT);
//   pinMode(BUTTON_RIGHT, INPUT);

}

// "State Machine"
void loop(){ 
        if (STATE == WELCOME){
          STATE = INIT;
        } else if (STATE == INIT) {
            update_snake_pos(); // save initial snake position in board

            STATE = OP;
        } else if (STATE == OP) { // Main game logic

            //Input handling
            char input = read_key();

            //Changes snake direction absed on input
            if (input == 'w' || input == 'a' || input == 's' || input == 'd') {
                if (!(((input == 'w') && (snake1->getheading() == 's')) ||
                      ((input == 's') && (snake1->getheading() == 'w')) ||
                      ((input == 'a') && (snake1->getheading() == 'd')) ||
                      ((input == 'd') && (snake1->getheading() == 'a')))) {

                    snake1->setheading(input);
                }

            }

            // handles snake timing - Seperates snake update timing form multiplex timing
            // This way, the snake movement (update) speed is not bound to the multiplex time and can be set
            // seperately.
           if (counter==snake_speed){
            go();
            counter=0;
           } else {
               counter++;
           }

           // Output current board to LED matrix
           board1.draw();

        } else if (STATE == GAMEOVER) {
          board1.fill(2); // Fill board solid red
          board1.draw();

        } else if (STATE == WIN) {
            board1.fill(1); // // Fill board solid green
            board1.draw();
        } else if (STATE == END) {
          // END behavior - not implemented
        }
    }




