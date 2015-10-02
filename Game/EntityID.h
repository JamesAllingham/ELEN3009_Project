#ifndef ENTITY_ID
#define ENTITY_ID

/**
* EntityID strongly typed enumeration class - used to enumerate the different types of entities.
* For example used as a key (id) with the ResourceHolder class.
*/
enum class EntityID
{
	Homing_Missile,
	Smart_Bomb,
	Missile,
	Ship,		
	Flyer,
	Laser,
	Landscape,
	Power_Up,
	Lives
};

#endif