// Filename: Carriage.cpp
// Date Created: 30/09/2011
// Author: Lance Baker
// Course: SENG1120
// Student Number: c3128034

#include <iostream>
#include <cstdlib>
#include "Carriage.h"

using namespace std;
using lance_project::Carriage;

namespace lance_project {
	// The default constructor initialises
	// the coal attribute to zero.
	Carriage::Carriage() {
		this->coal = 0;
	}
	
	// The constructor accepts an integer value (for the
	// amount of coal) which is assigned to the coal attribute.
	Carriage::Carriage(int coal) {
		this->coal = coal;
	}
	
	// Setter for the coal attribute.
	void Carriage::setCoal(int coal) {
		this->coal = coal;
	}
	
	// Getter for the coal attribute.
	int Carriage::getCoal() {
		return this->coal;
	}
}
