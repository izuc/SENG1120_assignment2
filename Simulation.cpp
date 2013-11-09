// Filename: Simulation.cpp
// Date Created: 30/09/2011
// Author: Lance Baker
// Course: SENG1120
// Student Number: c3128034

#include <iostream>
#include <cstdlib>
#include "Node.h"
#include "Carriage.h"
#include "LinkedList.h"
#include "Queue.h"
#include "Train.h"
#include "Simulation.h"

using namespace std;
using lance_project::Simulation;
using lance_project::Carriage;
using lance_project::Train;
using lance_project::Queue;

namespace lance_project {
	// The constructor for the simulation accepts two variables,
	// which are for the max capacity of the simulation and the 
	// amount of queues at the track junction.
	Simulation::Simulation(int maxCapacity, int maxQueues) {
		this->maxCapacity = maxCapacity;
		this->maxQueues = maxQueues;
		this->initQueues();
	}
	
	// The destructor for the Simulation.
	Simulation::~Simulation() {
		delete [] this->trains;
		delete [] this->queues;
	}
	
	// The initQueues method initialises the queue array with new queue instances
	// for the max amount of queues.
	void Simulation::initQueues() {
		for (int i = 0; i < this->maxQueues; i++) {
			this->queues[i] = new Queue<Carriage>();
		}
	}
	
	// The createTrains method instantiates four instances of Train stored
	// in the array. Each instance has a random amount of carriages, with each
	// carriage having a random amount of coal.
	void Simulation::createTrains() {
		// Iterates for each train.
		for (int i = 0; i < MAX_TRAINS; i++) {
			// Instantiates a new Train.
			this->trains[i] = new Train();
			// Iterates for a random amount of carriages.
			int carriages = this->getRand(10, 20);
			for (int c = 0; c < carriages; c++) {
				// Instantiates a new Carriage with a random amount of coal.
				// Adds the carriage to the train instance.
				this->trains[i]->add(new Carriage(this->getRand(4000, 5000)));
			}
		}
	}
	
	// The trackJunction method simulates the loading of the carriages onto
	// the queues. It iterates for each train; loading the carriages from 
	// the train onto the shortest queue.
	void Simulation::trackJunction() {
		// Iterates for each Train.
		for (int i = 0; i < MAX_TRAINS; i++) {
			// Sets the shortestQueue pointer to the first queue in the array.
			Queue<Carriage>* shortestQueue = this->queues[0];
			// Iterates for each queue.
			for (int q = 1; q < this->maxQueues; q++) {
				// If the size of the current queue is less than the 
				// shortestQueue pointer
				if (this->queues[q]->size() < shortestQueue->size()) {
					// Then it sets the shortestQueue pointer to the
					// shorter queue found.
					shortestQueue = this->queues[q];
				}
			}
			// Iterates until Train's head node is null.
			while (this->trains[i]->getList()->getHead() != NULL) {
				// Loads the the carriage onto the queue.
				shortestQueue->enqueue(this->trains[i]->getList()->getHead()->data());
				// Removes the head node.
				this->trains[i]->getList()->removeHead();
			}
		}
	}
	
	// The isEmpty method is used to check whether all
	// the queues are empty.
	bool Simulation::isEmpty() {
		int count = 0; // A counter.
		// Iterates for each queue.
		for (int i = 0; i < this->maxQueues; i++) {
			// If the queue is empty.
			if (this->queues[i]->isEmpty()) {
				// The count is incremented
				count++;
			}
		}
		// Returns true if all the queues are empty.
		return (count == this->maxQueues);
	}
	
	// Getter for the average length attribute. It also
	// divides the average length by the amount of days the
	// simulation ran for.
	int Simulation::getAvgLength() {
		return (this->avgLength / MAX_DAYS);
	}
	
	// Getter for the max carriages attribute.
	int Simulation::getMaxLength() {
		return this->maxLength;
	}
	
	// The getRand method is used to fetch a random
	// number between the min and max range.
	int Simulation::getRand(int min, int max) {
		return(rand()%(max-min)+min);  
	}
	
	// The calcQueues method is used to calculate the average length
	// and the maximum length of the queues.
	void Simulation::calcQueues() {
		int size = 0;
		// Sets the max to the first queue's size.
		int max = this->queues[0]->size();
		// Iterates for each queue.
		for (int i = 0; i < this->maxQueues; i++) {
			// Adds the size of the queue to the size variable.
			size += this->queues[i]->size();
			// If the current queue's size is greater than the max.
			if (this->queues[i]->size() > max) {
				// It then sets the new size to the max variable.
				max = this->queues[i]->size();
			}
		}
		// Adds the size divided by the amount of queue's,
		// to the avgLength attribute.
		this->avgLength += (size / this->maxQueues);
		// If the max is greater than the maxLength attribute
		if (max > this->maxLength) {
			// It then sets the attribute to the new max value.
			this->maxLength = max;
		}
	}
	
	// The run method is used to run the simulation for the 
	// max amount of days. For each day, it creates the trains,
	// then loads the carriages onto the shortest queue, calculates
	// the average & max length, and then unloads the carriages until
	// the max capacity has been reached.
	void Simulation::run() {
		// Iterates for each day.
		for (int day = 1; day <= MAX_DAYS; day++) {
			// Creates trains with a random amount of carriages & coal.
			this->createTrains();
			// Loads the trains onto the queues based on the shortest queue.
			this->trackJunction();
			// Calculates the average length & max length of the queues.
			this->calcQueues();
			// Iterates until the unload capacity has been reached or until
			// the queues are empty.
			int unloadCapacity = 0;
			while ((unloadCapacity < this->maxCapacity) && (!this->isEmpty())) {
				// Iterates for each queue.
				for (int i = 0; i < this->maxQueues; i++) {
					// If the queue is not empty.
					if (!this->queues[i]->isEmpty()) {
						// It then dequeues a carriage.
						Carriage* carriage = this->queues[i]->dequeue();
						// Adding the coal in the carriage to the unload capacity.
						unloadCapacity += carriage->getCoal();
					}
				}
			}
		}
	}
}

int main() {
	srand(10000); // Seeds the random number generator.
	// Prints out the headings for the table.
	cout << "\tNumber of queues - q" << endl;
	cout << "Oc\t2\t3\t4\t5" << endl;
	// Iterates for each capacity amount (incremented by 50,000) until
	// 350,000 has been reached.
	for (int capacity = 50000; capacity <= 350000; capacity+=50000) {
		// Prints out the capacity separated by a space.
		printf ("%06d ", capacity);
		// Iterates throughout the various queue sizes.
		for (int i = 2; i <= 5; i++) {
			// Instantiates a new Simulation with the capacity and queue size.
			Simulation* simulation = new Simulation(capacity, i);
			// Runs the simulation.
			simulation->run();
			// Prints out the results.
			printf (" %03d:%03d", simulation->getAvgLength(), simulation->getMaxLength());
		}
		cout << endl; // Prints a new line.
	}
	return 0;
}
