#ifndef GAME_LOGIC
#define GAME_LOGIC

#include <list>
using std::list;

#include "UserInterface.h"
#include "Ship.h"
#inlcude "Flyer.h"
#include "Events.h"
#include "TextureID.h"
#include "StopWatch.h"

class GameLogic {

public:
	//Constructor needs to go to main screen, main screen leads to run game
	GameLogic ();
private:
	void runGame();
	void update(float delta_time);
	
	UserInterface _user_interface;
	Ship _player;
	Flyers _flyers;
	bool _game_running = true;
	
	static constexpr const auto _FPS_LIMIT = 120.f; //this should be a constant I think, we never want it to change. should also be static since it is common to all instances of the game. the constexpr is a c++11 keyword used to allow us to have this static const
};
#endif