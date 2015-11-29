#pragma once
#include "..\Symbol.h"
#include "..\..\Utils.h"
#include "TriangleSymbol.h"
#include "../BatimentQuadra/RDC.h"
#include <list>

class QuadrangleSymbol :
	public Symbol {
private :
	void addTrees(Quadrangle q, Vec3<float> minQuad, Vec3<float> maxQuad, Mesh & m, std::list<Quadrangle> rdcs, int nbTryTree) const;
public:
	Vec3<float> p0, p1, p2, p3,mid ,loin;
	QuadrangleSymbol(const Vec3<float>&, const Vec3<float>&, const Vec3<float>&, const Vec3<float>&, const Vec3<float>&, const Vec3<float>&);
	QuadrangleSymbol();
	~QuadrangleSymbol ( );
	/* Methode realisant la grammaire de subdivision du mesh
	* mesh : Mesh
	* compteur : nombre d'appel reccursif max de la grammaire du plan
	*/
	void Generate(Mesh &mesh, int compteur) const;
	/* Genere un quadrangle symbole et un mesh avec une bordure de route
	* p1, p2, p3, p4 : coordonnées du quadrangle de base
	* borderSize : largeur de la bordure
	* sizePavement, hPavement : dimension du trottoir
	* m : mesh auquel on rajoute la bordure
	* mid : milieu pour definir le centre ville
	*/
	static QuadrangleSymbol genBorder(const Vec3<float>&, const Vec3<float>&, const Vec3<float>&, const Vec3<float>&, const float&, const float&, const float&, Mesh&, const Vec3<float>& ,const Vec3<float>&);
};

