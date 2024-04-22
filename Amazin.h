#pragma once
#include <string>
#include "Worker.h"
#include "EventQueue.h"
#include "ListOfWorkers.h"
#include "OrderQueue.h"
#include "Event.h"
/*
CLASS: Amazin

Author: Sanjam Khera, 007866840

REMARKS:
This is the brain of the entire operation.
All operations are happening with in this class.
It reads orders from the file and processes them,
as per the requirements of the assignment.
-----------------------------------------
*/

class Amazin 
{

    private:
        // number of employees at the facility
        int noOfEmployees;

        // This will hold the wait list of events to be processed
	    OrderQueue *waitingQueue;

        // This is our priority event queue queue
        EventQueue *eventQueue;

        // List of workers at the facility
        ListOfWorkers* workerList;

        // Track Profit
        double totalProfit;

        // Number of Work days
        int noOfWorkDays;

        // Total Worker Cost to the facility
        double totalWorkerCost;

        // Net profit at the facility
        double netProfit;

    public:
        // Constructor
        Amazin(int noOfEmployees);

        // Destructor
        ~Amazin();

        // Initialize WorkerList
        void initializeWorkerList();

        // Prime order queue
        // Tokenize the incoming line
        // Initialize the first order
        // Add it to order queue
        Order* primerOrderQueue(int arrivalTime, int orderID, double orderValue, string customerType);

        // Prime event queue
        // Take an order to initialize the queue
        // Initialize events 
        void primerEventQueue(Order* order);

        // Process Order
        // Creates a new order and returns the order
        Order* processOrder(int currentTime, int orderID, double orderValue, string customerType);

        // Process arrival Event
        // Add it to events Queue
        void processArrivalEvent(Order* order);

        // Process Prepare Event
        // Add it to the Events Queue
        void processPrepareEvent(int currentTime);

        // Process Shipping Event
        // Shipping Event helps evaluate profits
        void processShippingEvent(int currentTime);

        // Simulation Process 
        void simulation(string fileName);
};