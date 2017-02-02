/**
    EECE2560: Proj1b
    mastermind.cpp
    @Purpose: Implementing the member functions of the master mind class
    Implementations include: secret code initialization, check number of
    in/correct digits in in/correct location, checking if the game was won,
    and printing the result
    @author: Anas Abou Allaban & Turki Alrifaie
    @version: 1.0 2/1/17
 */

#include "../include/mastermind.h"

/**
    This function simply takes in user input, puts it in a temporary vector, and then
    returns a code object with the guess
    @param:
    @return: code GC: code object with stored guess code
*/
code mastermind::humanGuess()
{
    // Code object Declaration
    code GC(length, range);
    // Temp vars to hold user input
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
    // Return the users guess
    return GC;
}

/**
    The function creates a response object. The object is then used
    to call the response class functions to set the correct digits and
    the incorrect ones. It also assigns the GC and the SC to the corresponding
    functions of the class. It finally return the results (display).
    @param: code guessCode: The guessCode object to pass
            code secretCode: Secret code object used to check correct and incorrect digits
    @return: response respGues: response object with correct and incorrect digits
*/
response mastermind::getResponse(code guessCode, code secretCode)
{
    response respGuess;
    respGuess.setCorrect(guessCode, secretCode);
    respGuess.setIncorrect(guessCode, secretCode);
    respGuess.setGuessCode(guessCode);
    respGuess.setSecretCode(secretCode);
    return respGuess;
}

/**
   This function checks if the Lhs equals the Rhs and returns true or false.
   This implementation is used to determine if the secret code has been cracked.
   @param: response respL/respR: response objects corresponding to the LHS and RHS
            of the equation it is being used on.
   @return: bool <obj>: a true false if responses are equal
 */

bool mastermind::isSolved(response respL, response respR)
{
    return respL == respR;
}

/**
    This function initiates the game and calls the function randominit that
    creates a random secret code. For debugging purposes the function also prints
    out the secret code. The function then prompts the user for his guess and saves
    it in a vector. The vector is then passed to the object GC that sets the guess
    to the user input. The function then carry out a response check by passing the
    GC and mastermind objects to class response that checks for correct and incorrect
    digits. If the guess is right the loop breaks else the game continues until all
    attempts have been exhausted.
    @param:
    @return:
 */
void mastermind::playGame()
{
    int count = 0;
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
        GC = humanGuess();
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

    // Print the result if user won or not
    masterCode.printResult(result);

    /// End game
}
