#ifndef _GAME_H_
#define _GAME_H_

#include <iostream>
#include "Board.h"

using namespace std;

class Game {
public:
    Game();
    ~Game();

    Direction readInput() const;
    void addScore(int score);
    void printScore() const;    
    void start();
    int score;
    Board *board;
};






#endif
