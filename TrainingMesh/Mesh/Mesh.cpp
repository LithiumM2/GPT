#include "Mesh.h"


Mesh::Mesh ( ) : points ( std::vector<Vec3<float>> ( ) ), faces ( std::vector<Vec3<unsigned int>> ( ) ) { };

Mesh::Mesh ( std::vector<Vec3<float>> points_, std::vector<Vec3<unsigned int>> faces_, std::vector<Vec3<unsigned int>> facesTextures_, std::vector<Vec3<unsigned int>> facesNormales_, std::vector<Vec3<float>> textures_, std::vector<Vec3<float>> normales_ )
	: points ( points_ ), faces ( faces_ ), textures ( textures_ ), facesTextures ( facesTextures_ ), facesNormalesIndex ( facesNormales_ ), facesNormales ( normales_ ) {
	pivot = Vec3<float> ( 0.f );
	for ( unsigned int i = 0; i < points_.size ( ); ++i ) {
		pivot += points[i];
	}
	pivot = pivot / ( float ) points_.size ( );
}

Mesh::Mesh ( std::vector<Vec3<float>> points_, std::vector<Vec3<unsigned int>> faces_, std::vector<Vec3<unsigned int>> facesTextures_, std::vector<Vec3<float>> textures_ )
	: points ( points_ ), faces ( faces_ ), textures ( textures_ ), facesTextures ( facesTextures_ ) {
	pivot = Vec3<float> ( 0.f );
	for ( unsigned int i = 0; i < points_.size ( ); ++i ) {
		pivot += points[i];
	}
	pivot = pivot / ( float ) points_.size ( );

	calculateNormals ( );
}

void Mesh::calculateNormals ( ) {
	// Calcule des normales par face
	std::cout << "Calculate face normals...\n";
	unsigned int facesCount = faces.capacity ( );
	facesNormalesIndex = std::vector<Vec3<unsigned int>> ( facesCount );
	facesNormales = std::vector<Vec3<float>> ( facesCount );

	for ( unsigned int i = 0; i < facesCount; ++i ) {
		Vec3<unsigned int> face = faces[i];
		Vec3<float> normal = Vec3<float>::crossProduct ( points[face.y] - points[face.x], points[face.z] - points[face.x] ).normalized ( );
		facesNormalesIndex[i] = face;
		facesNormales[i] = normal;
	}

	// Calcule des normales par vertex
	std::cout << "Calculate vertex normals...\n";
	unsigned int verticesCount = points.capacity ( );
	verticesNormales = std::vector<Vec3<float>> ( verticesCount );

	for ( unsigned int i = 0; i < verticesCount; ++i ) {
		Vec3<float> normal = { .0f, .0f, .0f };

		for ( unsigned int j = 0; j < facesCount; ++j ) {
			Vec3<unsigned int> face = faces[j];

			for ( unsigned int k = 0; k < verticesCount; ++k ) { // Obligé d'avoir des faces triangulaires ...
				if ( ( k == 0 && face.x == i ) ||
					 ( k == 1 && face.y == i ) ||
					 ( k == 2 && face.z == i ) ) {
					normal += facesNormales[j];
				}
			}

			verticesNormales[i] = normal.normalized ( );
		}
	}
}

Mesh::Mesh(const Mesh & mesh) 
	: points(mesh.points), faces(mesh.faces), textures(mesh.textures), facesTextures(mesh.facesNormalesIndex), facesNormalesIndex(mesh.facesNormalesIndex), facesNormales(mesh.facesNormales), pivot(mesh.pivot){};

std::vector<Vec3<float>> Mesh::getPoints() const
{
	return points;
}

std::vector<Vec3<unsigned int>> Mesh::getFaces() const
{
	return faces;
}

std::vector<Vec3<float>> Mesh::getTextures() const
{
	return textures;
}

std::vector<Vec3<float>> Mesh::getFacesNormales() const
{
	return facesNormales;
}

std::vector<Vec3<unsigned int>> Mesh::getFacesTextures() const
{
	return facesTextures;
}

std::vector<Vec3<unsigned int>> Mesh::getFacesNormalesIndex() const
{
	return facesNormalesIndex;
}

std::vector<Vec3<float>> Mesh::getVerticesNormales ( ) const {
	return verticesNormales;
}

/* Application d'une transformation au mesh
* t : transformation
*/
void Mesh::transform(Transform t)
{
	for (unsigned int i = 0; i < points.size(); ++i) {
				points[i] = t.m * points[i];
			}
}

/* Merge du mesh courant avec un autre
* m : mesh a fusionner
*/
void Mesh::merge(const Mesh & m)
{
	std::vector<Vec3<unsigned int>> newFaces = m.getFaces();
	std::vector<Vec3<unsigned int>> newFacesTextures = m.getFacesTextures();
	std::vector<Vec3<unsigned int>> newFacesNormales = m.getFacesNormalesIndex();

	std::vector<Vec3<float>> newPoints = m.getPoints();
	std::vector<Vec3<float>> newTextures = m.getTextures();
	std::vector<Vec3<float>> newNormales = m.getFacesNormales();

	Vec3<unsigned int> offset(points.size());

	for (unsigned int i = 0; i < newFaces.size(); ++i)
		newFaces[i] += offset;
	for (unsigned int i = 0; i < newFacesTextures.size(); ++i)
		newFacesTextures[i] += offset;
	for (unsigned int i = 0; i < newFacesNormales.size(); ++i)
		newFacesNormales[i] += offset;

	faces.insert(faces.end(), newFaces.begin(), newFaces.end());
	facesTextures.insert(facesTextures.end(), newFacesTextures.begin(), newFacesTextures.end());
	facesNormalesIndex.insert(facesNormalesIndex.end(), newFacesNormales.begin(), newFacesNormales.end());
	
	points.insert(points.end(), newPoints.begin(), newPoints.end());
	textures.insert(textures.end(), newTextures.begin(), newTextures.end());
	facesNormales.insert(facesNormales.end(), newNormales.begin(), newNormales.end());
}

Mesh::~Mesh()
{
}
