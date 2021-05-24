#include <iostream>
bool HandleInput(int input);

int main()
{
    bool quit = false;
    while (!quit) {
        int input = -1;
        std::cout << "1 - Play nim\n";
        std::cout << "2 - Play tictactoe\n";
        std::cout << "3 - Quit \n";
        std::cin >> input;
        quit = HandleInput(input);
    }
}

bool HandleInput(int input) {
    bool quit = false;
    switch (input)
    {
    case 1:
        std::cout << "Starting nim";
        break;
    case 2:
        std::cout << "Starting tictactoe";
        break;
    case 3:
        quit = true;
        break;
    default:
        break;
    }
    return quit;
}
