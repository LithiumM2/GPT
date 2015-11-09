#pragma once

#include "../Vec3.h"
#include "Geometry.h"
#include <algorithm>
#include "../Transform/Transform.h"
#include <vector>

class Triangle : public Geometry {
protected:
	Vec3<float> Points[3];

public:
	Triangle ( void ) :Geometry ( ) { };
	Triangle ( Vec3<float> p1, Vec3<float> p2, Vec3<float> p3 );
	~Triangle ( void );

	float area ( ) const;
	float perimeter ( ) const;
	void shrink ( float t );

	Vec3<float>* getPoints ( ) { return Points; }

	//Triangle* divideIn2Triangles ( float low, float high );

};
