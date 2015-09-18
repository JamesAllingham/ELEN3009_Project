#include "Flyer.h"

Flyer::Flyer() : Entity{TextureID::Flyer, Vector2f(RandomPosition(mapLimits().x), RandomPosition(mapLimits().y)), Vector2f(75.f,75.f)} {
	
	//std::cout << "entering flyer constructor" <<std::endl;
	//_number_of_flyers = 0;
	//Entity{TextureID::Flyer, static_cast<float>(_rand_x), static_cast<float>(_rand_y), 75.f};
	_number_of_flyers++;
}

// shared_ptr<Flyer> Flyer::createFlyer() {
	// shared_ptr<Flyer> flyer_ptr = make_shared<Flyer>();
	// return flyer_ptr;
// }

void Flyer::move(float delta_time){
	
	//auto distance = delta_time * _velocity;
	//if (_moving_up) _player.y -= distance;
	//if (_moving_down) _player.y += distance;
	//if (_moving_left) _player.x -= distance;
	//if (_moving_right) _player.x += distance;
	
}

float Flyer::RandomPosition (float max_positon) {

	int rand_num;
	if (!_srand_called) {
		srand(time(0));
		_srand_called = true;
	}
	int tmp = static_cast<int>(max_positon);
	rand_num = rand()%tmp;
	return static_cast<float>(rand_num);
}

//Need to initialise this in the .cpp file
int Flyer::_number_of_flyers = 0;
bool Flyer::_srand_called = false;