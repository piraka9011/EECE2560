/**
	EECE2560: Proj3a
	Dictionary.cpp
	Purpose: This file provides the implementation for the Dictionary class.
    It allows for reading in the dictionary words to a vector, sorting them
    using the very very efficient selection sort,and then searching the
    dictionary for a word using the very very inefficient binary search.
	@author: Anas Abou Allaban & Turki Alrifaie
	@version: 1.0 3/13/17
*/

#include "Dictionary.h"

/**
    A constructor that specifies the directory in which the sorted dictionary
    will be saved.The saved file will be used if it was located, otherwise it
    will declare the file directory of the unsorted dictionary.
                                **** NOTE TO TA ****
    Please note that this program was tested on Ubuntu 14.04. Other students
    reported errors with opening the file the way we do. Please make sure that
    you put in the correct file path extension.
    If the file is in the same directory as the project, you may not need to
    add the file path extension.
    ***************************************************************************
 */
Dictionary::Dictionary()
{
    /// CHANGE DIRECTORY HERE
    std::ifstream savedFile("/home/osboxes/algo_ws/proj3/sortedDict.txt");
    // Check to see if the dictionary was previously sorted
    if (savedFile.is_open()) {
        // If it is, set the directory accordingly and inform user
        savedDict = true;
        /// CHANGE DIRECTORY HERE
        fileDir = "/home/osboxes/algo_ws/proj3/sortedDict.txt";
        std::cout << "Using previously sorted dictionary\n";
    }
    // Otherwise use default dictionary
    else
        /// CHANGE DIRECTORY HERE
        fileDir = "/home/osboxes/algo_ws/proj3/dictionary.txt";
}

/**
    This function opens the file dictionary and stores all of the dictionary
    text file contents into a vector.
  */
void Dictionary::readDictionary()
{
    // Temp string var
    std::string line;
    // Create an istream obj for our dictionary
    std::ifstream inFile(fileDir);

    // Check if file can be opened
    // Read through file line by line
    if (inFile.is_open())
    {
        while (!inFile.eof())
        {
            std::getline(inFile, line);
            // Put each word in a vector
            stringDict.push_back(line);
        }
        // Close the istream
        inFile.close();
    }
    else // Uh-oh x2
        std::cout << "ERROR: UNABLE TO OPEN FILE\n";
}

void Dictionary::heapSort()
{
    Heap<std::string> h;
    stringDict = h.heapSort(stringDict);
    // Save dictionary after sorting
    if (!savedDict)
        saveDict();
}

/**
    This function sorts the contents of the dictionary using selection sort method.
    The function also saves a sorted copy of the dictionary if it is not saved.
 */
void Dictionary::selectionSort()
{
    int min = 0;
    std::string temp;
    // Take a number from the start
    for (int i = 0; i < stringDict.size() - 1; i++)
    {
        // Set that index as min
        min = i;
        // Loop from start number through rest of array
        for (int j = i+1; j < stringDict.size(); j++)
        {
            // If a number is found to be less than current min, set that index
            // as the new min
            if (stringDict.at(j) < stringDict.at(min))
                min = j;
        }
        // Swap the lowest current index with min, however check to see if
        // a new min was actually found
        if (min != i)
            std::swap(stringDict.at(i), stringDict.at(min));
    }
    // Save dictionary after sorting
    if (!savedDict)
        saveDict();
}


void Dictionary::quickSort()
{
    int qsLeft = 0, qsRight = stringDict.size() - 1;
    qs(qsLeft, qsRight);
    // Save dictionary after sorting
    if (!savedDict)
       saveDict();
}

void Dictionary::qs(int left, int right){
    //save the size of the vector and adjusted to get the last element iterator
    int l = left, r = right;
    int pivot = (l+r) / 2;
    std::string p = stringDict[pivot];

    // Partition logic
    // Loop while our left index is less than the right one
    while (l <= r)
    {
        // Loop until we reach a value that needs to be swapped
        while(stringDict.at(l) < p)
            l++;
        while(stringDict.at(r) > p)
            r--;
        // After looping, find a value that needs to be swapped
        if (l <= r)
        {
            // Swap and move to next index
            std::swap(stringDict.at(l), stringDict.at(r));
            l++;
            r--;
        }
    }

    // The 'left'/'right' index is less than our right/left, sort it
    if (left < r)
        qs(left, r);
    if (l < right)
        qs(l, right);
}


void Dictionary::saveDict()
{
    std::cout << "Saving dictionary...\n";
    std::ofstream outFile("/home/osboxes/algo_ws/proj3/sortedDict.txt");
    for (int i = 0; i < stringDict.size(); i++)
    {
        outFile << stringDict.at(i) << '\n';
    }
    outFile.close();
}

/**
    This function uses the binary search algorithm to search for a word
    in the sorted dictionary.
    @param string word: The key word to search for
    @return int middle: When the word is found, middle is the index where the
            word is located in the sorted dictionary
 */
int Dictionary::searchWord(std::string word)
{
    int first = 0, last = stringDict.size() - 1, middle;
    // Loop until we found the value and our first search element is less than
    // the last element
    while (first <= last)
    {
        // Set our middle search position
        middle = (first + last) / 2;
        // If its greater, set the range to the 'right' side.
        if (stringDict.at(middle) < word)
            first = middle + 1;
        // If the word in the middle is greater than our key word,
        // set the range to be the 'left' side.
        else if (stringDict.at(middle) > word)
            last = middle - 1;
        // Any other case means we found our word, return position
        else
        {
            std::cout << "found: " << word << '\n';
            return middle;
        }
    }
    // If no word is found, return -1
    return -1;
}

/**
    An overloaded print out operator that prints out the entire dictionary.
    @param  ostream& os: Outputstream object
            Dictionary d: Our dictionary object that we will read words from
    @return osrteam& os: Output stream object to output to console.
 */
std::ostream& operator<< (std::ostream &os, Dictionary d)
{
    for (int i = 0; i < d.getDict().size(); i++)
        os << d.getDict().at(i) << '\n';
    return os;
}