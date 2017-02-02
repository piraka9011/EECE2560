/**
    EECE2560: Proj1b
    response.cpp
    @Purpose: Implementing the member functions of the response class
    Implementations include: secret code initialization, return number of
    in/correct digits in in/correct location, return if the GC and the SC were
    equal (Win the game)
    @author: Anas Abou Allaban & Turki Alrifaie
    @version: 1.0 2/1/17
 */

#include "../include/response.h"

response::response()
{

}

/**
    The function checks whether the RHS equals the RHS
    It then return true or false.
    @param: response respR: A response object that is compared against the class
            self on the RHS of the == operator
    @return: bool <obj>: True if responses are equal, false if not
 */
bool response::operator ==(response &respR)
{
        if (secretCode == respR.guessCode)
            return true;
        else if (respR.secretCode == guessCode)
            return true;
        else
            return false;
}

/**
    The function returns the number of correct digits and incorrect
    using the response class get in/correct function.
    @param: std::ostream& os: An output stream object that will be used to
            stream data into the console.
            response resp: Response placed after the ostream object that will
            be used to print correct/incorrect digits in response.
    @return: std::ostream os: An output stream that will print out to console
 */
std::ostream& operator<< (std::ostream& os, const response resp)
{
    os << "Correct digits in correct position: "
       << resp.getCorrect() << '\n';
    os << "Correct digits in incorrect position: "
       << resp.getIncorrect() << '\n';
    return os;
}

std::istream& operator>> (std::istream& is, response& resp)
{
    is >> resp.correct >> resp.incorrect;
    return is;
}

