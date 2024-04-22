#include "Order.h"

using namespace std;

// Constructor
Order :: Order(int arrivalTime, string customerType, double orderValue, int orderID) : 
arrivalTime(arrivalTime), customerType(customerType), orderValue(orderValue), orderID(orderID)
{
    prepareTime = (orderValue / 200) + 1;
    setTargetShipTime();
}

// Accessor Methods
int Order :: getArrivalTime()
{return this->arrivalTime;}

string Order :: getCustomerType()
{return this->customerType;}

double Order :: getOrderValue()
{return this->orderValue;}

int Order :: getPrepareTime()
{return this->prepareTime;}

int Order :: getOrderID()
{return this->orderID;}

int Order :: getTargetShipTime()
{
    return this->targetShipTime;
}

// We are not using it
void Order ::  printOrder()
{
    cout << "orderID: " << this->orderID << endl;
    cout << "Time: " << this->arrivalTime << endl;
    cout << "customerType: " << this->customerType << endl;
    cout << "orderValue: " << this->orderValue << endl;
}

//------------------------------------------------------
// setTargetShipTime()
//
// PURPOSE:    To set target ship time when the order get's created
// PARAMETERS: No Parameters
// Returns:    Set's the target ship time for an order 
//------------------------------------------------------
void Order :: setTargetShipTime()
{
    if (this->customerType == "primero")
    {
        this->targetShipTime = (this->arrivalTime) + 8;
    }
    else 
    {
        this->targetShipTime = (this->arrivalTime) + 24;
    }
}

