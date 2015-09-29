#ifndef CHARACTER
#define CHARACTER

#include "EntityID.h"

#include "Vector2f.h"

class Character
{
public:
	Character (EntityID type, const Vector2f& position) : Entity_ID(type), position(position) {};
	
	EntityID Entity_ID;
    Vector2f position;	
};

#endif