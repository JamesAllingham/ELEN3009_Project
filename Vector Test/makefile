CFLAGS=-c -Wall -std=c++14
LFLAGS=-Wall -std=c++14
LPATH=-L..\gtest\lib -lgtest_main -lgtest
IPATH=-I..\gtest\include -I..\Game 
CC=g++
ATTACKERPATH:=..\Game
MAKE=mingw32-make
OBJS=main.o Vector2f_unit_tests.o
all: test.exe
test.exe: $(OBJS) 
	$(CC) $(OBJS) $(LFLAGS) $(LPATH) -o test.exe
main.o: main.cpp
	$(CC) $(CFLAGS) $(IPATH) main.cpp -o main.o
Vector2f_unit_tests.o: Vector2f_unit_tests.cpp $(ATTACKERPATH)\Vector2f.h
	$(CC) $(CFLAGS) $(IPATH) Vector2f_unit_tests.cpp -o Vector2f_unit_tests.o
clean:
	del *.o *.exe
clean_Attacker:
	del $(ATTACKERPATH)\*.o $(ATTACKERPATH)\*.exe