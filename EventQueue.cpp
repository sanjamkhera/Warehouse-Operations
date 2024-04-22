#include "EventQueue.h"
#include <iostream>
#include "Event.h"
#include "ArrivalEvent.h"
#include "PrepareEvent.h"
#include "ShippingEvent.h"

using namespace std;

// Constructor
EventQueue :: EventQueue() : front(nullptr), rear(nullptr) {}

// Check if empty
// Returns boolean
bool EventQueue :: isEmpty() {return (front == nullptr && rear == nullptr);}

//------------------------------------------------------
// enqueue(Event *event)
//
// PURPOSE:    Takes in an event and enters it to the event queue.
// It iterates over the queue and finds the correct spot for the event to 
// to be placed. Note that it uses multiple loops.
// 1. If it is a prepare event it should go behind arrival event
// as arrival event get's priority.
// 2. It finds the correct spot for prepare event by iterating over the list
// and adds it to the correct.
// PARAMETERS: event, to be processed
//------------------------------------------------------
void EventQueue :: enqueue(Event *event)
{
	EventNode *newNode = new EventNode(event);
	if (isEmpty())
	{
		front = rear = newNode;
	}
	else
	{
		EventNode *prev = nullptr;
		EventNode *curr = front;

		if (event->getEventType() == "Prepare")
		{
			// Insert the new prepare event at the back of the queue
			while (curr != nullptr && curr->event->getEventType() == "Prepare" &&
					dynamic_cast<PrepareEvent *>(event)->getEndTime() >= 
					dynamic_cast<PrepareEvent *>(curr->event)->getEndTime())
			{
				prev = curr;
				curr = curr->next;
			}
			if (prev == nullptr)
			{
				newNode->next = front;
				front = newNode;
			}
			else if (curr == nullptr)
			{
				rear->next = newNode;
				rear = newNode;
			}
			else
			{
				prev->next = newNode;
				newNode->next = curr;
			}
			return;
		}

		while (curr != nullptr && (curr->event->getStartTime() < event->getStartTime() ||
		(curr->event->getStartTime() == event->getStartTime() && curr->event->getOrderID() < event->getOrderID())))
		{
			prev = curr;
			curr = curr->next;
		}

		// Insert the new event
		if (prev == nullptr)
		{
			newNode->next = front;
			front = newNode;
		}
		else if (curr == nullptr)
		{
			rear->next = newNode;
			rear = newNode;
		}
		else
		{
			prev->next = newNode;
			newNode->next = curr;
		}
	}
}

// Checks if there is an arrival event in the queue.
// Returns a boolean.
// Used by various functions in Amazin class.
bool EventQueue :: hasArrivalEvent()
{
	EventNode* curr = front;

	while (curr != nullptr)
	{
		if (curr->event->getEventType() == "Arrival")
		{
			return true;
		}
		curr = curr->next;
	}

	return false;
}

// Checks if there is an prepare event in the queue.
// Returns a boolean.
// Used by various functions in Amazin class.
bool EventQueue :: hasPrepareEvent()
{
	EventNode* curr = front;

	while (curr != nullptr)
	{
		if (curr->event->getEventType() == "Prepare")
		{
			return true;
		}
		curr = curr->next;
	}

	return false;
}

// Returns an integer value, end time of the first prepare event.
// Used by various functions in Amazin class.
int EventQueue :: getPrepareEventEndTime()
{
	EventNode* curr = front;

	while (curr != nullptr)
	{
		if (curr->event->getEventType() == "Prepare")
		{
			return dynamic_cast<PrepareEvent *>(curr->event)->getEndTime();
		}
		curr = curr->next;
	}

	return 0;
}


// Iterates over the events queue first arrival
// Used by various functions in Amazin class.
// I implemented this method in case
// An order in case an order is being prepped.
// It will be on top and it looks for another arrival events
// to be processed.
Event* EventQueue :: dequeFirstArrivalEvent()
{
	EventNode* prev = nullptr;
	EventNode* curr = front;

	while (curr != nullptr && curr->event->getEventType() != "Arrival")
	{
		prev = curr;
		curr = curr->next;
	}

	if (curr == nullptr) {
		// No arrival event found
		return nullptr;
	}

	Event* dequeuedEvent = curr->event;

	if (prev == nullptr) {
		// Removing the first node
		front = curr->next;
	}
	else {
		prev->next = curr->next;
	}

	if (rear == curr) {
		// Removing the last node
		rear = prev;
	}

	delete curr;
	return dequeuedEvent;
}

//------------------------------------------------------
// dequeue(Event *event)
//
// PURPOSE: Standard dequeue function returns the top element
// returns the top element of events queue.
// PARAMETERS: event, to be processed
//------------------------------------------------------
Event* EventQueue :: dequeue()
{
	if (isEmpty())
	{
		cout << "Queue is empty." << endl;
	}

	// Whatever is at the top of the queue, is of the highest priority
	EventNode *temp = front;

	// If there is no event in the queue, we empty the queue
	if (front == rear)
	{
		front = rear = nullptr;
	}
	else
	{
		// Whatever is the next event, becomes the top of the queue
		front = front->next;
	}

	return temp->event;
	delete temp;
}

// Print queue for check
void EventQueue :: display()
{
	if (isEmpty())
	{
		cout << "Queue is empty." << endl;
		return;
	}

	EventNode *temp = front;
	while (temp != nullptr)
	{
		temp->event->printEvent();
		temp = temp->next;
	}
}