#include "EntityHolder.h"

list<Character> EntityHolder::characters()
{
	list<Character> character_list;
	
	for (auto entity_ptr : _entities)
	{
		character_list.push_back(entity_ptr->character());
	}
	
	return character_list;
}
