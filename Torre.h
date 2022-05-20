#pragma once
#include "Pieza.h"

class Torre:public Pieza
{

public:
	Torre(float x, float y, float r, int c);

	void dibuja();

};
