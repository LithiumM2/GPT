#include "QuadrangleSymbol.h"

QuadrangleSymbol::QuadrangleSymbol ( ) {
}


QuadrangleSymbol::QuadrangleSymbol(const Vec3<float>& p0_, const Vec3<float>& p1_, const Vec3<float>& p2_, const Vec3<float>& p3_) : p0(p0_), p1(p1_), p2(p2_), p3(p3_)
{

}
void QuadrangleSymbol::Generate(Mesh & m, int compteur) const
{
	if (compteur == 0)
	{
		Quadrangle q = Quadrangle(p0, p1, p2, p3);
		q.shrinkByDist(10.f);
		
		Mesh m1 = Mesh::Quadrangle(q.p1, q.p2, q.p3, q.p4);
		m.merge(Mesh::Route(p0, p1, q.p2, q.p1, 1.f, 1.F));
		m.merge(Mesh::Route(p2, p3, q.p4, q.p3, 1.f, 1.f));
		m.merge(Mesh::Route(p3, p0 , q.p1, q.p4, 1.f, 1.f));
		m.merge(Mesh::Route(p1, p2, q.p3, q.p2, 1.f, 1.f));
		//m.merge(Mesh::Route(p2, q.p1, p3, q.p2, 1.f));
		m.merge(m1);
		if (rand() % 2)
		{
			RDC(q.p1, q.p2, q.p3, q.p4, 10.f).G(m);
		//	m.merge(m1);
		}
	}
	else
	{
		float AB = distance(p0, p1);
		float BC = distance(p1, p2);
		float CD = distance(p2, p3);
		float DA = distance(p3, p0);
		float fact = 0.5f;
		float shiftCenter1 = (float)((rand() % 2) - 1) * 0.1f;
		float shiftCenter2 = (float)((rand() % 2) - 1) * 0.1F;
		if ((AB >= BC && AB >= DA) || (CD >= BC && CD >= DA))
		{
			Vec3<float> center1 = (p0 + p1) * fact;
			Vec3<float> center2 = (p2 + p3) * fact;
			center1 = ((p1 - p0) * shiftCenter1) + center1;
			center2 = ((p3 - p2) * shiftCenter2) + center2;
			QuadrangleSymbol(center1, p1, p2, center2).Generate(m, compteur - 1);
			QuadrangleSymbol(p0, center1, center2, p3).Generate(m, compteur - 1);
		}
		else
		{
			Vec3<float> center1 = (p1 + p2) * fact;
			Vec3<float> center2 = (p3 + p0) * fact;
			center1 = ((p2 - p1) * shiftCenter1) + center1;
			center2 = ((p3 - p0) * shiftCenter2) + center2;
			QuadrangleSymbol(center1, p2, p3, center2).Generate(m, compteur - 1);
			QuadrangleSymbol(p1, center1, center2, p0).Generate(m, compteur - 1);
		}
	}
}

QuadrangleSymbol::~QuadrangleSymbol ( ) {
}
