/* Turki Alrifaie Anas Abou Allaban - Proj1a
 * This main file holds the implementation of the class code.
 * It declares two class objects GC and SC to call the class Code
 * function Check correct and incorrect
 */
#include "../include/code.h"

std::vector<int> int2vector(int int2parse) {
    std::vector<int> parsedInt;

    // Mod 10 to get digits, divide by 10 until number doesn't exist
    while (int2parse > 0){
        int digit = int2parse % 10;
        int2parse /= 10;
        parsedInt.push_back(digit);
    }

    // Flip digits to correct order
    std::reverse(parsedInt.begin(), parsedInt.end());

    return parsedInt;
}

int getSize(int number) {
    int length = 0;
    while (number){
        number /= 10;
        length++;
    }
    return length;
}

int main() {

    //Declaring the length of the code and the range of the numbers variables
    int length, range, guess;
    int count = 0;
    bool result = false;
    std::vector<int> secretTemp;

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

    // Input conditions
    std::cout << "\nPlease input your guess with no spaces\n";

    // Loop while user has not won or less than 10 tries have been done
    while ( !result && count < 10 ) {
        // Make sure user enters the right amount of digits
        do {
            // Prompt user to enter a guess
            std::cout << "Enter guess code: ";
            std::cin >> guess;
        } while (getSize(guess) != length);
        // Parse input string and set guess code
        GC.setGuessCode(int2vector(guess));
        //Calling the check in/correct
        std::cout << "Correct digits in correct position: "
                  << SC.checkCorrect(GC) << '\n';
        std::cout << "Correct digits in incorrect position: "
                  << SC.checkIncorrect(GC) << '\n';

        result = SC.checkWin(SC.checkCorrect(GC));
        count++;
    }

    // Print whether user lost or won
    SC.printResult(result);

    return 0;
}
