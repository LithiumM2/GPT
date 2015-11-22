#include "Quadrangle.h"


Quadrangle::Quadrangle() : p1(Vec3<float>(0.f)), p2(Vec3<float>(0.f)), p3(Vec3<float>(0.f)), p4(Vec3<float>(0.f))
{
}

Quadrangle::Quadrangle(Vec3<float> p1_, Vec3<float> p2_, Vec3<float> p3_, Vec3<float> p4_) : p1(p1_), p2(p2_), p3(p3_), p4(p4_)
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

void Quadrangle::shrinkByDist ( float distance_ ) {
	Triangle t1 = Triangle ( p2, p1, p4 ); // T1;
	t1.shrinkByDistForQuad ( -distance_ );

	Triangle t2 = Triangle ( p2, p1, p3 ); // T2;
	t2.shrinkByDistForQuad ( -distance_ );

	Triangle t3 = Triangle ( p2, p4, p3 ); // T3;
	t3.shrinkByDistForQuad ( -distance_ );

	Triangle t4 = Triangle ( p1, p4, p3 ); // T4;
	t4.shrinkByDistForQuad ( -distance_ );

	p1 = t1.getPoints ( )[1];
	p2 = t2.getPoints ( )[0];
	p3 = t3.getPoints ( )[2];
	p4 = t4.getPoints ( )[1];
}

// Test si 2 quadrangle s'overlap (on les suppode de meme Z)
bool Quadrangle::intersect(Quadrangle q)
{
	return (Utils::isSegmentIntersect(p1.x, p1.y, p2.x, p2.y, q.p1.x, q.p1.y, q.p2.x, q.p2.y) ||
		Utils::isSegmentIntersect(p1.x, p1.y, p2.x, p2.y, q.p2.x, q.p2.y, q.p3.x, q.p3.y) ||
		Utils::isSegmentIntersect(p1.x, p1.y, p2.x, p2.y, q.p3.x, q.p3.y, q.p4.x, q.p4.y) ||
		Utils::isSegmentIntersect(p1.x, p1.y, p2.x, p2.y, q.p4.x, q.p4.y, q.p1.x, q.p1.y) ||

		Utils::isSegmentIntersect(p2.x, p2.y, p3.x, p3.y, q.p1.x, q.p1.y, q.p2.x, q.p2.y) ||
		Utils::isSegmentIntersect(p2.x, p2.y, p3.x, p3.y, q.p2.x, q.p2.y, q.p3.x, q.p3.y) ||
		Utils::isSegmentIntersect(p2.x, p2.y, p3.x, p3.y, q.p3.x, q.p3.y, q.p4.x, q.p4.y) ||
		Utils::isSegmentIntersect(p2.x, p2.y, p3.x, p3.y, q.p4.x, q.p4.y, q.p1.x, q.p1.y) ||

		Utils::isSegmentIntersect(p3.x, p3.y, p4.x, p4.y, q.p1.x, q.p1.y, q.p2.x, q.p2.y) ||
		Utils::isSegmentIntersect(p3.x, p3.y, p4.x, p4.y, q.p2.x, q.p2.y, q.p3.x, q.p3.y) ||
		Utils::isSegmentIntersect(p3.x, p3.y, p4.x, p4.y, q.p3.x, q.p3.y, q.p4.x, q.p4.y) ||
		Utils::isSegmentIntersect(p3.x, p3.y, p4.x, p4.y, q.p4.x, q.p4.y, q.p1.x, q.p1.y) ||

		Utils::isSegmentIntersect(p4.x, p4.y, p1.x, p1.y, q.p1.x, q.p1.y, q.p2.x, q.p2.y) ||
		Utils::isSegmentIntersect(p4.x, p4.y, p1.x, p1.y, q.p2.x, q.p2.y, q.p3.x, q.p3.y) ||
		Utils::isSegmentIntersect(p4.x, p4.y, p1.x, p1.y, q.p3.x, q.p3.y, q.p4.x, q.p4.y) ||
		Utils::isSegmentIntersect(p4.x, p4.y, p1.x, p1.y, q.p4.x, q.p4.y, q.p1.x, q.p1.y));
}

