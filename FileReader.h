#pragma once
#include <sstream>
#include <fstream>
#include <iostream> 
#include <string>

using namespace std;

/*
CLASS: FileReader

Author: Sanjam Khera, 007866840

REMARKS:
Used to read a file line by line.
-----------------------------------------
*/

class FileReader
{
private:
	string fileName;
public:
	// Null Constructor
	FileReader();

	// Constructor
	FileReader(string fileName);

    // Open File
	ifstream openFile();

	// Read Next Line
	string getNextLine(ifstream &inputFile);
};