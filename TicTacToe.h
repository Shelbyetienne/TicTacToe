//
// Created by Shelby Etienne on 4/24/20.
//

#ifndef COMPUTERGAME_TICTACTOE_H
#define COMPUTERGAME_TICTACTOE_H
#include "Game.h"

using namespace std;
namespace se_T3 {
    class TicTacToe : public Game {
    public:
        TicTacToe();

        /**
         * Post-Condition--Print out my Tic Tac Toe board at current state
         */
        void print() {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    cout << grid[j][i] << " ";
                }
                cout << endl;
            }
        }

        /**
         * Post-Condition--Displays the message.
         */
        virtual void displayMessage() const {
            Game::displayMessage();
            std::cout << "TicTacToe!\n"
                      << "Three in a row is the goal!!!\n"
                      << "Computer is X, and you'll be O\n"
                      << "You'll take turns finding a place to go!\n"
                      << "Whoever gets three, horizontal, vertical, or diagonal...\n"
                      << "WINS THE GAME!\n\n"
                      << "\t\t\t(HOW TO MOVE)\n"
                      << "* pick a number between 1-3 on x-axis   *\n"
                         "* then press space and choose a number  *\n"
                         "* between 1-3 on y-axis and press ENTER *\n\n";
        }

        /**
         * Pre-Condition--It is Computers turn.
         * Post-Condition--Computer makes a move.
         */
        virtual void computerMove();

        /**
         * Pre-Condition--It is HUMANS move, and selects a position.
         * Post-Condition--Human makes a move.
         */
        virtual void makeMove();

        /**
         *
         * Post-Condition--@return true if someone gets three in a row.
         */
        virtual bool isGameOver() const;

        virtual ~TicTacToe() {}

        //bool hasConnect();

    private:
        char **grid;//2d array
        int x;//position X
        int y;//position Y
    };
}

#endif //COMPUTERGAME_TICTACTOE_H
