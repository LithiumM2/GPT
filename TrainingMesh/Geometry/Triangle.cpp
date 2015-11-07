#include "Triangle.h"


Triangle::Triangle(Vec3<float> _Points[3])
{
	for(int i=0;i<3;i++){
		Points[i]=_Points[i];
	}
}


float Triangle::area() const{
	
	float a = distance(Points[1],Points[2]);
	float b = distance(Points[0],Points[1]);
	float c = distance(Points[0],Points[2]);
	
	float s = 0.5f*(a+b+c);

	return sqrtf(s*(s-a)*(s-b)*(s-c));
}

float Triangle::perimeter() const{
	float a = distance(Points[1],Points[2]);
	float b = distance(Points[0],Points[1]);
	float c = distance(Points[0],Points[2]);

	return a+b+c;
}
	
void Triangle::shrink(float t){

	Vec3<float> pivot(0.f);
	for(int i=0;i<3;i++)
		pivot+=Points[i];
	pivot*=1.f/3.f;

	Mat4x4 matrice = Transform::Shrink(t,pivot).m;

	for(int i=0;i<3;i++)
	Points[i] = matrice*Points[i];
	
}

Triangle::~Triangle(void)
{
}
