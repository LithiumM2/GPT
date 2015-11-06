#pragma once

#include "..\Mesh\Mesh.h"

class Symbol {

public:
	Symbol ( );
	~Symbol ( );

	virtual void Generate ( Mesh &mesh ) const = 0;
};

