#pragma once
#include "Event.h"
#include "PrepareEvent.h"
#include "ArrivalEvent.h"

/*
CLASS: Event Queue.

Author: Sanjam Khera, 007866840

REMARKS:
Takes in an event and places is accordingly with in the event queue.
-----------------------------------------
*/

class EventQueue
{
private:
	struct EventNode
	{
		Event *event;
		EventNode *next;
		EventNode(Event *event) : event(event), next(nullptr) {}
	};

	EventNode *front;
	EventNode *rear;

public:
	// Constructor
	EventQueue();

	// Modifiers
	void enqueue(Event *event);
	Event* dequeue();

	// Get Set Methods;
	bool isEmpty();
	bool hasArrivalEvent();
	bool hasPrepareEvent();
	int getPrepareEventEndTime();
	Event* dequeFirstArrivalEvent();
	void display();
};