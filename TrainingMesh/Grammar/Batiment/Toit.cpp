#include "Toit.h"


Toit::Toit(const Vec3<float>& a, const Vec3<float>& b, const Vec3<float>& c, const Vec3<float>& d, const float& _h){
	q = Quadrangle(a, b, c, d);
	h = _h;

}


void Toit::G(Mesh& m) const{
	m.merge(Mesh::Box(q.p1, q.p2, q.p3, q.p4, h));
//	Toit(q.p1 + Vec3<float>(0.0, 0.0, h), q.p1 + Vec3<float>(0.0, 0.0, h), q.p1 + Vec3<float>(0.0, 0.0, h), q.p1 + Vec3<float>(0.0, 0.0, h), 1.f).G(m);

}
