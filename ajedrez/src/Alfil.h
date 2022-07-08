#pragma once
#include "Pieza.h"

class Alfil : public Pieza //un Alfil es una Pieza
{
public:

	//Constructor
	Alfil(Vector2D pos, float r, int c);

	//Métodos (heredados de la clase Pieza)
	void dibuja();
	bool validar_movimiento(Vector2D, ListaPiezas*);

};
