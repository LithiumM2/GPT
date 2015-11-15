#include "TriangleSymbol.h"


TriangleSymbol::TriangleSymbol ( Vec3<float> a, Vec3<float> b, Vec3<float> c)
{ 
	p[0] = a;
	p[1] = b;
	p[2] = c;

}

void TriangleSymbol::Generate ( Mesh &mesh, int level ) const {
	if ( ( level == 0 ) || ( Triangle ( p[0], p[1], p[2] ).area ( ) ) < 1.f ) {
		Mesh m = Mesh::Triangle ( p[0], p[1], p[2] );
		//m.transform ( Transform::Shrink ( .9f, m.getPivot ( ) ) );
		mesh.merge ( m );
		//Bloc( p[0], p[1], p[2] ).G(mesh);
	}
	else {
		int random = rand ( ) % 100;

		if ( random < 33 ) {
			// Divise le triangle en 2 triangles
			TriangleSymbol(0.5f * (p[2] + p[1]), p[1], p[0]).Generate(mesh, level - 1);
			TriangleSymbol(p[2], 0.5f * (p[2] + p[1]), p[0]).Generate(mesh, level - 1);
		}
		else if ( random < 66) {
			// Divise le triangle en 3 triangles
			Vec3<float> center = p[0];
			Vec3<float> min = p[0];
			Vec3<float> max = p[0];
			for ( int i = 1; i < 3; ++i ) {
				center += p[i];
				min = Vec3<float> ( std::fminf ( min.x, p[i].x ), std::fminf ( min.y, p[i].y ), std::fminf ( min.z, p[i].z ) );
				max = Vec3<float> ( std::fmaxf ( max.x, p[i].x ), std::fmaxf ( max.y, p[i].y ), std::fmaxf ( max.z, p[i].z ) );
			}
			center *= 1.f / 3.f;
			
			TriangleSymbol({ p[1], p[0], center, }).Generate(mesh, level - 1);
			TriangleSymbol({ p[2], p[1], center }).Generate(mesh, level - 1);
			TriangleSymbol({ p[0], p[2], center }).Generate(mesh, level - 1);
		}
		else {
			// Divise en 1 triangle et 1 Quadrangle
			Vec3<float> p4 = ( p[0] + p[1] ) * .5f;
			Vec3<float> p5 = ( p[0] + p[2] ) * .5f;

			TriangleSymbol({ p[0], p5, p4 }).Generate(mesh, level - 1);
			QuadrangleSymbol({ p[2] , p[1], p4, p5, Vec3<float>(0.f)}).Generate(mesh, level - 1);
		}
	}
}
