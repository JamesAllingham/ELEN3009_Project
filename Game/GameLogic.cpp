#include "GameLogic.h"

GameLogic::GameLogic () : _user_interface(), _entities(), _player_ptr(new Ship)
{
	//std::cout << "constructor" << std::endl;
	Entity::setMapLimits(Vector2f(_MAX_X,_MAX_Y));
	_entities.addEntity(_player_ptr);
	runGame();
}

void GameLogic::runGame() {
	//std::cout << "runGame" << std::endl;
	StopWatch clock;
	clock.start();
	auto time_since_last_update = 0.f;
	auto time_per_frame = 1.0f/_FPS_LIMIT;
	
	while (_game_running) {
		//std::cout << "game running" << std::endl;
		time_since_last_update += clock.stop();
		clock.restart();
		
		while (time_since_last_update > time_per_frame) {
			//std::cout << "updating logic" << std::endl;
			update(time_per_frame);
			time_since_last_update -= time_per_frame;
		}
		list<Character> characters = _entities.characters();
		_user_interface.render(characters);
	}
}

void GameLogic::update(float delta_time) {
	// Event management
	handleUserInput();
	
	// Create any fliers needed so that there are always 16 on screen
	createEntities();
	
	// Move all entites based on their rules
	for (auto entity_ptr: _entities){
		entity_ptr->move(delta_time);
	}	
	
	// Collision detection
	manageCollisions();
	
	// Shoot with all entities that can shooting
	// for (auto entity_ptr: _entities)
	// {
		// entity_ptr->shoot();
	// }
	
	// re-center the view on the ship in the x-direction
	followPlayer();
}

void GameLogic::followPlayer()
{
	// This function needs to prevent flying off of the map
	_user_interface.moveWindow(_player_ptr->changeInPosition().x);
}

void GameLogic::handleUserInput()
{
	_user_interface.processEvents();
	list<Events> events_since_last_poll = _user_interface.convertedEvents();
	for (auto event : events_since_last_poll ) {
		switch (event) {
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
				// Handle player shooting homing missile - should probably target the closest flyer, I think this should be handled similarly to how we have done movemnt
				// We should change the state of the Ship based on these events and then later call the shoot() function which will behave differently based on the state
				// i.e. if a bool isShootingMissile is true or false which will be set by these events
				break;
			case Events::Space_Pressed:
			case Events::Space_Released:
				// Handle player shooting laser - should probably fire in a straight like in the direction of movement of the ship on the x-axis (can be found using Ship's changeInPosition() function)
				break;
			case Events::Window_Close:
				_user_interface.closeWindow();
				_game_running = false;
				break;
			default:
				break;
		}
	}
}

void GameLogic::manageCollisions()
{
	Collision collision;
	for (auto entity_itr1 = begin(_entities); entity_itr1 != prev(end(_entities)); entity_itr1++)
	{	
		for (auto entity_itr2 = next(entity_itr1); entity_itr2 != end(_entities); entity_itr2++)
		{
			if (collision.collision(*entity_itr1,*entity_itr2))
			{
				// This logic is only for demonstration purposes and needs to be rewritten
				if((*entity_itr1)->character().texture_ID == TextureID::Flyer)
				{
					_entities.eraseEntity(entity_itr1);
					_number_of_flyers_killed++;
					std::cout << "number of entities = " << _entities.numberOfEntities() << std::endl;
					entity_itr2 = prev(end(_entities));
				}
				else
				{
					_entities.eraseEntity(entity_itr2);					
				}
				// Actual logic will be something like:
				// Only need to check each interaction once
				// The following interactions are potentiall important
				// Flyer--Ship If the player crashes into a flyer then the game should end
				// Flyer--Laser If a Flyer is hit with a misile it should be distroyed and the number of flyers destroyed should be incremented, the laser should also be destroyed
				// Flyer--Homing Missile as above
				// Flyer--Flyer Maybe this should do something, but more likely we will allow flyers to pass through each other
				// Missile--Ship If the player is hit by a missile the game should end
				// Missile--Missile If two missiles collide they should be destroyed
				// Missile--Laser If the player hits a missile with their laser, they should be destroyed
				// Power Up--Ship If the player lands on a power up they should get a number of heat seeking missiles
				// Homing Missile--Missile If the players homin missile comes into contact with a missile maybe it should also be destoryed
				
			}
		}			
	}
}

void GameLogic::createEntities () {

	while (Flyer::numberOfFlyers() != 15) {
		//std::cout << "creating flyers" << std::endl;
		//shared_ptr<Flyer> flyer_ptr = make_shared<Flyer>();
		//std::cout << "adding to vector" << std::endl;
		_entities.addEntity(shared_ptr<Flyer> (new Flyer));
	}
}