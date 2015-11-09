#pragma once

#include "..\Symbol.h"
#include "..\..\Mesh\GeometryMesh\TriangleMesh.h"

class TriangleSymbol :
	public Symbol {
protected:
	Vec3<float> p[3];
public:
	TriangleSymbol ( Vec3<float>, Vec3<float>, Vec3<float>  );
	

	void Generate ( Mesh &mesh, int level ) const;

};

