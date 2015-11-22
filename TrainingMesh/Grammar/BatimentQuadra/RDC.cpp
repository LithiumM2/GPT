#include "RDC.h"


RDC::RDC(const Vec3<float>& a, const Vec3<float>& b, const Vec3<float>& c, const Vec3<float>& d, const float& _h,const float& _dif,const int& _type)
{
	q = Quadrangle(a, b, c, d);
	h = _h;
	dif = _dif;
	type = _type;
}

void RDC::G(Mesh& m) const
{
	Mesh m2(Mesh::Box(q.p1, q.p2, q.p3, q.p4, h));
	m.merge(m2);

	addDoor(m, q.p1, q.p2, q.p3, q.p4, h);

	// La grammaire commence ici
	int e = rand()%100;
	if (e < dif)
	{
		float window_size = 1.5f + (float)(rand() % 100) / 100.f;
		Etage(q.p1 + Vec3<float>(0.0, 0.0, h), q.p2 + Vec3<float>(0.0, 0.0, h), q.p3 + Vec3<float>(0.0, 0.0, h), q.p4 + Vec3<float>(0.0, 0.0, h), h, dif, type, 0.f, false, 0, window_size).G(m);
	}
	else
	{
		Toit(q.p1 + Vec3<float>(0.0, 0.0, h), q.p2 + Vec3<float>(0.0, 0.0, h), q.p3 + Vec3<float>(0.0, 0.0, h), q.p4 + Vec3<float>(0.0, 0.0, h), h,0.f,0).G(m);
	}
}

void RDC::addDoor(Mesh& m, const Vec3<float>& p1, const Vec3<float>& p2, const Vec3<float>& p3, const Vec3<float>& p4, const float& h)
{
	int selected_side = rand() % 4;
	float s = 1.f; // Shrink hauteur

	switch (selected_side)
	{
	case 0:
		Etage::addWindowsSide(m, p1, p2, h * 0.6f, s, -1, -1.f);
		break;
	case 1:
		Etage::addWindowsSide(m, p2, p3, h * 0.6f, s, -1, -1.f);
		break;
	case 2:
		Etage::addWindowsSide(m, p3, p4, h * 0.6f, s, -1, -1.f);
		break;
	case 3:
		Etage::addWindowsSide(m, p4, p1, h * 0.6f, s, -1, -1.f);
		break;
	default:
		break;
	}
}