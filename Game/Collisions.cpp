#include "Collisions.h"

bool Collision::collision(shared_ptr<Entity> entity1_ptr, shared_ptr<Entity> entity2_ptr) const
{
	list<Vector2f> polygon1_points = entity1_ptr->hitboxPoints();
	list<Vector2f> polygon2_points = entity2_ptr->hitboxPoints();
	list<Vector2f> polygon1_normals = normals(polygon1_points);
	list<Vector2f> polygon2_normals = normals(polygon2_points);
	
	//test for collision using polygon1's normals
	for (auto normal : polygon1_normals)
	{
		auto separated = maximumProjection(polygon1_points,normal) < minimumProjection(polygon2_points,normal) || maximumProjection(polygon2_points,normal) < minimumProjection(polygon1_points,normal);
		if (separated) return false;
	}
	
	//test for collision using polygon2's normals
	for (auto normal : polygon2_normals)
	{
		auto separated = maximumProjection(polygon1_points,normal) < minimumProjection(polygon2_points,normal) || maximumProjection(polygon2_points,normal) < minimumProjection(polygon1_points,normal);
		if (separated) return false;
	}
	
	return true;
} 

// Calculate the normal vectors for each vector linking the polygon (in the clockwise direction)
list<Vector2f> Collision::normals(const list<Vector2f>& polygon_points) const
{
	list<Vector2f> normals;
	for (auto iter = begin(polygon_points); iter != end(polygon_points); iter++)
	{		
		Vector2f temp_normal(-next(iter)->y + iter->y,next(iter)->x - iter->x);
		temp_normal = temp_normal/sqrtf(temp_normal.x*temp_normal.x + temp_normal.y*temp_normal.y);
		normals.push_back(temp_normal);
	}
	
	Vector2f temp_normal(-begin(polygon_points)->y + end(polygon_points)->y,begin(polygon_points)->x - end(polygon_points)->x);
	temp_normal = temp_normal/sqrtf(temp_normal.x*temp_normal.x + temp_normal.y*temp_normal.y);
	normals.push_back(temp_normal);
	
	return normals;
}

// Calculate the maximum projection of any of the vectors to the points of the polygon onto the given normal vector
float Collision::maximumProjection(const list<Vector2f>& polygon_points, const Vector2f& polygon_normal) const
{
	auto maximum = 0.f;
	for (const auto& point : polygon_points)
	{
		auto temp_maximum = dotProduct(point,polygon_normal);
		if (temp_maximum > maximum) maximum = temp_maximum;
	}
	return maximum;
}

// Calculate the minimum projection of any of the vectors to the points of the polygon onto the given normal vector
float Collision::minimumProjection(const list<Vector2f>& polygon_points, const Vector2f& polygon_normal) const
{
	auto minimum = numeric_limits<float>::max();
	for (const auto& point : polygon_points)
	{
		auto temp_minimum = dotProduct(point,polygon_normal);
		if (temp_minimum < minimum) minimum = temp_minimum;
	}
	return minimum;
}

// Return the dotProduct of two vectors - will probably get removed or moved to vector class
float Collision::dotProduct(const Vector2f& vector1, const Vector2f& vector2) const
{
	return vector1.x*vector2.x + vector1.y*vector2.y;
}

void Collision::manageCollisions()
{
	// set entites to be delted
	for (auto entity_itr1 = _begin_entity_itr; entity_itr1 != prev(_end_entity_itr); entity_itr1++)
	{	
		for (auto entity_itr2 = next(entity_itr1); entity_itr2 != _end_entity_itr; entity_itr2++)
		{
			if (collision(*entity_itr2,*entity_itr1))
			{		
				(*entity_itr2)->collide(*entity_itr1);	
				(*entity_itr1)->collide(*entity_itr2);
			}
		}			
	}	
	
}

