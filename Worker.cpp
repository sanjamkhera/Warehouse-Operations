#include "Worker.h"
#include "WorkerNode.h"
#include "Event.h"
#include "PrepareEvent.h"


// Null Constructor
Worker :: Worker() : workerID(0), isFree(true), currentOrder(0), hoursWorked(0) {}

// Constructor
Worker :: Worker(int workerID) : workerID(workerID), isFree(true), currentOrder(0), hoursWorked(0) {}

// Assigns the current order being worked on by the worker
void Worker :: assignOrder(Event *event)
{
	PrepareEvent *assignedEvent = dynamic_cast<PrepareEvent *>(event);
	this->currentOrder = assignedEvent->getOrderID();
	this->isFree = false;
	this->hoursWorked += assignedEvent->getPrepareTime();
}

// Returns true if the worker is available to work on an order
bool Worker :: isAvailable()
{
	return this->isFree;
}

// Returns the number of hours the worker will take to complete the current order
int Worker :: getHoursWorked()
{
	return this->hoursWorked;
}

// Resets the worker state after completing an order
void Worker :: makeAvailable()
{
	this->currentOrder = 0;
	this->isFree = true;
}

// get worker ID
int Worker :: getWorkerID()
{
	return this->workerID;
}

// get number of days worked by the worker
int Worker :: getNumberOfDaysWorked()
{
    int result = 0; ;
    if (this->hoursWorked == 0)
    {
        result = 0;
    } 
    else 
    {
        result = (hoursWorked / 8) + 1;
    }
    return result;
}

// Returns Wages paid to the worker
double Worker :: getWages()
{
    double result = 0.00;
    if (this->workerID == 0)
    {
        result += 0;
    }
    else 
    {
        result += (this->getNumberOfDaysWorked()*8)*13.50 + (this->getNumberOfDaysWorked()*1);
    }
    return result;
}