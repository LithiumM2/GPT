#pragma once

#include "..\Mesh.h"
#include "..\..\Geometry\Quadrangle.h"

class QuadrangleMesh :
	public Mesh, public Quadrangle {

public:
	QuadrangleMesh ( ) : Mesh ( ), Quadrangle ( ) { }
	~QuadrangleMesh ( );

	void setPoints ( std::vector<Vec3<float>> points_ );
};

