#ifndef ENTITY
#define ENTITY

class Entity
{
public:
	void getCharacter ();
	void getPosition (_type.x, _type.y);
private:
	float _speed_of_entity;
	Character _type;
#endif