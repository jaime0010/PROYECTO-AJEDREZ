#pragma once
#include "Pieza.h"

class Reina : public Pieza //una Reina es una Pieza
{
public:

	//Constructor
	Reina(Vector2D pos, float r, bool b);

	//Métodos (heredados de la clase Pieza)
	void dibuja();
	bool validar_movimiento(Vector2D, ListaPiezas*);

};
