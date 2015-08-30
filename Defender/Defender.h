#ifndef DEFENDER
#define DEFENDER

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "ResourceHolder.h"
#include "Ship.h"

// for debugging purposes
#include <iostream> 

using sf::RenderWindow;
using sf::Texture;
using sf::Event;
using sf::VideoMode;
using sf::Sprite;

using std::runtime_error;
using std::cerr;

class Defender { //Perhaps we should rename this to Attacker or something since we are just making a defender like game

 public:

	//constructor
	Defender();
	//game loop
	void run();
	
	// Define some strongly typed enumerations which will act as the keys for the ResourceHolder objects
	enum class TextureID
	{
		Ship = 1,
		Lander,
		Misile,
		Laser,
		HeatSeakingLaser,
		SmartBomb,
		Landscape
	};

 private:

	//Handle all user input
	void process_events();
	//Update the game logic
	void update();
	//Render the game to the screen
	void render();
	
	RenderWindow _window;
	Ship _kestrel;
	Sprite _testSprite;
	
	ResourceHolder<Texture,TextureID> _textures;
};

#endif