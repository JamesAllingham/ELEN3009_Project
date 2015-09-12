//Create a random spawning point for the landers and the bombs

#ifndef SPAWNPOINT
#define SPAWNPOINT

#include <ctime>

#include "TextureID.h"

struct SpawnPoint
{
	SpawnPoint (TextureID type, float x, float y);
	
	Texture ID type;
	float x;
	float y;
};

#endif