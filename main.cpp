#include "Board.h"
#include "AI.h"
#include <iostream>
#include <Windows.h>

inline void Render(TicTacToe ttt) {
	system("cls");
	ttt.ShowBoard();
}

int main() {
	TicTacToe ttt;
	AI ai;

	while (!ttt.CheckIfWon()) {
		Render(ttt);
		ttt.GetUserInput();

		if (!ttt.CheckIfWon()) {
			ttt.NextTurn(ai.BestMove(ttt.Board));
		}
	}

	Render(ttt);

	if (ttt.CheckIfWon() == 2) {
		std::cout << "The player won!";
	} else if (ttt.CheckIfWon() == 3) {
		std::cout << "The computer won!";
	} else {
		std::cout << "It's a draw!";
	}

	return 0;
}