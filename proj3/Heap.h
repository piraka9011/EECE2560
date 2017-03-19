/**
	EECE2560: Proj3b
	Heap.h
	Purpose: This template class allows for the utilization of the heapSort
    sorting algorithm for any kind of vector. For this project, heapSort
    is conducted on a vector of strings.
	@author: Anas Abou Allaban & Turki Alrifaie
	@version: 1.0 3/13/17
*/


#ifndef PROJ3_HEAP_H
#define PROJ3_HEAP_H

#include <cmath>    // std::floor
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

/**
 * Constructor for the Heap object. No work needed here
 * @tparam T
 */
template <typename T>
Heap<T>::Heap() {}

/**
 * This function copies the vector into the heap vector and stores the size
 * in a priveate variable that is used later on during the sorting process.
 * @tparam T
 * @param v: A vector that contains the list to be sorted
 */
template <typename T>
void Heap<T>::initializeMaxHeap(std::vector<T> v)
{
    heap = v;
    heapSize = heap.size();
}

/**
 * maxHeapify takes an index and checks to see if the current subset of nodes
 * follow the Max Heap properties. If not, it adjusts the nodes accordingly
 * @tparam T
 * @param i: The index of the node to check
 */
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

/**
 * This is the second step in the heapSort algorithm, where a list is built
 * into a max heap starting from the center and working up the list
 * @tparam T
 */
template <typename T>
void Heap<T>::buildMaxHeap()
{
    // Rearrange vector according to heap structure
    for (int i = std::floor(heap.size()/2) - 1; i >= 1; i--)
        maxHeapify(i);
}

/**
 * The main heapSort function conducts all necessary calls to helper functions
 * and conducts the sorting process using the Heap Sort algorithm
 * @tparam T
 * @param v: A list or vector to heapify and sort
 * @return heap: The sorted heap vector
 */
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
