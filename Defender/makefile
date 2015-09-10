CFLAGS=-c -Wall -std=c++14
LFLAGS= -Wall -std=c++14
LPATH=-L..\sfml\lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-graphics -lsfml-audio
IPATH=-I..\sfml\include
CC=g++
OBJS= main.o GameLogic.o UserInterface.o Ship.o StopWatch.o
all: attacker.exe
attacker.exe: $(OBJS)
	$(CC) $(OBJS) $(LFLAGS) $(LPATH) -o attacker.exe
main.o: main.cpp GameLogic.h
	$(CC) $(CFLAGS) $(IPATH) -o main.o main.cpp
GameLogic.o: GameLogic.cpp GameLogic.h UserInterface.h Ship.h Events.h TextureID.h StopWatch.h
	$(CC) $(CFLAGS) $(IPATH) -o GameLogic.o GameLogic.cpp
UserInterface.o: UserInterface.cpp UserInterface.h Events.h Character.h TextureID.h ResourceHolder.h
	$(CC) $(CFLAGS) $(IPATH) -o UserInterface.o UserInterface.cpp
Ship.o: Ship.cpp Ship.h Events.h Character.h
	$(CC) $(CFLAGS) -o Ship.o Ship.cpp
StopWatch.o:
	$(CC) $(CFLAGS) -o StopWatch.o StopWatch.cpp
clean:
	del *.o *.exe
