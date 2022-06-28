#pragma once

//Forward declaration
class Pieza;

#include "Pieza.h"

//#include "peon.h"
//#include "Torre.h"
//#include "Alfil.h"
//#include "Rey.h"
//#include "Reina.h"
//#include "Caballo.h"
//#include "ETSIDI.h"

#include "ETSIDI.h"


#define MAX_PIEZAS 32


class ListaPiezas
{
//private:
	//Lista que contiene piezas de diferentes tipos
	Pieza* lista_piezas[MAX_PIEZAS];
	//Obtener una referencia a la pieza en la posicion h del array !!!!!!!!!!!!
	Pieza* obtener(int);

	//Duda
	int numero_p;
	//Límites del tablero ??
	int x_fuera_blanca = 11, y_fuera_blanca = 1;
	int x_fuera_negra = -2.5, y_fuera_negra = 1;

public:
	//Constructor
	ListaPiezas(); //Constructor
	//Obtener una referencia a la pieza según unas coordenadas
	Pieza* obtener(Vector2D);

	//Duda
	bool agregar(Pieza*);

	//Duda
	void dibuja();

	//Duda
	void mover(int h);

	//Duda
	int donde_esta(Vector2D);

	//Me dice si hay pieza en la coordenada que le paso
	bool hay_pieza(Vector2D);

	//Duda
	void destruir(int);

	//Duda
	bool es_blanca(int);

	//La fucnión validar es PROPIA de cada tipo concreto de pieza

	bool validar_peon(Vector2D,int);

	bool validar_torre(Vector2D, int);

	bool validar_alfil(Vector2D, int);

	bool validar_rey(Vector2D, int);

	bool validar_reina(Vector2D, int);

	bool validar_caballo(Vector2D, int);

	//No se si jaque mate también debería de ser propia del REY ???

	bool jaque_negro();

	bool jaquemate_negro();

	bool jaque_blanco();

	bool jaquemate_blanco();

};