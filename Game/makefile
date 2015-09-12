CFLAGS=-c -Wall -std=c++14
LFLAGS= -Wall -std=c++14
LPATH=-L..\sfml\lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-graphics -lsfml-audio
IPATH=-I..\sfml\include
CC=g++
OBJS= main.o GameLogic.o UserInterface.o Ship.o Flyer.o StopWatch.o EntityHolder.o Entity.o
all: attacker.exe
attacker.exe: $(OBJS)
	$(CC) $(OBJS) $(LFLAGS) $(LPATH) -o attacker.exe
main.o: main.cpp GameLogic.h
	$(CC) $(CFLAGS) $(IPATH) -o main.o main.cpp
GameLogic.o: GameLogic.cpp GameLogic.h UserInterface.h Ship.h Events.h TextureID.h StopWatch.h
	$(CC) $(CFLAGS) $(IPATH) -o GameLogic.o GameLogic.cpp
UserInterface.o: UserInterface.cpp UserInterface.h Events.h Character.h TextureID.h ResourceHolder.h
	$(CC) $(CFLAGS) $(IPATH) -o UserInterface.o UserInterface.cpp
Ship.o: Ship.cpp Ship.h Events.h Character.h Entity.h
	$(CC) $(CFLAGS) -o Ship.o Ship.cpp
Flyer.o: Flyer.cpp Flyer.h Character.h Entity.h
	$(CC) $(CFLAGS) -o Flyer.o Flyer.cpp
StopWatch.o: StopWatch.h
	$(CC) $(CFLAGS) -o StopWatch.o StopWatch.cpp
EntityHolder.o: EntityHolder.h Entity.h Character.h
	$(CC) $(CFLAGS) -o EntityHolder.o EntityHolder.cpp
Entity.o: Entity.h Character.h
	$(CC) $(CFLAGS) -o Entity.o Entity.cpp
clean:
	del *.o *.exe
