#pragma once
#include "Event.h"
#include <string>
using namespace std;

/*
CLASS: Shipping Event

Author: Sanjam Khera, 007866840

REMARKS:
Sub class of event class
This event get's initialized as soon as it's time for an order to be processed
-----------------------------------------
*/

class ShippingEvent : public Event
{
private:
	int shipTime;
	int targetShipTime;
	string eventType;
	string orderType;
	int orderID;
	double orderValue; 
	double penaltyPaid; // Calculated as soon as an order is shipped
    double orderCost; // Calculated as soon as an order is shipped

public:
	// Constructor
	ShippingEvent(int shipTime, int targetShipTime, double orderValue, string orderType, int orderID);

	// // Destructor
	// ~ShippingEvent();

	// Accessor Methods
	int getStartTime();
	int getOrderID();
	string getEventType();
	void printEvent();
	double getPenaltyPaid();
    double getOrderCost();

	// Used by constructor
	void setPenaltyPaid();
    void setOrderCost();
};