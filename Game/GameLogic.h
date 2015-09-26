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

#include <SFML/System.hpp> // This is only temporary, using SFMLs Vector2f, but later will write a lightweight vector class to use instead
using sf::Vector2f;

class GameLogic {

public:
	//Constructor needs to go to main screen, main screen leads to run game
	GameLogic ();
private:
	void runGame();
	void update(float delta_time);
	void createEntities ();
	void handleCollisions ();
	void handleUserInput();
	void followPlayer();
	void endGame();
	
	UserInterface _user_interface;
	EntityHolder _entities;
	shared_ptr<Ship> _player_ptr;
	bool _game_running = true;
	static constexpr const auto _NUMBER_OF_FLYERS_TO_KILL = 5;
	static constexpr const auto _MAX_X = 4800.f;
	static constexpr const auto _MAX_Y = 600.f;	
	static constexpr const auto _MAX_ON_SCREEN_DISTANCE_FROM_PLAYER = 400.f;
	static constexpr const auto _FPS_LIMIT = 120.f; 
};
#endif
