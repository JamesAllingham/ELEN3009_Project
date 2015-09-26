#ifndef COLLISIONS
#define COLLISIONS

#include "Entity.h"

#include <SFML/System.hpp>
using sf::Vector2f;
#include <Memory>
using std::shared_ptr;
#include <list>
using std::list;
using std::begin;
using std::end;
using std::next;

using std::numeric_limits;

#include <cmath>

class Collision{
	
	public:		
		//Collision();
		
		bool collision(shared_ptr<Entity> entity1_ptr, shared_ptr<Entity> entity2_ptr) const;
		
	private:
	
		list<Vector2f> normals(const list<Vector2f>& polygon_points) const;
		float maximumProjection(const list<Vector2f>& polygon_points, const Vector2f& polygon_normal) const;
		float minimumProjection(const list<Vector2f>& polygon_points, const Vector2f& polygon_normal) const;
		float dotProduct(const Vector2f& vector1, const Vector2f& vector2) const;
	
};

// May need to add a vector class depending on Boost, for now will use sfml - actually this should not be a part of Collisions but should have its own file instead
// class Vector2f{
	
	// public:
	
	// private:
	
// };

// Will add this when there is time, will make the collisions more efficient
// class QuadTree {
	
	// public:
	
	// private:
	
// };
#endif