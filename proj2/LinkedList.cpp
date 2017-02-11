//
// Created by piraka9011 on 2/8/17.
//

#include "LinkedList.h"

LinkedList::LinkedList()
{
    headNode = NULL;
}

bool LinkedList::isEmpty()
{
    return headNode == NULL;
}

void LinkedList::insertHead(Card c)
{
    // Create new node
    node<Card>* n = new node<Card>;
    // Set value as card
    n->nodeValue = c;
    // Set next node to head
    n->next = headNode;
    // Put head back in head position
    headNode = n;
}

void LinkedList::insertTail(Card c)
{
    if(isEmpty())
    {
        insertHead(c);
        return;
    }
    node<Card>* n = new node<Card>;
    node<Card>* curr = headNode;
    // Iterate through list until the end/NULL
    while(curr->next)
    {
        curr = curr->next;
    }
    // Set the value of the node;
    n->nodeValue = c;
    // Set the node at the element after the last
    curr->next = n;
    // Set the next element as null (Node is at end of list)
    n->next = NULL;
}

void LinkedList::replaceHere(int i, Card c)
{
    node<Card>* curr = headNode;
    for (int j = 0; j < i; j++)
    {
        curr = curr->next;
    }
    curr->nodeValue = c;
}

node<Card>* LinkedList::getCard(int i)
{
    node<Card>* curr= headNode;
    for (int j = 0; j < i; j++)
    {
        curr = curr->next;
    }
    return curr;
}

LinkedList::~LinkedList() {}