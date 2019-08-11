CC = g++
CFLAGS = -g -Wall

DATASTRUCTURESDIR = ../../../../Data_Structures
TARGET = main.o
ARRAYQUEUEDIR = $(DATASTRUCTURESDIR)/queue/arrayqueue

$(TARGET):main.cc $(ARRAYQUEUEDIR)/arrayqueue.hpp
	$(CC) -I $(DATASTRUCTURESDIR) main.cc  -o 	$@ 	$(CFLAGS)

.PHONY:clean
clean:
	rm -rf $(ARRAYQUEUEDIR)/arrayqueue.hpp.gch