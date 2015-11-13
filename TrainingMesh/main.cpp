#include "Vec3.h"
#include "MeshWriter.h"
#include "Transform\Transform.h"
#include "Geometry\Quadrangle.h"
#include "Geometry\Triangle.h"
#include "Geometry\Hexagone.h"
#include "Mesh\Mesh.h"
#include <time.h>

#include "Grammar\Map\QuadrangleSymbol.h"
#include "Grammar\Map\TriangleSymbol.h"
#include "Grammar\BatimentQuadra\RDC.h"
int main(int argc, char ** argv)
{
	srand(time(NULL));
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

	/************************Example Quadrangle *****************************/
	Mesh m;//(Mesh::Quadrangle(Vec3<float>(0.f), Vec3<float>(0.f, 150.f, 0.f), Vec3<float>(100.f, 100.f, 0.f), Vec3<float>(100.f, 0.f, 0.f)));
	QuadrangleSymbol qs(Vec3<float>(0.f), Vec3<float>(0.f, 150.f, 0.f), Vec3<float>(100.f, 100.f, 0.f), Vec3<float>(100.f, 0.f, 0.f));
	qs.Generate(m, 3);
	MeshWriter::exportObj(m, "testSymbole.obj");
	/*Vec3<float> _Points[6]= {Vec3<float>(0.f),Vec3<float>(5.f,5.f,0.f),Vec3<float>(10.f,5.f,0.f),Vec3<float>(15.f,0.f,0.f),Vec3<float>(10.f,-5.f,0.f),Vec3<float>(5.f,-5.f,0.f)};
	Hexagone q(_Points);

	std::cout<<"Aire : "<<q.area()<<" et Premietre : "<<q.perimeter()<<"\n"<<std::endl;*/

	/************************ Example Pentagone Mesh *****************************/

	//Mesh m(Mesh::Pentagone(Vec3<float>(0.f), Vec3<float>(5.f, 5.f, 0.f), Vec3<float>(10.f, 5.f, 0.f), Vec3<float>(15.f, 0.f, 0.f), Vec3<float>(10.f, -5.f, 0.f)));
	//MeshWriter::exportObj ( m, "test_pentagone.obj" );

	/************************ Example Hexagone Mesh *****************************/
	/*std::vector<Vec3<float>> points = { Vec3<float> ( 0.f ), Vec3<float> ( 5.f, 5.f, 0.f ), Vec3<float> ( 10.f, 5.f, 0.f ), Vec3<float> ( 15.f, 0.f, 0.f ), Vec3<float> ( 10.f, -5.f, 0.f ), Vec3<float> ( 5.f, -5.f, 0.f ) };
>>>>>>> origin/master
	HexagoneMesh hm = HexagoneMesh ( points );
	Mesh m ( hm );
	MeshWriter::exportObj ( m, "test_hexagone.obj" );*/

	/************************ Example TriangleSymbol Generate *****************************/
	/* std::vector<Vec3<float>> points = { Vec3<float> ( 0.f ), Vec3<float> ( 10.f, 0.f, 0.f ), Vec3<float> ( 10.f, 10.f, 0.f ) };
	Mesh m2;
	TriangleSymbol ts = TriangleSymbol ( points[0], points[1], points[2] );
	ts.Generate ( m2, 2 );

	MeshWriter::exportObj ( m2, "test_triangle_symbole2.obj" ); */
	/************************ Example Batiment à tester *****************************/
	//Mesh m;
	//Batiment b(Vec3<float>(0.f), Vec3<float>(0.f, 1500.f, 0.f), Vec3<float>(100.f, 1000.f, 0.f), Vec3<float>(1000.f, 0.f, 0.f));
	//Etage e(Vec3<float>(0.f), Vec3<float>(0.f, 150.f, 0.f), Vec3<float>(100.f, 100.f, 0.f), Vec3<float>(100.f, 0.f, 0.f));

	//Toit t(Vec3<float>(0.f), Vec3<float>(0.f, 120.f, 0.f), Vec3<float>(100.f, 100.f, 0.f), Vec3<float>(100.f, 0.f, 0.f));

	//b.G(m);
	/*Mesh m;
	RDC(Vec3<float>(0.f), Vec3<float>(0.f, 150.f, 0.f), Vec3<float>(100.f, 100.f, 0.f), Vec3<float>(100.f, 0.f, 0.f), 10.f).G(m);
	MeshWriter::exportObj ( m, "test_batiment.obj" );*/
	system("pause");
	return 0;
}