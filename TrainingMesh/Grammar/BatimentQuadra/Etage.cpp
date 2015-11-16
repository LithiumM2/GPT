#include "Etage.h"


Etage::Etage(const Vec3<float>& a, const Vec3<float>& b, const Vec3<float>& c, const Vec3<float>& d, const float& _h, const float& _pourcentage){
	q = Quadrangle(a, b, c, d);
	h = _h;
	pourcentage = _pourcentage;
}


void Etage::G(Mesh& m) const{

	float _h = h/6.f;

	/*****************Inter Etage************************/
	Quadrangle q2 = q;
	q2.shrinkByDist(2.f);
	Mesh m2(Mesh::Box(q2.p1, q2.p2, q2.p3, q2.p4, _h));
	m.merge(m2);
	/****************************************************/

	// Etage
	q2 = Quadrangle(q.p1 + Vec3<float>(0.0, 0.0, _h), q.p2 + Vec3<float>(0.0, 0.0, _h), q.p3 + Vec3<float>(0.0, 0.0, _h), q.p4 + Vec3<float>(0.0, 0.0, _h));
	q2.shrinkByDist(1.f);
	Mesh m3(Mesh::Box(q2.p1, q2.p2, q2.p3, q2.p4, h));
	//Etage::addWindows(m3, q2.p1, q2.p2, q2.p3, q2.p4, h);
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

// TODO JORIS
void Etage::addWindows(Mesh& m, const Vec3<float>& p1, const Vec3<float>& p2, const Vec3<float>& p3, const Vec3<float>& p4, const float& h)
{
	float n = 0.1f; // écart entre deux fenêtres
	float size = 0.5f; // largeur fenêtre

	Quadrangle q(p1, p2, p2 + Vec3<float>(0.0, 0.0, h), p1 + Vec3<float>(0.0, 0.0, h));
	q.shrinkByDist(distance(p2, p1) / 2.);

	int i = 0;
	for (float s = q.p1.x; s < q.p2.x - size; s += size)
	{
		Vec3<float> eps((float)i * size, 0, 0);
		Mesh win(Mesh::Window(q.p1 + eps, q.p2 + eps, q.p3 + eps, q.p4 + eps, Vec3<float>(size, 0., 0.)));
		m.merge(win);
		i++;
	}
}


