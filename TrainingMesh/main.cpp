#include "Vec3.h"
#include "MeshWriter.h"
#include "Transform\Transform.h"
#include "Geometry\Quadrangle.h"
#include "Geometry\Triangle.h"
#include "Geometry\Hexagone.h"
#include "Mesh\Mesh.h"

#include "Grammar\Map\QuadrangleSymbol.h"
#include "Grammar\Map\TriangleSymbol.h"
#include "Grammar\BatimentQuadra\RDC.h"
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

	/************************Example Quadrangle *****************************/
	/*Mesh m;//(Mesh::Quadrangle(Vec3<float>(0.f), Vec3<float>(0.f, 150.f, 0.f), Vec3<float>(100.f, 100.f, 0.f), Vec3<float>(100.f, 0.f, 0.f)));
	QuadrangleSymbol qs(Vec3<float>(0.f), Vec3<float>(0.f, 150.f, 0.f), Vec3<float>(100.f, 100.f, 0.f), Vec3<float>(100.f, 0.f, 0.f));
	qs.Generate(m, 3);
	MeshWriter::exportObj(m, "testSymbole.obj");*/
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

	/************************ Example shrink triangle *****************************/
	/*std::vector<Vec3<float>> points = { Vec3<float> ( 0.f ), Vec3<float> ( 10.f, 0.f, 0.f ), Vec3<float> ( 10.f, 10.f, 0.f ) };
	Mesh m1, m2;
	Triangle t ( Vec3<float> ( 0.f ), Vec3<float> ( 10.f, 0.f, 0.f ), Vec3<float> ( 10.f, 10.f, 0.f ) );
	t.shrinkByDist ( 2.3f );
	Vec3<float> *points2 = t.getPoints ( );
	TriangleSymbol ts1 = TriangleSymbol ( points[0], points[1], points[2] );
	TriangleSymbol ts2 = TriangleSymbol ( points2[0], points2[1], points2[2] );

	ts1.Generate ( m1, 0 );
	ts2.Generate ( m2, 0 );

	m1.transform ( Transform::translate ( Vec3<float> ( 0.f, 0.f, -5.f ) ) );

	m1.merge ( m2 );

	MeshWriter::exportObj ( m1, "test_shrink_dist.obj" );*/

	/************************ Example shrink quadrangle *****************************/
	std::vector<Vec3<float>> points = { Vec3<float> ( 0.f ), Vec3<float> ( 0.f, 150.f, 0.f ), Vec3<float> ( 100.f, 100.f, 0.f ), Vec3<float> ( 100.f, 0.f, 0.f ) };
	Mesh m1, m2;
	Quadrangle q ( points[0], points[1], points[2], points[3] );
	q.shrinkByDist ( 50.f );
	m1 = Mesh::Quadrangle ( points[0], points[1], points[2], points[3] );
	m2 = Mesh::Quadrangle ( q.p1, q.p2, q.p3, q.p4 );

	m1.transform ( Transform::translate ( Vec3<float> ( 0.f, 0.f, -5.f ) ) );

	m1.merge ( m2 );

	MeshWriter::exportObj ( m1, "test_shrink_dist2.obj" );

	//Mesh m;
	//RDC(Vec3<float>(0.f), Vec3<float>(0.f, 150.f, 0.f), Vec3<float>(100.f, 100.f, 0.f), Vec3<float>(100.f, 0.f, 0.f), 10.f).G(m);
	//MeshWriter::exportObj ( m, "test_batiment.obj" );

	//MeshWriter::exportObj(Mesh::Route(Vec3<float>(0.f), Vec3<float>(0.f, 150.f, 0.f), Vec3<float>(100.f, 100.f, 0.f), Vec3<float>(100.f, 0.f, 0.f), 20.f), "test_route.obj");

	system("pause");
	return 0;
}