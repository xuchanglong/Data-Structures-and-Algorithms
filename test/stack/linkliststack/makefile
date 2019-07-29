CC = g++
CFLAGS = -g -Wall

DATASTRUCTURESDIR = ../../../Data-Structures
TARGET = main.o
LINKLISTSTACKDIR = $(DATASTRUCTURESDIR)/stack/linkliststack

$(TARGET):main.cpp linkliststack.o
	$(CC)	-I $(LINKLISTSTACKDIR) main.cpp 	-o 	$@ 	$(CFLAGS)

linkliststack.o: $(LINKLISTSTACKDIR)/linkliststack.hpp 
	$(CC)  -c $(LINKLISTSTACKDIR)/linkliststack.hpp  $(CFLAGS)