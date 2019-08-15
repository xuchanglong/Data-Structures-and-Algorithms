CC := g++
CFLAGS := -g -Wall
TARGET := main

DATASTRUCTURESDIR := ../../../../datastructures
ALGORITHMSDIR := ../../../../algorithms

SINGLELINKLISTDIR := $(DATASTRUCTURESDIR)/linklist/singlelinklist
SINGLELINKLIST_ALGODIR := $(ALGORITHMSDIR)/singlelinklist_algo

$(TARGET):main.cc \
	   	  $(SINGLELINKLIST_ALGODIR)/singlelinklist_algo.hpp \
	   	  $(SINGLELINKLISTDIR)/*
	$(CC) $< -o $@ -I  $(DATASTRUCTURESDIR) -I $(ALGORITHMSDIR)

.PHONY:clean
clean:
	-rm  -rf main.exe main.exe.stackdump main
