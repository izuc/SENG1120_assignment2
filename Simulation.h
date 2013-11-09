// Filename: Simulation.h
// Date Created: 30/09/2011
// Author: Lance Baker
// Course: SENG1120
// Student Number: c3128034

#ifndef LANCE_SIMULATION_H
#define LANCE_SIMULATION_H
namespace lance_project {
	static const int MAX_TRAINS = 4;
	static const int MAX_QUEUES = 5;
	static const int MAX_DAYS = 30;
	
	class Simulation {
		public:
			// The constructor accepts the max capacity of the unloading
			// machine, and the max amount of queues at the track junction.
			Simulation(int maxCapacity, int maxQueues);
			
			~Simulation(); // Destructor
			
			void run(); // Runs the simulation
			
			int getAvgLength(); // Getter for the average length
			
			int getMaxLength(); // Getter for the max length
			
		private:
			Train* trains[MAX_TRAINS]; // The trains.
			Queue<Carriage>* queues[MAX_QUEUES]; // The queues.
			
			int maxCapacity; // The max capacity of the unloading machine.
			int maxQueues; // The max amount of queues at the track junction.
			
			int avgLength; // The average length of the queues.
			int maxLength; // The max length of any of the queues.
			
			// The createTrains method instantiates four trains with a random
			// amount of carriages, with each carriage having a random amount of coal.
			void createTrains();
			
			// The trackJunction method unloads the carriages of each train 
			// onto the shortest queue.
			void trackJunction();
			
			// The calcQueues method calculates the average length, and max length.
			void calcQueues();
			
			// The initQueues method initialises the queues.
			void initQueues();
			
			// The isEmpty method checks whether the queues are empty.
			bool isEmpty();
			
			// The getRand method returns a random integer between a particular range.
			int getRand(int min, int max);
	};
}
#endif
