#include "Board.h"

TicTacToe::TicTacToe() {
    EmptyBoxes = 9;
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            Board[y][x] = ' ';
        }
    }
}

void TicTacToe::ShowBoard() const {
    for (int i = 0; i < 3; i++) {
        std::cout << Board[i][0] << " | " << Board[i][1] << " | " << Board[i][2] << std::endl;
    }
}

void TicTacToe::NextTurn(int pos) {
    Board[pos / 3][pos % 3] = 'O';
    EmptyBoxes--;
}

void TicTacToe::GetUserInput() {
    int x, y;
    do {
        std::cout << "Please enter the position of your box:" << std::endl;
        do {
            scanf_s("%d,%d", &x, &y);
            x--, y = 3 - y;
        } while ((y < 0 || y > 2) || (x < 0 || x > 2));
    } while (Board[y][x] != ' ');

    Board[y][x] = 'X';
    EmptyBoxes--;
}

int TicTacToe::CheckIfWon() const {
    if (EmptyBoxes == 0) {
        return 1;
    }
    else {
        char symbols[2] = { 'X', 'O'};
        int returnstatus[2] = { 2, 3 };
        bool flag;
        for (int i = 0; i < 2; i++) {
            for (int y = 0; y < 3; y++) {
                flag = true;
                for (int x = 0; x < 3; x++) {
                    if (Board[y][x] != symbols[i]) {
                        flag = false;
                    }
                }
                if (flag == true) {
                    return returnstatus[i];
                }

                flag = true;
                for (int x = 0; x < 3; x++) {
                    if (Board[x][y] != symbols[i]) {
                        flag = false;
                    }
                }
                if (flag == true) {
                    return returnstatus[i];
                }

                flag = true;
                for (int x = 0; x < 3; x++) {
                    if (Board[x][x] != symbols[i]) {
                        flag = false;
                    }
                }
                if (flag == true) {
                    return returnstatus[i];
                }

                flag = true;
                for (int x = 0; x < 3; x++) {
                    if (Board[x][2 - x] != symbols[i]) {
                        flag = false;
                    }
                }
                if (flag == true) {
                    return returnstatus[i];
                }
            }

        }
        return 0;
    }
}