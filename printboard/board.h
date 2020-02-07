#ifndef BOARD_H_
#define BOARD_H_
#include "board.cpp";

class board {
    private:
    short mat [8][8];
    void setpixel(short rg, short x, short y);
    
    public:
    board():{mat = {{0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},}};
    ~board(){};
    void draw();
    void init();
    void setvalue(short value, short x, short y);
    short getvalue(short x, short y);

}

#endif