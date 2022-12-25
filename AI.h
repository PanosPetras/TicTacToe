#pragma once
#ifndef AI_H
#define AI_H

#include <iostream>
#include <string>

class AI {
public:
	int BestMove(char Board[3][3]);

	int AlphaBeta(char Board[3][3], int depth, int a, int b, bool bIsMaximizing);

	char CheckWinner(char Board[3][3]);
};
#endif // !AI_H