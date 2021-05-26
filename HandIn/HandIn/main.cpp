#include <iostream>
#include "input_handler.h"
#include "nim.h"
#include "tictactoe.h"

bool HandleInput(int input);
const std::string options{   
    "1 - Play nim\n"
    "2 - Play tictactoe\n"
    "3 - Quit \n\n"
};

int main()
{
    bool quit = false;
    while (!quit) {
        std::cout << options;
        int input{ InputHandler::GetInt() };
        quit = HandleInput(input);
    }
}

bool HandleInput(int input) {

    bool quit = false;
    if (input == 1) {
        std::cout << "Starting nim...\n";
        Nim nim{};
        nim.Play();
    }
    else if (input == 2) {
        std::cout << "Starting tictactoe... \n";
        TicTacToe tictactoe{};
        tictactoe.Play();
    }
    else if (input == 3) {
        std::cout << "Closing application... \n";
        quit = true;
    }
    return quit;
}
