#include "OrderQueue.h"
#include "Order.h"

// Constructor
OrderQueue :: OrderQueue() : front(nullptr), rear(nullptr) {} // Constructor 

// Check if empty
// Returns boolean
bool OrderQueue :: isEmpty()
{
	return (front == nullptr && rear == nullptr);
}

//------------------------------------------------------
// enqueue(Order *order)
//
// PURPOSE:    Takes in an order and enters it to the Order queue (Wait list).
// It iterates over the queue and finds the correct spot for the order to 
// to be placed. Note that it uses a loops to find the correct spot to enter.
// If it is a standard order it should go behind Primer Order
// as Primero event get's priority.
// After looking for the correct spot for order type.
// It uses another loop to add according to orderID.
// PARAMETERS: order, to be processed
//------------------------------------------------------
void OrderQueue :: enqueue(Order *order)
{
	OrderNode *newNode = new OrderNode(order);

	if (isEmpty())
	{
		front = rear = newNode;
	}
	else if (order->getCustomerType() == "standard")
	{
		rear->next = newNode;
		rear = newNode;
	}
	else // order is "Primero"
	{
		OrderNode *curr = front;
		OrderNode *prev = nullptr;

		while (curr != nullptr && curr->order->getOrderID() < order->getOrderID() && curr->order->getCustomerType() == "primero")
		{
			prev = curr;
			curr = curr->next;
		}

		if (prev == nullptr) // insert at front
		{
			newNode->next = front;
			front = newNode;
		}
		else // insert after prev
		{
			prev->next = newNode;
			newNode->next = curr;
			if (curr == nullptr) // update rear if newNode is last
			{
				rear = newNode;
			}
		}
	}
}

//------------------------------------------------------
// dequeue(Event *event)
//
// PURPOSE: Standard dequeue function returns the top element
// returns the top element of events queue.
// PARAMETERS: event, to be processed
//------------------------------------------------------
Order* OrderQueue :: dequeue()
{
	if (isEmpty())
	{
		cout << "Queue is empty." << endl;
		return nullptr;
	}

	OrderNode *temp = front;
	if (front == rear)
	{
		front = rear = nullptr;
	}
	else
	{
		front = front->next;
	}
	return temp->order;
	delete temp;
}

// Print queue for check
void OrderQueue :: display()
{
	if (isEmpty())
	{
		cout << "Queue is empty." << endl;
		return;
	}

	OrderNode *temp = front;
	while (temp != nullptr)
	{
		temp->order->printOrder();
		temp = temp->next;
	}
}