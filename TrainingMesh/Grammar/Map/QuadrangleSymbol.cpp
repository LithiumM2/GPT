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
		QuadrangleMesh rec1;
		QuadrangleMesh rec2;

		float AB = distance(points[0], points[1]);
		float BC = distance(points[1], points[2]);
		float CD = distance(points[2], points[3]);
		float DA = distance(points[3], points[0]);
		float fact = 0.5f;// (float)((rand() % 2) + 4) / 10.f;
		if ((AB >= BC && AB >= DA) || (CD >= BC && CD >= DA))
		{
			rec1.setPoints({ (points[0] + points[1]) * fact, points[1], points[2], (points[2] + points[3]) * fact });
			rec2.setPoints({ points[0], (points[0] + points[1]) * fact, (points[2] + points[3]) * fact, points[3] });
		}
		else
		{
			rec1.setPoints({ (points[1] + points[2]) * fact, points[2], points[3], (points[3] + points[0]) * fact });
			rec2.setPoints({ points[1], (points[1] + points[2]) * fact, (points[3] + points[0]) * fact, points[0] });
		}
		rec1.transform(Transform::Shrink(0.9f, rec1.pivot));
		rec2.transform(Transform::Shrink(0.9f, rec2.pivot));
		/*
		Vec3<float> center = points[0];
		Vec3<float> min = points[0];
		Vec3<float> max = points[0];
		for (int i = 1; i < points.size(); ++i)
		{
		center += points[i];
		min = Vec3<float>(std::fminf(min.x, points[i].x), std::fminf(min.y, points[i].y), std::fminf(min.z, points[i].z));
		max = Vec3<float>(std::fmaxf(max.x, points[i].x), std::fmaxf(max.y, points[i].y), std::fmaxf(max.z, points[i].z));
		}
		center *= 1.f / (float)points.size(); */

		//rec1.transform(Transform::Shrink(0.5f, center));

		//rec2.transform(Transform::Shrink(0.5f, center));
		/*	int random = rand() % 100;
			if (compteur > 0)
			{
			if (true)
			{

			/*	rec1.setPoints(std::vector<Vec3<float>>({ Vec3 < float >(min.x, center.y, min.z), Vec3 < float >(min.x, max.y, min.z), max, Vec3 < float >(max.x, center.y, min.z) }));
			rec2.setPoints(std::vector<Vec3<float>>({ min, Vec3 < float >(min.x, center.y, min.z), Vec3 < float >(max.x, center.y, min.z), Vec3 < float >(max.x, min.y, min.z) }));
			rec1.transform(Transform::Shrink(0.9f, rec1.pivot));
			rec2.transform(Transform::Shrink(0.9f, rec2.pivot)); */
		//	}
		/*	else
			{
			QuadrangleMesh rec1;
			QuadrangleMesh rec2;
			rec1.setPoints(std::vector<Vec3<float>>({ Vec3 < float >(center.x, max.y, min.z), Vec3 < float >(min.x, max.y, min.z), max, Vec3 < float >(max.x, center.y, min.z) }));
			rec2.setPoints(std::vector<Vec3<float>>({ min, Vec3 < float >(min.x, center.y, min.z), Vec3 < float >(max.x, center.y, min.z), Vec3 < float >(max.x, min.y, min.z) }));
			rec1.transform(Transform::Shrink(0.9f, rec1.pivot));
			rec2.transform(Transform::Shrink(0.9f, rec2.pivot));
			} */
		//rec2.transform(Transform::Shrink(0.9f, center));
		/*
		if (random < 100)
		{
		//coupure horizontale
		Vec3<float> t1 = Vec3<float>(0.f, (max.y - center.y), 0.f);
		rec1.transform(Transform::Shrink(0.9f, center) * Transform::translate(t1) * Transform::scale(1.f, 0.5f, 1.f));

		Vec3<float> t2 = Vec3<float>(0.f, (min.y - center.y), 0.f);
		rec2.transform(Transform::Shrink(0.9f, center) * Transform::translate(t2) * Transform::scale(1.0f, 0.5f, 1.f));
		}
		else
		{

		// coupure vertical
		Vec3<float> t1 = Vec3<float>((max.x - center.x * 0.5f), 0.f, (max.z - center.z));
		rec1.transform(Transform::translate(t1) * Transform::Shrink(0.9f, center) * Transform::scale(0.5f, 1.f, 1.f));

		Vec3<float> t2 = Vec3<float>((min.x - center.x * 0.5f), 0.f, (min.z - center.z));
		rec2.transform(Transform::translate(t2) * Transform::Shrink(0.9f, center) * Transform::scale(0.5f, 1.f, 1.f));
		} */
		QuadrangleSymbol().Generate(rec1, compteur - 1);
		QuadrangleSymbol().Generate(rec2, compteur - 1);
		rec1.merge(rec2);
		m = rec1;
		//}
	}
}

QuadrangleSymbol::~QuadrangleSymbol ( ) {
}
