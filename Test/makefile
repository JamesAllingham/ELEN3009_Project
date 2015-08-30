CFLAGS=-c -Wall -std=c++14
LFLAGS=-Wall
LPATH=-L..\gtest\lib -lgtest_main -lgtest -L..\sfml\lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-graphics -lsfml-audio
IPATH=-I..\gtest\include -I..\Defender -I..\sfml\include
CC=g++
DEFENDERPATH:=..\Defender
MAKE=mingw32-make

all: test.exe
test.exe: main.o unit_tests.o $(DEFENDERPATH)\defender.o
	$(CC) main.o unit_tests.o $(DEFENDERPATH)\defender.o $(DEFENDERPATH)\ship.o $(LFLAGS) $(LPATH) -o test.exe
main.o: main.cpp
	$(CC) $(CFLAGS) $(IPATH) main.cpp -o main.o
unit_tests.o: ResourceHolder_unit_tests.cpp $(DEFENDERPATH)\Defender.h $(DEFENDERPATH)\defender.o 
	$(CC) $(CFLAGS) $(IPATH) ResourceHolder_unit_tests.cpp -o unit_tests.o
$(DEFENDERPATH)\defender.o:
	$(MAKE) -C $(DEFENDERPATH) 
clean:
	del *.o *.exe
#	del $(DEFENDERPATH)\*.o $(DEFENDERPATH)\*.exe