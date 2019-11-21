# Definitions.
CC = gcc
INCLUDES = -I./include -I./include/Create_Project
CFLAGS = -g -Wall -std=c99 $(INCLUDES) -pthread
GTK_LIB = `pkg-config --cflags --libs gtk+-3.0` -rdynamic


# Default target.
all: build
	cd app && python3.6 build.py build && chmod +x app/*.desktop


# Compile: create object files from C source files.
app/codeManager.o: src/codeManager.c include/codeManager.h
	$(CC) -c $(CFLAGS) $< -o $@ $(GTK_LIB) 

app/chooseTemplate.o: src/Create_Project/chooseTemplate.c include/Create_Project/chooseTemplate.h
	$(CC) -c $(CFLAGS) $< -o $@ $(GTK_LIB) 


# Link: create ELF output file from object files.
app/Code_Manager.out: app/codeManager.o
	$(CC) $^ -o $@ $(GTK_LIB) 
	
app/chooseTemplate.out: app/chooseTemplate.o
	$(CC) $^ -o $@ $(GTK_LIB) 

build: app/Code_Manager.out app/chooseTemplate.out
	

# Target: Clean Project.
.PHONY: cleanProject
clean:
	cd app && rm -f *.o *.out
	cd app && python3.6 build.py remove
	