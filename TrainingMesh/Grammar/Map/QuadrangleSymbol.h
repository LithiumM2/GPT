#pragma once
#include "..\Symbol.h"
#include "../BatimentQuadra/RDC.h"

class QuadrangleSymbol :
	public Symbol {
public:
	Vec3<float> p0, p1, p2, p3,mid;
	QuadrangleSymbol(const Vec3<float>&, const Vec3<float>&, const Vec3<float>&, const Vec3<float>&, const Vec3<float>&);
	QuadrangleSymbol();
	~QuadrangleSymbol ( );

	void Generate(Mesh &mesh, int compteur) const;
	static QuadrangleSymbol genBorder(const Vec3<float>&, const Vec3<float>&, const Vec3<float>&, const Vec3<float>&, const float&, const float&, const float&, Mesh&, const Vec3<float>&);
};

