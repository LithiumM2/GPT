#include "PentagoneMesh.h"

PentagoneMesh::~PentagoneMesh ( ) {
}

void PentagoneMesh::setPoints ( std::vector<Vec3<float>> points_ ) {
	for ( unsigned i = 0; i < 3; ++i ) {
		Points[i] = points_[i];
	}

	points = points_;

	faces = std::vector<Vec3<unsigned int>> ( 3 );
	faces[0] = Vec3<unsigned int> ( 2, 1, 3 );
	faces[1] = Vec3<unsigned int> ( 1, 4, 3 );
	faces[2] = Vec3<unsigned int> ( 1, 5, 4 );

	calculateNormals ( );
}
