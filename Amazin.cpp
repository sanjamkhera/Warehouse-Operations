#include <sstream>
#include <fstream>
#include <string> 
#include <iostream>

#include "ArrivalEvent.h"
#include "PrepareEvent.h"
#include "ShippingEvent.h"
#include "Event.h"
#include "EventQueue.h"
#include "FileReader.h"
#include "Order.h"
#include "OrderQueue.h"
#include "ListOfWorkers.h"
#include "Worker.h"
#include "WorkerNode.h"
#include "Amazin.h"
#include <iomanip>

// Constructor
Amazin :: Amazin (int noOfEmployees) : noOfEmployees(noOfEmployees)
{
}

// Destructor
Amazin::~Amazin()
{
    delete waitingQueue;
    delete eventQueue;
    delete workerList;
}

// Initialize all the employees at the facility
void Amazin :: initializeWorkerList()
{   
	this->totalProfit = 0.00;

    // Initialize Geoff
    Worker *geoff = new Worker();

    // List of worker at the facility
    workerList = new ListOfWorkers();

    // Add geoff to list
    this->workerList->addWorker(geoff);

    cout << "Simulation begins..." << endl;

    // Fill the list if there are more employees
    if (this->noOfEmployees > 0)
	{
		for (int i = 1; i <= this->noOfEmployees; i++)
		{
			Worker *newWorker = new Worker(i);
			this->workerList->addWorker(newWorker);
		}
	}
}

//------------------------------------------------------
// primerOrderQueue(int arrivalTime, int orderID, double orderValue, string customerType)
//
// PURPOSE:    Primes the order queue with the first line in the file.
// PARAMETERS: Takes in the arrival time of the order, orderID, value, customerType
// We use the returned order to create the first arrival event.
// Returns: Returns the pointer to the first order.
//------------------------------------------------------
Order* Amazin :: primerOrderQueue(int arrivalTime, int orderID, double orderValue, string customerType)
{
    waitingQueue = new OrderQueue();
	Order *order = new Order(arrivalTime, customerType, orderValue, orderID);
	this->waitingQueue->enqueue(order);
    return order;
    delete order;
}

//------------------------------------------------------
// primerEventQueue(Order* order)
//
// PURPOSE:    Takes in the order and starts processing it.
// PARAMETERS: Takes an order to be processed.
// We use the returned order to create the first arrival event.
// Returns: Returns the pointer to the first order
//------------------------------------------------------
void Amazin :: primerEventQueue(Order* order)
{
    eventQueue = new EventQueue();
	Event *primerEvent = new ArrivalEvent(order->getArrivalTime(), order->getOrderID(), order->getOrderValue(), order->getCustomerType());
	primerEvent->printEvent();
    this->eventQueue->enqueue(primerEvent);
}

//------------------------------------------------------
// processOrder(int currentTime, int orderID, double orderValue, string customerType)
//
// PURPOSE:    Process an order to create an arrival event.
// PARAMETERS: current time, order ID, order value, customer type
// Used by process arrival event to create events.
// Returns: Returns a pointer to the order created
// and also adds it to the queue.
//------------------------------------------------------
Order* Amazin :: processOrder(int currentTime, int orderID, double orderValue, string customerType)
{
    Order* order = new Order(currentTime, customerType, orderValue, orderID);
    this->waitingQueue->enqueue(order);
    return order;
}


//------------------------------------------------------
// processArrivalEvent(Order* order)
//
// PURPOSE:    Process arrival Event Add it to events Queue.
// PARAMETERS: Order, to be processed
// Returns: Nothing
//------------------------------------------------------

void Amazin :: processArrivalEvent(Order* order)
{
    
    Event* newArrivalEvent = new ArrivalEvent(order->getArrivalTime(), order->getOrderID(), order->getOrderValue(), order->getCustomerType());
    this->eventQueue->enqueue(newArrivalEvent);
    newArrivalEvent->printEvent();
}

//------------------------------------------------------
// processPrepareEvent(int currentTime)
//
// PURPOSE:    
// Process Prepare Event
// Add it to the Events Queue
// RETURNS: Nothing 
//------------------------------------------------------
void Amazin :: processPrepareEvent(int currentTime)
{
    while (this->workerList->getFirstAvailableWorkerID() >= 0 && this->eventQueue->hasArrivalEvent())
    {
        Order* order = this->waitingQueue->dequeue();
				ArrivalEvent* nextArrivalEvent = dynamic_cast<ArrivalEvent *>(eventQueue->dequeue());
        Event* newPrepareEvent = new PrepareEvent(currentTime, order->getTargetShipTime(), order->getPrepareTime(), order->getOrderID(), order->getOrderValue(), order->getCustomerType(), workerList->getFirstAvailableWorkerID());
        newPrepareEvent->printEvent();
        this->eventQueue->enqueue(newPrepareEvent);

        Worker* assignedWorker = workerList->getWorker(workerList->getFirstAvailableWorkerID());
        assignedWorker->assignOrder(newPrepareEvent);
		delete order;
    }

}

