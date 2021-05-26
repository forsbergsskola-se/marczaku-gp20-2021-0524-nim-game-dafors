#pragma once

class TicTacToe {
public:
	void Play();
	
private:
	int board[3][3] = { 0 };
	void PlaceMark(int current_player, int col, int row);
	void PrintBoard();
	bool MoveIsLegal(int col, int row);
	bool IsWinningMove(int col, int row);
};