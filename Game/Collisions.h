#ifndef COLLISIONS
#define COLLISIONS

#include "Entity.h"
#include "EntityHolder.h"

#include "Vector2f.h"

#include <Memory>
using std::shared_ptr;
#include <list>
using std::list;
using std::begin;
using std::end;
using std::next;
using std::prev;
#include <limits>
using std::numeric_limits;

#include <cmath>

/**
* Collision class - responsible for collision detection using the separating axis theorem. 
*/
class Collision{
	
public:	
	/**
	* Constructor. creates the Collision object. 
	* @param begin_entity_itr is an EntityholderIterator for the start of the container of Entity objects to be checked for collisions. 
	* @param end_entity_itr is an EntityholderIterator for the end of the container of Entity objects to be checked for collisions. 
	*/
	Collision(const	EntityholderIterator& begin_entity_itr, const EntityholderIterator& end_entity_itr): _begin_entity_itr(begin_entity_itr), _end_entity_itr(end_entity_itr) {};	
	
	/**
	* manageCollisions() function which causes the collision algorithm to be run.		
	*/
	void manageCollisions();		
	
private:
	/**
	* collision() function which implements the separating axis theorem for two Entity objects.
	* @param entity1_ptr is a pointer to the first Entity in the collision check.
	* @param entity2_ptr is a pointer to the second Entity in the collision check.
	*/
	bool collision(shared_ptr<Entity> entity1_ptr, shared_ptr<Entity> entity2_ptr) const;
	list<Vector2f> normals(const list<Vector2f>& polygon_points) const;
	float maximumProjection(const list<Vector2f>& polygon_points, const Vector2f& polygon_normal) const;
	float minimumProjection(const list<Vector2f>& polygon_points, const Vector2f& polygon_normal) const;
	float dotProduct(const Vector2f& vector1, const Vector2f& vector2) const;
	
	EntityholderIterator _begin_entity_itr;
	EntityholderIterator _end_entity_itr;
	
};

// Will add this when there is time, will make the collisions more efficient
// class QuadTree {
	
	// public:
	
	// private:
	
// };
#endif