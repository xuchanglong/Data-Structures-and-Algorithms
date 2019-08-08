CC = g++
CFLAGS = -g -Wall

DATASTRUCTURESDIR = ../../../Data-Structures
TARGET = main.o
DOUBLELINKLISTDIR = $(DATASTRUCTURESDIR)/linklist/doublelinklist

$(TARGET):main.cc $(DOUBLELINKLISTDIR)/doublelinklist.hpp
	$(CC) -I $(DATASTRUCTURESDIR) main.cc  -o 	$@ 	$(CFLAGS)

.PHONY:clean
clean:
	rm -rf $(DOUBLELINKLISTDIR)/doublelinklist.hpp.gch