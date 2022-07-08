#pragma once
#include "Pieza.h"

class Caballo : public Pieza //un Caballo es una Pieza
{
public:

	//Constructor
	Caballo(Vector2D pos, float r, int c);

	//M�todos (heredados de la clase Pieza)
	void dibuja();
	bool validar_movimiento(Vector2D, ListaPiezas*);

};