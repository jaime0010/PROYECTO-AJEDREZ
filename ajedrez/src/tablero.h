#pragma once
#include "listapiezas.h"
#include "freeglut.h"

class Tablero
{
public:
	//Constructor
	Tablero();
	int turno = -1;
	ListaPiezas piezas; //lista de piezas
	void inicializa();
	void dibuja();
	Vector2D preguntar();
	void esta_ocupada(Vector2D);//para saber si hay una pieza en la casilla seleccionada
};