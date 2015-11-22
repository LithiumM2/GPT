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
	bool duo; //to check if there is already the building cut in 2 buildings
	int etages;
	float window_size;
public:
	Etage(const Vec3<float>&, const Vec3<float>&, const Vec3<float>&, const Vec3<float>&, const float&, const float&, const int&, const float&, const bool&, const int&, const float&);
	void G(Mesh&) const;
	static void addWindows(Mesh&, const Vec3<float>&, const Vec3<float>&, const Vec3<float>&, const Vec3<float>&, const float&, const int&, const float&);
	static void addWindowsSide(Mesh&, const Vec3<float>&, const Vec3<float>&, const float&, const float&, const int&, const float&);
};
