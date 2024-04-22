#pragma once
#include "Event.h"
#include <string>
using namespace std;

/*
CLASS: Prepare Event

Author: Sanjam Khera, 007866840

REMARKS:
Sub class of event class
This event get's initialized as soon as an order get's of the waiting list
-----------------------------------------
*/

class PrepareEvent : public Event
{
private:
	// Instance Variables
	int startTime;
	int targetShipTime; // Get's assigned from order
	int prepareTime; // Get's calculated as soon the prepare event is made
	int orderID; 
	double orderValue;
	string orderType;
	int workerID;
	string eventType;

public:
	// Constructor
	PrepareEvent(int startTime, int targetShipTime, int prepareTime, int orderID, double orderValue, string orderType, int workerID);

	// // Destructor
	// ~PrepareEvent();

	// Accessor Method
	int getStartTime();
	int getTargetShipTime();
	string getEventType();
	int getOrderID();
	string getOrderType();
	double getOrderValue();
	int getEndTime();
	int getWorkerID();	
	int getPrepareTime();

	// Print Method
	void printEvent();
};