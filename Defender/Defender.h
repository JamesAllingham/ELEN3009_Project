#ifndef DEFENDER
#define DEFENDER

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;

class Defender {

 public:

	//constructor
	Defender();
	//game loop
	void run();

 private:

	//Handle all user input
	void process_events();
	//Update the game logic
	void update();
	//Render the game to the screen
	void render();
	
	RenderWindow _Window;
	CircleShape mPlayer;

};

#endif