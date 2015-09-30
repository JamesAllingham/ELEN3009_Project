#ifndef CHARACTER
#define CHARACTER

#include "EntityID.h"

#include "Vector2f.h"

/**
* Character class. 
* This class is the drawable representation of an Entity. 
* It is used to decouple the UserInterface from the GameLogic by only giving the UserInterface the information it needs to draw each entity i.e. the texture to use and it's position.
*/
class Character
{
public:
	/**
    * Constructor.
    * @param Entity_ID is the EntityID which describes the texture of the Character to be drawn by the UserInterface.
    * @param position is a Vector2f containing the position of the Character to be drawn by the UserInterface.
    */
	Character (EntityID Entity_ID, const Vector2f& position) : _Entity_ID(Entity_ID), _position(position) {};
	
	EntityID entityID() { return _Entity_ID; };
	Vector2f position() { return _position; };

private:	
	EntityID _Entity_ID;
    Vector2f _position;	
};

#endif