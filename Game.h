/**
 * Game.h
 * A base class for all computer games
 */

#ifndef COMPUTERGAME_GAME_H
#define COMPUTERGAME_GAME_H
#include <iostream>

class Game
{
public:
    enum who{HUMAN, COMPUTER, NEUTRAL};

    Game(){numberMoves=0;}
    void displayMessage2()
    {
        std::cout << "The game ends at move number "<< numberMoves << ".\n";
    }

    /**
     * The human and the machine takes turns to play this game
     * Post-Condition: A player is returned depending on who is the last player when the game is over
     * @return
     */
    who play();
    virtual bool isGameOver()const=0;//must be pure virtual
    /**
     * Post-Condition: a message that describes the game has been displayed at the beginning of the game
     */
    virtual void displayMessage()const=0;
    /**
     * Post-Condition: the computer has made its move
     */
    virtual void computerMove()=0;
    /**
     * Post-Condition: the human has made its move
     */
    virtual void makeMove()=0;

    int getNumber(){return numberMoves;}
    virtual~ Game(){}
private:
    int numberMoves; //number of moves made so far
};


#endif //COMPUTERGAME_GAME_H
