CFLAGS=-c -Wall -std=c++14
LFLAGS=-Wall -std=c++14
LPATH=-L..\gtest\lib -lgtest_main -lgtest -L..\sfml\lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-graphics -lsfml-audio
IPATH=-I..\gtest\include -I..\Game -I..\sfml\include
CC=g++
ATTACKERPATH:=..\Game
MAKE=mingw32-make
OBJS=main.o unit_tests.o 
all: test.exe
test.exe: $(OBJS) 
	$(CC) $(OBJS) $(LFLAGS) $(LPATH) -o test.exe
main.o: main.cpp
	$(CC) $(CFLAGS) $(IPATH) main.cpp -o main.o
unit_tests.o: ResourceHolder_unit_tests.cpp 
	$(CC) $(CFLAGS) $(IPATH) ResourceHolder_unit_tests.cpp -o unit_tests.o
$(ATTACKERPATH)\GameLogic.o:
	$(MAKE) -C $(ATTACKERPATH) 
clean:
	del *.o *.exe
clean_Attacker:
	del $(ATTACKERPATH)\*.o $(ATTACKERPATH)\*.exe