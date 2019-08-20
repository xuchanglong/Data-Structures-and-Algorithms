CC := g++
CFLAGS := -g -Wall
TARGET := main

ALGORITHMSDIR := ../../../Algorithms

SORTSDIR := $(ALGORITHMSDIR)/sorts

$(TARGET):main.cc $(SORTSDIR)/sorts.hpp
	$(CC) $< -o $@ -I $(ALGORITHMSDIR)

.PHONY:clean
clean:
	-rm  -rf main.exe main
