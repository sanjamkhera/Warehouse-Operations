#pragma once
#include <string>
using namespace std;

/*
CLASS: Event

Author: Sanjam Khera, 007866840

REMARKS:
Abstract (Pure Virtual Class), An event gets created from 
order, morphs into subclasses
-----------------------------------------
*/

class Event
{
// Instance variables
// Protected so sub classes can use them
protected:
	int arrivalTime;
	int startTime;
	int endTime;
	int orderID; 
	double orderValue;
	string orderType;
	string eventType;
public:
	// Null Constructor
	Event();

	// // Destructor
	// virtual ~Event();

	// Abstract methods for polymorphism
	virtual void printEvent() = 0;
	virtual string getEventType() = 0;
	virtual int getOrderID() = 0;
	virtual int getStartTime() = 0;
};