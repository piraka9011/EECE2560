/**
	EECE2560: Proj3a
	Dictionary.h
	Purpose: This file provides the definitions for the Dictionary class.
    It contains an overloaded output operator, functions to read, search and
    sort the dictionary, and get the vector of words from the dictionary.
	@author: Anas Abou Allaban & Turki Alrifaie
	@version: 2.0 3/21/17
*/

#ifndef PROJ3_DICTIONARY_H
#define PROJ3_DICTIONARY_H

#include "d_except.h"
#include "Heap.h"

#include <fstream>      // i/ofstream
#include <iostream>     // cout/cin
#include <vector>       // swap
/**
 *                                 **** NOTE TO TA ****
    Please note that this program was tested on Ubuntu 14.04. Other students
    reported errors with opening the file the way we do. Please make sure that
    you put in the correct file path extension.
    If the file is in the same directory as the project, you may not need to
    add the file path extension.
    ***************************************************************************
 */
class Dictionary {
private:
    // Vector to store words
    std::vector<std::string> stringDict;
    // Boolean to determine if the dictionary was previously sorted
    bool savedDict = false;
    // File directory
    std::string fileDir = " ";
    /// CHANGE DIRECTORY HERE   ///////////////////////////////////////////
    std::string sortDir = "/home/pineapple/algo_ws/proj3/sortedDict.txt";
    std::string unsortDir = "/home/pineapple/algo_ws/proj3/dictionary.txt";
    ///////////////////////////////////////////////////////////////////////

public:
    Dictionary();
    void readDictionary();
    friend std::ostream& operator << (std::ostream& os, Dictionary d);
    void selectionSort();
    void heapSort();
    void qs(int left, int right);
    void quickSort();
    int searchWord(std::string word);
    std::vector<std::string> getDict() { return stringDict; };
    bool isSaved() { return savedDict; };
    void saveDict();
};

#endif //PROJ3_DICTIONARY_H
