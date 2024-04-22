#include "FileReader.h"
#include <string>


// Null Constructor
FileReader :: FileReader() : fileName(nullptr) {}

// Constructor
FileReader :: FileReader(string fileName) : fileName(fileName) {}

ifstream FileReader :: openFile()
{
    ifstream inputFile;
    inputFile.open(this->fileName);
    return inputFile;
}

// Read Next Line
string FileReader :: getNextLine(ifstream &inputFile)
{
    string line;
    if (getline(inputFile, line))
    { // gets the next line from the file and saves it in 'line', if there is one
        return line;
    }
    return line;
}