CC = g++
CFLAGS = -g -Wall

DATA_STRUCTURES_DIR = ../../../Data-Structures
TARGET = main.o
ARRAYQUEUE_DIR = $(DATA_STRUCTURES_DIR)/queue/arrayqueue

$(TARGET):main.cc $(ARRAYQUEUE_DIR)/arrayqueue.hpp
	$(CC) -I $(DATA_STRUCTURES_DIR) main.cc  -o 	$@ 	$(CFLAGS)