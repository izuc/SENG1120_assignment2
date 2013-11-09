// Filename: Queue.h
// Date Created: 30/09/2011
// Author: Lance Baker
// Course: SENG1120
// Student Number: c3128034

#ifndef LANCE_QUEUE_H
#define LANCE_QUEUE_H
namespace lance_project {
	template <class T>
	class Queue {
		public:
			// The default constructor for the queue.
			Queue();
			
			// Destructor for the Queue.
			~Queue();
			
			// The enqueue method accepts a value, and adds
			// it to the residing data structure.
			void enqueue(T* value);
			
			// The dequeue method takes a value from the 
			// internal data structure, and returns it. 
			T* dequeue();
			
			// The size method returns the size of the queue.
			int size();
			
			// The isEmpty method returns a boolean true if the
			// queue has no elements.
			bool isEmpty();
			
			// The front method returns the front value without
			// removing the element from the queue.
			T* front();
		private:
			// The linked list stores the data.
			LinkedList<T>* linked_list;
	};
}
#include "Queue.template"
#endif
