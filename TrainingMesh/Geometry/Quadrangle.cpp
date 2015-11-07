#include "Quadrangle.h"


Quadrangle::Quadrangle() : p1(Vec3<float>(0.f)), p2(Vec3<float>(0.f)), p3(Vec3<float>(0.f)), p4(Vec3<float>(0.f))
{
}

Quadrangle::Quadrangle(Vec3<float> p1_, Vec3<float> p2_, Vec3<float> p3_, Vec3<float> p4_) : p1(p1_), p2(p2_), p3(p3_), p4(p4_)
{
}

Quadrangle::Quadrangle(const Quadrangle& q) : p1(q.p1), p2(q.p2), p3(q.p3), p4(q.p4)
{
}

float Quadrangle::area() const
{
	
	float a = distance(p1, p2);
	float b = distance(p2, p3);
	float c = distance(p3, p4);
	float d = distance(p4, p1);
	float p = distance(p1, p3);
	float q = distance(p2, p4);
	//float s = (a + b + c + d) * 0.5;

	return(0.25f * sqrtf(4.f * p * p * q * q - (b * b + d * d - a * a - c * c) * (b * b + d * d - a * a - c * c)));


	//return 0.5 * sqrtf(Vec3<float>::dotProduct(p, p) * Vec3<float>::dotProduct(q, q) - (Vec3<float>::dotProduct(p, q) * Vec3<float>::dotProduct(p, q)));
}

float Quadrangle::perimeter() const
{
	return distance(p1, p2) + distance(p2, p3) + distance(p3, p4) + distance(p4, p1);
}

void Quadrangle::shrink(float t)
{
	Vec3<float> pivot = (p1+p2+p3+p4)*0.25f;

	Mat4x4 matrice = Transform::Shrink(t,pivot).m;

	p1 = matrice*p1;
	p2 = matrice*p2;
	p3 = matrice*p3;
	p4 = matrice*p4;
}

Quadrangle::~Quadrangle()
{
}
