#include "GameLogic.h"

GameLogic::GameLogic () : _user_interface(), _entities(), _player_ptr(new Ship)
{
	//std::cout << "constructor" << std::endl;
	Entity::setMapLimits(Vector2f(_MAX_X,_MAX_Y));
	//std::cout << "setMapLimits" << std::endl;
	//_player_ptr = shared_ptr<Ship> (new Ship);
	_entities.addEntity(_player_ptr);
	runGame();
}

void GameLogic::runGame() {
	//std::cout << "runGame" << std::endl;
	//UserInterface.drawCharacters(vector<characters>);
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
	_user_interface.processEvents();
	list<Events> events_since_last_poll = _user_interface.convertedEvents();
	for (auto event_iter : events_since_last_poll ) {
		switch (event_iter) {
			case Events::W_Pressed:
			case Events::W_Released:
			case Events::S_Pressed:
			case Events::S_Released:
			case Events::A_Pressed:
			case Events::A_Released:
			case Events::D_Pressed:
			case Events::D_Released:
				_player_ptr->controlMovement(event_iter);
				break;
			case Events::Window_Close:
				_user_interface.closeWindow();
				_game_running = false;
				break;
			default:
				break;
		}
	}
	
	// Create any fliers needed so that there are always 16 on screen
	createEntities();
	
	// Move all entites based on their rules
	for (auto entity_ptr: _entities){
		entity_ptr->move(delta_time);
	}	
	
	manageCollisions();
	
	// re-center the view on the ship in the x-direction
	_user_interface.moveWindow(_player_ptr->changeInPosition().x);
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
					std::cout << "number of entities = " << _entities.numberOfEntities() << std::endl;
					entity_itr2 = prev(end(_entities));
				}
				else
				{
					_entities.eraseEntity(entity_itr2);					
				}
				// Actual logic will be something like:
				// Only need to check each interaction once
				// switch((*entity_itr1)->character().texture_ID)
				// {
					// case (TextureID::Ship):
						// if ((*entity_itr1)->character().texture_ID == TextureID::Flyer)
						// {
							Do something 
						// }
						// else if ((*entity_itr1)->character().texture_ID == TextureID::Missile)
						// {
							Do something 
						// }
						
						// break;
					// case (TextureID::Flyer):
						// if ((*entity_itr1)->character().texture_ID == TextureID::Flyer)
						// {
							Do something 
						// }						
						// else if ((*entity_itr1)->character().texture_ID == TextureID::Laser)
						// {
							Do something 
						// }
						// else if ((*entity_itr1)->character().texture_ID == TextureID::Heat_Seeking_Missile)
						// {
							Do something 
						// }
						
						// break;
					// case (TextureID::Missile):
						// if ((*entity_itr1)->character().texture_ID == TextureID::Missile)
						// {
							Do something 
						// }
						// else if ((*entity_itr1)->character().texture_ID == TextureID::Heat_Seeking_Missile)
						// {
							Do something 
						// }
						
						// break;
					// case (TextureID::Laser):
						// if ((*entity_itr1)->character().texture_ID == TextureID::Missile)
						// {
							Do something 
						// }
						
						// break;
					// case (TextureID::Power_Up):
						// if ((*entity_itr1)->character().texture_ID == TextureID::Ship)
						// {
							Do something 
						// }						
						
						// break;
					// case (TextureID::Heat_Seeking_Missile):
						// if ((*entity_itr1)->character().texture_ID == TextureID::Heat_Seeking_Missile)
						// {
							Do something 
						// }
						// break;
					// default:
						// break;
				// }
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