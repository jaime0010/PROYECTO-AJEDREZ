#pragma once
#include "listapiezas.h"
#include "freeglut.h"


class tablero
{
public:
	tablero();
	int turno = -1;
	listapiezas piezas;
	void inicializa(); 
	void dibuja();
	Vector2D preguntar();

	void esta_ocupada(Vector2D);//para saber si hay una pieza en la casilla seleccionada
	void mapear(int fila, int estado, int colummna, int button);

	


};