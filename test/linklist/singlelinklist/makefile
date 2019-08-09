CC = g++
CFLAGS = -g -Wall

DATASTRUCTURESDIR = ../../../Data-Structures
TARGET = main.o
SINGLELINKLISTDIR = $(DATASTRUCTURESDIR)/linklist/singlelinklist

$(TARGET):main.cc $(SINGLELINKLISTDIR)/singlelinklist.hpp
	$(CC) -I $(DATASTRUCTURESDIR) main.cc  -o 	$@ 	$(CFLAGS)

.PHONY:clean
clean:
	rm -rf $(SINGLELINKLISTDIR)/singlelinklist.hpp.gch