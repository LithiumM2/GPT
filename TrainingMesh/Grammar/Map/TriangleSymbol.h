#pragma once

#include "..\Symbol.h"

class TriangleSymbol :
	public Symbol {

public:
	TriangleSymbol ( );
	~TriangleSymbol ( );

	void Generate(Mesh &mesh, int compteur);
};

