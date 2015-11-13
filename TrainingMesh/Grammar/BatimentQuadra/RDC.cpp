#include "RDC.h"


RDC::RDC(const Vec3<float>& a, const Vec3<float>& b, const Vec3<float>& c, const Vec3<float>& d, const float& _h)
{
	q = Quadrangle(a, b, c, d);
	h = _h;
}

void RDC::G(Mesh& m) const
{
	Mesh m2(Mesh::Box(q.p1, q.p2, q.p3, q.p4, h));
	m2.transform(Transform::Shrink(0.9f, m2.getPivot()));
	m.merge(m2);


	// La grammaire commence ici
	int e = rand()%100;
	if (e < 90)
	{
		Etage(q.p1 + Vec3<float>(0.0, 0.0, h), q.p2 + Vec3<float>(0.0, 0.0, h), q.p3 + Vec3<float>(0.0, 0.0, h), q.p4 + Vec3<float>(0.0, 0.0, h), h).G(m);
	}
	else
	{
		Toit(q.p1 + Vec3<float>(0.0, 0.0, h), q.p2 + Vec3<float>(0.0, 0.0, h), q.p3 + Vec3<float>(0.0, 0.0, h), q.p4 + Vec3<float>(0.0, 0.0, h), h).G(m);

	}
}