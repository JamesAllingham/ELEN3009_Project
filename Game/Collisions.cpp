#include "Collision.h"

bool Collision::collision(shared_ptr<Entity> entity1_ptr, shared_ptr<Entity> entity2_ptr)
{
	list<vector2f> polygon1_points = entity1_ptr->hitboxPoints();
	list<vector2f> polygon2_points = entity2_ptr->hitboxPoints();
	list<vector2f> polygon1_normals = normals(polygon1_points);
	list<vector2f> polygon2_normals = normals(polygon2_points);
	
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
list<Vector2f> Collision::normals(const list<vector2f>& polygon_points)
{
	list<Vector2f> normals;
	for (auto iter = begin(polygon_points); iter != end(polygon_points); iter++)
	{		
		vector2f = temp_normal(-next(iter)->y + iter->y,next(iter)->x - iter->x);
		temp_normal = temp_normal/sqrt(temp_normal.x*temp_normal.x + temp_normal.y*temp_normal.y);
		normals.push_back(temp_normal);
	}
	
	vector2f = temp_normal(-begin(polygon_points)->y + end(polygon_points)->y,begin(polygon_points)->x - end(polygon_points)->x);
	temp_normal = temp_normal/sqrt(temp_normal.x*temp_normal.x + temp_normal.y*temp_normal.y);
	normals.push_back(temp_normal);
	
	return normals;
}

// Calculate the maximum projection of any of the vectors to the points of the polygon onto the given normal vector
float Collision::maximumProjection(const list<vector2f>& polygon_points, const vector2f& polygon_normal)
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
float Collision::minimumProjection(const list<vector2f>& polygon_points, const vector2f& polygon_normal)
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
float Collision::dotProduct(const vector2f& vector1, const vector2f& vector2)
{
	return vector1.x*vector2.x + vector1.y*vector2.y;
}

