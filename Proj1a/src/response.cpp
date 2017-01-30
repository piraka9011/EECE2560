//
// Created by piraka9011 on 1/28/17.
//

#include "../include/response.h"

response::response()
{

}

bool response::operator==(response)
{

}

friend std::ostream& response::operator<<(std::ostream& os, const response resp)
{
    os << "Correct digits in correct position: "
       << resp.getCorrect() << '\n';
    os << "Correct digits in incorrect position: "
       << resp.getIncorrect() << '\n';
    return os;
}

