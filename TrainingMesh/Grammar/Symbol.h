#pragma once

#include "..\Mesh\Mesh.h"

class Symbol {

public:
	Symbol ( );
	~Symbol ( );

	virtual void Generate ( Mesh &mesh, int level ) const = 0;
};

