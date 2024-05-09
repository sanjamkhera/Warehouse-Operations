Warehouse Simulation (Operations)
===============================
This document talks about the project and provides with instructions:  
- How to compile and run the program.
- An explanation of activities class hierarchy.
- It's structure and methods along with it.

Overview
--------
### About
- The program simulates the business operations for a warehouse of an Online store.  
- Focusing on order processing, shipping, penalties for late deliveries, and workforce management. 
- The model involves selling products with a 50% profit margin and offering two classes of customers: 
    - Primero (1-day shipping) and Standard (3-day shipping).
    - A 15% discount is given for late deliveries.

### How it Works
- The project implements a simulation program in C++ that reads customer orders from a file.
- It then processes them, calculates preparation times, manages shipping, and estimates the number of additional workers needed for optimal profit. 
- The simulation class maintains a priority queue of events (arrival, preparation, shipping) sorted by time and order ID. 
- Workers (including owner and additional employees) prepare orders based on their value, with each worker able to process one order at a time. 
- The simulation outputs event details and a summary of workdays, costs, and profits.

How to compile and run
----------------------
## Compile
Compile the program: once in the directory, enter ```make``` to compile and ```./main [inputFile.txt] [noOfEmployees]``` to run the program.

Design
------------------
## Types of Classes and their behavior
- Total of 12 classes, out of which 4 classes are part of one hierarchy. 
- Event Class is an abstract class that morphs into multiple events from arrival to shipment.
- Amazin is the main brain of the operation, It process the input orders, creates events accordingly, assigns workers jobs.
- It does that by holding two priority queues, events queue and order queue (wait list).
    - Arrived orders get's processed right away and get added to events queue.
    - If and when a worker get's available it assigns the the order.

### Pseudo Code for the simulation.
#### Section 1
- Loop until there are no orders left in Event's Queue.
- While there are workers in the workList.
- While there are arrival events in the system.
- Keep assigning workers arrival events.

#### Section 2
- While there are prepare events in the events queue.  
- While their end time is less than or equal to current time.  
- Keep processing those events.
- If an employee get's free from the last shipping event. 
- Assign them a new order.

#### Section 3
- While there are workers in the workList.
- While there are arrival events in the system.
- Keep assigning workers arrival events.
- While the next order's arrival time is less than or equal to current time.
- Keep adding that arrival events to queue and orders to order queue.
- Move to next hour.
