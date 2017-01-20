
#include <iostream>
#include <vector>
#include "../include/code.h"


int main() {
    //std::cout << "Hello, World!" << std::endl;

    //Declaring the length of the code and the range of the numbers variables
    int m,n;

    //Prompting the user for two inputs to assign to length and range
    std::cout << "Please enter the length of the desired secret code followed by the range of numbers\n";
    std::cin >> n >> m;

    //Creating two objects in class code; Where CG (Code Guess) and SC(Secret Code).
    code SC(n,m);
    code GC(n,m);
    SC.randomInit();
    //counter for the while loop that breaks if the user failed to win in the first 10 times (Loses).
    int count=0;

    //Reminder of the parameters that the user passed
    std::cout<<"Enter your guess\n Remember that the code length is "
             <<n<<" and the range is from "<<0 << " To " <<m << std::endl;

    //While loop to implement the calss functions
    while(count!=10) {
        //Calling the check correct class function that also prompts the user for inputs
        SC.checkCorrect(GC);

    }

    return 0;
}
