// Filename: Node.h
// Date Created: 30/09/2011
// Author: Lance Baker
// Course: SENG1120
// Student Number: c3128034

#ifndef LANCE_NODE_H
#define LANCE_NODE_H
namespace lance_project {
	template <class T>
	class Node {
		public:			
			// Postconditions: The default constructor creates a empty instance.
			Node();
			
			// Postconditions: The constructor creates a instance with data.
			Node(T* data_field);
			
			// Postconditions: The constructor creates a instance with data and a Node link.
			Node(T* data_field, Node<T>* link_field);
			
			// Postconditions: The destructor ensures that the memory is freed.
			~Node();
			
			// Postconditions: The setter for the data.
			void setData(T* data_field);
			
			// Postconditions: The setter for the next linked Node.
			void setLink(Node<T>* link_field);
			
			// Postconditions: The getter for the data.
			T* data() const;
			
			// Postconditions: The getter for the next linked Node.
			const Node<T>* link() const;
			
			// Postconditions: The getter for the next linked Node.
			Node<T>* link();
		private:
			T* data_field; // Instance field containing the data.
			Node<T>* link_field; // Pointer to the next Node.
	};
}
#include "Node.template"
#endif
