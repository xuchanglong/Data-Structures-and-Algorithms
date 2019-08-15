CC = g++
CFLAGS = -g -Wall

DATASTRUCTURESDIR = ../../../../Data_Structures
TARGET = main.o
SINGLELINKLISTDIR = $(DATASTRUCTURESDIR)/linklist/singlelinklist

$(TARGET):main.cc $(SINGLELINKLISTDIR)/singlelinklist.hpp $(SINGLELINKLISTDIR)/singlelinklistnode.h
	$(CC)  $<  -o 	$@ 	$(CFLAGS) -I $(DATASTRUCTURESDIR)

.PHONY:clean
clean:
	rm -rf $(SINGLELINKLISTDIR)/singlelinklist.hpp.gch ./main.exe ./main.o ./main