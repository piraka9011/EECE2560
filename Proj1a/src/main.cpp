/**
	EECE2560: Proj1a
	main.cpp
	Purpose: Main function to implement the game and call all necessary classes
    It declares two class objects GC and SC to call the class Code
    function Check correct and incorrect
	@author: Anas Abou Allaban & Turki Alrifaie
	@version: 1.0 1/26/17

*/
#include "../include/code.h"

int main()
{
    //Declaring the length of the code and the range of the numbers variables
    int length, range, guess;
    int count = 0;
    bool result = false;
    std::vector<int> tempGuess;

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

    //Creating two objects in class code; Where CG (Code Guess) and SC(Secret Code).
    code SC(length,range);
    code GC(length,range);

    // Initialize secret code with random numbers
    SC.randomInit();

    // Print secret code for debugging
    SC.printSecretCode();

    // Loop while user has not won or less than 10 tries have been done
    while ( !result && count < 10 ) {
        // Input conditions
        std::cout << "\nPlease input your guess digit by digit with no spaces\n";
        // Make sure user enters the right amount of digits
        for (int i = 0; i < length; i++)
        {
            std::cin >> guess;
            tempGuess.push_back(guess);
        }
        // Set the user input to the guess code
        GC.setGuessCode(tempGuess);
        //Calling the check in/correct
        std::cout << "Correct digits in correct position: "
                  << SC.checkCorrect(GC) << '\n';
        std::cout << "Correct digits in incorrect position: "
                  << SC.checkIncorrect(GC) << '\n';

        // Reset our tempGuess vector
        tempGuess.clear();
        // Update results
        result = SC.checkWin(SC.checkCorrect(GC));
        // Increment count
        count++;
    }

    // Print whether user lost or won
    SC.printResult(result);

    return 0;
}
