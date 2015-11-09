#pragma once
#include "../../Geometry/Quadrangle.h"
#include "../../Mesh/Mesh.h"

class Toit {
protected:
	Quadrangle q;
	double h;
public:
	Toit(const Vec3<float>&, const Vec3<float>&, const Vec3<float>&, const Vec3<float>&, const double&);
	void G(Mesh&) const;
};
