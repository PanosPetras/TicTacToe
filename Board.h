#pragma once
#ifndef Board_H
#define Board_H

#include <iostream>
#include <string>

class TicTacToe {
private:
    int EmptyBoxes;

public:
    /*The Game Board
    Each element of the Array represents a box on the board
    Filled with either Xs or Os
    O is for the computer, X is for the player*/
    std::string Board[3][3];

    //Constructor
    TicTacToe();

    //Print the game board to the screen
    void ShowBoard();

    void NextTurn(int pos);

    void GetUserInput();

    //Check if either the player or the AI won
    int CheckIfWon() const;
};

#endif // !Board_H#pragma once
