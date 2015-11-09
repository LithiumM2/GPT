#include "TriangleSymbol.h"


TriangleSymbol::TriangleSymbol ( ) {
}


TriangleSymbol::~TriangleSymbol ( ) {
}

void TriangleSymbol::Generate ( Mesh &mesh, int level ) const {
	if ( level > 0 ) {
		std::vector<Vec3<float>> points = mesh.getPoints ( );

		Vec3<float> center = points[0];
		Vec3<float> min = points[0];
		Vec3<float> max = points[0];
		for ( int i = 1; i < points.size ( ); ++i ) {
			center += points[i];
			min = Vec3<float> ( std::fminf ( min.x, points[i].x ), std::fminf ( min.y, points[i].y ), std::fminf ( min.z, points[i].z ) );
			max = Vec3<float> ( std::fmaxf ( max.x, points[i].x ), std::fmaxf ( max.y, points[i].y ), std::fmaxf ( max.z, points[i].z ) );
		}
		center *= 1.f / ( float ) points.size ( );

		TriangleMesh m1 = TriangleMesh ( std::vector<Vec3<float>> { center, points[0], points[1] } );
		TriangleMesh m2 = TriangleMesh ( std::vector<Vec3<float>> { center, points[1], points[2] } );
		TriangleMesh m3 = TriangleMesh ( std::vector<Vec3<float>> { center, points[2], points[0] } );

		m1.transform ( Transform::Shrink ( .9f, m1.getPivot ( ) ) );
		m2.transform ( Transform::Shrink ( .9f, m2.getPivot ( ) ) );
		m3.transform ( Transform::Shrink ( .9f, m3.getPivot ( ) ) );

		TriangleSymbol ( ).Generate ( m1, level - 1 );
		TriangleSymbol ( ).Generate ( m2, level - 1 );
		TriangleSymbol ( ).Generate ( m3, level - 1 );

		m1.merge ( m2 );
		m1.merge ( m3 );

		mesh = m1;
	}
}
