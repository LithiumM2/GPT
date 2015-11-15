#include "Etage.h"


Etage::Etage(const Vec3<float>& a, const Vec3<float>& b, const Vec3<float>& c, const Vec3<float>& d, const float& _h, const float& _pourcentage){
	q = Quadrangle(a, b, c, d);
	h = _h;
	pourcentage = _pourcentage;
}


void Etage::G(Mesh& m) const{

	float _h = h/4;
	/*****************Inter Etage************************/
	Quadrangle q2 = q;
	q2.shrinkByDist(15.f);
	Mesh m2(Mesh::Box(q2.p1, q2.p2, q2.p3, q2.p4, _h));
	m.merge(m2);
	/****************************************************/

	q2 = Quadrangle(q.p1 + Vec3<float>(0.0, 0.0, _h), q.p2 + Vec3<float>(0.0, 0.0, _h), q.p3 + Vec3<float>(0.0, 0.0, _h), q.p4 + Vec3<float>(0.0, 0.0, _h));
	q2.shrinkByDist(10.f);
	Mesh m3(Mesh::Box(q2.p1, q2.p2, q2.p3, q2.p4, h));
	m.merge(m3);

	// La grammaire commence ici
	int e = rand() %100;
	if (e < pourcentage)
	{
		_h += h;
		Etage(q.p1 + Vec3<float>(0.0, 0.0, _h), q.p2 + Vec3<float>(0.0, 0.0, _h), q.p3 + Vec3<float>(0.0, 0.0, _h), q.p4 + Vec3<float>(0.0, 0.0, _h), h, pourcentage - 2.5).G(m);
	}
	else
	{
		Toit(q.p1 + Vec3<float>(0.0, 0.0, h), q.p2 + Vec3<float>(0.0, 0.0, h), q.p3 + Vec3<float>(0.0, 0.0, h), q.p4 + Vec3<float>(0.0, 0.0, h), h).G(m);

	}
}

