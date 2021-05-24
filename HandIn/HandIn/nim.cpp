#include "nim.h"
#include <iostream>
#include "input_handler.h"

void Nim::Play()
{
	std::cout << this->rules;
	int input = -1;
	while (remaining_sticks > 0) {
		DrawSticks();
		std::cout << "Player " << current_player << ", draw your sticks... \n";
		int input{ InputHandler::GetInt() };
		if (MoveIsLegal(input)) {
			remaining_sticks -= input;
			current_player = (current_player + 1) % 2;
		}
	}
	std::cout << "Player " << current_player << "won!!!\n \n \n";
}

bool Nim::MoveIsLegal(int input)
{
	return input > 0 && input <= remaining_sticks && input <= 3;
}

void Nim::DrawSticks()
{
	for (size_t i = 0; i < remaining_sticks; i++)
	{
		std::cout << "|"; 
		if ((i + 1) % 5 == 0)
			std::cout << " ";
	}
	std::cout << "\n";
}

