#pragma once
#include "Etage.h"
#include "Toit.h"
#include "../../Mesh/Mesh.h"


class RDC {

protected:
	Quadrangle q;
	float h,dif;
	int type;
public:
	RDC(const Vec3<float>&, const Vec3<float>&, const Vec3<float>&, const Vec3<float>&, const float&, const float&, const int&);
	void G(Mesh&) const;
};
