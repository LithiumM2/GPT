#include "QuadrangleMesh.h"

QuadrangleMesh::~QuadrangleMesh ( ) {
}

void QuadrangleMesh::setPoints ( std::vector<Vec3<float>> points_ ) {
	p1 = points_[0];
	p2 = points_[1];
	p3 = points_[2];
	p4 = points_[3];

	points = points_;

	faces = std::vector<Vec3<unsigned int>> ( 2 );
	faces[0] = Vec3<unsigned int> ( 2, 1, 3 );
	faces[1] = Vec3<unsigned int> ( 1, 4, 3 );

	calculateNormals ( );
}
