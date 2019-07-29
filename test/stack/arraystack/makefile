CC = g++
CFLAGS = -g -Wall

DATASTRUCTURESDIR = ../../../Data-Structures
TARGET = main.o
ARRAYSTACKDIR = $(DATASTRUCTURESDIR)/stack/arraystack

$(TARGET):main.cpp arraystack.o
	$(CC)	-I $(ARRAYSTACKDIR) main.cpp 	-o 	$@ 	$(CFLAGS)

arraystack.o: $(ARRAYSTACKDIR)/arraystack.hpp
	$(CC)  -c $(ARRAYSTACKDIR)/arraystack.hpp  $(CFLAGS)