CC := g++
CFLAGS := -g -Wall
TARGET := main

DATASTRUCTURESDIR := ../../../Data_Structures
ALGORITHMSDIR := ../../../Algorithms

SINGLELINKLISTDIR := $(DATASTRUCTURESDIR)/linklist/singlelinklist
SINGLELINKLIST_ALGODIR := $(ALGORITHMSDIR)/singlelinklist_algo

$(TARGET):main.cc \
	   	  $(SINGLELINKLIST_ALGODIR)/singlelinklist_algo.hpp \
	   	  $(SINGLELINKLISTDIR)/singlelinklist.hpp \
	      $(SINGLELINKLISTDIR)/singlelinklistnode.h
	$(CC) $< -o $@ -I  $(DATASTRUCTURESDIR) -I $(ALGORITHMSDIR)

.PHONY:clean
clean:
	-rm  -rf main
