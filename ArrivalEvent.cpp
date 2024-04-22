#include "ArrivalEvent.h"
#include <iostream>
#include <string>
using namespace std;

// Constructor
ArrivalEvent :: ArrivalEvent(int arrivalTime, int orderID, double orderValue, string orderType): 
arrivalTime(arrivalTime), orderID(orderID), orderValue(orderValue), orderType(orderType)
{
	eventType = "Arrival";
}

// // Destructor
// ArrivalEvent :: ~ArrivalEvent()
// {
// }

// Accessor Methods
int ArrivalEvent :: getStartTime()
{return this->arrivalTime;}
string ArrivalEvent ::  getEventType()
{return this->eventType;}
int ArrivalEvent :: getOrderID()
{return this->orderID;}

// Print Method
void ArrivalEvent :: printEvent()
{
	cout << "Time: " << arrivalTime << " -> Order " << 
	orderID << " (" << orderType << ", $" << orderValue << ") arrives." << endl;
}