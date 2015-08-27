all: defender.exe
test.exe: main.o
	g++ main.o defender.o -o defender.exe -L..\sfml\lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-graphics -lsfml-audio -Wall
test.o: main.cpp
	g++ -c .\main.cpp .\Defender.h .\Defender.cpp -I..\sfml\include
clean:
	rm main.o defender.exe