
# Define the compiler
CC=g++
# Define the compiler options
CFLAGS=-O2
# Define the linker
LINK=g++

all: InfixToPostfix

# Define the dependencies
InfixToPostfix: InfixToPostfix.o
	$(LINK) -o InfixToPostfix InfixToPostfix.o
	
InfixToPostfix.o: InfixToPostfix.cpp List.h
	$(CC) -c $(CFLAGS) -std=c++0x InfixToPostfix.cpp 
###
clean:
	/bin/rm -f InfixToPostfix InfixToPostfix.o	
 
