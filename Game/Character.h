#ifndef CHARACTER
#define CHARACTER

#include "TextureID.h"

#include <SFML/System.hpp> // This is only temporary, using SFMLs Vector2f, but later will write a lightweight vector class to use instead
using sf::Vector2f;

class Character
{
public:
	//Character (TextureID type, float x, float y) : texture_ID(type), position(x,y) {};
	Character (TextureID type, const Vector2f& position) : texture_ID(type), position(position) {};
	
	TextureID texture_ID;
    Vector2f position;
};

#endif