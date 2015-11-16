#include "TriangleSymbol.h"


TriangleSymbol::TriangleSymbol ( const Vec3<float> &a, const Vec3<float> &b, const Vec3<float> &c )
{ 
	p[0] = a;
	p[1] = b;
	p[2] = c;

}

void TriangleSymbol::Generate ( Mesh &mesh, int level ) const {
	if ( ( level == 0 ) || Triangle ( p[0], p[1], p[2] ).area ( ) < 1000.f ) {
		Triangle t ( p[0], p[1], p[2] );
		t.shrinkByDist ( 10.f );
		Mesh m = Mesh::Triangle ( t.getPoints ( )[0], t.getPoints ( )[1], t.getPoints ( )[2] );
		//m.transform ( Transform::Shrink ( .95f, m.getPivot ( ) ) );
		mesh.merge ( m );
		//Bloc( p[0], p[1], p[2] ).G(mesh);
	}
	else {
		int random = rand ( ) % 100;

		if ( random < 33 ) {
			// Divise le triangle en 2 triangles
			float rand;
			float a = distance ( p[1], p[2] );
			float b = distance ( p[0], p[1] );
			float c = distance ( p[0], p[2] );

			//rand = .4f + static_cast <float> ( std::rand ( ) ) / ( static_cast <float> ( RAND_MAX / ( .6f - .4f ) ) ); // Marche pas avec ...
			rand = .5f;

			Vec3<float> *t1 = nullptr;
			Vec3<float> *t2 = nullptr;;
			Vec3<float> p_;
			if ( a > b && a > c ) {
				p_ = ( p[1] + p[2] ) * rand;

				t1 = Triangle ( p_, p[1], p[0] ).getPoints ( );
				t2 = Triangle ( p[2], p_, p[0] ).getPoints ( );
			} else if ( b > a && b > c ) {
				p_ = ( p[0] + p[1] ) * rand;

				t1 = Triangle ( p_, p[1], p[2] ).getPoints ( );
				t2 = Triangle ( p[2], p_, p[0] ).getPoints ( );
			} else if ( c > a && c > b ) {
				p_ = ( p[0] + p[2] ) * rand;

				t1 = Triangle ( p_ ,p[1], p[0] ).getPoints ( );
				t2 = Triangle ( p[1], p_, p[2]).getPoints ( );
			}

			
			TriangleSymbol ( t1[0], t1[1], t1[2] ).Generate ( mesh, level - 1 );
			TriangleSymbol ( t2[0], t2[1], t2[2] ).Generate ( mesh, level - 1 );

			//TriangleSymbol ( 0.5f * ( p[2] + p[1] ), p[1], p[0] ).Generate ( mesh, level - 1 );
			//TriangleSymbol ( p[2], 0.5f * ( p[2] + p[1] ), p[0] ).Generate ( mesh, level - 1 );
		}
		else if ( random < 45) {
			// Divise le triangle en 3 triangles
			Vec3<float> pivot ( .0f );
			for ( unsigned int i = 0; i < 3; ++i ) {
				pivot += p[i];
			}
			pivot = pivot / 3.f;

			
			TriangleSymbol ( { p[1], pivot, p[0] } ).Generate ( mesh, level - 1 );
			TriangleSymbol ( { p[2], pivot, p[1] } ).Generate ( mesh, level - 1 );
			TriangleSymbol ( { p[0], pivot, p[2] } ).Generate ( mesh, level - 1 );
		}
		else {
			// Divise en 1 triangle et 1 Quadrangle
			float rand;
			float a = distance ( p[1], p[2] );
			float b = distance ( p[0], p[1] );
			float c = distance ( p[0], p[2] );

			//rand = .4f + static_cast <float> ( std::rand ( ) ) / ( static_cast <float> ( RAND_MAX / ( .6f - .4f ) ) );
			rand = .5f;

			Vec3<float> p4;// = ( p[0] + p[1] ) * .5f;
			Vec3<float> p5;// = ( p[0] + p[2] ) * .5f;

			if ( a >= c && b >= c ) {
				p4 = ( p[1] + p[2] ) * rand;
				p5 = ( p[0] + p[1] ) * rand;
			}

			if ( b >= a && c >= a ) {
				p4 = ( p[0] + p[1] ) * rand;
				p5 = ( p[0] + p[2] ) * rand;
			}

			if ( c >= b && a >= b ) {
				p4 = ( p[0] + p[2] ) * rand;
				p5 = ( p[1] + p[2] ) * rand;
			}


			TriangleSymbol({ p[0], p5, p4 }).Generate(mesh, level - 1);
			QuadrangleSymbol({ p[2], p[1], p4, p5, Vec3<float>(0.f), Vec3<float>(0.f) }).Generate(mesh, level - 1); //Changer le Vecteur pour le MID
			//TriangleSymbol ( { p[0], p5, p4 } ).Generate ( mesh, level - 1 );
			////QuadrangleSymbol ( { p[2], p[1], p4, p5, } ).Generate ( mesh, level - 1 );
		}
	}
}
