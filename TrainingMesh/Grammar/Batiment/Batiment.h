#pragma once

#include "../../Mesh/Mesh.h"
#include "Etage.h"
#include "RDC.h"

class Batiment :
	public Mesh
{
protected:
	Quadrangle q;
	float h;
public:
	Batiment(const Vec3<float>& a, const Vec3<float>& b, const Vec3<float>& c, const Vec3<float>& d, const float& _h);
	void G(Mesh& m,unsigned int);
	virtual ~Batiment();
};