//------------------------------------------------------
// processShippingEvent(int currentTime)
//
// PURPOSE:    
// Process Shipping Event
// Shipping Event helps evaluate profits
// RETURNS: Nothing 
//------------------------------------------------------
void Amazin :: processShippingEvent(int currentTime)
{
	double result = 0.00;
	ShippingEvent* newShippingEvent = nullptr;
    while (eventQueue->hasPrepareEvent() && eventQueue->getPrepareEventEndTime() <= currentTime)
    {
        PrepareEvent* nextPrepareEvent = dynamic_cast<PrepareEvent *>(eventQueue->dequeue());
        workerList->getWorker(nextPrepareEvent->getWorkerID())->makeAvailable();
        newShippingEvent = new ShippingEvent(currentTime, nextPrepareEvent->getTargetShipTime(), nextPrepareEvent->getOrderValue(),  nextPrepareEvent->getOrderType(), 
        nextPrepareEvent->getOrderID());
        newShippingEvent->printEvent();
		if (newShippingEvent != nullptr) 
		{ 
			result = newShippingEvent->getOrderCost();
			this->totalProfit +=result; 
		}
		delete nextPrepareEvent;
		delete newShippingEvent;
    }
}

void Amazin :: simulation(string fileName)
{
	// Opening file using file reader
	FileReader *readFile = new FileReader(fileName);

	// Getting a stream of inputs from FileReader
	ifstream input = readFile->openFile();

	// Reading next line
	string line = readFile->getNextLine(input);

	// Tokenize the string
	stringstream sst(line);

	// Variables for creating order object
	// Time of arrival
	int arrivalTime = 0;

	// Type of order
	string customerType = " ";

	// Value of the order
	double value = 0.0;

	// Total Profit
    double totalProfit = 0;

	// Used to create orderIDs
	int setOrderID = 1;

	// Assigning values to variables
	sst >> arrivalTime;
	sst >> customerType; 
	sst >> value;

	// Initialize curren Time to arrival time of first order
	int currentTime = arrivalTime;
    this->initializeWorkerList();

	// Prime Order Queue 
	this->primerEventQueue(this->primerOrderQueue(arrivalTime, setOrderID, value, customerType));
    setOrderID++;

	// Loop until there are no orders left in Event's Queue 
	while (!eventQueue->isEmpty())
	{
		// While there are workers in the workList
		// While there are arrival events in the
		// Keep assigning workers arrival events
		this->processPrepareEvent(currentTime);

		// While there are prepare events in the events queue
		// While their end time is less than or equal to current time
		// Keep processing those events
		this->processShippingEvent(currentTime);

		// If an employee get's free from the last shipping event 
		// assign them a new order
		// While there are workers in the workList.
		// While there are arrival events in the.
		// Keep assigning workers arrival events.
		this->processPrepareEvent(currentTime);

		// While there is another line in the file 
		// While the next order's arrival time is less than or equal to current time
		// Keep adding that arrival events to queue and orders to order queue
		while (true)
		{
			line = readFile->getNextLine(input);
			if (line.empty())
			{
				break;
			}
			stringstream sst(line);
			sst >> arrivalTime;
			sst >> customerType;
			sst >> value;
			if (arrivalTime <= currentTime)
			{
				this->processArrivalEvent(this->processOrder(currentTime, setOrderID, value, customerType));
				setOrderID++;
				this->processPrepareEvent(currentTime);
			}
			else
			{
				input.clear();
				input.seekg(-(line.length() + 1), ios::cur);
				break;
			}
		}

		currentTime++;
	}

    this->noOfWorkDays = this->workerList->getTotalWorkDays();
	this->totalWorkerCost = this->workerList->getTotalWageCost();

	this->netProfit = this->totalProfit - this->totalWorkerCost;

    cout << "#######################" << endl;
    cout << "The simulation has ended." << endl;
    cout << "The number of additional workers was " << this->noOfEmployees << endl;
    cout << "The total number of work days was " << this->noOfWorkDays << endl;
	cout << "The cost of the additional workers was $" << fixed << std::setprecision(2) << this->totalWorkerCost << endl;
	cout << "The total profit before paying workers was $" << fixed << std::setprecision(2) << this->totalProfit << endl;
	cout << "The total profit when considering additional workers was $" << fixed << std::setprecision(2) << this->netProfit << endl;
    cout << "#######################" << endl;

	delete readFile;
}




