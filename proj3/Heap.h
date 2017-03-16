//
// Created by piraka9011 on 3/16/17.
//

#ifndef PROJ3_HEAP_H
#define PROJ3_HEAP_H

#include <cmath>
#include <vector>

#include "Dictionary.h"

template <typename T>
class Heap
{
private:
    std::vector<T> heap;

public:
    Heap(Dictionary d);
    int parent(int index) { return index/2; };
    int left(int index) { return index * 2; };
    int right(int index) { return index * 2 + 1; };
    int getItem(int index);
    void initializeMaxHeap();
    void maxHeapify(int i);
    void buildMaxHeap();
    void heapsort();

};


#endif //PROJ3_HEAP_H
