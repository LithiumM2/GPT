#include "TriangleSymbol.h"


TriangleSymbol::TriangleSymbol ( Vec3<float> a, Vec3<float> b, Vec3<float> c)
{ 
	p[0] = a;
	p[1] = b;
	p[2] = c;

}

// TODO
void TriangleSymbol::Generate ( Mesh &mesh, int level ) const {
	if ( ( level == 0 ) || ( Triangle ( p[0], p[1], p[2] ).area ( ) ) < 1.f ) {
		Mesh m = Mesh::Triangle ( p[0], p[1], p[2] );
		m.transform ( Transform::Shrink ( .9f, m.getPivot ( ) ) );
		mesh.merge ( m );
		//Bloc( p[0], p[1], p[2] ).G(mesh);
	}
	else {
		int random = rand ( ) % 100;

		if ( random < 50 ) {
			// Divise le triangle en 2 triangles
			TriangleSymbol ( p[0], p[1], 0.5f * ( p[2] + p[1] ) ).Generate ( mesh, level - 1 );
			TriangleSymbol ( p[0], 0.5f*( p[2] + p[1] ), p[2] ).Generate ( mesh, level - 1 );
		}
		else {
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
			
			TriangleSymbol ( { center, p[0], p[1] } ).Generate ( mesh, level - 1 );
			TriangleSymbol ( { center, p[1], p[2] } ).Generate ( mesh, level - 1 );
			TriangleSymbol ( { center, p[2], p[0] } ).Generate ( mesh, level - 1 );
		}
	}
}

// Old
//void TriangleSymbol::Generate ( Mesh &mesh, int level ) const {
//	if ( level > 0 ) {
//		// Divise en 2 triangles
//		/*std::vector<Vec3<float>> points = mesh.getPoints ( );
//
//		TriangleMesh t = TriangleMesh ( points );
//		Triangle* t_ = t.divideIn2Triangles ( .4f, .6f );
//
//		TriangleMesh t1 = TriangleMesh ( t_[0].getPoints ( ) );
//		TriangleMesh t2 = TriangleMesh ( t_[1].getPoints ( ) );
//
//		t1.transform ( Transform::Shrink ( .9f, t1.getPivot ( ) ) );
//		t2.transform ( Transform::Shrink ( .9f, t2.getPivot ( ) ) );
//
//		t1.merge ( t2 );
//
//		mesh = t1;*/
//
//		// Divise en 3 triangle
//		/*int random = rand ( ) % 100;
//
//		if ( random < 80 ) {
//			Vec3<float> center = points[0];
//			Vec3<float> min = points[0];
//			Vec3<float> max = points[0];
//			for ( int i = 1; i < points.size ( ); ++i ) {
//				center += points[i];
//				min = Vec3<float> ( std::fminf ( min.x, points[i].x ), std::fminf ( min.y, points[i].y ), std::fminf ( min.z, points[i].z ) );
//				max = Vec3<float> ( std::fmaxf ( max.x, points[i].x ), std::fmaxf ( max.y, points[i].y ), std::fmaxf ( max.z, points[i].z ) );
//			}
//			center *= 1.f / ( float ) points.size ( );
//
//			TriangleMesh m1 = TriangleMesh ( std::vector<Vec3<float>> { center, points[0], points[1] } );
//			TriangleMesh m2 = TriangleMesh ( std::vector<Vec3<float>> { center, points[1], points[2] } );
//			TriangleMesh m3 = TriangleMesh ( std::vector<Vec3<float>> { center, points[2], points[0] } );
//
//			m1.transform ( Transform::Shrink ( .9f, m1.getPivot ( ) ) );
//			m2.transform ( Transform::Shrink ( .9f, m2.getPivot ( ) ) );
//			m3.transform ( Transform::Shrink ( .9f, m3.getPivot ( ) ) );
//
//			TriangleSymbol ( ).Generate ( m1, level - 1 );
//			TriangleSymbol ( ).Generate ( m2, level - 1 );
//			TriangleSymbol ( ).Generate ( m3, level - 1 );
//
//			m1.merge ( m2 );
//			m1.merge ( m3 );
//
//			mesh = m1;
//		}*/
//	}
//}
