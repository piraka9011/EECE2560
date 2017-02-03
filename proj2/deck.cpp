//
// Created by river on 2/2/17.
//

#include "d_node.h"
#include "deck.h"

Deck::Deck()
{
    node<Card> *headNode = new node<Card>;
    for (int i = 0; i < NUM_SUIT; i++)
    {
        for (int j = 0; j < NUM_VALUE; j++)
        {
            Card newCard(j, i);
            node<Card> *newNode = new node<Card> (newCard);
            headNode -> next = newNode;
        }
    }
}

void Deck::shuffle()
{
    std::random_device rd;
    std::mt19937 g(rd());
    //std::shuffle(deck.begin(), deck.end(), g);
}

std::ostream& operator << (std::ostream& os, const node<Card> &n)
{
        os << n.nodeValue;
}
