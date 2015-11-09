#pragma once

#include "..\Mesh.h"
#include "..\..\Geometry\Pentagone.h"

class PentagoneMesh :
	public Mesh, public Pentagone {

public:
	PentagoneMesh ( ) : Mesh ( ), Pentagone ( ) { }
	PentagoneMesh ( std::vector<Vec3<float>> points_ ) : Mesh ( ), Pentagone ( ) { setPoints ( points_ ); }
	~PentagoneMesh ( );

	void setPoints ( std::vector<Vec3<float>> points_ );
};

