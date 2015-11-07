#include "TriangleMesh.h"

TriangleMesh::~TriangleMesh ( ) {
}

void TriangleMesh::setPoints ( std::vector<Vec3<float>> points_ ) {
	for ( unsigned i = 0; i < 3; ++i ) {
		Points[i] = points_[i];
	}

	points = points_;

	faces = std::vector<Vec3<unsigned int>> ( 1 );
	faces[0] = Vec3<unsigned int> ( 2, 1, 3 );

	calculateNormals ( );
}
