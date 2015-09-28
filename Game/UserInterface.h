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

using std::runtime_error;
using std::cerr;

/**
* UserInterface class. 
* This class contains all of the functionality for interacting with the player of the game.
* This includes both getting user input in the form of events and displaying the game (drawing the sprites).
* This is the only class which uses SFML.
*/
class UserInterface {

public:
	/**
    * Constructor.
    * Does not take any arguments. 	
	* Loads all of the expensive textures ahead of their use. 
	* Sets up the Window.  
    */
	UserInterface(); 	
	
	/**
    * render() function renders the game to the Window. 
	* The background and all of the sprites are drawn onto both the main map and mini map.
    * @param characters is a list of Character objects which need to be drawn. This includes the position and texture Entity.
    */
	void render(list<Character>& characters);	
	/**
    * convertedEvents() function converts polled events to non-SFML format. 
	* This function facilitates decoupling of GamleLogic from SFML by converting a SFML::Event object to an Events object. 
    * @return the list of converted Events.
    */
	list<Events> convertedEvents() {return _events;};	
	/**
    * closeWindow() function closes the game window. 
    */
	void closeWindow();
	/**
    * moveWindow() function moves the game window along the map along the x-axis allowing the map to be scrollable. 
    * @param delta_x is a float containing the amount to move the window by.
    */
	void moveWindow(float delta_x);	
	/**
    * processEvents() function handles all user input by polling for the events that have taken place since the last call.
    */
	void processEvents();
	
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