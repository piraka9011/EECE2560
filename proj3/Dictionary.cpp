//
// Created by piraka9011 on 2/27/17.
//

#include "Dictionary.h"

Dictionary::Dictionary()
{
    std::ifstream savedFile("/home/river/algo_ws/proj3/sortedDict.txt");
    if (savedFile.is_open()) {
        savedDict = true;
        fileDir = "/home/river/algo_ws/proj3/sortedDict.txt";
        std::cout << "Using previously sorted dictionary\n";
    }
    else
        fileDir = "/home/river/algo_ws/proj3/dictionary.txt";
}


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
    else
        std::cout << "ERROR: UNABLE TO OPEN FILE\n";
}

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
    saveDict();
}

void Dictionary::saveDict()
{
    std::ofstream outFile("/home/river/algo_ws/proj3/sortedDict.txt");
    for (int i = 0; i < stringDict.size(); i++)
    {
        outFile << stringDict.at(i) << '\n';
    }
    outFile.close();
}

int Dictionary::searchWord(std::string word)
{
    int first = 0, last = stringDict.size() - 1, middle, position = -1;
    bool found = false;
    // Loop until we found the value and our first search element is less than
    // the last element
    while (!found && first <= last)
    {
        // Set our middle search position
        middle = (first + last) / 2;
        if (stringDict.at(middle) == word)
        {
            found = true;
            std::cout<< word;
            return middle;
        }
        else if (stringDict.at(middle) > word)
            last = middle - 1;
        else
            first = middle + 1;
    }
    return middle;
}

std::ostream& operator<<(std::ostream &os, Dictionary d)
{
    for (int i = 0; i < d.getDict().size(); i++)
        std::cout << d.getDict().at(i) << '\n';
}