#pragma once
#include "..\Vec3.h"
#include "..\Transform\Transform.h"
#include <vector>
#include <iostream>

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

	/*
	* Centre de gravite du mesh
	*/
	Vec3<float> pivot;

public:
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
	~Mesh ( );

	static Mesh Triangle ( Vec3<float> p1, Vec3<float> p2, Vec3<float> p3 );
	static Mesh Quadrangle ( );
	//static Mesh Box ( );
};
