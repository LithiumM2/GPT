#include "Batiment.h"


Batiment::Batiment(const Vec3<float>& a, const Vec3<float>& b, const Vec3<float>& c, const Vec3<float>& d, const float& _h)
{
	q = Quadrangle(a, b, c, d);
	h = _h;
}


void Batiment::G(Mesh& m, unsigned int nb_e)
{
	m.merge(Mesh::Prism(q.p1, q.p2, q.p3, q.p4, h));
	RDC.G(m);
	while(nb_e>=0)
	{
		Etage.G(m);
		nb_e--;
	}
	Toit.G(m);
}

Batiment::~Batiment()
{
}
