
#include "../include/code.h"

int main() {

    //Declaring the length of the code and the range of the numbers variables
    int length, range, guess;
    int correctPos = 0, incorrectPos=0 , count = 0;
    bool win = false;
    std::vector<int> secretTemp;


    //Prompting the user for two inputs to assign to length and range
    std::cout << "Please enter the length of the desired secret code: ";
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
    while ( !win && count < 10 ) {
        // Prompt user to enter a guess
        std::cout << "Enter guess code: ";
        std::cin >> guess;

        // Parse input string and set guess code
        GC.setGuessCode(code::int2vector(guess));
        //Calling the check in/correct
        std::cout << "Correct digits in correct position: "
                  << SC.checkCorrect(GC) << '\n';
        std::cout << "Correct digits in incorrect position: "
                  << SC.checkIncorrect(GC) << '\n';

        win = SC.checkWin();
        count++;
    }

    // Print whether user lost or won
    SC.printResult();

    return 0;
}
