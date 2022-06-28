#pragma once
#include "Pieza.h"

class Torre:public Pieza
{

public:

	//Constructor
	Torre(Vector2D pos, float r, int c);

	//Métodos (heredados de la clase Pieza)
	void dibuja();
	bool validar_movimiento(Vector2D, ListaPiezas*);

};
