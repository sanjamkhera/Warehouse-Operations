CXX = clang++
CPPFLAGS = -gdwarf-4

.PHONY: clean 

all: main

main: ArrivalEvent.o Event.o EventQueue.o FileReader.o ListOfWorkers.o Order.o OrderQueue.o PrepareEvent.o ShippingEvent.o Worker.o WorkerNode.o Amazin.o

clean:
	rm -f main *.o