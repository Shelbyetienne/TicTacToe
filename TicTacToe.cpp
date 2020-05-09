//
// Created by Shelby Etienne on 4/24/20.
//

#include "TicTacToe.h"

namespace se_T3 {
    TicTacToe::TicTacToe() {
        grid = new char *[3];
        for (int i = 0; i < 3; ++i)
            grid[i] = new char[3];

        x = 0;
        y = 0;

        //insert the ; and : to make my 3 by 3 grid
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                grid[i][j] = ';';
        grid[1][0] = ':';
        grid[0][1] = ':';
        grid[2][2] = ':';
        grid[0][2] = ':';
    }

    void TicTacToe::computerMove() {
        cout << "Computer's Move: \n";
        //generate random number between 0 and 2
            srand(time(NULL));
            int v = rand() % 3;
            int b = rand() % 3;
            while (grid[v][b] != ';' && grid[v][b] != ':')//if two random numbers get generated again
            {
                //generate different numbers
                v = rand() % 3;
                b = rand() % 3;
            }
            grid[v][b] = 'X';
            /**SMART COMPUTER>**/
        /*    cout << "There is a connect!\n";
            if (hasConnect()) {
                if ((grid[0][0] == grid[1][1] || grid[1][1] == grid[2][2] || grid[0][0] == grid[2][2]) && (grid[0][0] != ';' && grid[1][1] != ';') && (grid[1][1]!='X' || grid[2][2]!='X' || grid[0][0]!='X'))//diagonal
                {
                    cout << "diagonal\\" << endl;
                    if (grid[0][0] == grid[1][1]) {
                        grid[2][2] = 'X';
                    } else if (grid[1][1] == grid[2][2] ) {
                        grid[0][0] = 'X';
                    } else if (grid[0][0] == grid[2][2]) {
                        grid[1][1] = 'X';
                    }
                } else if ((grid[0][0] == grid[0][1] || grid[0][1] == grid[0][2] || grid[0][0] == grid[0][2]) && (grid[0][0] != ';' && grid[0][2]!=':') && (grid[0][0]!='X' || grid[0][2]!='X' || grid[0][1]!='X'))//vertical 1
                {
                    cout << "vertical 1" << endl;
                    if (grid[0][0] == grid[0][1]) {
                        cout << "ve" << endl;
                        grid[0][2] = 'X';
                    } else if (grid[0][1] == grid[0][2]) {
                        cout << "vertical " << endl;
                        grid[0][0] = 'X';
                    } else if (grid[0][0] == grid[0][2]) {
                        cout << "verti 1" << endl;
                        grid[0][1] = 'X';
                    }
                } else if ((grid[0][0] == grid[1][0] || grid[1][0] == grid[2][0] || grid[0][0] == grid[2][0])&& (grid[1][0] != ':' || grid[2][0]!=';') && (grid[0][0]!='X' || grid[1][0]!='X' || grid[2][0]!='X' ))//horizontal 1
                {
                    cout << "horizontal 1" << endl;
                    if (grid[0][0] == grid[1][0]) {
                        grid[2][0] = 'X';
                    } else if (grid[1][0] == grid[2][0]) {
                        grid[0][0] = 'X';
                    } else if (grid[0][0] == grid[2][0]) {
                        grid[1][0] = 'X';
                    }
                } else if ((grid[0][1] == grid[1][1] || grid[1][1] == grid[2][1] || grid[0][1] == grid[2][1]) && (grid[1][1] != ';') && (grid[1][1]!='X' || grid[2][1]!='X' || grid[0][1]!='X'))//horizontal 2
                {
                    cout << "horizontal 2" << endl;
                    if (grid[0][1] == grid[1][1]) {
                        grid[2][1] = 'X';
                    } else if (grid[1][1] == grid[2][1]) {
                        grid[0][1] = 'X';
                    } else if (grid[0][1] == grid[2][1]) {
                        grid[1][1] = 'X';
                    }
                } else if ((grid[0][2] == grid[1][2] || grid[1][2] == grid[2][2] ||
                           grid[0][2] == grid[2][2])&& (grid[2][2] != ':')&& (grid[2][0] != ';') && (grid[1][2]!='X' || grid[2][2]!='X' || grid[0][2]!='X'))//horizontal 3
                {
                    cout << "horizontal 3" << endl;
                    if (grid[0][2] == grid[1][2]) {
                        grid[2][2] = 'X';
                    } else if (grid[1][2] == grid[2][2]) {
                        grid[0][2] = 'X';
                    } else if (grid[0][2] == grid[2][2]) {
                        grid[1][2] = 'X';
                    }
                } else if ((grid[2][0] == grid[2][1] || grid[2][1] == grid[2][2] || grid[2][0] == grid[2][2])&& (grid[2][0] != ';') && (grid[2][1]!='X' || grid[2][2]!='X' || grid[2][0]!='X'))//vertical 3
                {
                    cout << "vertical 3" << endl;
                    if (grid[2][0] == grid[2][1]) {
                        grid[2][2] = 'X';
                    } else if (grid[2][1] == grid[2][2] ) {
                        grid[2][0] = 'X';
                    } else if (grid[2][0] == grid[2][2]) {
                        grid[2][1] = 'X';
                    }
                } else if ((grid[1][0] == grid[1][1] || grid[1][1] == grid[1][2] || grid[1][0] == grid[1][2])&& (grid[1][0] != ':')&& (grid[1][1]!='X' || grid[1][2]!='X'|| grid[1][0]!='X'))//vertical 2
                {
                    cout << "vertical 2" << endl;
                    if (grid[1][0] == grid[1][1] ) {
                        grid[1][2] = 'X';
                    } else if (grid[1][1] == grid[1][2]) {
                        grid[1][0] = 'X';
                    } else if (grid[1][0] == grid[1][2]) {
                        grid[1][1] = 'X';
                    }
                } else if ((grid[2][0] == grid[1][1] || grid[1][1] == grid[0][2] || grid[2][0] == grid[0][2]) && (grid[2][0] != ';')&& (grid[1][1]!='X' || grid[0][2]!='X' || grid[2][0]!='X'))//diagonal
                {
                    cout << "diagonal/" << endl;
                    if (grid[2][0] == grid[1][1]) {
                        grid[0][2] = 'X';
                    } else if (grid[1][1] == grid[0][2]) {
                        grid[2][0] = 'X';
                    } else if (grid[2][0] == grid[0][2]) {
                        grid[1][1] = 'X';
                    }
                }
             }

        }
        */
        /**SMART COMPUTER<**/

        print();
    }

