//
// Created by river on 2/2/17.
//

#include "deck.h"

Deck::Deck()
{
    node<Card>* itr = headNode;
    for (int i = 0; i < NUM_SUIT; i++)
    {
        for (int j = 1; j < NUM_VALUE; j++)
        {
            Card newCard(j, i);
            node<Card> *newNode = new node<Card> (newCard, itr);
            std::cout << newNode->nodeValue;
            headNode->next = newNode;
            itr = newNode;
        }
    }

}

void Deck::insertHere(node<Card>* n, int i)
{


}

void Deck::swap(node<Card> *a, node<Card> *b)
{
    int tempC1r, tempC1s, tempC2r, tempC2s;
    tempC1r = a->nodeValue.getValue(); tempC1s = a->nodeValue.getSuit();
    tempC2r = b->nodeValue.getValue(); tempC2s = b->nodeValue.getSuit();
    a->nodeValue.setValue(tempC2r);    a->nodeValue.setSuit(tempC2s);
    b->nodeValue.setValue(tempC1r);    b->nodeValue.setSuit(tempC1s);
}

node<Card>* Deck::getTail()
{
    node<Card>* itr = headNode;
    while(itr)
    {
        itr = itr->next;
    }
    return itr;
}

node<Card>* Deck::getCard(int i)
{
    node<Card>* itr = headNode;
    for (int j = 0; j < i; j++)
    {
        itr = itr->next;
    }

    return itr;
}

node<Card>* Deck::getCard(int rank, int suit)
{
    // Create an iterator
    node<Card>* itr = headNode;
    // Loop until we get the rank and value we want
    while ( (itr->nodeValue.getValue() != rank) && (itr->nodeValue.getSuit() != suit) )
    {
        itr = itr->next;
    }

    // Return the element we want
    return itr;
}


void Deck::shuffle()
{
    int rank;
    node<Card>* c1;
    node<Card>* c2;
    srand(time(NULL));
    for (int i = DECK_SIZE; i >=0; i-- )
    {
        rank = rand() % (i+1);
        c1 = getCard(i);    c2 = getCard(rank);
        swap(c1, c2);
    }
}

void Deck::insertHead(Card c)
{
    // Create a new node with the next element as the headNode
    node<Card>* n = new node<Card>(c, headNode);
    // Set the new node as the head
    headNode = n;
}

void Deck::insertTail(Card c)
{
    node<Card>* curr = headNode;
    // If list is empty
    if(!curr)
    {
        // Insert element at the head
        insertHead(c);
        return;
    }

    // Other wise loop through list
    while(curr)
    {
        curr = curr->next;
    }
    // Insert new node where the next element is currents next element
    node<Card>* newNode = new node<Card>(c, curr->next);
    // Set the next element as NULL (EOL)
    newNode->next = NULL;
}

std::ostream& operator << (std::ostream& os, Deck &d)
{
        // Create iterator to loop through deck
        node<Card> *it = d.headNode;
        for (int i = 0; i < d.getDeckSize(); i++)
        {
            // Print node value
            os << it->nodeValue;
            // Set iterator as next value
            it = it->next;
        }
}
