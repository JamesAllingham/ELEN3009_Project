#include "GameLogic.h"

GameLogic::GameLogic () : _user_interface(), _player_ptr(new Ship), _entites() 
{
	_entites.addEntity(_player_ptr);
	runGame();
}

void GameLogic::runGame() {
	//UserInterface.drawCharacters(vector<characters>);
	StopWatch clock;
	clock.start();
	auto time_since_last_update = 0.f;
	auto time_per_frame = 1.0f/_FPS_LIMIT;
	
	while (_game_running) {
		
		time_since_last_update += clock.stop();
		clock.restart();
		
		while (time_since_last_update > time_per_frame) {
			update(time_per_frame);
			time_since_last_update -= time_per_frame;
		}
		list<Character> characters = _entites.characters();
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
	
	//ugly logic, needs to be rewritten, shouldn't be calculating dt
	auto old_x = _player_ptr->character().x;
	
	for (auto entity_ptr: _entites){
		entity_ptr->move(delta_time);
	}	
	
	auto delta_x = _player_ptr->character().x - old_x;
	// re-center the view on the ship in the x-direction
	_user_interface.moveWindow(delta_x);
}