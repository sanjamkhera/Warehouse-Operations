#pragma once
#include "Event.h"
#include <string>
using namespace std;

/*
CLASS: Arrival Even

Author: Sanjam Khera, 007866840

REMARKS:
Sub class of event class
This event get's initialized as soon as an order comes to the facility
-----------------------------------------
*/

class ArrivalEvent : public Event
{

// Instance Variables
private:
	int arrivalTime;
	int orderID;
	double orderValue;
	string orderType;
	string eventType;

public:
	// Constructor
	ArrivalEvent(int arrivalTime, int orderID, double orderValue, string orderType);

	// // Destructor 
	// ~ArrivalEvent();

	// Accessor Methods
	string getEventType();
	int getOrderID();
	void printEvent();
	int getStartTime();
};