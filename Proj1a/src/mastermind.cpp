//
// Created by piraka9011 on 1/28/17.
//

#include "../include/mastermind.h"

mastermind::mastermind(int n, int m) :
    masterCode(n, m)
{
    length = n, range = m;
}

code mastermind::humanGuess()
{
    code GC(length, range);
    int guess;
    std::vector<int> tempGuess;
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
    return GC;
}

response mastermind::getResponse(code guessCode, code secrectCode)
{
    response respGuess;
    respGuess.setGuessCode(guessCode);
    respGuess.setSecretCode(secrectCode);
    respGuess.setCorrect(guessCode);
    respGuess.setIncorrect(guessCode);
    return respGuess;
}

bool mastermind::isSolved(response respL, response respR)
{

}

void mastermind::playGame()
{
    // Initialize secret code
    masterCode.randomInit();

    // Print secret code
    printSecretCode();

    // Get Guesses from user


}