    void TicTacToe::makeMove() {
        cout << "Your Move (Enter where you want to go): \n";
        cin >> x >> y;
        //numbers must be between 1-3
        grid[x - 1][y - 1] = 'O';
        print();
    }

    bool TicTacToe::isGameOver() const {

        if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] && grid[0][0] == grid[2][2])//diagonal
        {
            return true;
        } else if (grid[0][0] == grid[0][1] && grid[0][1] == grid[0][2] && grid[0][0] == grid[0][2])//vertical 1
        {
            return true;
        } else if (grid[0][0] == grid[1][0] && grid[1][0] == grid[2][0] && grid[0][0] == grid[2][0])//horizontal 1
        {
            return true;
        } else if (grid[0][1] == grid[1][1] && grid[1][1] == grid[2][1] && grid[0][1] == grid[2][1])//horizontal 2
        {
            return true;
        } else if (grid[0][2] == grid[1][2] && grid[1][2] == grid[2][2] && grid[0][2] == grid[2][2])//horizontal 3
        {
            return true;
        } else if (grid[2][0] == grid[2][1] && grid[2][1] == grid[2][2] && grid[2][0] == grid[2][2])//vertical 3
        {
            return true;
        } else if (grid[1][0] == grid[1][1] && grid[1][1] == grid[1][2] && grid[1][0] == grid[1][2])//vertical 2
        {
            return true;
        } else if (grid[2][0] == grid[1][1] && grid[1][1] == grid[0][2] && grid[2][0] == grid[0][2])//diagonal
        {
            return true;
        }
    }
/*
    bool TicTacToe::hasConnect()
    {
        if ((grid[0][0] == grid[1][1] || grid[1][1] == grid[2][2] || grid[0][0] == grid[2][2]) && (grid[0][0] != ';' ||  grid[1][1] != ';'))//diagonal
        {
            cout << "diagonal\\*" << endl;
            return true;
        } else if ((grid[0][0] == grid[0][1] || grid[0][1] == grid[0][2] || grid[0][0] == grid[0][2]) && (grid[0][1] != ':' || grid[0][2]!=':'))//vertical 1
        {
            cout << "vertical 1*" << endl;
            return true;
        } else if ((grid[0][0] == grid[1][0] || grid[1][0] == grid[2][0] || grid[0][0] == grid[2][0]) && (grid[1][0] != ':' || grid[2][0]!=';'))//horizontal 1
        {
            cout << "/horizontal 1*" << endl;
            return true;
        } else if ((grid[0][1] == grid[1][1] || grid[1][1] == grid[2][1] || grid[0][1] == grid[2][1]) && (grid[1][1] != ';'))//horizontal 2
        {
            cout << "horizontal 2*" << endl;
            return true;
        } else if ((grid[0][2] == grid[1][2] || grid[1][2] == grid[2][2] || grid[0][2] == grid[2][2]) && (grid[2][2] != ':'))//horizontal 3
        {
            cout << "horizontal 3*" << endl;
            return true;
        } else if ((grid[2][0] == grid[2][1] || grid[2][1] == grid[2][2] || grid[2][0] == grid[2][2]) && (grid[2][0] != ';'))//vertical 3
        {
            cout << "vertical 3*" << endl;
            return true;
        } else if ((grid[1][0] == grid[1][1] || grid[1][1] == grid[1][2] || grid[1][0] == grid[1][2]) && (grid[1][0] != ':'))//vertical 2
        {
            cout << "vertical 2*" << endl;
            return true;
        } else if ((grid[2][0] == grid[1][1] || grid[1][1] == grid[0][2] || grid[2][0] == grid[0][2]) && (grid[2][0] != ';'))//diagonal
        {
            cout << "diagonal/*" << endl;
            return true;
        }
    }
    */
}