/**
	EECE2560: Proj1a
	code.cpp
	Purpose: This file implements the member functions of the Code class.
    Implementations include: secret code initialization, check number of
    in/correct digits in in/correct location, checking if the game was won,
    and printing the result
	@author: Anas Abou Allaban & Turki Alrifaie
	@version: 1.0 1/26/17

*/

#include "../include/code.h"

// Code constructor
// Sets the length (n) and range (m) of the secret code
code::code(int n, int m)
{
    this->n = n;
    this->m = m;
}

// Secret Code initializer
void code::randomInit()
{
    // Generate random seed
    srand(time(0));
    // Add random numbers to secret code in range [0, m-1]
    for (int i = 0; i < n; i++)
        secretCode.push_back(rand() % m);
    // Resize the right digits vector that checks to see if a digit has been
    // checked according to the size of the secret code
    rightDig.resize(n, false);
}

// Checks guess if it is the correct number in the correct location
int code::checkCorrect(code guessCode)
{
    int correctPos = 0; // Count for correct guesses
    // Loop through secret code
    for (int i = 0; i < n; i++)
    {
        //  Check if guess digit at position i matches the secret code
        if (secretCode.at(i) == guessCode.getGuessCode().at(i))
        {
            // Increment the count for the correct number guess
            correctPos++;
            // Set that digit position as checked
            rightDig.at(i) = true;
        }
    }
    // Return the number of correct guesses
    return correctPos;
}

int code::checkIncorrect(code guessCode)
{
    // Make a new vector to store possible digits
    std::vector<int> digits(m);
    // Fill digits vector with numbers from 0 to m-1
    std::iota(digits.begin(), digits.end(), 0);
    // Variable to count the number of digits in the code but in the incorrect
    // position
    int incorrectPos = 0;

    // Loop through all numbers in the code
    for (int i = 0; i < n; i++)
    {
        // Loop through all possible digits
        for (int j = 0; j < n; j++)
        {
            // Check if the digit is already counted
            if (!rightDig.at(i) && (j != i))
            {
                // If the digit is in the guess code, increment count of
                // incorrect position
                if (guessCode.getGuessCode().at(i) == secretCode.at(j))
                {
                    // If its not counted, increment incorrect count and set
                    // digit position as checked
                    incorrectPos++;
                    rightDig.at(i) = true;
                }
            }
        }
    }

    // Reset right digits vector
    std::replace(rightDig.begin(), rightDig.end(), true, false);

    // Return number of correct digits in incorrect location
    return incorrectPos;
}

// Checks if the game is won
bool code::checkWin(int correctGuess)
{
    // If user found all digits in correct position, user won
    if (correctGuess == n)
        return true;
    else
        return false;
}

// Prints the result of whether user won or not
void code::printResult(bool result)
{
    // If user won, print out congrats statement
    if (result)
        std::cout << "\nCongratulations, you win!";
    // Otherwise tell them they are losers :c
    else
        std::cout << "\nYou lost! Try Again...";
}

