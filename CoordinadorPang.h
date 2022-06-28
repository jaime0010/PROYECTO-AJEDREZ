#pragma once

#include"tablero.h"

class CoordinadorPang
{
public:
	CoordinadorPang();
	virtual ~CoordinadorPang();

	void teclaEspecial(unsigned char key);
	void Tecla(unsigned char key);
	void mueve();
	void dibuja();

protected:
	Tablero tab;
	enum Estado { INICIO, JUEGO, EMPEZAR };
	Estado estado;
};
