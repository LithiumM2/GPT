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

Vec3<float> Mesh::getPivot ( ) {
	pivot = Vec3<float> ( 0.f );
	for ( unsigned int i = 0; i < points.size ( ); ++i ) {
		pivot += points[i];
	}
	pivot = pivot / ( float ) points.size ( );

	return pivot;
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
		Vec3<float> normal = Vec3<float>( .0f, .0f, .0f );

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

/*
* return : Mesh triangle
* p0, p1, p2 : sommet du triangle
*/
Mesh Mesh::Triangle(const Vec3<float>& p0, const Vec3<float>& p1, const Vec3<float>& p2)
{
	std::vector<Vec3<float>> points(3);
	points[0] = p0;
	points[1] = p1;
	points[2] = p2;

	 std::vector<Vec3<unsigned int>> faces(1);
	faces[0] = Vec3<unsigned int>(2, 1, 3);

	return Mesh(points, faces, std::vector<Vec3<unsigned int>>(), std::vector<Vec3<unsigned int>>(), std::vector<Vec3<float>>(), std::vector<Vec3<float>>());
}

/*
* return : Mesh quadrangle
* p0, p1, p2, p3 : sommet du quadrangle
*/
Mesh Mesh::Quadrangle(const Vec3<float>& p0, const Vec3<float>& p1, const Vec3<float>& p2, const Vec3<float>& p3)
{
	std::vector<Vec3<float>> points(4);
	points[0] = p0;
	points[1] = p1;
	points[2] = p2;
	points[3] = p3;

	std::vector<Vec3<unsigned int>> faces(2);
	faces[0] = Vec3<unsigned int>(2, 1, 3);
	faces[1] = Vec3<unsigned int>(1, 4, 3);

	return Mesh(points, faces, std::vector<Vec3<unsigned int>>(), std::vector<Vec3<unsigned int>>(), std::vector<Vec3<float>>(), std::vector<Vec3<float>>());
}

/*
* return : Mesh pentagone
* p0, p1, p2, p3, p4 : sommet du pentagone
*/
Mesh Mesh::Pentagone(const Vec3<float>& p0, const Vec3<float>& p1, const Vec3<float>& p2, const Vec3<float>& p3, const Vec3<float>& p4)
{
	std::vector<Vec3<float>> points(5);
	points[0] = p0;
	points[1] = p1;
	points[2] = p2;
	points[3] = p3;
	points[4] = p4;

	std::vector<Vec3<unsigned int>> faces = std::vector<Vec3<unsigned int>>(3);
	faces[0] = Vec3<unsigned int>(2, 1, 3);
	faces[1] = Vec3<unsigned int>(1, 4, 3);
	faces[2] = Vec3<unsigned int>(1, 5, 4);

	return Mesh(points, faces, std::vector<Vec3<unsigned int>>(), std::vector<Vec3<unsigned int>>(), std::vector<Vec3<float>>(), std::vector<Vec3<float>>());
}

/*
* return : Mesh hexagone
* p0, p1, p2, p3, p4, p5 : sommet du hexagone
*/
Mesh Mesh::Hexagone(const Vec3<float>& p0, const Vec3<float>& p1, const Vec3<float>& p2, const Vec3<float>& p3, const Vec3<float>& p4, const Vec3<float>& p5)
{
	std::vector<Vec3<float>> points(6);
	points[0] = p0;
	points[1] = p1;
	points[2] = p2;
	points[3] = p3;
	points[4] = p4;
	points[5] = p5;


	std::vector<Vec3<unsigned int>>faces = std::vector<Vec3<unsigned int>>(4);
	faces[0] = Vec3<unsigned int>(2, 1, 4);
	faces[1] = Vec3<unsigned int>(2, 4, 3);
	faces[2] = Vec3<unsigned int>(1, 5, 4);
	faces[3] = Vec3<unsigned int>(1, 6, 5);


	return Mesh(points, faces, std::vector<Vec3<unsigned int>>(), std::vector<Vec3<unsigned int>>(), std::vector<Vec3<float>>(), std::vector<Vec3<float>>());
}

/* Creation d'un mesh de prisme (Box)
* return : Mesh box
* p0, p1, p2, p3 : base de la box
* h : hauteur de la box
*/
Mesh Mesh::Box(const Vec3<float>& p1, const Vec3<float>& p2, const Vec3<float>& p3, const Vec3<float>& p4, const float& h){

	const unsigned int sizePoints = 8;
	const unsigned int sizeFaces = 12; //12 Triangles

	Vec3<float> Points[sizePoints] = { p1+Vec3<float>(0.,0.,h),
										p2+Vec3<float>(0.,0.,h),
										p3+Vec3<float>(0.,0.,h),
										p4 + Vec3<float>(0., 0., h),
										p1,
										p2,
										p3,
										p4
									
	};

	std::vector<Vec3<float>> points(Points, Points + sizePoints);


	Vec3<unsigned int> Faces[12] = { Vec3<unsigned int>(1, 5, 4),
									Vec3<unsigned int>(5, 8, 4),

									Vec3<unsigned int>(2, 1, 3),
									Vec3<unsigned int>(1, 4, 3),

									Vec3<unsigned int>(2, 6, 1),
									Vec3<unsigned int>(6, 5, 1),

									Vec3<unsigned int>(4, 8, 3),
									Vec3<unsigned int>(8, 7, 3),

									Vec3<unsigned int>(3, 7, 2),
									Vec3<unsigned int>(7, 6, 2),

									Vec3<unsigned int>(5, 6, 8),
									Vec3<unsigned int>(6, 7, 8)
	};

	std::vector<Vec3<unsigned int>> faces(Faces, Faces + sizeFaces);

	return  Mesh(points, faces, std::vector<Vec3<unsigned int>>(), std::vector<Vec3<unsigned int>>(), std::vector<Vec3<float>>(), std::vector<Vec3<float>>());

}

/*
* return : Mesh cercle
* o : origine du cercle
* r : rayon du cercle
* side : nombre de cote discretises du cercle
*/

Mesh Mesh::Circle(const Vec3<float>& o, const float & r, const unsigned int & side)
{
	const float dsize = 2.f * Constantes::PI / (float)side;
	unsigned int facesSize = side;
	std::vector<Vec3<float>> points;
	std::vector<Vec3<unsigned int>> faces;
	points.resize(side + 1);
	faces.resize(facesSize);
	points[0] = o;

	for (unsigned int i = 1; i <= side; ++i)
	{
		const float angle = (float)i * dsize;
		points[i] = Vec3<float>(o.x + r * cos(angle), o.y + r * sin(angle), o.z);

	}
	for (unsigned int i = 1; i < facesSize; ++i)
	{
		const unsigned int tmpi = i;// << 1;
		faces[i - 1] = Vec3<unsigned int>(1, tmpi + 1, tmpi + 2);
	}
	faces[facesSize - 1] = Vec3<unsigned int>(1, facesSize + 1, 2);
	return Mesh(points, faces, std::vector<Vec3<unsigned int>>(), std::vector<Vec3<unsigned int>>(), std::vector<Vec3<float>>(), std::vector<Vec3<float>>());
}

/*
* return : Mesh route
* p0, p1, p2, p3 : sommet du quadrangle
* sizePavement : taille d'un trottoir
*/
Mesh Mesh::Route(const Vec3<float>& p0, const Vec3<float>& p1, const Vec3<float>& p2, const Vec3<float>& p3, const float& sizePavement)
{
	const float hPavement = 20.f;
	Vec3<float> shiftPavementZ(0.f, 0.f, hPavement);
	Vec3<float> shiftPavementY(sizePavement, 0.f, 0.f);
	Mesh res;
	res.merge(Mesh::Box(p0 - shiftPavementZ, p1 - shiftPavementZ, p1 - shiftPavementZ + (Vec3<float>(p2 - p1).normalized() * sizePavement), p0 - shiftPavementZ + (Vec3<float>(p3 - p0).normalized() * sizePavement), hPavement));
	res.merge(Mesh::Quadrangle(p0 - shiftPavementZ, p1 - shiftPavementZ, p2 - shiftPavementZ, p3 - shiftPavementZ));
	res.merge(Mesh::Box(p2 - shiftPavementZ, p3 - shiftPavementZ, p3 - shiftPavementZ + (Vec3<float>(p0 - p3).normalized() * sizePavement), p2 - shiftPavementZ + (Vec3<float>(p1 - p2).normalized() * sizePavement), hPavement));
	return res;
}

Mesh::~Mesh()
{
}
