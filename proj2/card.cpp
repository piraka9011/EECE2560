//
// Created by river on 2/2/17.
//

#include "card.h"

Card::Card()
{
    value = 0;
    suit = 0;
}

Card::Card(int value, int suit)
{
    this -> value = value;
    this -> suit = suit;
}

std::ostream& operator << (std::ostream& os, const Card& c)
{
    switch (c.getValue()) {
        case 1:
            os << "Value: Ace\n";
            break;
        case 11:
            os << "Value: Joker\n";
            break;
        case 12:
            os << "Value: Queen\n";
            break;
        case 13:
            os << "Value: King\n";
            break;
        default:
            os << "Value: " << c.getValue()<< '\n';
            break;
    }
    switch (c.getSuit())
    {
        case 0:
            os << "Suit: Club\n";
            break;
        case 1:
            os << "Suit: Diamond\n";
            break;
        case 2:
            os << "Suit: Heart\n";
            break;
        case 3:
            os << "Suit: Spade\n";
            break;
        default:
            os << "Error: Out of bounds!\n";
            break;
    }
    return os;
}

/*
 *
 *
 *     default:
            os << "Error, no suite found!\n";
 *
 */