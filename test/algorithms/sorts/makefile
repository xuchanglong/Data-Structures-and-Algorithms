CC := g++
CFLAGS := -g -Wall
TARGET := main.o

ALGORITHMSDIR := ../../../algorithms

SORTSDIR := $(ALGORITHMSDIR)/sorts

$(TARGET):main.cc $(SORTSDIR)/sorts.hpp
	$(CC) $< -o $@ -I $(ALGORITHMSDIR) $(CFLAGS)

.PHONY:clean
clean:
	-rm  -rf main.exe main.o
