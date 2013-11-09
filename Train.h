// Filename: Train.h
// Date Created: 30/09/2011
// Author: Lance Baker
// Course: SENG1120
// Student Number: c3128034

#ifndef LANCE_TRAIN_H
#define LANCE_TRAIN_H
using namespace std;

namespace lance_project {
	class Train {
		public:
			// Postconditions: Creates an instance that does not contain any numeric data.
			Train();
			
			// Preconditions: The input array must contain a terminating element of -1
			//				in order for the array to know the end value. The datatype is
			//				restricted to integers.
			// Postconditions: Creates an instance and stores the array’s values in the instance.
			Train(int arr[]);
			
			// Destructor for the Train.
			~Train();
			
			// Postconditions: Adds the received carriage to the internal data structure.
			void add(Carriage* carriage);
			
			// Postconditions: Returns an integer indicating the total amount 
			// 					of coal being transported by the Train.
			int totalLoad();
			
			// Postconditions: Returns a count of how many empty carriages Train has.
			int countEmpty();
			
			// Preconditions: The "j" indice must exist in the array.
			// Postconditions: Adds “i” kilograms of coal to the “j”-th carriage of Train.
			void addLoad(int i, int j);
			
			// Preconditions: The "j" indice must exist in the array.
			// Postconditions: Removes “i” kilograms of coal to the “j”-th carriage of Train.
			void removeLoad(int i, int j);
			
			// Postconditions: Returns a pointer to the residing LinkedList.
			LinkedList<Carriage>* getList();
			
			// Postconditions: Returns a count of the number of carriages in the Train.
			int size();
			
			// Overloaded concatenation operator (i.e. ‘+=’). The result of use of this
			// operator is that the Train arguments are concatenated and the answer is
			// stored in the left argument.
			Train operator+=(Train & rhs);
			
			// Overloaded assignment operator (i.e. ‘=’) that makes the content of the left
			// Train operand the same as that of the right hand Train operand. 
			Train operator=(Train & rhs);
		private:
			LinkedList<Carriage>* linked_list;
	};
	// Overloaded output operator (i.e. ‘<<’) that outputs the content of the Train
	// in a form suitable for printing by the cout statement.
	ostream & operator<<(ostream & out, Train & value);
	static const std::string OUTPUT_DIVIDER = "|";
}
#endif
