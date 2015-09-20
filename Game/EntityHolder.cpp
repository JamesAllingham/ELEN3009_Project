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

void EntityHolder::addEntity(shared_ptr<Entity> entity_ptr)
{
	if (entity_ptr)
	{
		_entities.push_back(entity_ptr);
		//std::cout << "number of entities = " << numberOfEntities() << std::endl;
	}
	 
}
	
EntityholderIterator EntityHolder::eraseEntity(EntityholderIterator entity_itr)
{
	
	//std::cout << "number of entities = " << numberOfEntities() << std::endl;
	return _entities.erase(entity_itr);
}
