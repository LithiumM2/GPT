#include "Triangle.h"
#include <iostream>


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
	
		std::cout<<"ici : "<<c<<"\n";
	
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

	Mat4x4 matrice = Transform::scale(t,t,t).m;

	for(int i=0;i<3;i++)
	Points[i] = matrice*Points[i];
	
}

Triangle::~Triangle(void)
{
}
