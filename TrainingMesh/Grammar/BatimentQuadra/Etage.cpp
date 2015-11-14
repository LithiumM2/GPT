#include "Etage.h"


Etage::Etage(const Vec3<float>& a, const Vec3<float>& b, const Vec3<float>& c, const Vec3<float>& d, const float& _h, const float& _pourcentage){
	q = Quadrangle(a, b, c, d);
	h = _h;
	pourcentage = _pourcentage;
}


void Etage::G(Mesh& m) const{
	Mesh m2(Mesh::Box(q.p1, q.p2, q.p3, q.p4, h));
	m2.transform(Transform::Shrink(0.8f, m2.getPivot()));
	m.merge(m2);

	// La grammaire commence ici
	int e = rand() %100;
	if (e < pourcentage)
	{
		Etage(q.p1 + Vec3<float>(0.0, 0.0, h), q.p2 + Vec3<float>(0.0, 0.0, h), q.p3 + Vec3<float>(0.0, 0.0, h), q.p4 + Vec3<float>(0.0, 0.0, h), h , pourcentage-2.5).G(m);
	}
	else
	{
		Toit(q.p1 + Vec3<float>(0.0, 0.0, h), q.p2 + Vec3<float>(0.0, 0.0, h), q.p3 + Vec3<float>(0.0, 0.0, h), q.p4 + Vec3<float>(0.0, 0.0, h), h).G(m);

	}
}

