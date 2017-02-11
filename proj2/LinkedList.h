//
// Created by piraka9011 on 2/8/17.
//

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
    void insertTail(Card c);
    void insertHead(Card c);
    void replaceHere(int i, Card c);
    node<Card>* getHeadNode() { return headNode; }
    node<Card>* getCard(int i);
    ~LinkedList();
};


#endif //FLIP_LINKEDLIST_H
