#pragma once
#include "../Vec3.h"
#include "Geometry.h"
#include <algorithm>
#include "../Transform/Transform.h"

class Triangle: public Geometry
{
protected:
	Vec3<float> Points[3];

public:
	Triangle(void):Geometry(){};
	Triangle(Vec3<float>[]);
	~Triangle(void);

	float area() const;
	float perimeter() const;
	void shrink(float t) ;

};

