#pragma once
#include"Mat4x4.h"
#include "..\Vec3.h"

/*
Classe creant les differentes matrice de transformation
*/
class Transform
{
public:
	Mat4x4 m;
	Transform();
	Transform(Mat4x4 m_);

	/* Composition de Transformation
	* t : transformation
	* return : compose de la transformation courant et de t
	*/
	Transform operator*(const Transform &t);

	/* Translation
	* delta : vecteur
	* return : transformation de translation du vecteur delta
	*/
	static Transform translate(const Vec3<float> &delta);
	
	/* Mise a l'echelle 
	* x, y, z : scalaires
	* return : Transformation de mise a l'echelle des scalaires
	*/
	static Transform scale(float x, float y, float z);

	/* Rotation autour de l'axe x
	* angle : angle de la rotation (radian)
	* return : Transformation de rotation d'angle radian autour de l'axe x
	*/
	static Transform rotateX(float angle);

	/* Rotation autour de l'axe y
	* angle : angle de la rotation (radian)
	* return : Transformation de rotation d'angle radian autour de l'axe y
	*/
	static Transform rotateY(float angle);

	/* Rotation autour de l'axe z
	* angle : angle de la rotation (radian)
	* return : Transformation de rotation d'angle radian autour de l'axe z
	*/
	static Transform rotateZ(float angle);
	~Transform();
};

