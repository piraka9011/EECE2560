/**
	EECE2560: Proj2a
	card.cpp
	Purpose: This file contains the implementation of functions defined in
    card.h, specifically the overloaded operator and constructor
	@author: Anas Abou Allaban & Turki Alrifaie
	@version: 1.0 2/11/17
*/

#include "card.h"

/**
    Default constructor for a Card object. Sets the rank and suit to Ace and Club
    @param:
    @return:
 */
Card::Card()
{

    value = 1;
    suit = 0;
}

/**
    Another Card constructor that sets the rank and suit according to the
    users passed parameters
    @param: int value: rank of the card
            int suit: suit of the card
    @return:
 */
Card::Card(int value, int suit)
{
    this -> value = value;
    this -> suit = suit;
}

/**
    The overloaded operator prints the rank and suit of the card. A switch
    case block is used to print the values
    @param: std::ostream& os: Output stream object used as the LHS of the
            operator's std::cout.
            Card& c: A card object for the RHS of the operator, used to get
            the value and rank
    @return: std::ostream& os: An output stream object to print to the console
 */
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
