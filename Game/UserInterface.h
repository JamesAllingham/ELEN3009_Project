#ifndef USER_INTERFACE
#define USER_INTERFACE

#include <SFML/Window.hpp>
using sf::VideoMode;
#include <SFML/System.hpp>
using sf::Event;
using sf::Keyboard;
#include <SFML/Graphics.hpp>
using sf::RenderWindow;
using sf::Sprite;
using sf::View;
using sf::Texture;
using sf::FloatRect;
using sf::IntRect;
using sf::RectangleShape;
using sf::Color;
#include <SFML/Audio.hpp>

#include <list>
using std::list;

#include "ResourceHolder.h"
#include "Events.h"
#include "Character.h"
#include "EntityID.h"
#include "Vector2f.h"

using std::runtime_error;
using std::cerr;

class UserInterface {

public:

	UserInterface(); 
	//Render the game to the screen
	void render(list<Character>& characters);
	//Convert polled events to non-SFML format
	list<Events> convertedEvents() {return _events;};
	//Close window
	void closeWindow();
	void moveWindow(float delta_x);	
	//Handle all user input
	void processEvents();
	sf::Vector2f ConvertToSFMLVector (Vector2f vector_in) { return sf::Vector2f(vector_in.x, vector_in.y); };
	
private:
	
	void processTextures(list<Character>& characters);
	void drawSprite(const Sprite& texture);
	
	list<Events> _events;
	RenderWindow _game_window;
	View _camera;
	View _mini_map;
	ResourceHolder<Texture,EntityID> _textures;
	Sprite _background;
	RectangleShape _focusWindow;
};
#endif