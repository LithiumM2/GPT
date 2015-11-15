#pragma once

#include <algorithm>
#include "../Vec3.h"
#include "../Transform/Transform.h"
#include "Geometry.h"
#include "Triangle.h"



class Quadrangle : public Geometry {

public:
	Vec3<float> p1, p2, p3, p4;
	Quadrangle ( );
	Quadrangle ( Vec3<float> p1_, Vec3<float> p2_, Vec3<float> p3_, Vec3<float> p4_ );
	Quadrangle ( const Quadrangle& q );

	float area ( ) const;
	float perimeter ( ) const;
	void shrink ( float t );

	void shrinkByDist ( float distance );

	~Quadrangle ( );
};

