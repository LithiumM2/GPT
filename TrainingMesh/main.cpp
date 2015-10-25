#include "Primitives.h"
#include "Vec3.h"
#include "Mesh.h"
#include "MeshWriter.h"

/*
TODO : 
Rotation

*/
int main(int argc, char ** argv)
{

//	Mesh m(Primitives::box(Vec3<float>(3.f, 3.f, 3.f)));
	Mesh m(Primitives::cylinder(10.f, 3.f, 30));
	Mesh m2(Primitives::cylinder(10.f, 3.f, 30));
	m2.rotate(Quaternion(Constantes::PI, 0.f, 0.f, 1.f));
	m.merge(m2);
	//Mesh m(Primitives::circle(Vec3<float>(0.f), 3.f, 20));
//	Mesh m(Primitives::box(Vec3<float>(3.f, 3.f, 3.f)));
	MeshWriter::exportObj(m, "test.obj");
	return 0;
}