#pragma once
#include"peon.h"
#include "Torre.h"
#define MAX_PIEZAS 32


class listapiezas
{
public:
	int numero_p;
	listapiezas();
    Pieza* lista_piezas[MAX_PIEZAS];
	bool agregar(Pieza*);
	void dibuja();

	void mover(int h);
	int donde_esta(Vector2D);

   
};
