#include "../Mesh/Mesh.h"
#include "../Vec3.h"
#include "../Constantes.h"

/*
* Namespace contenant la creation des differentes primitives en Mesh (Factory)
*/
namespace Primitives
{
	/*
	* return : Mesh cercle
	* o : origine du cercle
	* r : rayon du cercle
	* side : nombre de cote discretises du cercle
	*/

	Mesh circle(const Vec3<float>& o, const float r, const unsigned int side)
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
	* return : Mesh cylindre (centre en 0, 0, 0)
	* h : hauteur du cylindre
	* r : rayon du cylindre
	* nbmeridien : nombre de cote discretises du cylindre
	*/
	Mesh cylinder(const float h, const float r, const unsigned int nbmeridien)
	{
		const float dmeridien = 2.f * Constantes::PI / nbmeridien;
		const float hsur2 = h * .5f;
		const unsigned int size = nbmeridien << 1;
		std::vector<Vec3<float>> points;
		std::vector<Vec3<unsigned int>> faces;
		points.resize(size + 2);
		faces.resize(size << 1);
		for (unsigned int i = 0; i < nbmeridien; ++i)
		{
			const float angle = (float)i * dmeridien;
			const float rcosi = r * cos(angle);
			const float rsini = r * sin(angle);
			const int iPoint = i << 1;
			//const int iFace = i << 1;

			points[iPoint] = Vec3<float>(rcosi, rsini, hsur2);
			points[iPoint + 1] = Vec3<float>(rcosi, rsini, -hsur2);
		}
		points[size] = Vec3<float>(0.f, 0.f, hsur2); // centre des cercles au plus haut et 
		points[size + 1] = Vec3<float>(0.f, 0.f, -hsur2); // au plus bas
		for (unsigned int i = 0; i < nbmeridien - 1 ; ++i)
		{
			const int iFace = i << 1;
			faces[iFace] = Vec3<unsigned int>(iFace + 1, iFace + 2, iFace + 3);
			faces[iFace + 1] = Vec3<unsigned int>(iFace + 2, iFace + 4, iFace + 3);
		}
		// deroulage de la boucle pour eviter un modulo a chaque tour
		faces[size - 2] = Vec3<unsigned int>(size - 1, size, 1);
		faces[size - 1] = Vec3<unsigned int>(size, 2, 1);

		for (unsigned int i = 0; i < nbmeridien - 1; i++)
		{
			faces[size + i] = Vec3<unsigned int>(size + 1, (i << 1) + 1,( (i + 1) << 1) + 1) ;
		}

		// deroulage de la boucle pour eviter un modulo a chaque tour
		faces[size + nbmeridien - 1] = Vec3<unsigned int>(size + 1, size - 1, 1);

		for (unsigned int i = 0; i < nbmeridien - 1; i++)
		{
			faces[size + nbmeridien + i] = Vec3<unsigned int>(size + 2, ((i + 1) << 1) + 2, (i << 1) + 2);
		}

		// deroulage de la boucle pour eviter un modulo a chaque tour
		faces[size + (nbmeridien << 1) - 1] = Vec3<unsigned int>(size + 2, 2, size);

		Mesh res(points, faces, std::vector<Vec3<unsigned int>>(), std::vector<Vec3<unsigned int>>(), std::vector<Vec3<float>>(), std::vector<Vec3<float>>());
		return res;
	}

	/*
	* return : Mesh cube (centre en 0, 0, 0)
	* size : distance entre le centre et le cote du cube respectivement en x, y et z ("rayon")
	*/
	Mesh box(const Vec3<float> & size)
	{
		
		const unsigned int sizePoints = 8 ;
		const unsigned int sizeFaces = 12;

		Vec3<float> tabpoint[sizePoints] = {Vec3<float>(-size.x, size.y, size.z),
							Vec3<float>(-size.x, size.y, -size.z),
							Vec3<float>(size.x, size.y, -size.z),
							size,
			

							Vec3<float>(-size.x, -size.y, size.z),
							Vec3<float>(-size.x, -size.y, -size.z),
							Vec3<float>(size.x, -size.y, -size.z),
							Vec3<float>(size.x, -size.y, size.z)};

		std::vector<Vec3<float>> points(tabpoint,tabpoint+sizePoints);


		Vec3<unsigned int> tabface[sizeFaces] = {Vec3<unsigned int>(1, 5, 4),
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
										Vec3<unsigned int>(6, 7, 8)};

		std::vector<Vec3<unsigned int>> faces(tabface,tabface+sizeFaces);

		return  Mesh(points, faces, std::vector<Vec3<unsigned int>>(), std::vector<Vec3<unsigned int>>(), std::vector<Vec3<float>>(), std::vector<Vec3<float>>());

	}
}