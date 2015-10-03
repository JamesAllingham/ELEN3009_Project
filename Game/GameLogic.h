#ifndef GAME_LOGIC
#define GAME_LOGIC

#include <list>
using std::list;
using std::begin;
using std::end;
using std::next;
#include <memory>
using std::shared_ptr;
using std::make_shared;
#include <ctime>

#include <iostream>

#include "UserInterface.h"
#include "Ship.h"
#include "Flyer.h"
#include "Events.h"
#include "EntityID.h"
#include "StopWatch.h"
#include "EntityHolder.h"
#include "Collisions.h"
#include "Powerup.h"

#include "Vector2f.h"

/**
* GameLogic class - contains all of the functionality for running the game.
* To play the game only this class and the SFML DLLs are needed.
*/
class GameLogic {

public:
	/**
    * Constructor.
    * Does not take any arguments. 	
	* Completes the required game set-up.
	* Then automatically runs the game.  
    */
	GameLogic ();
	
private:
	/**
	* Runs the game loop.
	* No arguments or return value.
	*/
	void runGame();
	/**
	* Updates the state of the game based on how much time has passed.
	* @param delta_time a float containing the amount of time since the last function call.
	*/
	void update(float delta_time);
	/**
	* Tells the graphic interface to render the current state of the game.
	* No arguments or return value.
	*/
	void renderCurrentState ();
	/**
	* Makes sure there are enough Flyer and Powerup objects on the map.
	* No arguments or return value.
	*/
	void createEntities();
	/**
	* Checks for collisions and then cleans up after the collisions take place.
	* No arguments or return value.
	*/
	void handleCollisions();
	/**
	* Polls for user input and converts it from sf::Event to Events.
	* No arguments or return value.
	*/
	void handleUserInput();
	/**
	* Refocuses the camera on the Ship.
	* No arguments or return value.
	*/
	void followPlayer();
	/**
	* Begins the pausing game sequence.
	* No arguments or return value.
	*/
	void pauseGame() {_game_paused = !_game_paused;};
	/**
	* Begins the winning game sequence.
	* No arguments or return value.
	*/
	void winGame();
	/**
	* Begins the losing the game sequence.
	* No arguments or return value.
	*/
	void loseGame();
	/**
	* Closes the game window and ends the game.
	* No arguments or return value.
	*/
	void endGame();
	
	UserInterface _user_interface;
	EntityHolder _entities;
	list<shared_ptr<MovingEntity>> _moving_entities;
	list<shared_ptr<ShootingMovingEntity>> _shooting_entities;
	shared_ptr<Ship> _player_ptr;
	bool _game_running = true;
	bool _game_paused = false;
	
	static constexpr const auto _NUMBER_OF_FLYERS_TO_KILL = 15;
	static constexpr const auto _MAX_NUMBER_OF_FLYERS_ON_MAP = 10;
	static constexpr const auto _MAX_X = 4800.f;
	static constexpr const auto _MAX_Y = 600.f;	
	static constexpr const auto _MAX_ON_SCREEN_DISTANCE_FROM_PLAYER = 400.f;
	static constexpr const auto _FPS_LIMIT = 120.f;

};
#endif
