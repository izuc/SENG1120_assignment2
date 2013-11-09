CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=Carriage.cpp Train.cpp Simulation.cpp
value_typeS=$(SOURCES:.cpp=.o)
EXECUTABLE=Simulation

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(value_typeS)
	$(CC) $(LDFLAGS) $(value_typeS) -o $@

%.o : %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf *.o core
