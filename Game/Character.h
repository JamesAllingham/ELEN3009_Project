#ifndef CHARACTER
#define CHARACTER

#include "EntityID.h"

#include <SFML/System.hpp> // This is only temporary, using SFMLs Vector2f, but later will write a lightweight vector class to use instead
using sf::Vector2f;

class Character
{
public:
	Character (EntityID type, const Vector2f& position) : Entity_ID(type), position(position) {};
	
	EntityID Entity_ID;
    Vector2f position;	
};

#endif