CFLAGS=-c -Wall -std=c++14
LFLAGS=-Wall -std=c++14
LPATH=-L..\gtest\lib -lgtest_main -lgtest -L..\sfml\lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-graphics -lsfml-audio
IPATH=-I..\gtest\include -I..\Game -I..\sfml\include
CC=g++
ATTACKERPATH:=..\Game
MAKE=mingw32-make
OBJS=main.o ResourceHolder_unit_tests.o Collisions_unit_tests.o Flyer_unit_tests.o EntityHolder_unit_tests.o $(ATTACKERPATH)\Flyer.o $(ATTACKERPATH)\Collisions.o $(ATTACKERPATH)\Ship.o $(ATTACKERPATH)\Entity.o $(ATTACKERPATH)\Missile.o $(ATTACKERPATH)\Laser.o $(ATTACKERPATH)\HomingMissile.o $(ATTACKERPATH)\EntityHolder.o
all: test.exe
test.exe: $(OBJS) 
	$(CC) $(OBJS) $(LFLAGS) $(LPATH) -o test.exe
main.o: main.cpp
	$(CC) $(CFLAGS) $(IPATH) main.cpp -o main.o
ResourceHolder_unit_tests.o: ResourceHolder_unit_tests.cpp $(ATTACKERPATH)\ResourceHolder.h
	$(CC) $(CFLAGS) $(IPATH) ResourceHolder_unit_tests.cpp -o ResourceHolder_unit_tests.o
Collisions_unit_tests.o: Collisions_unit_tests.cpp $(ATTACKERPATH)\Collisions.h $(ATTACKERPATH)\Ship.h $(ATTACKERPATH)\Flyer.h
	$(CC) $(CFLAGS) $(IPATH) Collisions_unit_tests.cpp -o Collisions_unit_tests.o
Flyer_unit_tests.o: Flyer_unit_tests.cpp $(ATTACKERPATH)\Character.h $(ATTACKERPATH)\Entity.h $(ATTACKERPATH)\Missile.h
	$(CC) $(CFLAGS) $(IPATH) Flyer_unit_tests.cpp -o Flyer_unit_tests.o
EntityHolder_unit_tests.o: EntityHolder_unit_tests.cpp $(ATTACKERPATH)\EntityHolder.h $(ATTACKERPATH)\Flyer.h $(ATTACKERPATH)\Ship.h
	$(CC) $(CFLAGS) $(IPATH) EntityHolder_unit_tests.cpp -o EntityHolder_unit_tests.o
$(ATTACKERPATH)\Flyer.o:
	$(MAKE) -C $(ATTACKERPATH)
$(ATTACKERPATH)\Ship.o:
	$(MAKE) -C $(ATTACKERPATH) 
$(ATTACKERPATH)\Collisions.o:
	$(MAKE) -C $(ATTACKERPATH) 
$(ATTACKERPATH)\Entity.o:
	$(MAKE) -C $(ATTACKERPATH)
$(ATTACKERPATH)\Missile.o:
	$(MAKE) -C $(ATTACKERPATH)
$(ATTACKERPATH)\Laser.o:
	$(MAKE) -C $(ATTACKERPATH)
$(ATTACKERPATH)\HomingMissile.o:
	$(MAKE) -C $(ATTACKERPATH)
$(ATTACKERPATH)\EntityHolder.o:
	$(MAKE) -C $(ATTACKERPATH)
clean:
	del *.o *.exe
clean_Attacker:
	del $(ATTACKERPATH)\*.o $(ATTACKERPATH)\*.exe