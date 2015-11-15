#pragma once

#include "..\..\Vec3.h"
#include "..\Symbol.h"
#include "..\Map\QuadrangleSymbol.h"
#include "..\..\Geometry\Triangle.h"

class TriangleSymbol :
	public Symbol {
protected:
	Vec3<float> p[3];

public:
	TriangleSymbol ( const Vec3<float> &, const Vec3<float> &, const Vec3<float> & );
	
	void Generate ( Mesh &mesh, int compteur ) const;
};

