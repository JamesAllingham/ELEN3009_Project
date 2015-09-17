#include "GameLogic.h"
#include <iostream>

GameLogic::GameLogic () : _user_interface(), _entities(), _player_ptr(new Ship)
{
	//std::cout << "constructor" << std::endl;
	Entity::setMapLimits(_MAX_X,_MAX_Y);
	//std::cout << "setMapLimits" << std::endl;
	//_player_ptr = shared_ptr<Ship> (new Ship);
	_entities.addEntity(_player_ptr);
	runGame();
}

void GameLogic::runGame() {
	std::cout << "runGame" << std::endl;
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
	
	createEntities();
	
	//ugly logic, needs to be rewritten, shouldn't be calculating dt
	auto old_x = _player_ptr->character().x;
	
	for (auto entity_ptr: _entities){
		entity_ptr->move(delta_time);
	}	
	
	auto delta_x = _player_ptr->character().x - old_x;
	// re-center the view on the ship in the x-direction
	_user_interface.moveWindow(delta_x);
}

void GameLogic::createEntities () {

	while (Flyer::numberOfFlyers() < 15) {
		//std::cout << "creating flyers" << std::endl;
		//shared_ptr<Flyer> flyer_ptr = make_shared<Flyer>();
		//std::cout << "adding to vector" << std::endl;
		_entities.addEntity(shared_ptr<Flyer> (new Flyer));
		std::cout << "number of entities = " << _entities.numberOfEntities() << std::endl;
	}
}