#pragma once
#include "..\..\Mesh\GeometryMesh\QuadrangleMesh.h"
#include "..\Symbol.h"

class QuadrangleSymbol :
	public Symbol {
public:
	QuadrangleSymbol ( );
	~QuadrangleSymbol ( );

	void Generate(Mesh &mesh, int compteur) const;
};

