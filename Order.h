#pragma once
#include <string>
#include <iostream>

using namespace std;

/*
CLASS: Order

Author: Sanjam Khera, 007866840

REMARKS:
It hold an order object that goes through the facility
-----------------------------------------
*/

// With in order there can be multiple classes 
// Pending and processed can be for both Primero and Standard
// We mark order as processed and it to the processed order queue
class Order
{
private:
	// Instance Variables
	int arrivalTime;
	string customerType;
	double orderValue;
	int orderID;
    int targetShipTime;
	int prepareTime;
public:
	// Constructor
	Order(int arrivalTime, string customerType, double orderValue, int orderID);

	// Accessor Methods
	int getArrivalTime();
	string getCustomerType();
	double getOrderValue();
	int getPrepareTime();
	int getOrderID();
    int getTargetShipTime();

	// Setter Methods
	void setTargetShipTime();

	// Print Method
	void printOrder();
};