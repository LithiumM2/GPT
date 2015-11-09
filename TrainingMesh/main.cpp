#include "Vec3.h"
#include "MeshWriter.h"
#include "Transform\Transform.h"
#include "Geometry\Quadrangle.h"
#include "Geometry\Triangle.h"
#include "Geometry\Hexagone.h"
#include "Mesh\Mesh.h"
#include "Mesh\GeometryMesh\TriangleMesh.h"
#include "Mesh\GeometryMesh\PentagoneMesh.h"
#include "Mesh\GeometryMesh\HexagoneMesh.h"
#include "Mesh\GeometryMesh\QuadrangleMesh.h"
#include "Grammar\Map\QuadrangleSymbol.h"
#include "Grammar\Map\TriangleSymbol.h"

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
	QuadrangleMesh m;
	m.setPoints(std::vector<Vec3<float>>({ Vec3<float>(0.f), Vec3<float>(0.f, 150.f, 0.f), Vec3<float>(100.f, 100.f, 0.f), Vec3<float>(100.f, 0.f, 0.f) }));
	QuadrangleSymbol qs;
	qs.Generate(m, 3);
	MeshWriter::exportObj(m, "testSymbole.obj");
	/*Vec3<float> _Points[6]= {Vec3<float>(0.f),Vec3<float>(5.f,5.f,0.f),Vec3<float>(10.f,5.f,0.f),Vec3<float>(15.f,0.f,0.f),Vec3<float>(10.f,-5.f,0.f),Vec3<float>(5.f,-5.f,0.f)};
	Hexagone q(_Points);

	std::cout<<"Aire : "<<q.area()<<" et Premietre : "<<q.perimeter()<<"\n"<<std::endl;*/

	/************************ Example Pentagone Mesh *****************************/
	/*std::vector<Vec3<float>> points = { Vec3<float> ( 0.f ), Vec3<float> ( 5.f, 5.f, 0.f ), Vec3<float> ( 10.f, 5.f, 0.f ), Vec3<float> ( 15.f, 0.f, 0.f ), Vec3<float> ( 10.f, -5.f, 0.f ) };
	PentagoneMesh pm = PentagoneMesh ( points );
	Mesh m ( pm );
	MeshWriter::exportObj ( m, "test_pentagone.obj" );*/

	/************************ Example Hexagone Mesh *****************************/
	/*std::vector<Vec3<float>> points = { Vec3<float> ( 0.f ), Vec3<float> ( 5.f, 5.f, 0.f ), Vec3<float> ( 10.f, 5.f, 0.f ), Vec3<float> ( 15.f, 0.f, 0.f ), Vec3<float> ( 10.f, -5.f, 0.f ), Vec3<float> ( 5.f, -5.f, 0.f ) };
>>>>>>> origin/master
	HexagoneMesh hm = HexagoneMesh ( points );
	Mesh m ( hm );
	MeshWriter::exportObj ( m, "test_hexagone.obj" );*/

	/************************ Example TriangleSymbol Generate *****************************/
	/*std::vector<Vec3<float>> points = { Vec3<float> ( 0.f ), Vec3<float> ( 10.f, 0.f, 0.f ), Vec3<float> ( 10.f, 10.f, 0.f ) };
	TriangleMesh tm = TriangleMesh ( points );
<<<<<<< HEAD
	TriangleSymbol ts = TriangleSymbol ( points[0], points[1], points[2] );
	ts.Generate ( tm, 1 );
	
	MeshWriter::exportObj ( tm, "test_triangle_symbole2.obj" );

=======
	TriangleSymbol ts = TriangleSymbol ( );
	ts.Generate ( tm, 1 );
	
	MeshWriter::exportObj ( tm, "test_triangle_symbole.obj" );
	*/
	system("pause");
	return 0;
}