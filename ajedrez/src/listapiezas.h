#pragma once

//Forward declaration
class Pieza;

#include "Pieza.h"

#include "ETSIDI.h"


#define MAX_PIEZAS 32


class ListaPiezas
{
	//private:
	//Lista que contiene piezas de diferentes tipos
	Pieza* lista_piezas[MAX_PIEZAS];
	//Obtener una referencia a la pieza en la posicion h del array !!!!!!!!!!!!
	Pieza* obtener(int);
	int numero_p;
	int x_fuera_blanca = 11, y_fuera_blanca = 1;
	int x_fuera_negra = -2.5, y_fuera_negra = 1;

public:
	//Constructor
	ListaPiezas(); //Constructor
	//Obtener una referencia a la pieza según unas coordenadas
	Pieza* obtener(Vector2D);

	bool agregar(Pieza*);

	void dibuja();

	void mover(int h);

	int donde_esta(Vector2D);

	//Me dice si hay pieza en la coordenada que le paso
	bool hay_pieza(Vector2D);

	void destruir(int);

	bool es_blanca(int);

	bool jaque_total(Vector2D, Pieza*);

	bool jaque_mate_total(Pieza*, Pieza*);
};
