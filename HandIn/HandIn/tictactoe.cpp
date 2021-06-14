#include "tictactoe.h"
#include <iostream>
#include <cmath>
#include "input_handler.h"

void TicTacToe::Play()
{
	int current_player{ 0 };
	int moves{ 0 };

	while (true) {
		PrintBoard();
		std::cout << "Player " << current_player << ", select column \n";
		int col{ InputHandler::GetInt() };
		std::cout << "Player " << current_player << ", select row \n";
		int row{ InputHandler::GetInt() };

		if (!MoveIsLegal(col, row)) {
			std::cout << "illegal move. Try again";
			continue;
		}
		
		moves++;
		PlaceMark(current_player, col, row);
		PrintBoard();
		if (IsWinningMove(col, row)) {
			std::cout << "Player " << current_player << "won!!!\n \n \n";
			break;
		}
		else if (moves == 9) {
			std::cout << "Its a draw! \n";
			break;
		}
		current_player = (current_player + 1) % 2;
	}
}

void TicTacToe::PlaceMark(int current_player, int col, int row)
{
	int mark = current_player % 2 == 0 ? -1 : 1;
	board[col][row] = mark;
}

void TicTacToe::PrintBoard()
{
	std::cout << "\n";
	for (size_t y = 0; y < 3; y++)
	{
		for (size_t x = 0; x < 3; x++)
		{
			char mark = '#';
			if (board[x][y] == 1)
				mark = 'X';
			else if (board[x][y] == -1)
				mark = 'O';
			std::cout << mark << " ";
		}
		std::cout << "\n";
	}
}

bool TicTacToe::MoveIsLegal(int col, int row)
{
	return col >= 0 && col < 3 && row >= 0 && row < 3 && board[col][row] == 0;
}

bool TicTacToe::IsWinningMove(int col, int row)
{
	int r_col{ 0 };
	int r_row{ 0 }; 
	int diag_tl_br{ 0 };
	int diag_tr_bl{ 0 };

	for (size_t i = 0; i < 3; i++)
	{
		r_col += board[col][i]; 
		r_row += board[i][row];
		diag_tl_br += board[i][i];
		diag_tr_bl += board[i][2 - i];
	}
	return abs(r_col) == 3 || abs(r_row) == 3 || abs(diag_tl_br) == 3 || abs(diag_tl_br) == 3;
}
