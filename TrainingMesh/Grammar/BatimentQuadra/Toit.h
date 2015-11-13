#pragma once
#include "../../Geometry/Quadrangle.h"
#include "../../Mesh/Mesh.h"

class Toit {
protected:
	Quadrangle q;
	float h;
public:
	Toit(const Vec3<float>&, const Vec3<float>&, const Vec3<float>&, const Vec3<float>&, const float&);
	void G(Mesh&) const;
};
