CFLAGS=-c -Wall -std=c++14
LFLAGS=-Wall
LPATH=-L..\sfml\lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-graphics -lsfml-audio
IPATH=-I..\sfml\include
CC=g++
all: defender.exe
defender.exe: main.o
	$(CC) main.o defender.o ship.o $(LFLAGS) $(LPATH) -o defender.exe 
main.o: main.cpp defender.o Defender.h
	$(CC) $(CFLAGS) main.cpp $(IPATH) -o main.o 
defender.o: defender.cpp ship.o ResourceHolder.h Ship.h
	$(CC) $(CFLAGS) Defender.cpp $(IPATH) -o defender.o
ship.o: Ship.cpp
	$(CC) $(CFLAGS) Ship.cpp $(IPATH) -o ship.o
clean:
	del *.o *.exe
