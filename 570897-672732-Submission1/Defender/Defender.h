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
using sf::Keyboard;
using sf::Clock;
using sf::Time;
using sf::View;
using sf::FloatRect;
using sf::IntRect;

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
	void update( Time );
	//Render the game to the screen
	void render();
	
	RenderWindow _window;
	static constexpr const float _FPS_LIMIT = 120; //this should be a constant I think, we never want it to change. should also be static since it is common to all instances of the game. the constexpr is a c++11 keyword used to allow us to have this static const
	Ship _kestrel; //a nice FTL reference :)
	ResourceHolder<Texture,TextureID> _textures;
	View _camera;
	Sprite _background;
};

#endif