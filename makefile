# Definitions.
CC = gcc
INCLUDES = -I./include -I./include/Window_Options -I./include/Dialog -I./include/Create_Project
CFLAGS = -g -Wall -std=c99 $(INCLUDES) -pthread
GTK_LIB = `pkg-config --cflags --libs gtk+-3.0` -rdynamic


# Default target.
all: app/Code_Manager.out
	cd app && python3.6 build.py build && chmod +x app/*.desktop


# Compile: create object files from C source files.
app/main.o: src/main.c
	$(CC) -c $(CFLAGS) $< -o $@ $(GTK_LIB) 

app/windows.o: src/Window_Options/createWindow.c
	$(CC) -c $(CFLAGS) $< -o $@ $(GTK_LIB) 

app/chooseFolder.o: src/Dialog/chooseFolder.c include/Dialog/chooseFolder.h
	$(CC) -c $(CFLAGS) $< -o $@ $(GTK_LIB) 

app/manager.o: src/manager.c include/manager.h
	$(CC) -c $(CFLAGS) $< -o $@ $(GTK_LIB) 

app/createProject.o: src/Create_Project/createProject.c include/Create_Project/createProject.h
	$(CC) -c $(CFLAGS) $< -o $@ $(GTK_LIB) 


# Link: create ELF output file from object files.
app/Code_Manager.out: app/main.o app/manager.o app/windows.o app/createProject.o app/chooseFolder.o
	$(CC) $^ -o $@ $(GTK_LIB) 
	

# Target: Clean Project.
.PHONY: cleanProject
clean:
	cd app && rm -f *.o *.out
	cd app && python3.6 build.py remove
	