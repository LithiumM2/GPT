#include "TriangleSymbol.h"


TriangleSymbol::TriangleSymbol ( const Vec3<float> &a, const Vec3<float> &b, const Vec3<float> &c, const Vec3<float> & mid_, const Vec3<float> & loin_ )
{ 
	p1 = a;
	p2 = b;
	p3 = c;
	mid = mid_;
	loin = loin_;
}

void TriangleSymbol::Generate ( Mesh &mesh, int level ) const {
	if ( ( level == 0 ) ) {
		Triangle t ( p2, p1, p3 );
		t.shrinkByDist ( 10.f );
		Mesh m = Mesh::Triangle ( t.getPoints ( )[0], t.getPoints ( )[1], t.getPoints ( )[2] );
		m.merge ( Mesh::RouteL ( p2, p1, t.getPoints ( )[1], t.getPoints ( )[0], 3.f, 1.f ) );
		m.merge ( Mesh::RouteL ( p1, p3, t.getPoints ( )[2], t.getPoints ( )[1], 3.f, 1.f ) );
		m.merge ( Mesh::RouteL ( p3, p2, t.getPoints ( )[0], t.getPoints ( )[2], 3.f, 1.f ) );
		mesh.merge ( m );
	}
	else {
		int random = rand ( ) % 100;

		if ( random < 35 && Triangle ( p2, p1, p3 ).area ( ) > 2500.f ) {
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

			
			TriangleSymbol ( t1[1], t1[0], t1[2], mid, loin ).Generate ( mesh, level - 1 );
			TriangleSymbol ( t2[1], t2[0], t2[2], mid, loin ).Generate ( mesh, level - 1 );

			//TriangleSymbol ( 0.5f * ( p[2] + p[1] ), p[1], p[0] ).Generate ( mesh, level - 1 );
			//TriangleSymbol ( p[2], 0.5f * ( p[2] + p[1] ), p[0] ).Generate ( mesh, level - 1 );
		}
		//else if ( random < 45 && Triangle ( p2, p1, p3 ).area ( ) > 20000.f ) { Rendu mauvais
		//	// Divise le triangle en 3 triangles
		//	Vec3<float> pivot ( .0f );		
		//	pivot += p1;
		//	pivot += p2;
		//	pivot += p3;
		//	pivot = pivot / 3.f;

		//	TriangleSymbol ( p2, p1, pivot, mid, loin ).Generate ( mesh, level - 1 );
		//	TriangleSymbol ( pivot, p1, p3, mid, loin ).Generate ( mesh, level - 1 );
		//	TriangleSymbol ( p2, pivot, p3, mid, loin ).Generate ( mesh, level - 1 );
		//}
		else if ( random < 45 && Triangle ( p2, p1, p3 ).area ( ) > 5000.f ) {
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

				TriangleSymbol ( p2, p5, p4, mid, loin ).Generate ( mesh, level - 1 );
				QuadrangleSymbol ( p1, p3, p4, p5, mid, loin ).Generate ( mesh, level - 1 );
			} else if ( b >= a && c >= a ) {
				p4 = ( p1 + p2 ) * rand;
				p5 = ( p1 + p3 ) * rand;

				TriangleSymbol ( p1, p5, p4, mid, loin ).Generate ( mesh, level - 1 );
				QuadrangleSymbol ( p3, p5, p4, p2, mid, loin ).Generate ( mesh, level - 1 );
			} else if ( c >= b && a >= b ) {
				p4 = ( p1 + p3 ) * rand;
				p5 = ( p2 + p3 ) * rand;

				TriangleSymbol ( p3, p5, p4, mid, loin ).Generate ( mesh, level - 1 );
				QuadrangleSymbol ( p2, p1, p4, p5, mid, loin ).Generate ( mesh, level - 1 );
			}		
		}
		else if ( Triangle ( p2, p1, p3 ).area ( ) < 5000.0f ) {
			// Génére des batiments dans le cercle inscri de 1, 2, ou 3 triangles
			int rng = rand ( ) % 3;

			if ( level % 2 == 0 )
				mesh.merge ( Mesh::Triangle ( p2, p1, p3 ) );
			else
				mesh.merge ( Mesh::Triangle ( p1, p2, p3 ) );

			float dif = 100 - ( ( distance ( mid, p2 ) / distance ( mid, loin ) ) * 100 );

			//rng = 0;
			if ( rng == 0 ) {
				Circle c = incircle ( Triangle ( p2, p1, p3 ) );
				c.radius -= ( c.radius * static_cast < float > ( rand ( ) ) / static_cast < float > ( RAND_MAX ) );
				Quadrangle q = randomQuadInCircle ( c );
				RDC ( q.p2, q.p1, q.p4, q.p3, 3.0f, dif ).G ( mesh );
			}

			if ( rng == 1 ) {
				float a = distance ( p2, p3 );
				float b = distance ( p1, p2 );
				float c = distance ( p1, p3 );

				Vec3<float> *t1 = nullptr;
				Vec3<float> *t2 = nullptr;;
				Vec3<float> p_;
				if ( a >= b && a >= c ) {
					p_ = ( p2 + p3 ) * .5f;

					t1 = Triangle ( p_, p2, p1 ).getPoints ( );
					t2 = Triangle ( p3, p_, p1 ).getPoints ( );
				}
				else if ( b >= a && b >= c ) {
					p_ = ( p1 + p2 ) * .5f;

					t1 = Triangle ( p2, p_, p3 ).getPoints ( );
					t2 = Triangle ( p3, p_, p1 ).getPoints ( );
				}
				else if ( c >= a && c >= b ) {
					p_ = ( p1 + p3 ) * .5f;

					t1 = Triangle ( p_, p2, p1 ).getPoints ( );
					t2 = Triangle ( p2, p_, p3 ).getPoints ( );
				}

				Circle c0 = incircle ( Triangle ( t1[1], t1[0], t1[2] ) );
				c0.radius -= ( c0.radius * static_cast < float > ( rand ( ) ) / static_cast < float > ( RAND_MAX ) );
				Quadrangle q = randomQuadInCircle ( c0 );
				RDC ( q.p2, q.p1, q.p4, q.p3, 3.0f, dif ).G ( mesh );

				Circle c1 = incircle ( Triangle ( t2[1], t2[0], t2[2] ) );
				c1.radius -= ( c1.radius * static_cast < float > ( rand ( ) ) / static_cast < float > ( RAND_MAX ) );
				Quadrangle q1 = randomQuadInCircle ( c1 );
				RDC ( q1.p2, q1.p1, q1.p4, q1.p3, 3.0f, dif ).G ( mesh );
			}

			if ( rng == 2 ) {
				Vec3<float> pivot ( .0f );
				pivot += p1;
				pivot += p2;
				pivot += p3;
				pivot = pivot / 3.f;

				Circle c0 = incircle ( Triangle ( p2, p1, pivot ) );
				c0.radius -= ( c0.radius * static_cast < float > ( rand ( ) ) / static_cast < float > ( RAND_MAX ) );
				Quadrangle q = randomQuadInCircle ( c0 );
				RDC ( q.p2, q.p1, q.p4, q.p3, 3.0f, dif ).G ( mesh );

				Circle c1 = incircle ( Triangle ( p3, p2, pivot ) );
				c1.radius -= ( c1.radius * static_cast < float > ( rand ( ) ) / static_cast < float > ( RAND_MAX ) );
				Quadrangle q1 = randomQuadInCircle ( c1 );
				RDC ( q1.p2, q1.p1, q1.p4, q1.p3, 3.0f, dif ).G ( mesh );

				Circle c2 = incircle ( Triangle ( p1, p3, pivot ) );
				c2.radius -= ( c2.radius * static_cast < float > ( rand ( ) ) / static_cast < float > ( RAND_MAX ) );
				Quadrangle q2 = randomQuadInCircle ( c2 );
				RDC ( q2.p2, q2.p1, q2.p4, q2.p3, 3.0f, dif ).G ( mesh );
			}
		}
		else {
			TriangleSymbol ( p2, p1, p3, mid, loin ).Generate ( mesh, level - 1 );
		}
	}
}

