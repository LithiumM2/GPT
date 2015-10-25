#include "Quaternion.h"


Quaternion::Quaternion ( ) {
}

Quaternion::Quaternion(float x_, float y_, float z_, float w_) :x(x_), y(y_), z(z_), w(w_){};
Quaternion::Quaternion(const Quaternion & q) : x(q.x), y(q.y), z(q.z), w(q.w){};
Quaternion::~Quaternion ( ) {
}
