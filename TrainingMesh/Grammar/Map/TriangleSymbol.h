#pragma once

#include "..\Symbol.h"
#include "..\..\Mesh\GeometryMesh\TriangleMesh.h"

class TriangleSymbol :
	public Symbol {

public:
	TriangleSymbol ( );
	~TriangleSymbol ( );

	void Generate(Mesh &mesh, int compteur) const;
};

