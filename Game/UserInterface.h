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

#include <iostream>

#include <list>
using std::list;

#include "ResourceHolder.h"
#include "Events.h"
#include "Character.h"
#include "EntityID.h"
#include "Vector2f.h"

using std::runtime_error;
using std::cerr;

using std::string;
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
    * Renders the game to the Window. 
	* The background and all of the sprites are drawn onto both the main map and mini map.
    * @param characters is a list of Character objects which need to be drawn. This includes the position and texture Entity.
    */
	void render(list<Character>& characters, list<int>& status);	
	/**
    * Converts polled events to non-SFML format. 
	* This function facilitates decoupling of GamleLogic from SFML by converting a SFML::Event object to an Events object. 
    * @return the list of converted Events.
    */
	list<Events> convertedEvents() {return _events;};	
	/**
    * Closes the game window. 
	* No arguments or return value.
    */
	void closeWindow();
	/**
    * Moves the game window along the map along the x-axis allowing the map to be scrollable. 
    * @param delta_x is a float containing the amount to move the window by.
    */
	void moveWindow(float delta_x);	
	/**
    * Handles all user input by polling for the events that have taken place since the last call.
	* No arguments or return value.
    */
	void processEvents();
	/**
    * Converts Vector2f to sf::Vector2f for use with SFML functions.
	* @param vector_in Vector2f to be converted to sf::Vector2f.
	* @return a sf::Vector2f version of vector_in.
    */
	sf::Vector2f convertToSFMLVector (Vector2f vector_in) { return sf::Vector2f(vector_in.x, vector_in.y); };
	/**
    * Handles the displaying for whether or not the game is paused.
	* No arguments or return value.
    */
	void pausedGame() {_game_paused = !_game_paused;};
	/**
    * Handles the displaying for whether or not the game is won.
	* No arguments or return value.
    */
	void wonGame() {_game_won = true;};
	/**
    * Handles the displaying for whether or not the game is lost.
	* No arguments or return value.
    */
	void lostGame() {_game_lost = true;};
	
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
	/**
    * handles all text displaying.
    */
	void drawText(string text_to_display, float text_size, const Vector2f& text_position);
	/**
    * displays the current information regarding the status of the ship.
    */
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
	
	bool _game_paused = false;
	bool _game_won = false;
	bool _game_lost = false;
	
	static constexpr const auto _CAMERA_X_OFFSET = 2000.f;
	static constexpr const auto _CAMERA_Y_OFFSET = 0.f;
	static constexpr const auto _CAMERA_WIDTH = 800.f;
	static constexpr const auto _CAMERA_HEIGHT = 600.f;
	static constexpr const auto _CAMERA_X_POS_RATIO = 0.f;
	static constexpr const auto _CAMERA_Y_POS_RATIO = 0.2f;
	static constexpr const auto _CAMERA_WIDTH_RATIO = 1.f;
	static constexpr const auto _CAMERA_HEIGHT_RATIO = 0.8f;
	static constexpr const auto _FOCUS_WINDOW_WIDTH = 800.f;
	static constexpr const auto _FOCUS_WINDOW_HEIGHT = 600.f;
	static constexpr const auto _FOCUS_WINDOW_OUTLINE_THICKNESS = -25.f;
	static constexpr const auto _MAP_X_OFFSET = 0.f;
	static constexpr const auto _MAP_Y_OFFSET = 0.f;
	static constexpr const auto _MAP_WIDTH = 4800.f;
	static constexpr const auto _MAP_HEIGHT = 600.f;
	static constexpr const auto _MINI_MAP_X_POS_RATIO = 0.1f;
	static constexpr const auto _MINI_MAP_Y_POS_RATIO = 0.f;
	static constexpr const auto _MINI_MAP_WIDTH_RATIO = 0.8f;
	static constexpr const auto _MINI_MAP_HEIGHT_RATIO = 0.175f;
	static constexpr const auto _STATUS_MAP_WIDTH_RATIO = 75.f;
	static constexpr const auto _STATUS_MAP_HEIGHT_RATIO = 100.f;
	static constexpr const auto _STATUS_MAP_SPRITES_X_OFFSET = 15.f;
	static constexpr const auto _STATUS_MAP_SPRITES_Y_OFFSET = 5.f;
	static constexpr const auto _STATUS_MAP_TEXT_X_OFFSET = 40.f;
	static constexpr const auto _STATUS_MAP_TEXT_Y_OFFSET = 5.f;
	static constexpr const auto _STATUS_MAP_STATES_X_OFFSET = 0.f;
	static constexpr const auto _STATUS_MAP_STATES_Y_OFFSET = 30.f;
	static constexpr const auto _STATUS_MAP_TEXT_SIZE = 20.f;
	static constexpr const auto _PAUSE_TEXT_X_OFFSET = 150.f;
	static constexpr const auto _PAUSE_TEXT_Y_OFFSET = 100.f;
	static constexpr const auto _PAUSE_GAME_TEXT_SIZE = 100.f;
	static constexpr const auto _END_GAME_TEXT_X_OFFSET = 100.f;
	static constexpr const auto _END_GAME_TEXT_Y_OFFSET = 0.f;
	static constexpr const auto _INFORMATION_TEXT_SIZE = 30.f;
	static constexpr const auto _INFORMATION_TEXT_X_OFFSET = 120.f;
	static constexpr const auto _INFORMATION_TEXT_Y_OFFSET = 450.f;
};
#endif