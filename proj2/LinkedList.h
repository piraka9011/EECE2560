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
    bool isEmpty();
    void replace(Card c);
    void insertHead(Card c);
    void removeHead();
    node<Card>* getHeadNode() { return headNode; }
    node<Card>* getCard(int i);
    ~LinkedList();
};


#endif //FLIP_LINKEDLIST_H
