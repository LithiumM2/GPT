#pragma once

#include "..\Symbol.h"

class QuadrangleSymbol :
	public Symbol {
public:
	QuadrangleSymbol ( );
	~QuadrangleSymbol ( );

	void Generate ( const Mesh &mesh ) const;
};

