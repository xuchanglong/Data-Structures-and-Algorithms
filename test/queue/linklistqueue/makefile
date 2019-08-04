CC = g++
CFLAGS = -g -Wall

DATASTRUCTURESDIR = ../../../Data-Structures
TARGET = main.o
LINKLISTQUEUEDIR = $(DATASTRUCTURESDIR)/queue/linklistqueue

$(TARGET):main.cc $(LINKLISTQUEUEDIR)/linklistqueue.hpp
	$(CC) -I $(DATASTRUCTURESDIR) main.cc  -o 	$@ 	$(CFLAGS)

.PHONY:clean
clean:
	rm -rf $(LINKLISTQUEUEDIR)/linklistqueue.hpp.gch