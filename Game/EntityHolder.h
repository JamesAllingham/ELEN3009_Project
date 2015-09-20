#ifndef ENTITY_HOLDER
#define ENTITY_HOLDER

#include <list>
using std::list;
#include <memory>
using std::shared_ptr;

#include <iostream> // For testing purposes

#include "Entity.h"
#include "Character.h"

using std::runtime_error;

using EntityholderIterator = list<shared_ptr<Entity>>::iterator;

class EntityHolder {

public:	
	

	EntityholderIterator begin() {return _entities.begin();};
	EntityholderIterator end() {return _entities.end();};
	list<Character> characters();
	void addEntity(shared_ptr<Entity> entity_ptr);
	EntityholderIterator eraseEntity(EntityholderIterator entity_itr);
	int numberOfEntities () {return _entities.size();};
	
private:	
	list<shared_ptr<Entity>> _entities;
	
};	
#endif