/**
	EECE2560: Proj3a
	Dictionary.h
	Purpose: This file provides the definitions for the Dictionary class.
    It contains an overloaded output operator, functions to read, search and
    sort the dictionary, and get the vector of words from the dictionary.
	@author: Anas Abou Allaban & Turki Alrifaie
	@version: 1.0 3/13/17
*/

#ifndef PROJ3_DICTIONARY_H
#define PROJ3_DICTIONARY_H

#include "d_except.h"

#include <fstream>      // i/ofstream
#include <iostream>     // cout/cin
#include <vector>       // swap

class Dictionary {
private:
    // Vector to store words
    std::vector<std::string> stringDict;
    // Boolean to determine if the dictionary was previously sorted
    bool savedDict = false;
    // File directory
    std::string fileDir = " ";

public:
    Dictionary();
    void readDictionary();
    friend std::ostream& operator << (std::ostream& os, Dictionary d);
    void selectionSort();
    int searchWord(std::string word);
    std::vector<std::string> getDict() { return stringDict; };
    bool isSaved() { return savedDict; };
    void saveDict();
};

#endif //PROJ3_DICTIONARY_H
