#pragma once
#include "listapiezas.h"
#include "freeglut.h"

//Es algo as� como el "main" de mi ejemplo
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

	//void mapear(int fila, int estado, int colummna, int button);
};