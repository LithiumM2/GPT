#pragma once
#include "Etage.h"
#include "Toit.h"
#include "../../Mesh/Mesh.h"


class RDC {

protected:
	Quadrangle q;
	float h;
public:
	RDC(const Vec3<float>&, const Vec3<float>&, const Vec3<float>&, const Vec3<float>&, const float&);
	void G(Mesh&) const;
};
