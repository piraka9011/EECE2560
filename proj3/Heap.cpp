//
// Created by piraka9011 on 3/16/17.
//

#include "Heap.h"
template <typename T>
Heap<T>::Heap() {}

template <typename T>
void Heap<T>::initializeMaxHeap(std::vector<T> v)
{
    heap = v;
    heapSize = heap.size();
}

template <typename T>
void Heap<T>::maxHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int large;
    if (l <= heapSize && heap.at(l) > heap.at(i))
        large = l;
    else
        large = i;
    if (r <= heapSize && heap.at(r) > heap.at(i))
        large = r;
    if (large != i)
    {
        std::swap(heap.at(i), heap.at(large));
        maxHeapify(large);
    }
}

template <typename T>
void Heap<T>::buildMaxHeap()
{
    for (int i = std::floor(heap.size()/2); i > 1; i++)
        maxHeapify(i);
}

template <typename T>
std::vector<T> Heap<T>::heapSort(std::vector<T> v)
{
    initializeMaxHeap(v);
    buildMaxHeap();
    for (int i = heap.size(); i > 2; i++)
    {
        std::swap(heap.at(1), heap.at(i));
        heapSize--;
        maxHeapify(1);
    }
    return heap;
}