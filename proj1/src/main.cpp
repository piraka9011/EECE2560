/**
	EECE2560: Proj1b
	main.cpp
	Purpose: Main function to implement the game and call all necessary classes
    It declares a class object game which is passed to the class mastermind
    to call the necessary function/s
	@author: Anas Abou Allaban & Turki Alrifaie
	@version: 1.0 1/26/17

*/
#include "../include/mastermind.h"

int main()
{
    // Declaring the length of the code and the range of the numbers variables
    int length, range;

    // Welcome message
    std::cout << "****************************************************\n";
    std::cout << "*                                                  *\n";
    std::cout << "*______________ Welcome to MasterMind! ____________*\n";
    std::cout << "*               ~~~~~~~~~~~~~~~~~~~~~~             *\n";
    std::cout << "****************************************************\n";

    //Prompting the user for two inputs to assign to length and range
    std::cout << "\nPlease enter the length of the desired secret code: ";
    std::cin >> length;
    std::cout << "Please enter the range of digits: ";
    std::cin >> range;

    // Create new Mastermind object
    mastermind game(length, range);
    game.playGame();

    return 0;
}
