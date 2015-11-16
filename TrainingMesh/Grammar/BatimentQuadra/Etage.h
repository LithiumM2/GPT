#pragma once
#include "../../Geometry/Quadrangle.h"
#include "../../Mesh/Mesh.h"
#include "Toit.h"

class Etage {
protected:
	Quadrangle q;
	float h,rotate;
	float pourcentage; //Pour eviter une creation de bulding trop haute
	int type; //0= normal -- 1= twisted
public:
	Etage(const Vec3<float>&, const Vec3<float>&, const Vec3<float>&, const Vec3<float>&, const float&, const float&, const int&,const float&);
	void G(Mesh&) const;
	static void addWindows(Mesh&, const Vec3<float>&, const Vec3<float>&, const Vec3<float>&, const Vec3<float>&, const float&);
};
