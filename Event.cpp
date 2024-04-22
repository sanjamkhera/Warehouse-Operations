#include "Event.h"
#include <string>
#include <iostream>

// Null constructor
Event :: Event() 
{
}

// // Destructor
// Event :: ~Event()
// {
// }

// Pure Virtual Method
// Should never be called
void Event :: printEvent()
{
	cout << "Printing an empty event." << endl;
}

// Accessor methods 
string Event :: getEventType()
{
	return this->eventType;
}

int Event :: getOrderID()
{
	return this->orderID;
}

int Event :: getStartTime()
{
	return this->startTime;
}