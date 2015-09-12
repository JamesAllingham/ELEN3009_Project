#ifndef CHARACTER
#define CHARACTER

#include "TextureID.h"

class Character
{
public:
	Character (TextureID type, float x, float y) : texture_ID(type), x(x), y(y) {};
	
	TextureID texture_ID;
    float x;
	float y;
};

#endif