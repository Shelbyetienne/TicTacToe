/**
 * Game.cpp
 */

#include "Game.h"

void Game::displayMessage()const
{
    std::cout <<"Welcome to our great game: ";
}

Game::who Game::play()
{
    //Determine who starts first
    srand((unsigned)time(NULL));
    int turn=(int)(0.5 + rand()/(double)RAND_MAX);
    displayMessage();

    std::cout << ((turn==0)? "The machine goes " : "You go ") << "first: \n";

    while(true)
    {
        numberMoves++;
        if(turn==0)
            computerMove();
        else
            makeMove();

        if(isGameOver() && turn == 0)
        {
            displayMessage2();
            return COMPUTER;
        }
        else if(isGameOver() && turn ==1) {
            displayMessage2();
            return HUMAN;
        }
        else if(getNumber()==9) {
            displayMessage2();
            return NEUTRAL;
        }

        turn=(1+turn)%2;
    }
}
