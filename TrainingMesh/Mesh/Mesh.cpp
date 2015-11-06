#include "Mesh.h"


Mesh::Mesh() : points(std::vector<Vec3<float>>()), faces(std::vector<Vec3<unsigned int>>()){};
Mesh::Mesh(std::vector<Vec3<float>> points_, std::vector<Vec3<unsigned int>> faces_, std::vector<Vec3<unsigned int>> facesTextures_, std::vector<Vec3<unsigned int>> facesNormales_, std::vector<Vec3<float>> textures_, std::vector<Vec3<float>> normales_)
	: points(points_), faces(faces_), textures(textures_), facesTextures(facesNormales_), facesNormales(facesNormales_), normales(normales_)
{
	pivot = Vec3<float>(0.f);
	for (unsigned int i = 0; i < points_.size(); ++i)
	{
		pivot += points[i];
	}
	pivot / (float)points_.size();
}

Mesh::Mesh(const Mesh & mesh) 
	: points(mesh.points), faces(mesh.faces), textures(mesh.textures), facesTextures(mesh.facesNormales), facesNormales(mesh.facesNormales), normales(mesh.normales), pivot(mesh.pivot){};

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

std::vector<Vec3<float>> Mesh::getNormales() const
{
	return normales;
}

std::vector<Vec3<unsigned int>> Mesh::getFacesTextures() const
{
	return facesTextures;
}

std::vector<Vec3<unsigned int>> Mesh::getFacesNormales() const
{
	return facesNormales;
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
	std::vector<Vec3<unsigned int>> newFacesNormales = m.getFacesNormales();

	std::vector<Vec3<float>> newPoints = m.getPoints();
	std::vector<Vec3<float>> newTextures = m.getTextures();
	std::vector<Vec3<float>> newNormales = m.getNormales();

	Vec3<unsigned int> offset(points.size());

	for (unsigned int i = 0; i < newFaces.size(); ++i)
		newFaces[i] += offset;
	for (unsigned int i = 0; i < newFacesTextures.size(); ++i)
		newFacesTextures[i] += offset;
	for (unsigned int i = 0; i < newFacesNormales.size(); ++i)
		newFacesNormales[i] += offset;

	faces.insert(faces.end(), newFaces.begin(), newFaces.end());
	facesTextures.insert(facesTextures.end(), newFacesTextures.begin(), newFacesTextures.end());
	facesNormales.insert(facesNormales.end(), newFacesNormales.begin(), newFacesNormales.end());
	
	points.insert(points.end(), newPoints.begin(), newPoints.end());
	textures.insert(textures.end(), newTextures.begin(), newTextures.end());
	normales.insert(normales.end(), newNormales.begin(), newNormales.end());
}

Mesh::~Mesh()
{
}
