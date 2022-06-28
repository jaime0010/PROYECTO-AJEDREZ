#pragma once
#include "Pieza.h"

class Reina : public Pieza
{
public:

	//Constructor
	Reina(Vector2D pos, float r, int c);

	//Métodos (heredados de la clase Pieza)
	void dibuja();
	bool validar_movimiento(Vector2D, ListaPiezas*);

};