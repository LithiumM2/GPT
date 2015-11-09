#include "Mesh/Primitives.h"
#include "Vec3.h"
#include "Mesh/Mesh.h"
#include "MeshWriter.h"
#include "Transform\Transform.h"
#include "Geometry\Quadrangle.h"
#include "Geometry\Triangle.h"
#include "Geometry\Hexagone.h"
#include "Mesh\GeometryMesh\QuadrangleMesh.h"
#include "Mesh\GeometryMesh\TriangleMesh.h"
#include "Grammar\Map\QuadrangleSymbol.h"

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


	/************************Example Quadrangle *****************************/
	//Quadrangle q(Vec3<float>(0.f), Vec3<float>(10.f, 0.f, 0.f), Vec3<float>(10.f, 10.f, 0.f), Vec3<float>(0.f, 10.f, 0.f));

	/************************Example Triangle *****************************/
	//Vec3<float> _Points[3]= {Vec3<float>(0.f),Vec3<float>(10.f,0.f,0.f),Vec3<float>(10.f,10.f,0.f)};
	//Triangle q(_Points);

	/************************Example Hexagone *****************************/
	//Vec3<float> _Points[6]= {Vec3<float>(0.f),Vec3<float>(5.f,5.f,0.f),Vec3<float>(10.f,5.f,0.f),Vec3<float>(15.f,0.f,0.f),Vec3<float>(10.f,-5.f,0.f),Vec3<float>(5.f,-5.f,0.f)};
	//Hexagone q(_Points);

	//std::cout<<"Aire : "<<q.area()<<" et Premietre : "<<q.perimeter()<<"\n"<<std::endl;
	QuadrangleMesh m;
	m.setPoints(std::vector<Vec3<float>>({ Vec3<float>(0.f), Vec3<float>(0.f, 150.f, 0.f), Vec3<float>(100.f, 100.f, 0.f), Vec3<float>(100.f, 0.f, 0.f) }));
	/*Vec3<float> center = m.getPoints()[0];
	for (int i = 0; i < m.getPoints().size(); ++i)
	{
		center += m.getPoints()[i];
	}
	center *= 1.f / (float)m.getPoints().size();
	m.transform(Transform::Shrink(0.5f, center));*/
	QuadrangleSymbol qs;
	qs.Generate(m, 3);
	MeshWriter::exportObj(m, "testSymbole.obj");
	system("pause");
	return 0;
}