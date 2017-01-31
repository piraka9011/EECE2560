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

response mastermind::getResponse(code guessCode, code secretCode)
{
    response respGuess;
    respGuess.setCorrect(guessCode, secretCode);
    respGuess.setIncorrect(guessCode, secretCode);
    respGuess.setGuessCode(guessCode);
    respGuess.setSecretCode(secretCode);
    return respGuess;
}

bool mastermind::isSolved(response respL, response respR)
{
    return respL == respR;
}

void mastermind::playGame()
{
    int count = 0, guess;
    bool result = false;
    code GC(length, range);
    std::vector<int> tempGuess;
    response userResp, secretResp;

    // Initialize secret code
    masterCode.randomInit();

    // Print secret code
    printSecretCode();

    // Get Guesses from user
    // Loop while user has not won or less than 10 tries have been done
    while ( !result && count < 10 )
    {
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
        // Create new response
        userResp = getResponse(GC, masterCode);
        secretResp = getResponse(GC, masterCode);
        // Print response
        std::cout << userResp;
        // Reset our tempGuess vector
        tempGuess.clear();
        // Update results
        result = isSolved(userResp, secretResp);
        // Increment count
        count++;
    }
}
