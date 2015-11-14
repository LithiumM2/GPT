#pragma once
#include "../../Geometry/Quadrangle.h"
#include "../../Mesh/Mesh.h"
#include "Toit.h"

class Etage {
protected:
	Quadrangle q;
	float h;
	float pourcentage; //Pour eviter une creation de bulding trop haute
public:
	Etage(const Vec3<float>&, const Vec3<float>&, const Vec3<float>&, const Vec3<float>&, const float&, const float&);
	void G(Mesh&) const;
};
