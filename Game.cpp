#include <iostream>
#include "Board.h"
#include "Game.h"


using namespace std;

    Game::Game(){
        board = new Board;
        score = 0;
    }
    Game::~Game(){
        delete board;
    }

    Direction Game::readInput() const{
        char input;
        cin >> input;
        if (input == 'w')
            return UP;
        if(input == 'a')
            return LEFT;
        if(input == 's')
            return DOWN;
        if(input == 'd')
            return RIGHT;
        else 
            return INVALID;
    }
    void Game::addScore(int score){
        this->score += score;
        
    }
    void Game::printScore() const{
        

    }

    void Game::start(){
        
        this->board->displayBoard(this->board->tiles);
        int score = this->board->moveBoard(board, this->board());
        //addScore();

       
    }

int main(){
    Direction a;
    
    Game b;
    cout << b.score << endl;
    char c[4][4];
    //b.board->displayBoard(c);

    
    return 0;
}



