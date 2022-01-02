#ifndef _BOARD_H_
#define _BOARD_H_

#include<iostream>
#include<ctime>
#include<cmath>
using namespace std;

enum Direction{
        UP,
        DOWN,
        LEFT,
        RIGHT,
        INVALID

};

class Board {
    
    public:

    Board ();
    int k;
    bool flag;
    int i;
    int j;
    int ran1;
    int ran2;
    int val;
    int reward;
    
    
    int score;
    char tiles[4][4];
    void newTile();
    int moveSingleLine(const char line[4], char new_line[4]);
    void displayBoard(const char tiles[4][4]) const;
    int moveBoard(char tiles[4][4], Direction dir);
    bool checkGameOver(char tiles[4][4]) const;

};
   


#endif
