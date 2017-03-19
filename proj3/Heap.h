//
// Created by piraka9011 on 3/16/17.
//

#ifndef PROJ3_HEAP_H
#define PROJ3_HEAP_H

#include <cmath>
#include <vector>

template <typename T>
class Heap
{
private:
    std::vector<T> heap;
    int heapSize;

public:
    Heap();
    int parent(int index) { return index/2; };
    int left(int index) { return index * 2; };
    int right(int index) { return index * 2 + 1; };
    int getItem(int index) { return heap.at(index); };
    void initializeMaxHeap(std::vector<T> v);
    void maxHeapify(int i);
    void buildMaxHeap();
    std::vector<T> heapSort(std::vector<T> v);

};

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
    // Set vars
    int l = left(i);
    int r = right(i);
    int large = i;
    // Check if left child is larger than root
    if (l < heapSize && heap.at(l) > heap.at(large))
        large = l;
    // Check if right child is larger than root
    if (r < heapSize && heap.at(r) > heap.at(large))
        large = r;
    // Check if the largest value is not the 'root'
    if (large != i)
    {
        // If it isn't, swap the largest value with current index
        std::swap(heap.at(i), heap.at(large));
        // Recursively heapify
        maxHeapify(large);
    }
}

template <typename T>
void Heap<T>::buildMaxHeap()
{
    // Rearrange vector according to heap structure
    for (int i = std::floor(heap.size()/2) - 1; i >= 1; i--)
        maxHeapify(i);
}

template <typename T>
std::vector<T> Heap<T>::heapSort(std::vector<T> v)
{
    // Store Vector and its size in the private vars
    initializeMaxHeap(v);
    // Build the Max Heap
    buildMaxHeap();
    // Conduct the actual sorting
    for (int i = heap.size() - 1; i >= 1; i--)
    {
        // Swap first element with last position in unsorted array
        // (first position in sorted)
        std::swap(heap.at(1), heap.at(i));
        heapSize--;
        maxHeapify(1);
    }
    return heap;
}

#endif //PROJ3_HEAP_H
