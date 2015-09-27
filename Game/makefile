CFLAGS=-c -Wall -std=c++14
LFLAGS=-Wall -std=c++14
LPATH=-L..\sfml\lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-graphics -lsfml-audio
IPATH=-I..\sfml\include
CC=g++
OBJS= main.o GameLogic.o UserInterface.o Ship.o Flyer.o StopWatch.o EntityHolder.o Entity.o Collisions.o Laser.o Missile.o HomingMissile.o Powerup.o
all: attacker.exe
attacker.exe: $(OBJS)
	$(CC) $(OBJS) $(LFLAGS) $(LPATH) -o attacker.exe
main.o: main.cpp GameLogic.h
	$(CC) $(CFLAGS) $(IPATH) -o main.o main.cpp
GameLogic.o: GameLogic.cpp GameLogic.h UserInterface.h Ship.h Events.h EntityID.h StopWatch.h Collisions.h
	$(CC) $(CFLAGS) $(IPATH) -o GameLogic.o GameLogic.cpp
UserInterface.o: UserInterface.cpp UserInterface.h Events.h Character.h EntityID.h ResourceHolder.h
	$(CC) $(CFLAGS) $(IPATH) -o UserInterface.o UserInterface.cpp
Ship.o: Ship.cpp Ship.h Events.h Character.h Entity.h Laser.h Flyer.h
	$(CC) $(CFLAGS) $(IPATH) -o Ship.o Ship.cpp
Flyer.o: Flyer.cpp Flyer.h Character.h Entity.h Ship.h Missile.h
	$(CC) $(CFLAGS) $(IPATH) -o Flyer.o Flyer.cpp
StopWatch.o: StopWatch.h
	$(CC) $(CFLAGS) $(IPATH) -o StopWatch.o StopWatch.cpp
EntityHolder.o: EntityHolder.h Entity.h Character.h
	$(CC) $(CFLAGS) $(IPATH) -o EntityHolder.o EntityHolder.cpp
Entity.o: Entity.h Character.h
	$(CC) $(CFLAGS) $(IPATH) -o Entity.o Entity.cpp
Collisions.o: Collisions.h Entity.h
	$(CC) $(CFLAGS) $(IPATH) -o Collisions.o Collisions.cpp
Laser.o: Laser.h Entity.h
	$(CC) $(CFLAGS) $(IPATH) -o Laser.o Laser.cpp
Missile.o: Missile.h Entity.h
	$(CC) $(CFLAGS) $(IPATH) -o Missile.o Missile.cpp
HomingMissile.o: HomingMissile.h Entity.h Flyer.h Character.h
	$(CC) $(CFLAGS) $(IPATH) -o HomingMissile.o HomingMissile.cpp
Powerup.o: Powerup.h Entity.h Character.h
	$(CC) $(CFLAGS) $(IPATH) -o Powerup.o Powerup.cpp
clean:
	del *.o *.exe
