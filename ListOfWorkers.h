#pragma once
#include "WorkerNode.h"
#include "Worker.h"

/*
CLASS: List of Workers

Author: Sanjam Khera, 007866840

REMARKS:
Holds all the workers at the facility
A list makes it easy to keep track of employee hours 
Employee Wage cost and all aspects related worker at the facility
-----------------------------------------
*/

class ListOfWorkers
{
private:
	WorkerNode *head;
	WorkerNode *tail;

public:
	// Constructor
	ListOfWorkers();

	// Destructor
	~ListOfWorkers();

	// Adds a worker to the end of the linked list
	void addWorker(Worker *worker);

	// Returns a pointer to the worker with the given ID
	// Returns nullptr if the worker is not found in the linked list
	Worker *getWorker(int workerID);

	// Returns the ID of the first worker in the linked list that is available
	// Returns 0 if no workers are available
	int getFirstAvailableWorkerID();

    // Iterates over the list returns total number of hours worked by all the employees
    int getTotalWorkDays();

    // Iterates over workerList and returns the total wag
    double getTotalWageCost(); 

};