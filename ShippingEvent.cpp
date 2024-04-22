#include "ShippingEvent.h"
#include <iostream>
using namespace std;

// Constructor
ShippingEvent :: ShippingEvent(int shipTime, int targetShipTime, double orderValue, string orderType, int orderID): 
shipTime(shipTime), targetShipTime(targetShipTime), orderValue(orderValue), orderType(orderType), orderID(orderID)
{
    eventType = "Shipping";
    setPenaltyPaid();
    setOrderCost();

}

// // Destructor
// ShippingEvent :: ~ShippingEvent(){}

// Print Event
// Has a different print statement based, if the order was late
void ShippingEvent :: printEvent()
{
    if (this->penaltyPaid == 0)
    {
        cout << "Time: " << shipTime << " -> Order " << orderID << " (" << orderType 
        << ", $" << orderValue << ") has been shipped." << endl;
    }
    else
    {
        cout << "Time: " << shipTime << " -> Order " << orderID << " (" << orderType 
        << ", $" << orderValue << ") has been shipped." << "***Penalty Paid: $" << penaltyPaid << "." << endl;
    }
}

// Setter Methods used by constructor
void ShippingEvent :: setPenaltyPaid()
{
    double result = 0.00;
    if (this->shipTime < this->targetShipTime)
    {
        result = 0.00;
    }
    else 
    {
        result = this->orderValue * 0.15;
    }
    this->penaltyPaid = result;
}

void ShippingEvent :: setOrderCost()
{
    double result = 0.00;
    if (this->shipTime < this->targetShipTime)
    {
        result = this->orderValue - (this->orderValue * 0.50)  ;
    }
    else 
    {
        result = this->orderValue - (this->orderValue * 0.50 + this->orderValue * 0.15)  ;
    }
    this->orderCost = result;
}

// Accessor Methods
double ShippingEvent :: getPenaltyPaid()
{   
    return this->penaltyPaid;
}

int ShippingEvent :: getStartTime()
{
    return this->shipTime;
}

int ShippingEvent :: getOrderID()
{
    return this->orderID;
}

string ShippingEvent :: getEventType()
{
    return this->eventType;
}

double ShippingEvent :: getOrderCost()
{
    return this->orderCost;
}



