#include "GameLogic.h"

GameLogic::GameLogic () : _user_interface(), _entities(), _player_ptr(make_shared<Ship>())
{
	Entity::setMapLimits(Vector2f(_MAX_X,_MAX_Y));
	Flyer::setTarget(_player_ptr);
	
	_entities.addEntity(_player_ptr);
	_shooting_entities.push_back(_player_ptr);
	_moving_entities.push_back(_player_ptr);
	
	srand(time(0));
	
	runGame();
}

void GameLogic::runGame() 
{
	StopWatch clock;
	clock.start();
	auto time_since_last_update = 0.f;
	auto time_per_frame = 1.0f/_FPS_LIMIT;
	
	while (_game_running)	{
		if (_game_paused)
		{
			clock.stop();
			handleUserInput();
			renderCurrentState();
			clock.start();
		}
		else 
		{
			time_since_last_update += clock.stop();
			clock.start();
		
			while (time_since_last_update > time_per_frame && !_game_paused) 
			{
				update(time_per_frame);
				time_since_last_update -= time_per_frame;
			}
			renderCurrentState();
		}

	}
}

void GameLogic::update(float delta_time) 
{
	// Event management
	handleUserInput();
	
	// Create any flyers and powerups needed
	createEntities();
	
	// Move all entities based on their rules
	for (auto moving_entity_ptr: _moving_entities)
	{
		moving_entity_ptr->move(delta_time);	
	}		
	
	// Collision detection
	handleCollisions();
	
	_player_ptr->setNearestTarget(_entities);
	
	// Shoot with all entities that can shoot
	for (auto shooting_entity_ptr: _shooting_entities)
	{
		shared_ptr<MovingEntity> moving_entity_ptr = shooting_entity_ptr->shoot(delta_time);
		if (moving_entity_ptr)
		{
			_entities.addEntity(moving_entity_ptr);
			_moving_entities.push_back(moving_entity_ptr);
		}
	}
	
	followPlayer();
	
	// End the game if the player has been destroyed
	if (_player_ptr->destroyed()) loseGame();
	else if (Flyer::numberOfFlyersKilled() == _NUMBER_OF_FLYERS_TO_KILL) winGame();
}

void GameLogic::renderCurrentState ()
{
	list<Character> characters = _entities.characters();
	_user_interface.render(characters, _player_ptr->status());
}

void GameLogic::followPlayer()
{
	_user_interface.moveWindow(_player_ptr->changeInPosition().x);
}

void GameLogic::handleUserInput()
{
	_user_interface.processEvents();
	list<Events> events_since_last_poll = _user_interface.convertedEvents();
	for (auto event : events_since_last_poll ) {
		switch (event) 
		{
			case Events::W_Pressed:
			case Events::W_Released:
			case Events::S_Pressed:
			case Events::S_Released:
			case Events::A_Pressed:
			case Events::A_Released:
			case Events::D_Pressed:
			case Events::D_Released:
				_player_ptr->controlMovement(event);
				break;
			case Events::E_Pressed:
			case Events::E_Released:			
			case Events::Space_Pressed:
			case Events::Space_Released:
			case Events::Q_Pressed:
			case Events::Q_Released:
				_player_ptr->controlShooting(event);
				break;
			case Events::P_Pressed:
				pauseGame();
				_user_interface.pausedGame();
				break;
			case Events::ESC_Pressed:
			case Events::Window_Close:
				endGame();
				break;
			default:
				break;
		}
	}
}

void GameLogic::handleCollisions()
{
	Collision collision(_entities.begin(),_entities.end());
	
	collision.manageCollisions();
	
	// Delete entities
	for (auto entity_itr = begin(_entities); entity_itr != end(_entities); )
	{
		if ((*entity_itr)->destroyed())
		{			
			entity_itr = _entities.eraseEntity(entity_itr);
		}
		else 
		{
			entity_itr++;
		}
	}
	
	for (auto entity_itr = begin(_moving_entities); entity_itr != end(_moving_entities); )
	{
		if ((*entity_itr)->destroyed())
		{
			entity_itr = _moving_entities.erase(entity_itr);
		}
		else 
		{
			entity_itr++;
		}
	}
	
	for (auto entity_itr = begin(_shooting_entities); entity_itr != end(_shooting_entities); )
	{
		if ((*entity_itr)->destroyed())
		{
			entity_itr = _shooting_entities.erase(entity_itr);
		}
		else 
		{
			entity_itr++;
		}
	}
}

void GameLogic::createEntities () 
{
	while (Flyer::numberOfFlyers() + Flyer::numberOfFlyersKilled() < _NUMBER_OF_FLYERS_TO_KILL && Flyer::numberOfFlyers() < _MAX_NUMBER_OF_FLYERS_ON_MAP) 
	{		
		shared_ptr<Flyer> flyer_ptr = make_shared<Flyer> ();
		_entities.addEntity(flyer_ptr);
		_shooting_entities.push_back(flyer_ptr);
		_moving_entities.push_back(flyer_ptr);
	}	
	
	if (!Powerup::powerupOnTheMap() ) _entities.addEntity(make_shared<Powerup> ());
}

void GameLogic::winGame()
{
	_user_interface.wonGame();
	pauseGame();
}

void GameLogic::loseGame()
{
	_user_interface.lostGame();
	pauseGame();
}

void GameLogic::endGame() 
{
	_user_interface.closeWindow();
	_game_running = false;
}