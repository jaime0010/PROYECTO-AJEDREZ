#pragma once
#include "Pieza.h"

class Alfil : public Pieza
{
public:

	//Constructor
	Alfil(Vector2D pos, float r, int c);

	//Métodos (heredados de la clase Pieza)
	void dibuja();
	bool validar_movimiento(Vector2D, Vector2D, Pieza*);

	//Bien
	bool validar_movimiento(Vector2D, ListaPiezas*);

};
