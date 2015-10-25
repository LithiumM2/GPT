#pragma once
/*
* classe utilitaire representant un quaternion (qui represente une rotation)
*/
class Quaternion {
public:
	Quaternion ( );
	~Quaternion ( );
	Quaternion(float x_, float y_, float z_, float w_);
	Quaternion(const Quaternion & q);
	float
		x,
		y,
		z,
		w;

};

