all: defender.exe
defender.exe: main.o
	g++ main.o defender.o ship.o -o defender.exe -L..\sfml\lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-graphics -lsfml-audio -Wall
main.o: main.cpp defender.o
	g++ -c .\main.cpp -I..\sfml\include
defender.o: defender.cpp ship.o
	g++ -c .\Defender.h .\Defender.cpp .\Ship.h -I..\sfml\include -std=c++11 -std=c++14
ship.o: Ship.cpp
	g++ -c .\Ship.cpp .\Ship.h -std=c++11 -std=c++14 -Wall -I..\sfml\include
clean:
	rm test.o test.exe