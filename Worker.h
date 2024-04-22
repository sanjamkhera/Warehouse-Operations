#pragma once
#include "Worker.h"
#include "Event.h"
#include "PrepareEvent.h"

/*
CLASS: Worker

Author: Sanjam Khera, 007866840

REMARKS:
Implements a worker that works at the facility
Get's initialized based on the number of employees passed in the argument
-----------------------------------------
*/

class Worker
{
private:
	int workerID;
	bool isFree;
	int currentOrder;
	int hoursWorked;

public:
	// null constructor for jeff
	Worker();

	// Constructor
	Worker(int workerID);

	// Assigns the current order being worked on by the worker
	void assignOrder(Event *event);

	// Returns true if the worker is available to work on an order
	bool isAvailable();

	// Returns the number of hours the worker will take to complete the current order
	int getHoursWorked();

	// Resets the worker state after completing an order
	void makeAvailable();

	// get worker ID
	int getWorkerID();

    // int get number of days worked
    int getNumberOfDaysWorked();

    // int get wages
    double getWages();
};