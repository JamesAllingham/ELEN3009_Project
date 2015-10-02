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
using sf::Font;
using sf::Text;
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

using std::to_string;

/**
* UserInterface class - contains all of the functionality for interacting with the player of the game.
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
	void render(list<Character>& characters, list<int>& status);	
	/**
    * convertedEvents() function converts polled events to non-SFML format. 
	* This function facilitates decoupling of GamleLogic from SFML by converting a SFML::Event object to an Events object. 
    * @return the list of converted Events.
    */
	list<Events> convertedEvents() {return _events;};	
	/**
    * closeWindow() function closes the game window. 
	* No arguments or return value.
    */
	void closeWindow();
	/**
    * moveWindow() function moves the game window along the map along the x-axis allowing the map to be scrollable. 
    * @param delta_x is a float containing the amount to move the window by.
    */
	void moveWindow(float delta_x);	
	/**
    * processEvents() function handles all user input by polling for the events that have taken place since the last call.
	* No arguments or return value.
    */
	void processEvents();
	/**
    * ConvertToSFMLVector() function converts Vector2f to sf::Vector2f for use with SFML functions.
	* @param vector_in Vector2f to be converted to sf::Vector2f.
	* @return a sf::Vector2f version of vector_in.
    */
	sf::Vector2f ConvertToSFMLVector (Vector2f vector_in) { return sf::Vector2f(vector_in.x, vector_in.y); };
	
private:
	/**
    * Create and draw a sf::Sprite for each of the characters that must be rendered.
	* @param characters a list of Character objects to be drawn.
    */
	void processTextures(list<Character>& characters);
	/**
    * Draw a sprite on both the map and mini-map.
	* @param texture a Sprite to draw.
    */
	void drawSprite(const Sprite& texture);
	void drawText(Text& text, int text_to_display, const sf::Vector2f& text_position);
	void processStatusMap(list<int>& status);
	
	list<Events> _events;
	RenderWindow _game_window;
	View _camera;
	View _mini_map;
	View _ship_status_map;
	ResourceHolder<Texture,EntityID> _textures;
	Sprite _background;
	RectangleShape _focusWindow;	

	list<EntityID> _status_map_states;
	Font _text_font;
	
	static constexpr const float _CAMERA_X_OFFSET = 2000.f;
	static constexpr const float _CAMERA_Y_OFFSET = 0.f;
	static constexpr const float _CAMERA_WIDTH = 800.f;
	static constexpr const float _CAMERA_HEIGHT = 600.f;
	static constexpr const float _CAMERA_X_POS_RATIO = 0.f;
	static constexpr const float _CAMERA_Y_POS_RATIO = 0.2f;
	static constexpr const float _CAMERA_WIDTH_RATIO = 1.f;
	static constexpr const float _CAMERA_HEIGHT_RATIO = 0.8f;
	static constexpr const float _MAP_X_OFFSET = 0.f;
	static constexpr const float _MAP_Y_OFFSET = 0.f;
	static constexpr const float _MAP_WIDTH = 4800.f;
	static constexpr const float _MAP_HEIGHT = 600.f;
	static constexpr const float _MINI_MAP_X_POS_RATIO = 0.1f;
	static constexpr const float _MINI_MAP_Y_POS_RATIO = 0.f;
	static constexpr const float _MINI_MAP_WIDTH_RATIO = 0.8f;
	static constexpr const float _MINI_MAP_HEIGHT_RATIO = 0.175f;
	static constexpr const float _STATUS_MAP_SPRITES_X_OFFSET = 15.f;
	static constexpr const float _STATUS_MAP_SPRITES_Y_OFFSET = 5.f;
	static constexpr const float _STATUS_MAP_TEXT_X_OFFSET = 40.f;
	static constexpr const float _STATUS_MAP_TEXT_Y_OFFSET = 5.f;
	static constexpr const float _STATUS_MAP_STATES_X_OFFSET = 0.f;
	static constexpr const float _STATUS_MAP_STATES_Y_OFFSET = 30.f;
	static constexpr const float _TEXT_SIZE = 20.f;
};
#endif