#ifndef POWERUP
#define POWERUP

#include "Character.h"
#include "Entity.h"

#include "Vector2f.h"

#include <iostream> // For debugging

#include <memory>
using std::shared_ptr;

#include <ctime>

class Powerup : public Entity
{

	public:
		Powerup();
		~Powerup();
		
		//virtual void move(float delta_time) override {};
		virtual list<Vector2f> hitboxPoints() override;
		//virtual shared_ptr<Entity> shoot(float delta_time) {return shared_ptr<Entity> (nullptr);};
		virtual void collide(shared_ptr<Entity> collider) override;	
		
		static bool PowerupOnTheMap ();
		
	protected:    	
		float randomPosition (float max_position);
		
	private:		
		static const constexpr float _POWER_UP_WIDTH = 42;
		static const constexpr float _POWER_UP_HEIGHT = 48;
		static bool _powerup_on_the_map;
};	
#endif