/**
	EECE2560: Proj2a
	deck.h
	Purpose: This is the header file of Deck class containing the definition
    of all member functions and variables
	@author: Anas Abou Allaban & Turki Alrifaie
	@version: 1.0 2/11/17
*/

#ifndef FLIP_DECK_H
#define FLIP_DECK_H

#include "card.h"
#include "d_node.h"
#include "LinkedList.h"
#include <random> // srand(), rand()
#include <ctime>  // time()

class Deck {

private:
    const int DECK_SIZE = 52;
    // Num of possible suits is incremented by one due to nature of
    // this decks implementation
    const int NUM_SUIT = 3;
    const int NUM_VALUE = 13;
    LinkedList deck;

public:
    // Constructor
    Deck();
    // Shuffle function
    void shuffle();
    // Swap
    void swap(node<Card> *a, node<Card> *b);
    LinkedList getDeck() { return deck; };
    // Get the size of the deck
    int getDeckSize() const { return DECK_SIZE; };
    // Get the head node of the list (top of deck)
    node<Card>* getHeadNode() {return deck.getHeadNode(); }
    // Overloaded print out operator
    friend std::ostream& operator << (std::ostream& os, Deck &d);
    node<Card>* deal();
    // Destructor
    ~Deck();
};


#endif //FLIP_DECK_H
