#pragma once
#include "Order.h"
#include <string>
#include <iostream>

using namespace std;

/*
CLASS: Order Queue

Author: Sanjam Khera, 007866840

REMARKS:
Sub class of event class
This event get's initialized as soon as it's time for an order to be processed
-----------------------------------------
*/

class OrderQueue
{
private:
	struct OrderNode
	{
		Order *order;
		OrderNode *next;
		OrderNode(Order *order) : order(order), next(nullptr) {}
	};

	OrderNode *front;
	OrderNode *rear;

public:
	OrderQueue();
	bool isEmpty();
	void enqueue(Order *order);
	Order *dequeue();
	void display();
};