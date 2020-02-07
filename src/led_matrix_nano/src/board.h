#ifndef BOARD_H
#define BOARD_H

class board {
    private:
    short mat [8][8];
    void setpixel(short rg, short x, short y);
    
    public:
    board();
    ~board();
    void draw();
    void init();
    void setvalue(short value, short x, short y);
    short getvalue(short x, short y);
    void set_default();
    void fill(short f);

};

#endif