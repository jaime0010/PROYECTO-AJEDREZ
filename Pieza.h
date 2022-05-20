#pragma once
#include "Vector2D.h"

class Pieza
{
public:
	Vector2D posicion;
	float radio;
	int color;
	virtual void dibuja();


};
