#pragma once
#include "../../Geometry/Quadrangle.h"
#include "../../Mesh/Mesh.h"
#include "Toit.h"

class Etage {
protected:
	Quadrangle q;
	float h;
public:
	Etage(const Vec3<float>&, const Vec3<float>&, const Vec3<float>&, const Vec3<float>&, const float&);
	void G(Mesh&) const;
};
