#ifndef CHARACTER
#define CHARACTER

#include "TextureID.h"

class Character
{
public:
	Character (TextureID type, float x, float y) : _texture_ID(type), _x(x), _y(y) {};
	Character getCharacter() {return _entity};

private:
	TextureID _texture_ID;
    float _x;
	float _y;
	float _character_speed;
};

#endif