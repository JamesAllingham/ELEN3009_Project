#ifndef ENTITY_HOLDER
#define ENTITY_HOLDER

#include <list>
using std::list;
#include <memory>
using std::shared_ptr;

#include "Entity.h"
#include "Character.h"

class EntityHolder {

public:	
	using EntityholderIterator = list<shared_ptr<Entity>>::iterator;

	EntityholderIterator begin() {return _entities.begin();};
	EntityholderIterator end() {return _entities.end();};
	list<Character> characters();
	void addEntity(shared_ptr<Entity> entity_ptr) {_entities.push_back(entity_ptr);};
	int numberOfEntities () {return _entities.size();};
	
private:	
	list<shared_ptr<Entity>> _entities;
	
};	
#endif