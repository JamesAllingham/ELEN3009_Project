#ifndef ENTITY_HOLDER
#define ENTITY_HOLDER

#include <list>
using std::list;
#include <memory>
using std::shared_ptr;

#include <iostream> // For testing purposes

#include "Entity.h"
#include "Character.h"

using EntityholderIterator = list<shared_ptr<Entity>>::iterator;
/**
* EntityHolder class - manages the Entity objects in the game.
* This class stores a collection of shared pointers to all of the Entity objects in the game and can perform actions on this list.
*/
class EntityHolder {

public:	
	/**
    * When used with end() allows the Entity objects to be iterated through.
    * @return an EntityholderIterator to the begining of the collection.
	* @see end()
    */
	EntityholderIterator begin() {return _entities.begin();};
	/**
    * When used with begin() allows the Entity objects to be iterated through.
    * @return an EntityholderIterator to the end of the collection.
	* @see begin()
    */
	EntityholderIterator end() {return _entities.end();};	
	/**
    * Adds a shared pointer to an Entity to the collection.
    * @param entity_ptr a shared pointer to be added to the collection.
    */
	void addEntity(shared_ptr<Entity> entity_ptr);
	/**
    * Removes the shared pointer of a specific Entity from the collection.
    * @param entity_itr the EntityholderIterator corresponding to the Entity to be removed.
	* @return an EntityholderIterator after the one that was deleted. This facilitates the idiomatic c++ for loop to delete items with iterators.
    */
	EntityholderIterator eraseEntity(EntityholderIterator entity_itr);
	/**
    * Keeps track of the number of Entity objects in the game. 
	* @return an int containing the number of elements in the collection.
    */
	int numberOfEntities () {return _entities.size();};
	/**
    * Converts the collection of Entity pointers to a list of Character objects to be rendered by the user interface.
    * @return a list of Character objects corresponding to the Entity objects.
    */
	list<Character> characters();
	
private:	
	list<shared_ptr<Entity>> _entities;
	
};	
#endif