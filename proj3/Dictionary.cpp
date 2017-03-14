#include "Dictionary.h"

/**
    A constructor that specifies the directory in which the sorted dictionary will be saved.
    The saved file will be used if it was located other wise it will declare the file directory
    of the unsorted dictionary.
 */
Dictionary::Dictionary()
{
    // Ubuntu Path /home/piraka9011/Desktop/algo_ws/proj3/
    std::ifstream savedFile("/home/piraka9011/Desktop/algo_ws/proj3/sortedDict.txt");
    if (savedFile.is_open()) {
        savedDict = true;
        fileDir = "/home/piraka9011/Desktop/algo_ws/proj3/sortedDict.txt";
        std::cout << "Using previously sorted dictionary\n";
    }
    else
        fileDir = "/home/piraka9011/Desktop/algo_ws/proj3/dictionary.txt";
}

/**
    This function opens the file dictionary and stores all of the contents into a vector.
    @param: fildir refers to the directory where the sorted dictionary is located.
    @return:
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
    else
        std::cout << "ERROR: UNABLE TO OPEN FILE\n";
}

/**
    This function sorts the contents of the dictionary using selection sort method.
    The function also saves a sorted copy of the dictionary.
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
    saveDict();
}

/**
    The function specifies the directory that the sorted dictionary will be saved where
    it uses a fir loop to save each element in the output file.
 */
void Dictionary::saveDict()
{
    std::ofstream outFile("C:/users/turki_000/Desktop/grid/dictionary.txt");
    for (int i = 0; i < stringDict.size(); i++)
    {
        outFile << stringDict.at(i) << '\n';
    }
    outFile.close();
}

/**
 * The function uses binary search method to search for the word in the sorted dictionary.
 * @param word
 * @return middle
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
        // If we found the word, return it
        if (stringDict.at(middle) < word)
            first = middle + 1;
        // If the word in the middle is greater than our key word,
        // set the range to be the 'left' side.
        else if (stringDict.at(middle) > word)
            last = middle - 1;
        // If its greater, set the range to the 'right' side.
        else
        {
            std::cout << "found: " << word << '\n';
            return middle;
        }
    }
    return 0;
}

/**
 * overloaded operator that returns the string in the dictopnary at location i
 * @param os
 * @param d
 * @return
 */
std::ostream& operator<< (std::ostream &os, Dictionary d)
{
    for (int i = 0; i < d.getDict().size(); i++)
        os << d.getDict().at(i) << '\n';
}