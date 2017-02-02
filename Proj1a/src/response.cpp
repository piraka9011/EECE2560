/*
 * EECE2560: Proj1b
   Response.cpp
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


bool response::operator ==(const response &respR)
//The function checks whether the RHS equals the RHS
//It then return true or false.
{
        if (secretCode == respR.guessCode)
            return true;
        else if (respR.secretCode == guessCode)
            return true;
        else
            return false;
}

std::ostream& operator<< (std::ostream& os, const response resp)
//The function returns the number of correct digits and incorrect
//using the response class get in/correct function
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

