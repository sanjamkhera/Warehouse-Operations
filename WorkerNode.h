#pragma once 
#include "Worker.h"
#include "WorkerNode.h"

/*
CLASS: Worker Node Class

Author: Sanjam Khera, 007866840

REMARKS:
Worker Node 
This event get's initialized as soon as it's time for an order to be processed
-----------------------------------------
*/

class WorkerNode
{
public:
	Worker *worker;
	WorkerNode *next;

	// Constructor
	WorkerNode(Worker *worker);
};