#include "AI.h"

int AI::BestMove(char Board[3][3]) {
    // AI to make its turn
    int bestScore = -1000, score;
    int move;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            // Is the spot available?
            if (Board[i][j] == ' ') {
                Board[i][j] = 'O';
                score = AlphaBeta(Board, 0, -1000, 1000, false);
                Board[i][j] = ' ';

                if (score > bestScore) {
                    bestScore = score;
                    move = 3 * i + j;
                }
            }
        }
    }
    return move;
}

inline int max(int a, int b) {
    return a > b ? a : b;
}

inline int min(int a, int b) {
    return a < b ? a : b;
}

int AI::AlphaBeta(char Board[3][3], int depth, int a, int b, bool bIsMaximizing) {
    //Check if the game is at an end state
    char result = CheckWinner(Board);
    if (result != ' ') {
        if (result == 'X') {
            return -10 - depth;
        }
        else if (result == 'O') {
            return 10 - depth;
        }
        else {
            return 0 - depth;
        }
    }
    //Investigate incursively all the possible moves
    if (bIsMaximizing) {
        int BestScore = -1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                // Is the spot available?
                if (Board[i][j] == ' ') {
                    Board[i][j] = 'O';
                    BestScore = max(BestScore, AlphaBeta(Board, depth + 1, a, b, false));
                    Board[i][j] = ' ';

                    a = max(a, BestScore);
                    if (BestScore >= b) return BestScore;
                }
            }
        }
        return BestScore;
    } else {
        int WorstScore = 1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                // Is the spot available?
                if (Board[i][j] == ' ') {
                    Board[i][j] = 'X';
                    WorstScore = min(WorstScore, AlphaBeta(Board, depth + 1, a, b, true));
                    Board[i][j] = ' ';

                    b = min(b, WorstScore);
                    if (WorstScore < a) return WorstScore;
                }
            }
        }
        return WorstScore;
    }
}

char AI::CheckWinner(char Board[3][3]) {
    char winner = ' ';

    for (int i = 0; i < 3; i++) {
        //Horizontal
        if (Board[i][0] == Board[i][1] && Board[i][1] == Board[i][2] && Board[i][2] == Board[i][0]) {
            winner = Board[i][0];
        }
        //Vertical
        if (Board[0][i] == Board[1][i] && Board[1][i] == Board[2][i] && Board[2][i] == Board[0][i]) {
            winner = Board[0][i];
        }
    }

    // Diagonal
    if (Board[0][0] == Board[1][1] && Board[1][1] == Board[2][2] && Board[2][2] == Board[0][0]) {
        winner = Board[0][0];
    }
    if (Board[2][0] == Board[1][1] && Board[1][1] == Board[0][2] && Board[2][0] == Board[0][2]) {
        winner = Board[2][0];
    }

    int openSpots = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (Board[i][j] == ' ') {
                openSpots++;
            }
        }
    }

    if (winner == ' ' && openSpots == 0) {
        return 'T';
    }
    else {
        return winner;
    }
}