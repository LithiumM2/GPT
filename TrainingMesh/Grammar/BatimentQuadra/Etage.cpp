#include "Etage.h"


Etage::Etage(const Vec3<float>& a, const Vec3<float>& b, const Vec3<float>& c, const Vec3<float>& d, const float& _h, const float& _pourcentage,const int& _type,const float& _rotate){
	q = Quadrangle(a, b, c, d);
	h = _h;
	pourcentage = _pourcentage;
	type = _type;
	rotate = _rotate;
}


void Etage::G(Mesh& m) const{

	if (type == 0){
		float _h = h / 6;
		/*****************Inter Etage************************/
		Quadrangle q2 = q;
		q2.shrinkByDist(2.f);
		Mesh m2(Mesh::Box(q2.p1, q2.p2, q2.p3, q2.p4, _h));
		m.merge(m2);
		/****************************************************/

		q2 = Quadrangle(q.p1 + Vec3<float>(0.0, 0.0, _h), q.p2 + Vec3<float>(0.0, 0.0, _h), q.p3 + Vec3<float>(0.0, 0.0, _h), q.p4 + Vec3<float>(0.0, 0.0, _h));
		q2.shrinkByDist(1.f);
		Mesh m3(Mesh::Box(q2.p1, q2.p2, q2.p3, q2.p4, h));
		m.merge(m3);

		// La grammaire commence ici
		int e = rand() % 100;
		if (e < pourcentage)
		{
			_h += h;
			Etage(q.p1 + Vec3<float>(0.0, 0.0, _h), q.p2 + Vec3<float>(0.0, 0.0, _h), q.p3 + Vec3<float>(0.0, 0.0, _h), q.p4 + Vec3<float>(0.0, 0.0, _h), h, pourcentage - 2.5, 0, rotate).G(m);
		}
		/*else if(e < 10){
		_h += h;
		float distance1 = distance(q.p1,q.p2);
		float distance2 = distance(q.p1, q.p4);

		if (distance1 < distance2){

		Etage(q.p1 + Vec3<float>(0.0, 0.0, _h), q.p2 + Vec3<float>(0.0, 0.0, _h), q.p3 + Vec3<float>(0.0, 0.0, _h), q.p4 + Vec3<float>(0.0, 0.0, _h), h, pourcentage - 2.5).G(m);
		Etage(q.p1 + Vec3<float>(0.0, 0.0, _h), q.p2 + Vec3<float>(0.0, 0.0, _h), q.p3 + Vec3<float>(0.0, 0.0, _h), q.p4 + Vec3<float>(0.0, 0.0, _h), h, pourcentage - 2.5).G(m);

		}
		else{


		}

		}*/
		else
		{
			Toit(q.p1 + Vec3<float>(0.0, 0.0, h), q.p2 + Vec3<float>(0.0, 0.0, h), q.p3 + Vec3<float>(0.0, 0.0, h), q.p4 + Vec3<float>(0.0, 0.0, h), h, rotate).G(m);

		}
	}

	//****************************************//
	//************Building Twist**************//
	//***************************************//
	else if (type == 1){

		float _rotate = rotate + Constantes::PI * 0.025f;
		float _h = h / 6;

		/*****************Inter Etage************************/
		Quadrangle q2 = q;
		q2.shrinkByDist(2.f);
		Mesh m2(Mesh::Box(q2.p1, q2.p2, q2.p3, q2.p4, _h));
		m2.transform(Transform::RotatelocalZ(_rotate, m2.getPivot()));
		m.merge(m2);
		/****************************************************/

		q2 = Quadrangle(q.p1 + Vec3<float>(0.0, 0.0, _h), q.p2 + Vec3<float>(0.0, 0.0, _h), q.p3 + Vec3<float>(0.0, 0.0, _h), q.p4 + Vec3<float>(0.0, 0.0, _h));
		q2.shrinkByDist(1.f);
		Mesh m3(Mesh::Box(q2.p1, q2.p2, q2.p3, q2.p4, h));
		m3.transform(Transform::RotatelocalZ(_rotate, m3.getPivot()));
		m.merge(m3);

		// La grammaire commence ici
		int e = rand() % 100;
		if (e < pourcentage)
		{
			_h += h;
			Etage(q.p1 + Vec3<float>(0.0, 0.0, _h), q.p2 + Vec3<float>(0.0, 0.0, _h), q.p3 + Vec3<float>(0.0, 0.0, _h), q.p4 + Vec3<float>(0.0, 0.0, _h), h, pourcentage - 2.5, 1, _rotate).G(m);
		}
		else
		{
			Toit(q.p1 + Vec3<float>(0.0, 0.0, h), q.p2 + Vec3<float>(0.0, 0.0, h), q.p3 + Vec3<float>(0.0, 0.0, h), q.p4 + Vec3<float>(0.0, 0.0, h), h, _rotate).G(m);

		}
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