Quadrangle TriangleSymbol::randomQuadInCircle ( Circle c ) {
	float rng = static_cast < float > ( rand ( ) ) / static_cast < float > ( RAND_MAX ) * ( M_PI / 2.0f );
	float angle1 = rng;
	float angle2 = ( M_PI / 2.0f ) + rng;
	float angle3 = ( M_PI ) + rng;
	float angle4 = ( 3.0f * M_PI / 2.0f ) + rng;

	Quadrangle q ( 
		Vec3<float> ( c.center.x - std::cos ( angle1 ) * c.radius, c.center.y + std::sin ( angle1 ) * c.radius, c.center.z ),
		Vec3<float> ( c.center.x + std::cos ( angle2 ) * c.radius, c.center.y - std::sin ( angle2 ) * c.radius, c.center.z ),
		Vec3<float> ( c.center.x - std::cos ( angle3 ) * c.radius, c.center.y + std::sin ( angle3 ) * c.radius, c.center.z ),		
		Vec3<float> ( c.center.x + std::cos ( angle4 ) * c.radius, c.center.y - std::sin ( angle4 ) * c.radius, c.center.z ) );

	return q;
}

Circle TriangleSymbol::incircle ( Triangle t ) {
	Vec3<float>
		A = t.getPoints ( )[0],
		B = t.getPoints ( )[1],
		C = t.getPoints ( )[2];

	float a = distance ( B, C );
	float b = distance ( C, A );
	float c = distance ( A, B );

	Vec3<float>	Q =
		( a / ( a + b + c ) ) * A +
		( b / ( a + b + c ) ) * B +
		( c / ( a + b + c ) ) * C;

	float R = 2 * t.area ( ) / t.perimeter ( );

	return Circle ( Q, R );
}


TriangleSymbol TriangleSymbol::genBorder ( const Vec3<float>& p1_, const Vec3<float>& p2_, const Vec3<float>& p3_, const float& borderSize, const float& sizePavement, const float& hPavement, Mesh& m, const Vec3<float>& _mid, const Vec3<float> & _loin ) {
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

	TriangleSymbol ts ( p12, p11, p13, _mid, _loin );

	m.merge ( Mesh::RouteR ( p21, p22, p12, p11, sizePavement, hPavement ) );
	m.merge ( Mesh::RouteR ( p23, p21, p11, p13, sizePavement, hPavement ) );
	m.merge ( Mesh::RouteR ( p22, p23, p13, p12, sizePavement, hPavement ) );

	return ts;
}
