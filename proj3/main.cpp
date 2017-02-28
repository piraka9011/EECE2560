#include <iostream>

#include "Dictionary.h"

int main() {

    Dictionary d;
    d.readDictionary();
    d.selectionSort();
    int pos = d.searchWord("nature");
    std::cout << "Found at position: " << pos << '\n';

    return 0;
}