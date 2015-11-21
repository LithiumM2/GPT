#pragma once

#include "Geometry.h"
#include "../Vec3.h"

# define M_PI           3.14159265358979323846  /* pi */

class Circle :
	public Geometry {

public:
	Vec3<float> center;
	float radius;

	Circle ( ) { center = Vec3<float> ( .0f ); radius = .0f; }
	Circle ( const Vec3<float> o, const float &r ) { center = o; radius = r; }
	
	float area ( ) const { return radius * radius * M_PI; }
	float perimeter ( ) const { return 2.0f * radius * M_PI; }
	void shrink ( float t ) { radius -= t; }
};

