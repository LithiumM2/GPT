#pragma once

#include "..\Mesh.h"
#include "..\..\Geometry\Hexagone.h"

class HexagoneMesh :
	public Mesh, public Hexagone {

public:
	HexagoneMesh ( ) : Mesh ( ), Hexagone ( ) { }
	HexagoneMesh ( std::vector<Vec3<float>> points_ ) : Mesh ( ), Hexagone ( ) { setPoints ( points_ ); }
	~HexagoneMesh ( );

	void setPoints ( std::vector<Vec3<float>> points_ );
};