bool Quadrangle::isIn(Vec3<float> p)
{
	return Triangle(p1, p2, p3).isIn(p) || Triangle(p3, p1, p4).isIn(p);
}

bool Quadrangle::isIn(Quadrangle q)
{
	return isIn(q.p1) && isIn(q.p2) && isIn(q.p3) && isIn(q.p4);
}

bool Quadrangle::overlap(Quadrangle q)
{
	return isIn(q) || intersect(q) || q.isIn(*this);
}

Vec3<float> Quadrangle::getMinPoint()
{
	return p1.min(p2).min(p3).min(p4);
}
Vec3<float> Quadrangle::getMaxPoint()
{
	return p1.max(p2).max(p3).max(p4);
}

void Quadrangle::sortPoint()
{
	if (p1.x == p2.x || p1.x == p3.x || p1.x == p4.x) p1.x += 0.1f;
	if (p2.x == p3.x || p2.x == p4.x) p2.x -= 0.1f;
	if (p3.x == p4.x) p3.x += 0.1f;

	if (p1.y == p2.y || p1.y == p3.y || p1.y == p4.y) p1.y += 0.1f;
	if (p2.y == p3.y || p2.y == p4.y) p2.y -= 0.1f;
	if (p3.y == p4.y) p3.y += 0.1f;
	int cmp = 0;
	Vec3<float> up1(0.f), up2(0.f), down1(0.f), down2(0.f), tmp(0.f);
	if (p1.y > p2.y) ++cmp;
	if (p1.y > p3.y) ++cmp;
	if (p1.y > p4.y) ++cmp;
	if (cmp >= 2) up1 = p1;
	else down1 = p1;
	cmp = 0;
	if (p2.y > p1.y) ++cmp;
	if (p2.y > p3.y) ++cmp;
	if (p2.y > p4.y) ++cmp;
	if (cmp >= 2)
	{
		if (up1 == Vec3<float>(0.f))
			up1 = p2;
		else
			up2 = p2;
	}
	else
	{
		if (down1 == Vec3<float>(0.f))
			down1 = p2;
		else
			down2 = p2;
	}

	cmp = 0;
	if (p3.y > p1.y) ++cmp;
	if (p3.y > p2.y) ++cmp;
	if (p3.y > p4.y) ++cmp;
	if (cmp >= 2)
	{
		if (up1 == Vec3<float>(0.f))
			up1 = p3;
		else
			up2 = p3;
	}
	else
	{
		if (down1 == Vec3<float>(0.f))
			down1 = p3;
		else
			down2 = p3;
	}

	if (up1 == Vec3<float>(0.f))
		up1 = p4;
	else if (up2 == Vec3<float>(0.f))
		up2 = p4;
	else if (down1 == Vec3<float>(0.f))
		down1 = p4;
	else if (down2 == Vec3<float>(0.f))
		down2 = p4;

	if (down1.x > down2.x)
	{
		tmp = down1;
		down1 = down2;
		down2 = tmp;
	}

	if (up1.x > up2.x)
	{
		tmp = up1;
		up1 = up2;
		up2 = tmp;
	}
	p1 = down1;
	p2 = up1;
	p3 = up2;
	p4 = down2;
	
	//p2 =
}

bool Quadrangle::hasGoodNormal()
{
	return Vec3<float>::crossProduct(p4 - p1, p2 - p1).z > 0.f && Vec3<float>::crossProduct(p1 - p2, p3 - p2).z > 0.f  && Vec3<float>::crossProduct(p2 - p3, p4 - p3).z > 0.f && Vec3<float>::crossProduct(p3 - p4, p1 - p4).z > 0.f;
}
Quadrangle::~Quadrangle()
{
}
