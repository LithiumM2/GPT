#include "Mesh/Primitives.h"
#include "Vec3.h"
#include "Mesh/Mesh.h"
#include "MeshWriter.h"
#include "Transform\Transform.h"
#include "Geometry\Quadrangle.h"
#include "Geometry\Triangle.h"

int main(int argc, char ** argv)
{

//	Mesh m(Primitives::box(Vec3<float>(3.f, 3.f, 3.f)));
/*	Mesh m(Primitives::cylinder(16.f, 5.f, 8));
	//m.transform(Transform::rotateX(Constantes::PI * 0.5f));
	Mesh m2(Primitives::cylinder(10.f, 3.f, 30));
	m2.transform(Transform::rotateX(Constantes::PI * 0.5f) * Transform::translate(Vec3<float>(10.f)));
//	m2.transform();

	m.merge(m2);
	//Mesh m(Primitives::circle(Vec3<float>(0.f), 3.f, 20));
//	Mesh m(Primitives::box(Vec3<float>(3.f, 3.f, 3.f)));
	MeshWriter::exportObj(m, "test3.obj"); */

	/*Quadrangle q(Vec3<float>(0.f), Vec3<float>(10.f, 0.f, 0.f), Vec3<float>(10.f, 10.f, 0.f), Vec3<float>(0.f, 10.f, 0.f));
	std::cout << "Quadrangle : perimeter : " << q.perimeter() << " area : " << q.area() << std::endl;*/

	Vec3<float> _Points[3]= {Vec3<float>(0.f),Vec3<float>(10.f,0.f,0.f),Vec3<float>(10.f,10.f,0.f)};

	Triangle t(_Points);

	std::cout<<"Aire : "<<t.area()<<" et Premietre : "<<t.perimeter()<<"\n";

	system("pause");
	return 0;
}