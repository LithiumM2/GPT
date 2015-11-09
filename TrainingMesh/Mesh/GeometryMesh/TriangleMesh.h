#pragma once

#include "..\Mesh.h"
#include "..\..\Geometry\Triangle.h"

class TriangleMesh :
	public Mesh, public Triangle {

public:
	TriangleMesh ( ) : Mesh ( ), Triangle ( ) { }
	TriangleMesh ( std::vector<Vec3<float>> points_ ) : Mesh ( ), Triangle ( ) { setPoints ( points_ ); }
	TriangleMesh ( Vec3<float> points_[] ) : Mesh ( ), Triangle ( ) { setPoints ( points_ ); }
	~TriangleMesh ( );

	void setPoints ( std::vector<Vec3<float>> points_ );
	void setPoints ( Vec3<float> points_[] );
};

