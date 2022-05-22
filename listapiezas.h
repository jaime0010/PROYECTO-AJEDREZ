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

	int x_fuera_blanca = 11, y_fuera_blanca = 1;
	int x_fuera_negra = -2.5, y_fuera_negra = 1;

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
	
	bool jaque_negro();

	bool jaquemate_negro();
};
