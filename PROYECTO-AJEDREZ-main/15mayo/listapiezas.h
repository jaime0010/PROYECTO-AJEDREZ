#pragma once
#include"peon.h"
#include "Torre.h"
#include"Alfil.h"
#include"Rey.h"
#include"Reina.h"
#include"Caballo.h"
#define MAX_PIEZAS 32


class listapiezas
{
public:
	int numero_p;
	listapiezas();

	int x_fuera = 11, y_fuera = 1;

    Pieza* lista_piezas[MAX_PIEZAS];
	bool agregar(Pieza*);
	void dibuja();

	void mover(int h);
	int donde_esta(Vector2D);

	void destruir(int);

	bool es_blanca(int);

	bool validar_peon(Vector2D,int);

	bool validar_torre(Vector2D, int);

	bool validar_alfil(Vector2D, int);

	bool validar_rey(Vector2D, int);

	bool validar_reina(Vector2D, int);

	bool validar_caballo(Vector2D, int);
};