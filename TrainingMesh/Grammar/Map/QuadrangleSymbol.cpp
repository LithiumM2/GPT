#include "QuadrangleSymbol.h"

QuadrangleSymbol::QuadrangleSymbol ( ) {
}


QuadrangleSymbol::QuadrangleSymbol(const Vec3<float>& p0_, const Vec3<float>& p1_, const Vec3<float>& p2_, const Vec3<float>& p3_, const Vec3<float>& _mid) : p0(p0_), p1(p1_), p2(p2_), p3(p3_), mid(_mid)
{

}

void QuadrangleSymbol::Generate(Mesh & m, int compteur) const
{
	if (compteur == 0)
	{
		Quadrangle q = Quadrangle(p0, p1, p2, p3);
		q.shrinkByDist(10.f);

		//*******************Test Centre Ville***************/

		float dif = 0.f;
			;
		if (distance(mid,p0)<100){
			dif=100.f;
		}
		else if (distance(mid, p0)<200){
			dif=70.f;
		}
		else if (distance(mid, p0)<350){
			dif = 50.f;
		}
		else{
			dif = 0.f;
		}

		//printf("%f \n", dif);



		/************************************************/

		Mesh m1 = Mesh::Quadrangle(q.p1, q.p2, q.p3, q.p4);
		m.merge(Mesh::RouteL(p0, p1, q.p2, q.p1, 3.f, 1.F));
		m.merge(Mesh::RouteL(p2, p3, q.p4, q.p3, 3.f, 1.f));
		m.merge(Mesh::RouteL(p3, p0 , q.p1, q.p4, 3.f, 1.f));
		m.merge(Mesh::RouteL(p1, p2, q.p3, q.p2, 3.f, 1.f));
		m.merge(m1);
		int e = rand() % 100;
		if (e<75)
		{
			RDC(q.p1, q.p2, q.p3, q.p4, 5.f,dif).G(m);
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
			QuadrangleSymbol(center1, p1, p2, center2,mid).Generate(m, compteur - 1);
			QuadrangleSymbol(p0, center1, center2, p3, mid).Generate(m, compteur - 1);
		}
		else
		{
			Vec3<float> center1 = (p1 + p2) * fact;
			Vec3<float> center2 = (p3 + p0) * fact;
			center1 = ((p2 - p1) * shiftCenter1) + center1;
			center2 = ((p3 - p0) * shiftCenter2) + center2;
			QuadrangleSymbol(center1, p2, p3, center2, mid).Generate(m, compteur - 1);
			QuadrangleSymbol(p1, center1, center2, p0, mid).Generate(m, compteur - 1);
		}
	}
}

/* Genere un quadrangle symbole et un mesh avec une bordure de route
* p1, p2, p3, p4 : coordonnées du quadrangle de base
* borderSize : largeur de la bordure
* sizePavement, hPavement : dimension du trottoir
* m : mesh auquel on rajoute la bordure
* mid : milieu pour definir le centre ville
*/
QuadrangleSymbol QuadrangleSymbol::genBorder(const Vec3<float>& p1, const Vec3<float>& p2, const Vec3<float>&p3, const Vec3<float>& p4, const float& borderSize, const float& sizePavement, const float& hPavement, Mesh& m, const Vec3<float>& _mid)
{
	Quadrangle q(p1, p2, p3, p4);
	Quadrangle q2(q);
	q.shrinkByDist(borderSize);
	QuadrangleSymbol qs(q.p1, q.p2, q.p3, q.p4, _mid);

	m.merge(Mesh::RouteR(q2.p1, q2.p2, q.p2, q.p1, sizePavement, hPavement));
	m.merge(Mesh::RouteR(q2.p3, q2.p4, q.p4, q.p3, sizePavement, hPavement));
	m.merge(Mesh::RouteR(q2.p4, q2.p1, q.p1, q.p4, sizePavement, hPavement));
	m.merge(Mesh::RouteR(q2.p2, q2.p3, q.p3, q.p2, sizePavement, hPavement));
	return qs;
}
QuadrangleSymbol::~QuadrangleSymbol ( ) {
}
