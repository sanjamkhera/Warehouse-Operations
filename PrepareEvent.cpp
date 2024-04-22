#include "PrepareEvent.h"
#include <iostream>
using namespace std;

// Constructor
PrepareEvent :: PrepareEvent(int startTime, int targetShipTime, int prepareTime, int orderID, double orderValue, string orderType, int workerID) : 
startTime(startTime), targetShipTime(targetShipTime), prepareTime(prepareTime), orderID(orderID), orderValue(orderValue), orderType(orderType), workerID(workerID)
{
    eventType = "Prepare";
}

// // Destructor
// PrepareEvent :: ~PrepareEvent()
// {
// }

// Accessor Methods
int PrepareEvent :: getStartTime()
{return this->startTime;}

int PrepareEvent :: getTargetShipTime()
{return this->targetShipTime;}

string PrepareEvent :: getEventType()
{return this->eventType;}

int PrepareEvent :: getOrderID()
{return this->orderID;}

string PrepareEvent :: getOrderType()
{return this->orderType;}

double PrepareEvent :: getOrderValue()
{return this->orderValue;}

int PrepareEvent :: getWorkerID()
{return this->workerID;}

int PrepareEvent :: getEndTime()
{return this->startTime + this->prepareTime;}

int PrepareEvent :: getPrepareTime()
{return this->prepareTime;}

// Print Method
void PrepareEvent :: printEvent()
{
    cout << "Time: " << startTime << " -> Order " << orderID << " (" 
    << orderType << ", $" << orderValue << ") is being prepared (prep time = " 
    << prepareTime << ")." << endl;
}

