/**
	EECE2560: Proj2a
	card.h
	Purpose: This is the header file of Card class containing the definition
    of all member functions and variables.
	@author: Anas Abou Allaban & Turki Alrifaie
	@version: 1.0 2/11/17
*/

#ifndef CARD_H
#define CARD_H

#include <iostream>

class Card {

private:
    int value; // 0-12 -> 2-JQKA
    int suit; // 0-4 -> Club/Diamond/Heart/Spade

public:
    // Default Constructor
    Card();
    //Copy Constructor
    Card(const Card& c);
    // Constructor with params to set the value and suit
    Card(int value, int suit);
    // Set the rank and suit of a card;
    void setValue(int newVal) { value = newVal; }
    void setSuit(int newSuit) { suit = newSuit; }
    // Return rank and suit of a card
    int getValue() const { return value; }
    int getSuit() const { return suit; }
    Card& operator= (const Card& rhs);
    // Overloaded print out operator to prin contents of a card
    friend std::ostream& operator << (std::ostream& os, const Card& c);

};

#endif //PROJ2_CARD_H
