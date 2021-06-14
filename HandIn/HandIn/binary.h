#pragma once
#include <iostream>
#include <stack>
#include "input_handler.h"

namespace binary {

	static void PrintBitOpsRecursive(int decimal) {
		if ((decimal >> 1) > 0) {
			PrintBitOpsRecursive(decimal >> 1);
		}
		std::cout << (decimal & 1);
	}

	// This is the requested modulo solution. Currently not in use.
	static void PrintModuloRecursive(int decimal) {
		if ((decimal / 2) > 0)
			PrintModuloRecursive(decimal/2);
		std::cout << decimal % 2;
	}

	static void InputToBinary() {
		std::cout << "Enter number to transform \n>";
		int number{ InputHandler::GetInt() };
		if (number < 0) {
			std::cout << "Negative numbers are no fun. Come back later. \n";
			return;
		}
		std::cout << "0b";
		PrintBitOpsRecursive(number);
		std::cout << "\n";
	}
}