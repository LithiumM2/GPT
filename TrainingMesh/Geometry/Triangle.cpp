#include "Triangle.h"


Triangle::Triangle ( Vec3<float> p1_, Vec3<float> p2_, Vec3<float> p3_ )
{
	Points[0] = p1_;
	Points[1] = p2_;
	Points[2] = p3_;
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

void Triangle::shrinkByDist ( float distance_ ) {
	Vec3<float> Q; // Centre du cercle inscris
	float a,b,c,
		R, // Rayon du cercle inscris
		k; // Coef d'homotéthie
	Vec3<float>
		A = Points[0],
		B = Points[1],
		C = Points[2];

	a = distance ( B, C );
	b = distance ( C, A );
	c = distance ( A, B );

	Q =
		( a / ( a + b + c ) ) * A +
		( b / ( a + b + c ) ) * B +
		( c / ( a + b + c ) ) * C;

	R = 2 * area ( ) / perimeter ( );

	k = R / ( R - distance_ );

	/*Points[0] = A + ( k - 1 ) * ( A - Q );
	Points[1] = B + ( k - 1 ) * ( B - Q );
	Points[2] = C + ( k - 1 ) * ( C - Q );*/
	Points[0] = A + ( k - 1 ) * ( Q - A );
	Points[1] = B + ( k - 1 ) * ( Q - B );
	Points[2] = C + ( k - 1 ) * ( Q - C );
}

void Triangle::shrinkByDistForQuad ( float distance_ ) {
	Vec3<float> Q; // Centre du cercle inscris
	float a, b, c,
		R, // Rayon du cercle inscris
		k; // Coef d'homotéthie
	Vec3<float>
		A = Points[0],
		B = Points[1],
		C = Points[2];

	a = distance ( B, C );
	b = distance ( C, A );
	c = distance ( A, B );

	Q =
		( a / ( a + b + c ) ) * A +
		( b / ( a + b + c ) ) * B +
		( c / ( a + b + c ) ) * C;

	R = 2 * area ( ) / perimeter ( );

	k = R / ( R - distance_ );

	Points[0] = A + ( k - 1 ) * ( A - Q );
	Points[1] = B + ( k - 1 ) * ( B - Q );
	Points[2] = C + ( k - 1 ) * ( C - Q );
}



Triangle::~Triangle(void)
{
}
