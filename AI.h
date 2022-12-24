#pragma once
#ifndef AI_H
#define AI_H

#include <iostream>
#include <string>

class AI {
public:
	int BestMove(std::string Board[3][3]);

	int Minimax(std::string Board[3][3], int depth, bool bIsMaximizing);

	std::string CheckWinner(std::string Board[3][3]);
};
#endif // !AI_H