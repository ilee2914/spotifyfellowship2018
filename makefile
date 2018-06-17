CC=g++
CFLAGS=-std=c++17
PROGRAM_1=1.cpp
PROGRAM_2=2.cpp
PROGRAM_3=3.cpp

all: 
	$(CC) $(CFLAGS) $(PROGRAM_1) -o 1.out 
	$(CC) $(CFLAGS) $(PROGRAM_2) -o 2.out 
	$(CC) $(CFLAGS) $(PROGRAM_3) -o 3.out 
	
clean:
	rm *.exe *.o *.out