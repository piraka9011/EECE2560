/**
	EECE2560: Proj2a
	deck.cpp
	Purpose: This file implements the member functions of the Deck class.
    For  project 1, its main member functions are swap & shuffle. It has a
    constructor to initialzie a linked list deck and an overloaded print out
    operator
	@author: Anas Abou Allaban & Turki Alrifaie
	@version: 1.0 2/11/17
*/

#include "deck.h"

/**
    Deck class constructor. Creates a deck of cards using a linked list. The
    deck object in the constructor is a private memeber variable of type
    LinkedList.
    @param:
    @return:
 */
Deck::Deck()
{
    for (int i = NUM_SUIT; i >= 0; i--)
    {
        for (int j = NUM_VALUE; j > 0; j--)
        {
            Card c(j, i);
            deck.insertHead(c);
        }
    }
}

/**
    This function swaps two cards (i.e. suit and value) in a deck
    @param: node<Card>* a,b: Two nodes of type Card that are swapped
            with one another.
    @return:
 */
void Deck::swap(node<Card> *a, node<Card> *b)
{
    // Create temp values to switch node values
    int tempC1r, tempC1s, tempC2r, tempC2s;
    // Get the rank and suit of each node
    tempC1r = a->nodeValue.getValue(); tempC1s = a->nodeValue.getSuit();
    tempC2r = b->nodeValue.getValue(); tempC2s = b->nodeValue.getSuit();
    // Set the rankd and suit of node 1 to node 2 and vice versa
    a->nodeValue.setValue(tempC2r);    a->nodeValue.setSuit(tempC2s);
    b->nodeValue.setValue(tempC1r);    b->nodeValue.setSuit(tempC1s);
}

/**
    This function shuffles the deck by iterating through the deck from bottom
    to top. A random variable (rank) is set to a number mod the index of the
    for loop. The variable rank is then used to swap a card with the index of
    the for loop with that of the index of rank.
    @param:
    @return:
 */
void Deck::shuffle()
{
    // Random Variable
    int rank;
    // Temp node objects to pass to swap
    node<Card>* c1;
    node<Card>* c2;
    // Seed the random number gen.
    srand(time(NULL));
    // Loop through the deck from top to bottom
    for (int i = DECK_SIZE - 1; i >=0; i-- )
    {
        // Set the random variable
        rank = rand() % (i+1);
        // Get the cards of their respective index
        c1 = deck.getCard(i);    c2 = deck.getCard(rank);
        // Swap the cards
        swap(c1, c2);
    }
}

/**
    This overloaded operator prints out the entire deck from top to bottom
    @param: std::ostream& os: Output stream object used as the LHS of the
            operator's std::cout
            Deck& d: A deck object used to get the head of the deck and then
            have an iterator iterate through the deck.
    @return: std::ostream& os: An output stream object to print to the console
 */
std::ostream& operator << (std::ostream& os, Deck &d)
{
    // Create iterator to loop through deck
    node<Card> *it = d.getHeadNode();
    while (it)
    {
        // Print node value
        os << it->nodeValue;
        // Set iterator as next value
        it = it->next;
    }
    return os;
}
/**
    The deal function takes a card from the top of the deck and then removes
    that card from the original deck.
    @return: node<Card>* dealtCard: The head node or the card that is at the
             top of the deck
 */
node<Card>* Deck::deal()
{
    // Create a node to get the card at the top of the deck
    node<Card>* dealtCard = deck.getHeadNode();
    // Remove the card from the deck (function takes care of setting a new head
    // for the deck)
    deck.removeHead();
    return dealtCard;
}

void Deck::insertCard(node<Card>* dealtCard)
{

}

/**
    Destructor of the Deck class.
    Loops through entire deck from headNode to end of list (nullptr) and
    deletes each node.
 */
Deck::~Deck()
{
    // Create an iterator node ptr
    node<Card>* itr = deck.getHeadNode();
    // Make a temp node to delete the node
    node<Card>* curr = itr;
    // Loop while we have not reached end of list (while not null)
    while (itr)
    {
        itr = itr->next;
        delete curr;
        curr = itr;
    }
}

