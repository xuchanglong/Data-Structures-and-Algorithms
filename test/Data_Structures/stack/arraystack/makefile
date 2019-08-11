CC = g++
CFLAGS = -g -Wall

DATASTRUCTURESDIR = ../../../../Data_Structures
TARGET = main.o
ARRAYSTACKDIR = $(DATASTRUCTURESDIR)/stack/arraystack

$(TARGET):main.cc $(ARRAYSTACKDIR)/arraystack.hpp
	$(CC)	-I $(DATASTRUCTURESDIR) main.cc 	-o 	$@ 	$(CFLAGS)

.PHONY:clean
clean:
	-rm  -rf $(ARRAYSTACKDIR)/arraystack.hpp.gch
