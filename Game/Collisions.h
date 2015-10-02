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
	* Runs the collision detection algorithm		
	*/
	void manageCollisions();		
	
private:
	/**
	* Implements the separating axis theorem for two Entity objects.
	* @param entity1_ptr is a pointer to the first Entity in the collision check.
	* @param entity2_ptr is a pointer to the second Entity in the collision check.
	*/
	bool collision(shared_ptr<Entity> entity1_ptr, shared_ptr<Entity> entity2_ptr) const;
	/**
	* Generates left normals of the vectors connecting the given points.
	* @param polygon_points is a list of Vector2f points that connect the edges of a polygon. The points must be given in a clockwise direction.
	* @return a Vector2f list containing the normal vectors
	*/
	list<Vector2f> normals(const list<Vector2f>& polygon_points) const;
	/**
	* Calculates the maximum projection of a set of vectors onto a normal vector
	* @param polygon_points is a list of Vector2f points that connect the edges of a polygon.
	* @param polygon_normal is a Vector2f containing the normal vector on to which to do the projection.
	* @return a float containing the magnitude of the maximum projection. Must be greater than or equal to 0.
	*/
	float maximumProjection(const list<Vector2f>& polygon_points, const Vector2f& polygon_normal) const;
	/**
	* Calculates the minimum projection of a set of vectors onto a normal vector
	* @param polygon_points is a list of Vector2f points that connect the edges of a polygon.
	* @param polygon_normal is a Vector2f containing the normal vector on to which to do the projection.
	* @return a float containing the magnitude of the minimum projection. Must be greater than or equal to 0.
	*/
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