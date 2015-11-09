#pragma once
#include "..\Vec3.h"
#include "..\Transform\Transform.h"
#include "..\Geometry\Quadrangle.h"
#include <vector>
#include <iostream>
#include "../Constantes.h"

/*
* classe representant un Mesh
*/
class Mesh {
protected:
	/*
	* Vecteur des coordonnes des points du mesh
	*/
	std::vector<Vec3<float>> points;
	
	/*
	* Vecteur des faces du mesh, contenant les indices des points
	*/
	std::vector<Vec3<unsigned int>> faces;
	
	/*
	* Vecteur des faces du mesh, contenant les indices des coordonnees de textures
	*/
	std::vector<Vec3<unsigned int>> facesTextures;
	
	/*
	* Vecteur des faces du mesh, contenant les indices des coordonnees des normales par face
	*/
	std::vector<Vec3<unsigned int>> facesNormalesIndex;
	
	/*
	* Vecteur des coordonnees de textures du mesh
	*/
	std::vector<Vec3<float>> textures;
	
	/*
	* Vecteur des coordonnees de normales du mesh par face
	*/
	std::vector<Vec3<float>> facesNormales;
	
	/*
	* Vecteur des coordonnees de normales du mesh par vertices
	*/
	std::vector<Vec3<float>> verticesNormales;


public:

	/*
	* Centre de gravite du mesh
	*/
	Vec3<float> pivot;
	Mesh ( );
	Mesh ( std::vector<Vec3<float>> points_, std::vector<Vec3<unsigned int>> faces_, std::vector<Vec3<unsigned int>> facesTextures_, std::vector<Vec3<unsigned int>> facesNormales_, std::vector<Vec3<float>> textures_, std::vector<Vec3<float>> normales_ );
	Mesh ( std::vector<Vec3<float>> points_, std::vector<Vec3<unsigned int>> faces_, std::vector<Vec3<unsigned int>> facesTextures_, std::vector<Vec3<float>> textures_ );
	Mesh ( const Mesh & mesh );

	std::vector<Vec3<float>> getPoints ( ) const;
	std::vector<Vec3<unsigned int>> getFaces ( ) const;
	std::vector<Vec3<float>> getTextures ( ) const;
	std::vector<Vec3<float>> getFacesNormales ( ) const;
	std::vector<Vec3<unsigned int>> getFacesTextures ( ) const;
	std::vector<Vec3<unsigned int>> getFacesNormalesIndex ( ) const;
	std::vector<Vec3<float>> getVerticesNormales ( ) const;
	
	Vec3<float> getPivot ( );

	void calculateNormals ( );

	/* Application d'une transformation au mesh
	* t : transformation
	*/
	void transform ( Transform t );

	/* Merge du mesh courant avec un autre
	* m : mesh a fusionner
	*/
	void merge ( const Mesh & m );


	static Mesh Triangle ( const Vec3<float>& p1, const Vec3<float>& p2, const Vec3<float>& p3 );
	static Mesh Quadrangle(const Vec3<float>& p0, const Vec3<float>& p1, const Vec3<float>& p2, const Vec3<float>& p3 );
	//static Mesh Box ( );
	static Mesh Prism(const Vec3<float>&, const Vec3<float>&, const Vec3<float>&, const Vec3<float>&, const double&);
	static Mesh Cylinder(const Vec3<float>&, const double&, const double&);
	static Mesh Circle(const Vec3<float>& o, const float&, const unsigned int&);

	~Mesh();
};

/*


class ETA {
protected:
	Quadrangle q;
	double h;
public:
	ETA(const Vec3<float>&, const Vec3<float>&, const Vec3<float>&, const Vec3<float>&, const double&);
	void G(Mesh&) const;
};

class TOIT {
protected:
	Quadrangle q;
	double h;
public:
	TOIT(const Vec3<float>&, const Vec3<float>&, const Vec3<float>&, const Vec3<float>&, const double&);
	void G(Mesh&) const;
};

RDC::RDC(const Vec3<float>& a , const Vec3<float>& b, const Vec3<float>& c, const Vec3<float>& d, const double& h)
{
	q = Quadrangle(a, b, c, d);
	RDC::h = h;
}

void RDC::G(Mesh& m) const
{
	m.merge(Mesh::Prism(q.p1, q.p1, q.p1, q.p1,h));
	
	// La grammaire commence ici
	int e = rand() % 2;
	if (e == 0)
	{
		ETA(q.p1 + Vec3<float>(0.0, 0.0, h), q.p1 + Vec3<float>(0.0, 0.0, h), q.p1 + Vec3<float>(0.0, 0.0, h), q.p1 + Vec3<float>(0.0, 0.0, h), h + 0.25).G(m);
	}
	else
	{
		TOIT(q.p1 + Vec3<float>(0.0, 0.0, h), q.p1 + Vec3<float>(0.0, 0.0, h), q.p1 + Vec3<float>(0.0, 0.0, h), q.p1 + Vec3<float>(0.0, 0.0, h), 1.0).G(m);

	}
}*/
