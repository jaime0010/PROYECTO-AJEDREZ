#pragma once
#include "listapiezas.h"
#include "freeglut.h"


class tablero
{
public:
	tablero();
	listapiezas piezas;
	void inicializa(); 
	void dibuja();
	Vector2D preguntar();

	void esta_ocupada(Vector2D);//para saber si hay una pieza en la casilla seleccionada


};
