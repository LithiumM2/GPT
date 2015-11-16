#pragma once

#include "..\..\Vec3.h"
#include "..\Symbol.h"
#include "..\Map\QuadrangleSymbol.h"
#include "..\..\Geometry\Triangle.h"

class TriangleSymbol :
	public Symbol {
protected:
	Vec3<float> p1, p2, p3, mid;

public:
	TriangleSymbol ( const Vec3<float> &, const Vec3<float> &, const Vec3<float> &, const Vec3<float> & );
	
	void Generate ( Mesh &mesh, int compteur ) const;

	static TriangleSymbol genBorder ( const Vec3<float>& p1, const Vec3<float>& p2, const Vec3<float>&p3, const float& borderSize, const float& sizePavement, const float& hPavement, Mesh& m, const Vec3<float>& _mid );
};

