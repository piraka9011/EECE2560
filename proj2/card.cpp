//
// Created by river on 2/2/17.
//

#include "card.h"

Card::Card()
{
    value = 0;
    suit = 0;
}

std::ostream& operator << (std::ostream os, const Card& c)
{
    os << "Value: " << c.value << '\n';
    os << "Suite: " << c.suit << '\n';
    return os;
}