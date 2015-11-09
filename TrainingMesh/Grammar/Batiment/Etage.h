#pragma once
#include "../../Geometry/Quadrangle.h"
#include "../../Mesh/Mesh.h"

class Etage {
protected:
	Quadrangle q;
	double h;
public:
	Etage(const Vec3<float>&, const Vec3<float>&, const Vec3<float>&, const Vec3<float>&, const double&);
	void G(Mesh&) const;
};
