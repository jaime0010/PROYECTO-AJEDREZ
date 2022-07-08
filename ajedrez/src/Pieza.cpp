#include "Pieza.h"
#include "freeglut.h"

Pieza::Pieza(Vector2D v, float r, int c) //Constructor
{
	posicion.x = v.x;
	posicion.y = v.y;
	radio = r;
	color = c;
	if (color == 255)
		blanca = true;
	else
		blanca = false;
}

bool Pieza::mismo_color(Pieza* otra)
{
	return (blanca == otra->blanca);
}

//NOTA: Innecesarios al ser virtuales puros (=0 en su declaración)
//void Pieza::dibuja(){}
//bool Pieza::validar_movimiento(Vector2D a, ListaPiezas* s)


