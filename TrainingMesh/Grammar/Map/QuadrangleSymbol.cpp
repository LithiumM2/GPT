#include "QuadrangleSymbol.h"

QuadrangleSymbol::QuadrangleSymbol ( ) {
}

void QuadrangleSymbol::Generate(Mesh & m, int compteur) const
{
	if (compteur > 0)
	{
		std::vector<Vec3<float>> points(m.getPoints());
		//	Mesh rec1(m);
		//	Mesh rec2(m);
	//	QuadrangleMesh rec1;
	//	QuadrangleMesh rec2;
		Mesh rec1;
		Mesh rec2;
		float AB = distance(points[0], points[1]);
		float BC = distance(points[1], points[2]);
		float CD = distance(points[2], points[3]);
		float DA = distance(points[3], points[0]);
		float fact = 0.5f;
		float shiftCenter1 = (float)((rand() % 2) - 1) / 10.f;
		float shiftCenter2 = (float)((rand() % 2) - 1) / 10.f;
		if ((AB >= BC && AB >= DA) || (CD >= BC && CD >= DA))
		{
			Vec3<float> center1 = (points[0] + points[1]) * fact;
			Vec3<float> center2 = (points[2] + points[3]) * fact;
			center1 = ((points[1] - points[0]) * shiftCenter1) + center1;
			center2 = ((points[3] - points[2]) * shiftCenter2) + center2;
			rec1 = Mesh::Quadrangle(center1, points[1], points[2], center2);
			rec2 = Mesh::Quadrangle(points[0], center1, center2, points[3]);
		}
		else
		{
			Vec3<float> center1 = (points[1] + points[2]) * fact;
			Vec3<float> center2 = (points[3] + points[0]) * fact;
			center1 = ((points[2] - points[1]) * shiftCenter1) + center1;
			center2 = ((points[3] - points[0]) * shiftCenter2) + center2;
			rec1 = Mesh::Quadrangle(center1, points[2], points[3], center2);
			rec2 = Mesh::Quadrangle(points[1], center1, center2, points[0]);
		}
		rec1.transform(Transform::Shrink(0.9f, rec1.pivot));
		rec2.transform(Transform::Shrink(0.9f, rec2.pivot));
		QuadrangleSymbol().Generate(rec1, compteur - 1);
		QuadrangleSymbol().Generate(rec2, compteur - 1);
		rec1.merge(rec2);
		m = rec1;
		//}
	}
}

QuadrangleSymbol::~QuadrangleSymbol ( ) {
}
