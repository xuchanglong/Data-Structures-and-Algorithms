CC = g++
CFLAGS = -g -Wall

DATASTRUCTURESDIR = ../../../../Data_Structures
TARGET = main.o
LINKLISTSTACKDIR = $(DATASTRUCTURESDIR)/stack/linkliststack

$(TARGET):main.cc $(LINKLISTSTACKDIR)/linkliststack.hpp
	$(CC)	-I $(DATASTRUCTURESDIR) main.cc 	-o 	$@ 	$(CFLAGS)

.PHONY:clean
clean:
	rm -rf $(LINKLISTSTACKDIR)/linkliststack.hpp.gch