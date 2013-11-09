// Filename: LinkedList.h
// Date Created: 30/09/2011
// Author: Lance Baker
// Course: SENG1120
// Student Number: c3128034

#ifndef LANCE_LINKEDLIST_H
#define LANCE_LINKEDLIST_H
namespace lance_project {
	template <class T>
	class LinkedList {
		public:
			// Postconditions: The default constructor for the LinkedList.
			LinkedList();
			
			// Postconditions: The destructor for the LinkedList. 
			// Clears the List nodes, and deletes the head & tail pointers.
			~LinkedList();
			
			// Postconditions: Adds a new Node to the end of the LinkedList.
			void addLast(T* value);
			
			// Postconditions: Adds a new Node to the beginning of the LinkedList.
			void addFirst(T* value);
			
			// Postconditions: Adds a new Node after the prev_node.
			void insert(Node<T>* prev_node, T* value);
			
			// Postconditions: Chops the head off the LinkedList.
			void removeHead();
			
			// Postconditions: Removes the Node after the prev_node.
			void remove(Node<T>* prev_node);
			
			// Postconditions: Clears the LinkedList.
			void clear();
			
			// Postconditions: Clears & then performs a deep copy of the Nodes
			//				linked after the source_ptr adding them to the end
			//				of the current instance.
			void copy(Node<T>* source_ptr);
			
			// Postconditions: Retrieves the Node matching the received target value.
			Node<T>* search(T* target);
			
			// Postconditions: Fetches the Node at that present position in the LinkedList.
			Node<T>* getNode(int position);
			
			// Postconditions: Fetches the head Node of the LinkedList.
			Node<T>* getHead();
			
			// Postconditions: Determines & returns the size of the LinkedList.
			int getSize();
		private:
			Node<T>* head_ptr; // Pointer to the head Node.
			Node<T>* tail_ptr; // Pointer to the tail Node.
			int size;
	};
}
#include "LinkedList.template"
#endif
