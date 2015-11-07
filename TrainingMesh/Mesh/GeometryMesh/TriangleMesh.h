#pragma once

#include "..\Mesh.h"
#include "..\..\Geometry\Triangle.h"

class TriangleMesh :
	public Mesh, public Triangle {

public:
	TriangleMesh ( ) : Mesh ( ), Triangle ( ) { }
	~TriangleMesh ( );

	void setPoints ( std::vector<Vec3<float>> points_ );
};

