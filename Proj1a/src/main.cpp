/*Project 1a                 Turki Alrifaie Anas Abou Allaban
 *
 * This main file contains all the user prompts and class function calls.
 * In addition, it includes all of the object class (code) declarations.
 * */
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

int main() {

    //Declaring the length of the code and the range of the numbers variables
    int length, range, guess;
    int count = 0;
    bool result = false;
    std::vector<int> secretTemp;



    //Prompting the user for two inputs to assign to length and range
    std::cout << "Please enter the length of the desired secret code: ";
    std::cin >> length; // will be used to assign length
    std::cout << "Please enter the range of digits: ";
    std::cin >> range; // Will be used to assign range of numbers

    //Creating two objects in class code; Where CG (Code Guess) and SC(Secret Code).
    //Passing the same range and length to both class object
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
        // Prompt user to enter a guess
        std::cout << "Enter guess code: ";
        std::cin >> guess;

        // Parse input string and set guess code
        GC.setGuessCode(int2vector(guess));
        //Calling the check in/correct
        std::cout << "Correct digits in correct position: "
                  << SC.checkCorrect(GC) << '\n'; // Check how many correct digits object GC has
        std::cout << "Correct digits in incorrect position: "
                  << SC.checkIncorrect(GC) << '\n'; // Check how many incorrect digits object GC has

        //Pass the number of correct digits to SC check win function to decide whether to end loop or not
        result = SC.checkWin(SC.checkCorrect(GC));
        //Increment the counter
        count++;
    }

    // Print whether user lost or won
    SC.printResult(result);

    return 0;
}
