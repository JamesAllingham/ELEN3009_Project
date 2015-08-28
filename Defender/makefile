all: defender.exe
defender.exe: main.o
	g++ main.o defender.o -o defender.exe -L..\sfml\lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-graphics -lsfml-audio -Wall
main.o: main.cpp defender.o
	g++ -c .\main.cpp -I..\sfml\include
defender.o: defender.cpp 
	g++ -c ..\Defender.h ..\Defender.cpp -I..\sfml\include
clean:
	rm .\main.o 
	rm .\defender.o 
	rm .\defender.exe