#pragma once
class Geometry
{
public:
	Geometry();
	virtual float area() const = 0;
	virtual float perimeter() const = 0;
	virtual float shrink(float size) const = 0;
	~Geometry();
};

