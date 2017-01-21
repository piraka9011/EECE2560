
#include "../include/code.h"

int main() {

    //Declaring the length of the code and the range of the numbers variables
    int length,range, count = 0;
    bool win = false;

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

    //Reminder of the parameters that the user passed
    std::cout<<"Enter your guess\n Remember that the code length is "
             <<range<<" and the range is from "<<0 << " To " <<length;

    while (SC.checkWin() && count < 10 ) {
        std::cout << "Enter guess code: ";

        //Calling the check correct
        SC.checkCorrect(GC);
    }

    return 0;
}
