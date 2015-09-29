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
#include <limits>
using std::numeric_limits;

#include <cmath>

class Collision{
	
	public:		
		Collision(const	EntityholderIterator& begin_entity_itr, const EntityholderIterator& end_entity_itr): _begin_entity_itr(begin_entity_itr), _end_entity_itr(end_entity_itr) {};	

		void manageCollisions();		
		
	private:
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