#pragma once
#include "Etage.h"
#include "Toit.h"


class RDC {

protected:
	Quadrangle q;
	double h;
public:
	RDC(const Vec3<float>&, const Vec3<float>&, const Vec3<float>&, const Vec3<float>&, const double&);
	void G(Mesh&) const;
};
