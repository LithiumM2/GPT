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
}


