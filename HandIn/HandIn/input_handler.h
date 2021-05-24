// for anyone peeking =) 
// https://www.learncpp.com/cpp-tutorial/stdcin-and-handling-invalid-input/

#pragma once
#include <iostream>;

class InputHandler {
public:
    static int GetInt()
    {
        while (true) // Loop until user enters a valid input
        {
            int x{};
            std::cin >> x;

            // Check for failed extraction
            if (std::cin.fail()) // has a previous extraction failed?
            {
                std::cin.clear(); // put us back in 'normal' operation mode
                IgnoreLine(); // and remove the bad input
                std::cout << "Invalid input.\n";
            }
            else
            {
                IgnoreLine(); // remove any extraneous input
                return x;
            }
        }
    }
private:
    static void IgnoreLine()
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
};