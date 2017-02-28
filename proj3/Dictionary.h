//
// Created by piraka9011 on 2/27/17.
//

#ifndef PROJ3_DICTIONARY_H
#define PROJ3_DICTIONARY_H

#include "d_except.h"

#include <fstream>      // i/ofstream
#include <iostream>     // cout/cin
#include <vector>       // swap

class Dictionary {
private:
    std::vector<std::string> stringDict;

public:
    void readDictionary();
    friend std::ostream& operator<< (std::ostream& os, Dictionary d);
    void selectionSort();
    int searchWord(std::string word);
    std::vector<std::string> getDict() { return stringDict; };
};


#endif //PROJ3_DICTIONARY_H
