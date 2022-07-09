#pragma once
#include "Pieza.h"

class Rey : public Pieza //un Rey es una Pieza
{
public:

	//Constructor
	Rey(Vector2D pos, bool b);

	//Métodos (heredados de la clase Pieza)
	void dibuja();
	bool validar_movimiento(Vector2D, ListaPiezas*);

};
