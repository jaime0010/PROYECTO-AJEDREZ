#pragma once
#include "Pieza.h"

class Torre :public Pieza //una Torre es una Pieza
{
public:

	//Constructor
	Torre(Vector2D pos, bool b);

	//Métodos (heredados de la clase Pieza)
	void dibuja();
	bool validar_movimiento(Vector2D, ListaPiezas*);

};
