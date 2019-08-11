CC = g++
CFLAGS = -g -Wall
TARGET = main

DATASTRUCTURESDIR = ../../../Data_Structures
ALGORITHMSDIR = ../../../Algorithms

SINGLELINKLISTDIR = $(DATASTRUCTURESDIR)/linklist/singlelinklist
LRUDIR = $(ALGORITHMSDIR)/LRU

OBJDIR = ./obj

main.o:main.cc $(OBJDIR)/lru.o
	$(CC)  main.cc    -o $@ 	$(CFLAGS) -I  $(DATASTRUCTURESDIR) -I $(ALGORITHMSDIR)

$(OBJDIR)/lru.o:$(LRUDIR)/lru.h $(LRUDIR)/lru.c $(OBJDIR)/singlelinklist.o 
	$(CC) -c $(LRUDIR)/lru.c	-o 	$@ 	$(CFLAGS) -I $(DATASTRUCTURESDIR)

$(OBJDIR)/singlelinklist.o: $(SINGLELINKLISTDIR)/singlelinklist.cc $(SINGLELINKLISTDIR)/singlelinklistnode.h
	$(CC)  -c  $(SINGLELINKLISTDIR)/singlelinklist.cc -o $@ $(CFLAGS)

.PHONY:clean
clean:
	-rm  -rf $(SINGLELINKLIST)/singlelinklist.cc.gch
	-rm  -rf $(LRUDIR)/lru.c.gch
	-rm  -rf  $(OBJDIR)/lru.o $(OBJDIR)/singlelinklist.o
