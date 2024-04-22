/*
NAME		: Sanjam Khera
STUDENT NUMBER	: 007866840
COURSE		: COMP 2150
INSTRUCTOR	: Franklin Bristow
ASSIGNMENT	: assignment 2
QUESTION	: question 1     

Amazin Simulation, This class simulates a shopping operation, which process orders based on:
1) When they are received
2) Their value
3) Promised Shipping date
Each order received at the facility creates an arrival event, and checks if a worker is free.
If a worker is free, it assigns the order to the worker to process it via a prepare and shipping event class.
If a worker is not free, the program stores the order in the Order queue and waits till the worker gets free.
The program implements two priority queues one for Orders received and another one for processing events.
At the end it prints out the statistics of the operation.
*/

#include "Amazin.h"
using namespace std;

int main(int argc, char *argv[])
{
	// Validate Input
	if (argc != 3)
	{
		cout << "USAGE: FileReadingExample.exe filename numAdditionalEmp" << endl;
		cout << "where numAdditionalEmp is an integer >= 0." << endl;
		return 0;
	}
	else
	{
	// Parse Arguments
	string fileName = argv[1];

	// Num of extra workers 
	int numAddEmp = stoi(argv[2]);
	// int numAddEmp = 1;
	cout << "The filename is: " << fileName << endl;
	cout << "The number of additional employees is: " << numAddEmp << endl;

	// Create a new Amazon Warehouse
	Amazin *onlineStore = new Amazin(numAddEmp);
	onlineStore->simulation(fileName);
	}
}
