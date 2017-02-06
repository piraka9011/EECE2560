//
// Created by river on 2/2/17.
//

#include "deck.h"

Deck::Deck()
{
    node<Card>* itr = headNode;
    for (int i = 0; i < NUM_SUIT; i++)
    {
        for (int j = 0; j < NUM_VALUE; j++)
        {
            Card newCard(j, i);
            node<Card> *newNode = new node<Card> (newCard, itr);
            std::cout << newNode->nodeValue;
            itr = newNode;
        }
    }
}


void Deck::shuffle()
{
    std::random_device rd;
    std::mt19937 g(rd());
    //std::shuffle(deck.begin(), deck.end(), g);
}

std::ostream& operator << (std::ostream& os, Deck &d)
{
        node<Card> *it;
        for (int i = 0; i < d.getDeckSize(); i++)
        {
            it = d.headNode->next;
            os << it;
        }
}
