#pragma once

#include "Geometry.h"
#include <algorithm>
#include "../Vec3.h"
#include "../Transform/Transform.h"

class Quadrangle : public Geometry {
protected:
	Vec3<float> p2, p3, p4;

public:
	Vec3<float> p1;
	Quadrangle ( );
	Quadrangle ( Vec3<float> p1_, Vec3<float> p2_, Vec3<float> p3_, Vec3<float> p4_ );
	Quadrangle ( const Quadrangle& q );

	float area ( ) const;
	float perimeter ( ) const;
	void shrink ( float t );

	~Quadrangle ( );
};

