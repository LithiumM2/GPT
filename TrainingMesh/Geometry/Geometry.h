#pragma once
class Geometry
{
public:
	Geometry();
	virtual float area() const = 0;
	virtual float perimeter() const = 0;
	virtual void shrink(float size) = 0;
	~Geometry();
};

