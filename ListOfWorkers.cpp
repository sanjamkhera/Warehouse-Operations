#include "WorkerNode.h"
#include "Worker.h"
#include "ListOfWorkers.h"
#include <iostream>

// Constructor 
ListOfWorkers :: ListOfWorkers() : head(nullptr), tail(nullptr) {}

// Destructor
ListOfWorkers :: ~ListOfWorkers()
{
	WorkerNode *current = head;
	while (current != nullptr)
	{
		WorkerNode *next = current->next;
		delete current;
		current = next;
	}
	head = nullptr;
	tail = nullptr;
}

// Adds a worker to the end of the list
void ListOfWorkers :: addWorker(Worker *worker)
{
	WorkerNode *newNode = new WorkerNode(worker);
	if (head == nullptr)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		tail->next = newNode;
		tail = newNode;
	}
}

// Returns a pointer to the worker with the given ID
// Returns nullptr if the worker is not found in the linked list
Worker* ListOfWorkers :: getWorker(int workerID)
{
	WorkerNode *current = head;
	while (current != nullptr)
	{
		if (current->worker->getWorkerID() == workerID)
		{
			return current->worker;
		}
		current = current->next;
	}
	return nullptr;
}

// Returns the ID of the first worker in the linked list that is available
// Returns 0 if no workers are available
int ListOfWorkers :: getFirstAvailableWorkerID()
{
	WorkerNode *current = head;
	while (current != nullptr)
	{
		if (current->worker->isAvailable())
		{
			return current->worker->getWorkerID();
		}
		current = current->next;
	}
	return -1;
}

// Total work days in the facility by each employee
int ListOfWorkers :: getTotalWorkDays()
{
    int noOfTotalWorkDays = 0;
    WorkerNode* curr = this->head;

    if (curr == nullptr)
    {
        noOfTotalWorkDays = 0;
    }

    while (curr != nullptr)
    {
        noOfTotalWorkDays = noOfTotalWorkDays + curr->worker->getNumberOfDaysWorked();

        curr = curr->next;
    }
    return noOfTotalWorkDays;
}

// Returns total wage cost of all employees at the facility based on
// Get's total wage cost of all the employees at the facility
double ListOfWorkers :: getTotalWageCost()
{
    double totalWageCost = 0.00;
    WorkerNode* curr = this->head;

    if (curr == nullptr)
    {
        totalWageCost = 0;
    }

    while (curr != nullptr)
    {

        totalWageCost +=  curr->worker->getWages();
        curr = curr->next;
    }
    return totalWageCost;
}
