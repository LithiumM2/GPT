#pragma once
#include "..\Symbol.h"

class QuadrangleSymbol :
	public Symbol {
public:
	Vec3<float> p0, p1, p2, p3;
	QuadrangleSymbol(const Vec3<float>&, const Vec3<float>&, const Vec3<float>&, const Vec3<float>&);
	QuadrangleSymbol();
	~QuadrangleSymbol ( );

	void Generate(Mesh &mesh, int compteur) const;
};

