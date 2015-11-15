#include "Toit.h"


Toit::Toit(const Vec3<float>& a, const Vec3<float>& b, const Vec3<float>& c, const Vec3<float>& d, const float& _h){
	q = Quadrangle(a, b, c, d);
	h = _h;

}


void Toit::G(Mesh& m) const{

	Quadrangle q2 = q;
	q2.shrinkByDist(100.f);
	Mesh m2(Mesh::Box(q2.p1, q2.p2, q2.p3, q2.p4, h));
	//m2.transform(Transform::Shrink(0.5f, m2.getPivot()));
	m.merge(m2);
//	Toit(q.p1 + Vec3<float>(0.0, 0.0, h), q.p1 + Vec3<float>(0.0, 0.0, h), q.p1 + Vec3<float>(0.0, 0.0, h), q.p1 + Vec3<float>(0.0, 0.0, h), 1.f).G(m);

}
