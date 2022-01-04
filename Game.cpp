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
    void Game::addScore(int _score){
        this->score += _score;
        
        this->board->displayBoard(this->board->tiles);
        this->printScore();
        
    }
    void Game::printScore() const{
        cout << this->score << endl;
    }

    void Game::start(){
        //this->board->displayBoard(this->board->tiles);
        int _score;
        while(!(this->board->checkGameOver(this->board->tiles))){
            
            _score = this->board->moveBoard(board->tiles, this->readInput());
            this->addScore(_score);

        }
        cout << "Game Over"<< endl;
    }

