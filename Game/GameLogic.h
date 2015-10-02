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

#include <iostream> // For testing purposes

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
	void runGame();
	void update(float delta_time);
	void renderCurrentState ();
	void createEntities ();
	void handleCollisions ();
	void handleUserInput();
	void followPlayer();
	void endGame();
	void pauseGame () {_game_paused = !_game_paused;};
	
	UserInterface _user_interface;
	EntityHolder _entities;
	list<shared_ptr<MovingEntity>> _moving_entities;
	list<shared_ptr<ShootingMovingEntity>> _shooting_entities;
	shared_ptr<Ship> _player_ptr;
	bool _game_running = true;
	bool _game_paused = false;
	static constexpr const auto _NUMBER_OF_FLYERS_TO_KILL = 5;
	static constexpr const auto _MAX_X = 4800.f;
	static constexpr const auto _MAX_Y = 600.f;	
	static constexpr const auto _MAX_ON_SCREEN_DISTANCE_FROM_PLAYER = 400.f;
	static constexpr const auto _FPS_LIMIT = 120.f;

};
#endif
