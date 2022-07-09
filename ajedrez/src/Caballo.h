#pragma once
#include "Pieza.h"

class Caballo : public Pieza //un Caballo es una Pieza
{
public:

	//Constructor
	Caballo(Vector2D pos, bool b);

	//Métodos (heredados de la clase Pieza)
	void dibuja();
	bool validar_movimiento(Vector2D, ListaPiezas*);

};
