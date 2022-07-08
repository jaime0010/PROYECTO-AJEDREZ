#pragma once
#include "Pieza.h"

class Peon : public Pieza //un Peon es una Pieza
{
public:

	//Constructor
	Peon(Vector2D pos, float r, int c);

	//Métodos (heredados de la clase Pieza)
	void dibuja();
	bool validar_movimiento(Vector2D, ListaPiezas*);

};
