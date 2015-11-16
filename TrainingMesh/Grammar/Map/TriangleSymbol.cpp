#include "TriangleSymbol.h"


TriangleSymbol::TriangleSymbol ( const Vec3<float> &a, const Vec3<float> &b, const Vec3<float> &c, const Vec3<float> & mid_ )
{ 
	p1 = a;
	p2 = b;
	p3 = c;
	mid = mid_;
}

void TriangleSymbol::Generate ( Mesh &mesh, int level ) const {
	if ( ( level == 0 ) ) {
		Triangle t ( p2, p1, p3 );
		t.shrinkByDist ( 10.f );
		Mesh m = Mesh::Triangle ( t.getPoints ( )[0], t.getPoints ( )[1], t.getPoints ( )[2] );
		mesh.merge ( m );
	}
	else {
		int random = rand ( ) % 100;

		if ( random < 33 && Triangle ( p2, p1, p3 ).area ( ) > 2500.f ) {
			// Divise le triangle en 2 triangles
			float rand;
			float a = distance ( p2, p3 );
			float b = distance ( p1, p2 );
			float c = distance ( p1, p3 );

			//rand = .4f + static_cast <float> ( std::rand ( ) ) / ( static_cast <float> ( RAND_MAX / ( .6f - .4f ) ) ); // Marche pas avec ...
			rand = .5f;

			Vec3<float> *t1 = nullptr;
			Vec3<float> *t2 = nullptr;;
			Vec3<float> p_;
			if ( a >= b && a >= c ) {
				p_ = ( p2 + p3 ) * rand;

				t1 = Triangle ( p_, p2, p1 ).getPoints ( );
				t2 = Triangle ( p3, p_, p1 ).getPoints ( );
			} else if ( b >= a && b >= c ) {
				p_ = ( p1 + p2 ) * rand;

				t1 = Triangle ( p2, p_, p3 ).getPoints ( );
				t2 = Triangle ( p3, p_, p1 ).getPoints ( );
			} else if ( c >= a && c >= b ) {
				p_ = ( p1 + p3 ) * rand;

				t1 = Triangle ( p_, p2, p1 ).getPoints ( );
				t2 = Triangle ( p2, p_, p3 ).getPoints ( );
			}

			
			TriangleSymbol ( t1[1], t1[0], t1[2], mid ).Generate ( mesh, level - 1 );
			TriangleSymbol ( t2[1], t2[0], t2[2], mid ).Generate ( mesh, level - 1 );

			//TriangleSymbol ( 0.5f * ( p[2] + p[1] ), p[1], p[0] ).Generate ( mesh, level - 1 );
			//TriangleSymbol ( p[2], 0.5f * ( p[2] + p[1] ), p[0] ).Generate ( mesh, level - 1 );
		}
		else if ( random < 40 && Triangle ( p2, p1, p3 ).area ( ) > 20000.f ) {
			// Divise le triangle en 3 triangles
			Vec3<float> pivot ( .0f );		
			pivot += p1;
			pivot += p2;
			pivot += p3;
			pivot = pivot / 3.f;

			
			TriangleSymbol ( p2, p1, pivot, mid ).Generate ( mesh, level - 1 );
			TriangleSymbol ( p3, p2, pivot, mid ).Generate ( mesh, level - 1 );
			TriangleSymbol ( p1, p3, pivot, mid ).Generate ( mesh, level - 1 );
		}
		else if ( random < 60 && Triangle ( p2, p1, p3 ).area ( ) > 5000.f ) {
			// Divise en 1 triangle et 1 Quadrangle
			float rand;
			float a = distance ( p2, p3 );
			float b = distance ( p1, p2 );
			float c = distance ( p1, p3 );

			//rand = .4f + static_cast <float> ( std::rand ( ) ) / ( static_cast <float> ( RAND_MAX / ( .6f - .4f ) ) );
			rand = .5f;

			Vec3<float> p4;
			Vec3<float> p5;
			
			if ( a >= c && b >= c ) {
				p4 = ( p2 + p3 ) * rand;
				p5 = ( p1 + p2 ) * rand;

				TriangleSymbol ( p2, p5, p4, mid ).Generate ( mesh, level - 1 );
				QuadrangleSymbol ( p1, p3, p4, p5, mid ).Generate ( mesh, level - 1 );
			} else if ( b >= a && c >= a ) {
				p4 = ( p1 + p2 ) * rand;
				p5 = ( p1 + p3 ) * rand;

				TriangleSymbol ( p1, p5, p4, mid ).Generate ( mesh, level - 1 );
				QuadrangleSymbol ( p3, p5, p4, p2, mid ).Generate ( mesh, level - 1 );
			} else if ( c >= b && a >= b ) {
				p4 = ( p1 + p3 ) * rand;
				p5 = ( p2 + p3 ) * rand;

				TriangleSymbol ( p3, p5, p4, mid ).Generate ( mesh, level - 1 );
				QuadrangleSymbol ( p2, p1, p4, p5, mid ).Generate ( mesh, level - 1 );
			}		
		}
		else {
			// TODO : Générer des batiments
		}
	}
}


TriangleSymbol TriangleSymbol::genBorder ( const Vec3<float>& p1_, const Vec3<float>& p2_, const Vec3<float>& p3_, const float& borderSize, const float& sizePavement, const float& hPavement, Mesh& m, const Vec3<float>& _mid ) {
	Triangle t ( p2_, p1_, p3_ );
	Triangle t2 ( t );

	t.shrinkByDist ( borderSize );

	Vec3<float>
		p11 = t.getPoints ( )[0],
		p12 = t.getPoints ( )[1],
		p13 = t.getPoints ( )[2];

	Vec3<float>
		p21 = t2.getPoints ( )[0],
		p22 = t2.getPoints ( )[1],
		p23 = t2.getPoints ( )[2];

	TriangleSymbol ts ( p12, p11, p13, _mid );

	m.merge ( Mesh::RouteR ( p21, p22, p12, p11, sizePavement, hPavement ) );
	m.merge ( Mesh::RouteR ( p23, p21, p11, p13, sizePavement, hPavement ) );
	m.merge ( Mesh::RouteR ( p22, p23, p13, p12, sizePavement, hPavement ) );

	return ts;
}
