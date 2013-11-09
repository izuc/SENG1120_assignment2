// Filename: Carriage.h
// Date Created: 30/09/2011
// Author: Lance Baker
// Course: SENG1120
// Student Number: c3128034

#ifndef LANCE_CARRIAGE_H
#define LANCE_CARRIAGE_H
namespace lance_project {
	class Carriage {
		public:
			// The default constructor.
			Carriage();

			// The constructor initialises the
			// coal attribute with the received value.
			Carriage(int coal);
			
			// Setter for the coal.
			void setCoal(int coal);
			
			// Getter for the coal.
			int getCoal();
		private:
			// The amount of coal in the carriage.
			int coal;
	};
}
#endif
