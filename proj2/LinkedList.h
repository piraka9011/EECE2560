/**
	EECE2560: Proj2a
	LinkedList.h
	Purpose: This file contains the definition of a linked list. All
    features of a linked list will be added here as need for Proj 2.
	@author: Anas Abou Allaban & Turki Alrifaie
	@version: 1.0 2/11/17
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "d_node.h"
#include "card.h"

class LinkedList {
private:
    node<Card>* headNode;

public:
    LinkedList();
    // Checks if list is empty
    bool isEmpty();
    // Puts card at end of the list
    void replace(Card c);
    // Puts card at the head of the list
    void insertHead(Card c);
    // Removes the head node and sets next card as head
    void removeHead();
    node<Card>* getHeadNode() { return headNode; }
    // Rrturns the node at index i
    node<Card>* getCard(int i);
    friend std::ostream& operator << (std::ostream& os, LinkedList &l);
    ~LinkedList();
};


#endif //FLIP_LINKEDLIST_H
