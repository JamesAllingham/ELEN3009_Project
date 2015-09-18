#include "Flyer.h"

Flyer::Flyer() : Entity{TextureID::Flyer, Vector2f(RandomPosition(mapLimits().x), RandomPosition(mapLimits().y)), Vector2f(75.f,75.f)} {
	
	//std::cout << "entering flyer constructor" <<std::endl;
	//_number_of_flyers = 0;
	//Entity{TextureID::Flyer, static_cast<float>(_rand_x), static_cast<float>(_rand_y), 75.f};
	std::cout << "Create flyer" << std::endl;
	_number_of_flyers++;
}

Flyer::~Flyer()
{
	_number_of_flyers--;
	//std::cout << "Number of Flyers: " << _number_of_flyers << std::endl;
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

// The reason that I have made this a vitual function is that in future we might want to make the flyer and ship have differently shaped hit boxes
list<Vector2f> Flyer::hitboxPoints()
{
	list<Vector2f> hitbox_points;
	Vector2f top_left_point = character().position;
	// Add the points in a clockwise direction
	hitbox_points.push_back(Vector2f(top_left_point.x, top_left_point.y));
	hitbox_points.push_back(Vector2f(top_left_point.x + _width, top_left_point.y));
	hitbox_points.push_back(Vector2f(top_left_point.x + _width, top_left_point.y - _height));
	hitbox_points.push_back(Vector2f(top_left_point.x, top_left_point.y - _height));
	return hitbox_points;
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